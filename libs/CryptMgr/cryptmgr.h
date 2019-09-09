#if !defined(_CRYPTMGR_H_)
#define _CRYPTMGR_H_

#include "iostream.h"


class CCryptMgr
{
public:

	CCryptMgr();
	CCryptMgr(char* key);
	~CCryptMgr();

	void SetKey(const char* key);  // Max of 56 characters

	// if using fstreams be sure to open them in binary mode
	void Encrypt(istream& is, ostream& os);

	// if using fstreams be sure to open them in binary mode
	void Decrypt(istream& is, ostream& os);

};






#endif