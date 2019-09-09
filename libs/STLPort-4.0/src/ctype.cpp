/*
 * Copyright (c) 1999
 * Silicon Graphics Computer Systems, Inc.
 *
 * Copyright (c) 1999 
 * Boris Fomitchev
 *
 * This material is provided "as is", with absolutely no warranty expressed
 * or implied. Any use is at your own risk.
 *
 * Permission to use or copy this software for any purpose is hereby granted 
 * without fee, provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 *
 */ 

# include "stlport_prefix.h"

#include <string>
#include <stl/_locale.h>
#include <stl/_ctype.h>
#include <stl/_threads.h>

__STL_BEGIN_NAMESPACE

// Some helper functions used in ctype<>::scan_is and scan_is_not.

struct _Ctype_is_mask {
  typedef char argument_type;
  typedef bool result_type;
  
  ctype_base::mask M;
  const ctype_base::mask* table;
  
  _Ctype_is_mask(ctype_base::mask m, const ctype_base::mask* t) : M(m), table(t) {}
  bool operator()(char c) const { return (table[(unsigned char) c] & M) != 0; }
};

//----------------------------------------------------------------------
// ctype<char>

ctype<char>::ctype(const mask* tab, bool del, size_t refs)
#if !(defined(__MRC__) || defined(__SC__) )		//*TY 04/29/2000 - added workaround for mpw
  : locale::facet(refs),
#else					//*TY 04/29/2000 - 
  : _facet(refs),		//*TY 04/29/2000 - they forget to look into the nested class for the ctor
#endif					//*TY 04/29/2000 - 
  _M_ctype_table(0)
{
  _M_ctype_table = tab ? tab : classic_table();
  _M_delete = tab && del;
}

ctype<char>::~ctype() {
  if (_M_delete)
    delete[] __CONST_CAST(mask*, _M_ctype_table);
}

const char*
ctype<char>::is(const char* low, const char* high, mask* vec) const {
  for (const char* p = low;p != high; ++p, ++vec) {
    *vec = table()[(unsigned char)*p];
  }
  return high;
}

const char*
ctype<char>::scan_is(mask m, const char* low, const char* high) const {
  return find_if(low, high, _Ctype_is_mask(m, this->table()));
}

const char*
ctype<char>::scan_not(mask m, const char* low, const char* high) const {
  return find_if(low, high, not1(_Ctype_is_mask(m, this->table())));
}

const char* ctype<char>::do_toupper(char* low, const char* high) const {
  for ( ; low < high; ++low)
    *low = (char) _S_upper[(unsigned char) *low];
  return high;
}

const char* ctype<char>::do_tolower(char* low, const char* high) const {
  for ( ; low < high; ++low)
    *low = (char) _S_lower[(unsigned char) *low];
  return high;
}

// The classic table: static data members.

# if !defined(__STL_STATIC_CONST_INIT_BUG) && !(defined(__MRC__) || defined(__SC__))
//*TY 02/25/2000 - added workaround for MPW compilers; they confuse on in-class static const
const size_t ctype<char>::table_size;
# endif

// This macro is specifically for platforms where isprint() relies
// on separate flag

# define PRINTFLAG mask( _Locale_PRINT & ~(_Locale_UPPER | _Locale_LOWER | _Locale_ALPHA | _Locale_DIGIT | _Locale_PUNCT | _Locale_SPACE | _Locale_XDIGIT )) 

