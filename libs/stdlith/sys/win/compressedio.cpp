//------------------------------------------------------------------
//
//	FILE	  : CompressedIO.cpp
//
//	PURPOSE	  : 
//
//	CREATED	  : February 15 1997
//
//	COPYRIGHT : Microsoft 1997 All Rights Reserved
//
//------------------------------------------------------------------

// Includes....
#include "zlib.h"
#include "compressedio.h"



// Allocators for ZLib's allocation stuff.

void* CustomZAlloc( voidpf opqaud, uInt items, uInt size )
{
	void		*ptr;

	ptr = malloc( items*size );
	if( !ptr )
	{
		return Z_NULL;
	}

	return ptr;
}

void CustomZFree( voidpf opaque, voidpf address )
{
	free( address );
}




CCompressedIO::CCompressedIO()
{
	m_pReadStream = NULL;
	m_iCurLoadedChunk = (uint32)-1;
	EnableExceptions( TRUE );
}


CCompressedIO::~CCompressedIO()
{
	Term();
}


LTBOOL CCompressedIO::WriteStream( CAbstractIO *pInStream, CAbstractIO *pOutStream, uint32 chunkSize, uint32 sizeToWrite )
{
	CAbstractIO		&inStream = *pInStream;
	CAbstractIO		&outStream = *pOutStream;
	
	CMoByteArray	compressed;
	CMoByteArray	uncompressed;
	
	CMoDWordArray	chunkSizes;
	CMoDWordArray	uncompressedChunkSizes;
	
	uint32			descriptorPos;

	uint32			nChunks;
	uint32			nFullChunks = sizeToWrite / chunkSize;
	uint32			chunkLen;
	
	uint32			chunkStartPos, chunkEndPos, endPos;
	uint32			i;

	
	// Find out how many total chunks there are.
	nChunks = nFullChunks;
	if( chunkSize*nFullChunks != sizeToWrite )
		++nChunks;

	
	// Start the header off.
	outStream << nChunks;
	outStream << chunkSize;

	descriptorPos =	outStream.GetCurPos();


// This causes errors in CMemoryIO .. so now it just writes garbage..
//	outStream.SeekTo( outStream.GetCurPos() + sizeof(uint32)*nChunks + sizeof(uint32)*nChunks );
	for( i=0; i < nChunks*2; i++ )
		outStream << (uint32)0;

	
	compressed.SetSize( (chunkSize*2) + 8 );	
	uncompressed.SetSize( chunkSize );

		
	// Write all the full chunks.
	for( i=0; i < nFullChunks; i++ )
	{
		chunkStartPos = outStream.GetCurPos();
		WriteChunk( inStream, outStream, compressed, uncompressed, chunkSize );
		chunkEndPos = outStream.GetCurPos();

		chunkSizes.Append( chunkEndPos - chunkStartPos );
		uncompressedChunkSizes.Append( chunkSize );
	}

	// Write an extra one if necessary.
	if( nChunks != nFullChunks )
	{
		chunkLen = WriteChunk( inStream, outStream, compressed, uncompressed, sizeToWrite - (nFullChunks*chunkSize) );

		chunkSizes.Append( chunkLen );
		uncompressedChunkSizes.Append( sizeToWrite - (nFullChunks*chunkSize) );
	}


	// Go back and fill in the header.
	ASSERT( chunkSizes.GetSize() == nChunks );
	
	endPos = outStream.GetCurPos();

	outStream.SeekTo( descriptorPos );
	
	// Write the compressed chunk sizes.
	for( i=0; i < nChunks; i++ )
		outStream << chunkSizes[i];

	// Write the uncompressed chunk sizes.
	for( i=0; i < nChunks; i++ )
		outStream << uncompressedChunkSizes[i];

	outStream.SeekTo( endPos );

	return TRUE;
}


uint32 CCompressedIO::WriteChunk( CAbstractIO &inStream, CAbstractIO &outStream, CMoByteArray &compressed, CMoByteArray &uncompressed, uint32 size )
{
    z_stream		stream;
	int				err;


	inStream.Read( uncompressed.GetArray(), size );

    stream.next_in = (Bytef*)uncompressed.GetArray();
    stream.avail_in = (uInt)size;

    stream.next_out = compressed.GetArray();
    stream.avail_out = (uInt)compressed.GetSize();

    stream.zalloc = CustomZAlloc;
    stream.zfree = CustomZFree;
    stream.opaque = (voidpf)0;

    err = deflateInit( &stream, Z_DEFAULT_COMPRESSION );
    if( err != Z_OK )
		throw CLithMemException();

    err = deflate( &stream, Z_FINISH );
    deflateEnd(&stream);

    if( err != Z_STREAM_END )
		throw CLithMemException();

	outStream.Write( compressed.GetArray(), stream.total_out );
	return (uint32)stream.total_out;
}


