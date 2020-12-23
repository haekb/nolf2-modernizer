#include "stdafx.h"
#include "GameClientShell.h"
#include "InterfaceMgr.h"

#include "BaseHUDItem.h"


CBaseHUDItem::CBaseHUDItem() : CHUDItem()
{
	m_fCacheScale = 1.0f;
	m_bUpdateScale = true;
}

void CBaseHUDItem::Update()
{
	// Start of the frame, always set this to false
	m_bUpdateScale = false;

	float fCheckScale = g_pInterfaceResMgr->GetXRatio() + g_pInterfaceResMgr->GetYRatio();
	if (m_fCacheScale != fCheckScale)
	{
		m_fCacheScale = fCheckScale;
		m_bUpdateScale = true;
	}
}

void CBaseHUDItem::UpdateLayout()
{
	// Left empty!
}
