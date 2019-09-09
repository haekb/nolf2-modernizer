//////////////////////////////////////////////////////////////////////////////
// Object Template handling code

#ifndef __OBJECTTEMPLATEMGR_H__
#define __OBJECTTEMPLATEMGR_H__

#include <hash_map>

class CObjectTemplateMgr
{
public:
	CObjectTemplateMgr();
	~CObjectTemplateMgr();

	void AddTemplate(const ObjectCreateStruct *pOCS);
	const ObjectCreateStruct *FindTemplate(const char *pName) const;
	void Clear();
	
	void Save( ILTMessage_Write *pMsg );
	void Load( ILTMessage_Read *pMsg );

protected:
	// The template dictionary  (Note the startling similarity to GenericPropList..)

	// Template name comparison functor
	struct SCompare_TemplateName 
	{
		bool operator ()(const std::string &cLHS, const std::string &cRHS) const {
			return stricmp(cLHS.c_str(), cRHS.c_str()) == 0;
		}
	};

	// Template name hash functor
	struct SHash_TemplateName
	{
		size_t operator()(const std::string &sName) const { 
			uint32 nHash = 0;
			const char *pName = sName.begin();
			for (; *pName; ++pName)
				nHash = 13 * nHash + (toupper(*pName) - '@');
			return nHash;
		}
	};

	// The actual template dictionary type
	typedef std::hash_map<std::string, ObjectCreateStruct, SHash_TemplateName, SCompare_TemplateName> TTemplateMap;
	TTemplateMap m_cTemplates;
};

#endif //__OBJECTTEMPLATEMGR_H__