LTBOOL CCompressedIO::InitRead( CAbstractIO *pStreamToUse )
{
	uint32			i;
	uint32			curOffset;
	uint32			maxCompressedChunkSize;

	
	Term();


	// Store the stream pointer.
	m_pReadStream = pStreamToUse;


	// Read the header.
	Stream() >> m_nChunks >> m_ChunkSize;

	// Read the compressed chunk sizes and offsets.
	m_ChunkOffsets.SetSize( m_nChunks );
	m_ChunkSizes.SetSize( m_nChunks );

	curOffset = 0;
	maxCompressedChunkSize = 0;

	for( i=0; i < m_nChunks; i++ )
	{
		Stream() >> m_ChunkSizes[i];
		m_ChunkOffsets[i] = curOffset;

		curOffset += m_ChunkSizes[i];

		if( m_ChunkSizes[i] > maxCompressedChunkSize )
			maxCompressedChunkSize = m_ChunkSizes[i];
	}

	// Read the uncompressed chunk sizes.
	m_UncompressedChunkSizes.SetSize( m_nChunks );
	
	m_FileLen = 0;
	for( i=0; i < m_nChunks; i++ )
	{
		Stream() >> m_UncompressedChunkSizes[i];
		m_FileLen += m_UncompressedChunkSizes[i];
	}


	// Setup space for the compressed data to be read into.
	m_CompressedChunkSpace.SetSize( maxCompressedChunkSize );

	// Setup space for the current uncompressed chunk.
	m_UncompressedChunk.SetSize( m_ChunkSize );

	
	// Set it up on the first byte.
	SwitchToChunk( 0, 0 );


	// Store the base file position (where the actual data starts).
	m_BaseFilePos = Stream().GetCurPos();
		
	return TRUE;
}


void CCompressedIO::Term()
{
	if( m_pReadStream )
	{
		m_pReadStream = NULL;
		
		m_ChunkOffsets.Term();
		m_ChunkSizes.Term();
		m_UncompressedChunkSizes.Term();
		m_CompressedChunkSpace.Term();
		m_UncompressedChunk.Term();

		m_iCurChunk = (uint32)-1;
		m_CurChunkPos = 0;
	}
}


LTBOOL CCompressedIO::Read( void *pData, uint32 size )
{
	uint32			i;
	uint8			*pByteData = (uint8*)pData;


	ASSERT( m_pReadStream );

	// Make sure the current chunk is loaded.
	if( m_iCurLoadedChunk != m_iCurChunk )
		LoadCurChunk();

	for( i=0; i < size; i++ )
	{
		// Move to the next chunk if necessary.
		if( m_CurChunkPos >= m_CurChunkSize )
		{
			// Make sure the even is a next chunk.
			if( (m_iCurChunk+1) >= m_nChunks )
				throw CLithIOException(MoReadError);

			SwitchToChunk( m_iCurChunk+1, 0 );
			LoadCurChunk();
		}

		pByteData[i] = m_UncompressedChunk[m_CurChunkPos];
		++m_CurChunkPos;
	}
	
	return TRUE;
}


uint32 CCompressedIO::GetCurPos()
{
	ASSERT( m_pReadStream );
	
	
	return (m_iCurChunk*m_ChunkSize) + m_CurChunkPos;
}


uint32 CCompressedIO::GetLen()
{
	ASSERT( m_pReadStream );
	
	return m_FileLen;
}


LTBOOL CCompressedIO::SeekTo( uint32 pos )
{
	if( pos > m_FileLen )
		MaybeThrowIOException( MoSeekError );

	SwitchToChunk( pos/m_ChunkSize, pos%m_ChunkSize );	
	return TRUE;
}


void CCompressedIO::SwitchToChunk( uint32 iChunk, uint32 offset )
{
	ASSERT( iChunk < m_nChunks );
	
	m_iCurChunk = iChunk;
	m_CurChunkPos = offset;

	m_CurChunkSize = m_UncompressedChunkSizes[iChunk];
}


void CCompressedIO::LoadCurChunk()
{
    z_stream		stream;
    int				err;


	ASSERT( m_pReadStream && (m_iCurChunk != (uint32)-1) );

	// Read in the compressed data.
	Stream().SeekTo( m_BaseFilePos + m_ChunkOffsets[m_iCurChunk] );
	Stream().Read( m_CompressedChunkSpace.GetArray(), m_ChunkSizes[m_iCurChunk] );


    stream.next_in = (Bytef*)m_CompressedChunkSpace.GetArray();
    stream.avail_in = (uInt)m_ChunkSizes[m_iCurChunk];
    
    stream.next_out = m_UncompressedChunk.GetArray();
    stream.avail_out = (uInt)m_ChunkSize;

    stream.zalloc = (alloc_func)CustomZAlloc;
    stream.zfree = (free_func)CustomZFree;

    err = inflateInit( &stream );
    if( err != Z_OK )
		throw CLithMemException();

    err = inflate( &stream, Z_FINISH );
    inflateEnd(&stream);

    if( err != Z_STREAM_END )
		throw CLithMemException();

	// Ok .. now m_iCurChunk is loaded.
	m_iCurLoadedChunk = m_iCurChunk;
}









