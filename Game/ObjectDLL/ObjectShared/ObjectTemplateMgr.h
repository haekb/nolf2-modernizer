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

	class ObjectTemplateMgr_Hasher {
	public:
		enum { bucket_size = 10 };

		ObjectTemplateMgr_Hasher() {}

		size_t operator()(const char* key) const {
			return hash(key);
		}

		bool operator()(const char* left, const char* right) const {
			return compare(left, right);
		}
	private:
		// Was `equal_str_nocase`, need to left side.
		bool compare(const char* s1, const char* s2) const
		{
			return stricmp(s1, s2) < 0;
		}
		// Was hash_str_nocase, still kinda is!
		// Copied for stl-port's std::hash<const char*>.
		// Added tolower function on the string.
		unsigned long hash(const char* str) const
		{
			unsigned long hash = 0;
			for (; *str; ++str)
				hash = 5 * hash + tolower(*str);

			return hash;
		}
	};

	// The actual template dictionary type
	typedef stdext::hash_map<std::string, ObjectCreateStruct, ObjectTemplateMgr_Hasher> TTemplateMap;
	TTemplateMap m_cTemplates;
};

#endif //__OBJECTTEMPLATEMGR_H__