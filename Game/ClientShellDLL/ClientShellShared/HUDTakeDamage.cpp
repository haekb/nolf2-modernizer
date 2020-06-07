#include "stdafx.h"
#include "HUDMgr.h"

CHUDTakeDamage::CHUDTakeDamage()
{
}

CHUDTakeDamage::~CHUDTakeDamage()
{
}
HTEXTURE g_hDamageTex;
LTBOOL CHUDTakeDamage::Init()
{
	g_pDrawPrim->SetRGBA(&m_Poly, SET_ARGB(255, 255, 0, 0));

	g_hDamageTex = g_pInterfaceResMgr->GetTexture("Interface\\Hud\\SprTex\\ARMORHIT.DTX");

	SetupQuadUVs(m_Poly, g_hDamageTex, 0.0f, 0.0f, 1.0f, 1.0f);
	g_pDrawPrim->SetXYWH(&m_Poly, 0, 0, g_pInterfaceResMgr->GetScreenWidth(), g_pInterfaceResMgr->GetScreenHeight());

    return LTTRUE;
}

void CHUDTakeDamage::Render()
{
	SetRenderState();

	g_pDrawPrim->SetTexture(g_hDamageTex);
	g_pDrawPrim->DrawPrim(&m_Poly);
}

void CHUDTakeDamage::Update()
{

}
