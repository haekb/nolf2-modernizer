#include "pch.h"
#include "Peer.h"

Peer::Peer()
{
	m_sPeerAddress = "";
	m_nPing = 0;
	m_fCreatedAt = 0.0f;

	m_bHasNameData = false;
	m_bHasSummaryData = false;
	m_bHasDetailsData = false;
	m_bHasPortData = false;
	m_bHasServiceData = false;
	m_bIsValidated = false;
}

Peer::~Peer()
{

}
