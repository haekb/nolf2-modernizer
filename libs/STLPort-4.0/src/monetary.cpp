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

#include <iterator>
#include <cstring>
#include <cstdlib>

#include <locale>
// #include <algorithm> // for copy


__STL_BEGIN_NAMESPACE

void __init_monetary_formats(money_base::pattern& pos_format,
			     money_base::pattern& neg_format) {
  pos_format.field[0] = (char) money_base::symbol;
  pos_format.field[1] = (char) money_base::sign;
  pos_format.field[2] = (char) money_base::none;
  pos_format.field[3] = (char) money_base::value;

  neg_format.field[0] = (char) money_base::symbol;
  neg_format.field[1] = (char) money_base::sign;
  neg_format.field[2] = (char) money_base::none;
  neg_format.field[3] = (char) money_base::value;
}

void __init_monetary_formats(money_base::pattern& pos_format,
			     money_base::pattern& neg_format,
			     _Locale_monetary * monetary) {
  switch (_Locale_p_sign_posn(monetary)) {
    case 0: case 1:
      pos_format.field[0] = (char) money_base::sign;
      if (_Locale_p_cs_precedes(monetary)) {
	pos_format.field[1] = (char) money_base::symbol;
	if (_Locale_p_sep_by_space(monetary)) {
	  pos_format.field[2] = (char) money_base::space;
	  pos_format.field[3] = (char) money_base::value;
	}
	else {
	  pos_format.field[2] = (char) money_base::value;
	  pos_format.field[3] = (char) money_base::none;
	}
      }
      else {
	pos_format.field[2] = (char) money_base::value;
	if (_Locale_p_sep_by_space(monetary)) {
	  pos_format.field[2] = (char) money_base::space;
	  pos_format.field[3] = (char) money_base::symbol;
	}
	else {
	  pos_format.field[2] = (char) money_base::symbol;
	  pos_format.field[3] = (char) money_base::none;
	}
      }       
      break;
    case 2:
      if (_Locale_p_cs_precedes(monetary)) {
	pos_format.field[0] = (char) money_base::symbol;
	if (_Locale_p_sep_by_space(monetary)) {
	  pos_format.field[1] = (char) money_base::space;
	  pos_format.field[2] = (char) money_base::value;
	  pos_format.field[3] = (char) money_base::sign;
	}
	else {
	  pos_format.field[1] = (char) money_base::value;
	  pos_format.field[2] = (char) money_base::sign;
	  pos_format.field[3] = (char) money_base::none;
	}
      }
      else {
	pos_format.field[1] = (char) money_base::value;
	if (_Locale_p_sep_by_space(monetary)) {
	  pos_format.field[1] = (char) money_base::space;
	  pos_format.field[2] = (char) money_base::symbol;
	  pos_format.field[3] = (char) money_base::sign;
	}
	else {
	  pos_format.field[1] = (char) money_base::symbol;
	  pos_format.field[2] = (char) money_base::sign;
	  pos_format.field[3] = (char) money_base::none;
	}
      }
      break;
    case 3:
      if (_Locale_p_cs_precedes(monetary)) {
	pos_format.field[0] = (char) money_base::sign;
	pos_format.field[1] = (char) money_base::symbol;
	if (_Locale_p_sep_by_space(monetary)) {
	  pos_format.field[2] = (char) money_base::space;
	  pos_format.field[3] = (char) money_base::value;
	}
	else {
	  pos_format.field[2] = (char) money_base::value;
	  pos_format.field[3] = (char) money_base::none;
	}
      }
      else {
	pos_format.field[0] = (char) money_base::value;
	pos_format.field[1] = (char) money_base::sign;
	pos_format.field[2] = (char) money_base::symbol;
	pos_format.field[3] = (char) money_base::none;
      }
      break;
    case 4: default:
      if (_Locale_p_cs_precedes(monetary)) {
	pos_format.field[0] = (char) money_base::symbol;
	pos_format.field[1] = (char) money_base::sign;
	pos_format.field[2] = (char) money_base::value;
	pos_format.field[3] = (char) money_base::none;
      }
      else {
	pos_format.field[0] = (char) money_base::value;
	if (_Locale_p_sep_by_space(monetary)) {
	  pos_format.field[1] = (char) money_base::space;
	  pos_format.field[2] = (char) money_base::symbol;
	  pos_format.field[3] = (char) money_base::sign;
	}
        else {
	  pos_format.field[1] = (char) money_base::symbol;
	  pos_format.field[2] = (char) money_base::sign;
	  pos_format.field[3] = (char) money_base::none;
	}
      }
    break;
  }

  switch (_Locale_n_sign_posn(monetary)) {
    case 0: case 1:
      neg_format.field[0] = (char) money_base::sign;
      if (_Locale_n_cs_precedes(monetary)) {
        neg_format.field[1] = (char) money_base::symbol;
	if (_Locale_n_sep_by_space(monetary)) {
	  neg_format.field[2] = (char) money_base::space;
	  neg_format.field[3] = (char) money_base::value;
	}
	else {
	  neg_format.field[2] = (char) money_base::value;
	  neg_format.field[3] = (char) money_base::none;
	}
      }
      else {
	neg_format.field[2] = (char) money_base::value;
	if (_Locale_n_sep_by_space(monetary)) {
	  neg_format.field[2] = (char) money_base::space;
	  neg_format.field[3] = (char) money_base::symbol;
	}
	else {
	  neg_format.field[2] = (char) money_base::symbol;
	  neg_format.field[3] = (char) money_base::none;
	}
      }       
      break;
    case 2:
      if (_Locale_n_cs_precedes(monetary)) {
	neg_format.field[0] = (char) money_base::symbol;
	if (_Locale_n_sep_by_space(monetary)) {
	  neg_format.field[1] = (char) money_base::space;
	  neg_format.field[2] = (char) money_base::value;
	  neg_format.field[3] = (char) money_base::sign;
	}
	else {
	  neg_format.field[1] = (char) money_base::value;
	  neg_format.field[2] = (char) money_base::sign;
	  neg_format.field[3] = (char) money_base::none;
	}
      }
      else {
	neg_format.field[1] = (char) money_base::value;
	if (_Locale_n_sep_by_space(monetary)) {
	  neg_format.field[1] = (char) money_base::space;
	  neg_format.field[2] = (char) money_base::symbol;
	  neg_format.field[3] = (char) money_base::sign;
	}
	else {
	  neg_format.field[1] = (char) money_base::symbol;
	  neg_format.field[2] = (char) money_base::sign;
	  neg_format.field[3] = (char) money_base::none;
	}
      }
      break;
    case 3:
      if (_Locale_n_cs_precedes(monetary)) {
	neg_format.field[0] = (char) money_base::sign;
	neg_format.field[1] = (char) money_base::symbol;
	if (_Locale_n_sep_by_space(monetary)) {
	  neg_format.field[2] = (char) money_base::space;
	  neg_format.field[3] = (char) money_base::value;
	}
	else {
	  neg_format.field[2] = (char) money_base::value;
	  neg_format.field[3] = (char) money_base::none;
	}
      }
      else {
	neg_format.field[0] = (char) money_base::value;
	neg_format.field[1] = (char) money_base::sign;
	neg_format.field[2] = (char) money_base::symbol;
	neg_format.field[3] = (char) money_base::none;
      }
      break;
    case 4: default:
      if (_Locale_n_cs_precedes(monetary)) {
	neg_format.field[0] = (char) money_base::symbol;
	neg_format.field[1] = (char) money_base::sign;
	neg_format.field[2] = (char) money_base::value;
	neg_format.field[3] = (char) money_base::none;
      }
      else {
	neg_format.field[0] = (char) money_base::value;
	if (_Locale_n_sep_by_space(monetary)) {
	  neg_format.field[1] = (char) money_base::space;
	  neg_format.field[2] = (char) money_base::symbol;
	  neg_format.field[3] = (char) money_base::sign;
	}
        else {
	  neg_format.field[1] = (char) money_base::symbol;
	  neg_format.field[2] = (char) money_base::sign;
	  neg_format.field[3] = (char) money_base::none;
	}
      }
      break;
  }
}

__STL_END_NAMESPACE  

// Local Variables:
// mode:C++
// End:
