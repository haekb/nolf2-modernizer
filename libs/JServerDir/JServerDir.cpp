#include "pch.h"
#include "JServerDir.h"


JServerDir::JServerDir(bool bClientSide, ILTCSBase& ltCSBase, HMODULE hResourceModule)
{
	m_bClientSide = bClientSide;
	m_pLTCSBase = &ltCSBase;
	m_hResourceModule = hResourceModule;
}

JServerDir::~JServerDir()
{

}

//////////////////////////////////////////////////////////////////////////////
// Status

// Get the current status
IServerDirectory::EStatus JServerDir::GetCurStatus() const
{
	return m_eStatus;
}

// Get the descriptive text associated with the current status
const char* JServerDir::GetCurStatusString() const
{
	switch (m_eStatus) {
	case IServerDirectory::eStatus_Error:
		return "Error";
	case IServerDirectory::eStatus_Paused:
		return "Paused";
	case IServerDirectory::eStatus_Processing:
		return "Processing";
	case IServerDirectory::eStatus_TotalNum:
		return "You shouldn't get this >:(";
	case IServerDirectory::eStatus_Waiting:
		return "Waiting";
	}

	return "Unknown";
}

//////////////////////////////////////////////////////////////////////////////
// Game name

void JServerDir::SetGameName(const char* pName)
{
	m_szGameName = pName;
}

const char* JServerDir::GetGameName() const
{
	return m_szGameName.c_str();
}


//////////////////////////////////////////////////////////////////////////////
// CD Keys
// Fake keys work okay!
//

bool JServerDir::SetCDKey(const char* pKey)
{
	return true;
}

bool JServerDir::GetCDKey(std::string* pKey)
{
	*pKey = FAKE_CD_KEY;
	return true;
}

bool JServerDir::IsCDKeyValid() const
{
	return true;
}

