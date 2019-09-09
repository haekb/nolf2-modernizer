//------------------------------------------------------------------
//
//	FILE	  : CompressedIO.h
//
//	PURPOSE	  : Defines the CCompressedIO class, which allows you
//              to compress any IO stream.
//
//	CREATED	  : February 15 1997
//
//	COPYRIGHT : Microsoft 1997 All Rights Reserved
//
//------------------------------------------------------------------

#ifndef __COMPRESSEDIO_H__
	#define __COMPRESSEDIO_H__


	// Includes....
	#include "abstractio.h"
	#include "dynarray.h"


	class CCompressedIO : public CAbstractIO
	{
		// Initialization.
		public:

								CCompressedIO();
								~CCompressedIO();

			// Compresses the input stream into the output stream.
			// Throws CLithMemException and any exception thrown by pInStream or pOutStream.
			LTBOOL				WriteStream( CAbstractIO *pInStream, CAbstractIO *pOutStream, uint32 chunkSize, uint32 sizeToWrite );
			
			// Read from a stream compressed with WriteStream.
			LTBOOL				InitRead( CAbstractIO *pStreamToUse );
			void				Term();

		
		// Normal IO routines.
		public:

			// CANNOT WRITE TO A COMPRESSEDIO.  USE WRITESTREAM.
			virtual LTBOOL			Write( void *pBlock, uint32 blockSize )	{ ASSERT(FALSE); return FALSE; }

			// Functions to read data
			virtual LTBOOL			Read( void *pBlock, uint32 blockSize );

			virtual uint32			GetCurPos();
			virtual uint32			GetLen();

			virtual LTBOOL			SeekTo( uint32 pos );


		// Internal stuff.
		protected:

			CAbstractIO&		Stream()	{ return *m_pReadStream; }

			uint32				WriteChunk( CAbstractIO &inStream, CAbstractIO &outStream, CMoByteArray &compressed, CMoByteArray &uncompressed, uint32 size );

			void				SwitchToChunk( uint32 iChunk, uint32 offset );
			void				LoadCurChunk();


		protected:

			// Space for the compressed data while uncompressing into the uncompressed chunk.
			CMoByteArray		m_CompressedChunkSpace;

			// The current uncompressed chunk.
			CMoByteArray		m_UncompressedChunk;

			
			// Where we are in the file.
			uint32				m_iCurChunk;
			uint32				m_CurChunkPos;

			// Just stored data .. the current chunk's uncompressed size.
			uint32				m_CurChunkSize;

			
			// Which chunk is loaded (-1 if none).  It won't actually load a chunk and set this
			// until you try to read from a chunk.
			uint32				m_iCurLoadedChunk;

			

			// Number of chunks in this file.
			uint32				m_nChunks;

			// (Uncompressed) chunk size for this file.
			uint32				m_ChunkSize;			

			// (Uncompressed) file length.
			uint32				m_FileLen;


			// Offsets of each chunk into the file (NOT offset by m_BaseFilePos).
			CMoDWordArray		m_ChunkOffsets;

			// Size of each (compressed) chunk in the file.
			CMoDWordArray		m_ChunkSizes;


			// Size of each uncompressed chunk in the file.
			CMoDWordArray		m_UncompressedChunkSizes;


			// Used when seeking .. this way you can start up a compressed stream in the
			// middle of a big file containing lots of little compressed streams.
			uint32				m_BaseFilePos;


			// Stream used for reading.
			CAbstractIO			*m_pReadStream;

	};


#endif  // __COMPRESSEDIO_H__