// Ctype table for the ASCII character set.
// There are 257 entries in this table.  The first is EOF (-1).  
// That is, the "table" seen by ctype<char> member functions is
// _S_classic_table + 1.
const ctype_base::mask 
ctype<char>::_S_classic_table[257] = 
{
  mask(0) /* EOF */,
  cntrl /* null */,
  cntrl /* ^A */,
  cntrl /* ^B */,
  cntrl /* ^C */,
  cntrl /* ^D */,
  cntrl /* ^E */,
  cntrl /* ^F */,
  cntrl /* ^G */,
  cntrl /* ^H */,
  mask(space | cntrl) /* tab */,
  mask(space | cntrl) /* LF */,
  mask(space | cntrl) /* ^K */,
  mask(space | cntrl) /* FF */,
  mask(space | cntrl) /* ^M */,
  cntrl /* ^N */,
  cntrl /* ^O */,
  cntrl /* ^P */,
  cntrl /* ^Q */,
  cntrl /* ^R */,
  cntrl /* ^S */,
  cntrl /* ^T */,
  cntrl /* ^U */,
  cntrl /* ^V */,
  cntrl /* ^W */,
  cntrl /* ^X */,
  cntrl /* ^Y */,
  cntrl /* ^Z */,
  cntrl /* esc */,
  cntrl /* ^\ */,
  cntrl /* ^] */,
  cntrl /* ^^ */,
  cntrl /* ^_ */,
  mask (space | PRINTFLAG) /*  */,
  mask (punct | PRINTFLAG ) /* ! */,
  mask (punct | PRINTFLAG ) /* " */,
  mask (punct | PRINTFLAG ) /* # */,
  mask (punct | PRINTFLAG ) /* $ */,
  mask (punct | PRINTFLAG ) /* % */,
  mask (punct | PRINTFLAG ) /* & */,
  mask (punct | PRINTFLAG ) /* ' */,
  mask (punct | PRINTFLAG ) /* ( */,
  mask (punct | PRINTFLAG ) /* ) */,
  mask (punct | PRINTFLAG ) /* * */,
  mask (punct | PRINTFLAG ) /* + */,
  mask (punct | PRINTFLAG ) /* , */,
  mask (punct | PRINTFLAG ) /* - */,
  mask (punct | PRINTFLAG ) /* . */,
  mask (punct | PRINTFLAG ) /* / */,
  mask(digit | PRINTFLAG | xdigit) /* 0 */,
  mask(digit | PRINTFLAG | xdigit) /* 1 */,
  mask(digit | PRINTFLAG | xdigit) /* 2 */,
  mask(digit | PRINTFLAG | xdigit) /* 3 */,
  mask(digit | PRINTFLAG | xdigit) /* 4 */,
  mask(digit | PRINTFLAG | xdigit) /* 5 */,
  mask(digit | PRINTFLAG | xdigit) /* 6 */,
  mask(digit | PRINTFLAG | xdigit) /* 7 */,
  mask(digit | PRINTFLAG | xdigit) /* 8 */,
  mask(digit | PRINTFLAG | xdigit) /* 9 */,
  mask (punct | PRINTFLAG ) /* : */,
  mask (punct | PRINTFLAG ) /* ; */,
  mask (punct | PRINTFLAG ) /* < */,
  mask (punct | PRINTFLAG ) /* = */,
  mask (punct | PRINTFLAG ) /* > */,
  mask (punct | PRINTFLAG ) /* ? */,
  mask (punct | PRINTFLAG ) /* ! */,
  mask(alpha | PRINTFLAG | upper | xdigit) /* A */,
  mask(alpha | PRINTFLAG | upper | xdigit) /* B */,
  mask(alpha | PRINTFLAG | upper | xdigit) /* C */,
  mask(alpha | PRINTFLAG | upper | xdigit) /* D */,
  mask(alpha | PRINTFLAG | upper | xdigit) /* E */,
  mask(alpha | PRINTFLAG | upper | xdigit) /* F */,
  mask(alpha | PRINTFLAG | upper) /* G */,
  mask(alpha | PRINTFLAG | upper) /* H */,
  mask(alpha | PRINTFLAG | upper) /* I */,
  mask(alpha | PRINTFLAG | upper) /* J */,
  mask(alpha | PRINTFLAG | upper) /* K */,
  mask(alpha | PRINTFLAG | upper) /* L */,
  mask(alpha | PRINTFLAG | upper) /* M */,
  mask(alpha | PRINTFLAG | upper) /* N */,
  mask(alpha | PRINTFLAG | upper) /* O */,
  mask(alpha | PRINTFLAG | upper) /* P */,
  mask(alpha | PRINTFLAG | upper) /* Q */,
  mask(alpha | PRINTFLAG | upper) /* R */,
  mask(alpha | PRINTFLAG | upper) /* S */,
  mask(alpha | PRINTFLAG | upper) /* T */,
  mask(alpha | PRINTFLAG | upper) /* U */,
  mask(alpha | PRINTFLAG | upper) /* V */,
  mask(alpha | PRINTFLAG | upper) /* W */,
  mask(alpha | PRINTFLAG | upper) /* X */,
  mask(alpha | PRINTFLAG | upper) /* Y */,
  mask(alpha | PRINTFLAG | upper) /* Z */,
  mask (punct | PRINTFLAG ) /* [ */,
  mask (punct | PRINTFLAG ) /* \ */,
  mask (punct | PRINTFLAG ) /* ] */,
  mask (punct | PRINTFLAG ) /* ^ */,
  mask (punct | PRINTFLAG ) /* _ */,
  mask (punct | PRINTFLAG ) /* ` */,
  mask(alpha | PRINTFLAG | lower | xdigit) /* a */,
  mask(alpha | PRINTFLAG | lower | xdigit) /* b */,
  mask(alpha | PRINTFLAG | lower | xdigit) /* c */,
  mask(alpha | PRINTFLAG | lower | xdigit) /* d */,
  mask(alpha | PRINTFLAG | lower | xdigit) /* e */,
  mask(alpha | PRINTFLAG | lower | xdigit) /* f */,
  mask(alpha | PRINTFLAG | lower) /* g */,
  mask(alpha | PRINTFLAG | lower) /* h */,
  mask(alpha | PRINTFLAG | lower) /* i */,
  mask(alpha | PRINTFLAG | lower) /* j */,
  mask(alpha | PRINTFLAG | lower) /* k */,
  mask(alpha | PRINTFLAG | lower) /* l */,
  mask(alpha | PRINTFLAG | lower) /* m */,
  mask(alpha | PRINTFLAG | lower) /* n */,
  mask(alpha | PRINTFLAG | lower) /* o */,
  mask(alpha | PRINTFLAG | lower) /* p */,
  mask(alpha | PRINTFLAG | lower) /* q */,
  mask(alpha | PRINTFLAG | lower) /* r */,
  mask(alpha | PRINTFLAG | lower) /* s */,
  mask(alpha | PRINTFLAG | lower) /* t */,
  mask(alpha | PRINTFLAG | lower) /* u */,
  mask(alpha | PRINTFLAG | lower) /* v */,
  mask(alpha | PRINTFLAG | lower) /* w */,
  mask(alpha | PRINTFLAG | lower) /* x */,
  mask(alpha | PRINTFLAG | lower) /* y */,
  mask(alpha | PRINTFLAG | lower) /* x */,
  mask (punct | PRINTFLAG ) /* { */,
  mask (punct | PRINTFLAG ) /* | */,
  mask (punct | PRINTFLAG ) /* } */,
  mask (punct | PRINTFLAG ) /* ~ */,
  cntrl /* del (0x7f)*/,
    /* ASCII is a 7-bit code, so everything else is non-ASCII */
mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),
mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),
mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),
mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),
mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),
mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),
mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),
mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),
mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),
mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),
mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),
mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),
mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),
mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),
mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),
mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0),  mask(0)
};

// For every c in the range 0 <= c < 256, _S_upper[c] is the
// uppercased version of c and _S_lower[c] is the lowercased
// version.  As before, these two tables assume the ASCII character
// set.

const unsigned char ctype<char>::_S_upper[256] =
{
  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
  0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
  0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
  0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
  0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
  0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
  0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
  0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
  0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
  0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
  0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57,
  0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
  0x60, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
  0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
  0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57,
  0x58, 0x59, 0x5a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f,
  0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
  0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
  0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
  0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
  0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
  0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
  0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
  0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
  0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
  0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
  0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7,
  0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
  0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7,
  0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
  0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
  0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};

const unsigned char ctype<char>::_S_lower[256] =
{
  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
  0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
  0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
  0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
  0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
  0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
  0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
  0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
  0x40, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
  0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
  0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
  0x78, 0x79, 0x7a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
  0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
  0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
  0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
  0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f,
  0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
  0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
  0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
  0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
  0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
  0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
  0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
  0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
  0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
  0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
  0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7,
  0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
  0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7,
  0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
  0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
  0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};

__STL_END_NAMESPACE

// Local Variables:
// mode:C++
// End:

