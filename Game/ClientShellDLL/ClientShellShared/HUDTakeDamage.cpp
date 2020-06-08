#include "stdafx.h"
#include "HUDMgr.h"

// Max items for our vector,
// also affects how many hits vs the strength of the effect
#define MAX_LEVELS_OF_PAIN 5

// How long until a single effect fades out
#define PAIN_TIMEOUT 1000

CHUDTakeDamage::CHUDTakeDamage()
{
	m_UpdateFlags = kHUDAll;
	m_eLevel = kHUDRenderNone;
	m_hDamageTex = nullptr;
}

CHUDTakeDamage::~CHUDTakeDamage()
{
	m_vLevelsOfPain.clear();
}

LTBOOL CHUDTakeDamage::Init()
{
	// Give us a niiiiice red.
	g_pDrawPrim->SetRGBA(&m_Poly, SET_ARGB(0, 255, 0, 0));

	// ArmourHit.dtx has a odd placement, so we'll need to adjust the uv's accordingly.
	m_hDamageTex = g_pInterfaceResMgr->GetTexture("Interface\\Hud\\SprTex\\ARMORHIT.DTX");
	SetupQuadUVs(m_Poly, m_hDamageTex, 0.0f, 0.125f, 1.0f, 0.725f);

    return LTTRUE;
}

void CHUDTakeDamage::Render()
{
	if (m_vLevelsOfPain.size() == 0)
	{
		return;
	}

	SetRenderState();

	g_pDrawPrim->SetXYWH(&m_Poly, 0, 0, g_pInterfaceResMgr->GetScreenWidth(), g_pInterfaceResMgr->GetScreenHeight());
	g_pDrawPrim->SetTexture(m_hDamageTex);
	g_pDrawPrim->DrawPrim(&m_Poly);
}

void CHUDTakeDamage::Update()
{
	int nAlpha = 0;

	// Create a local copy to iterate over
	auto vLocalPain(m_vLevelsOfPain);

	for (int i = 0; i < vLocalPain.size(); i++)
	{
		// Amount we're adding to our total alpha this frame
		int nAdd = 255 / MAX_LEVELS_OF_PAIN;

		auto nCurrentTime = SDL_GetTicks();
		auto nTotalTime = nCurrentTime - vLocalPain[i];
		vLocalPain[i] = nTotalTime;

		// Check if times up!
		if (nTotalTime > PAIN_TIMEOUT)
		{
			// Ok, remove this level of pain from the og version
			// Since the timers are linearly added, we can just remove the first entry.
			m_vLevelsOfPain.erase(m_vLevelsOfPain.begin());
			continue;
		}

		if (nTotalTime != 0)
		{
			// If we've got time then let's inversely scale the add.
			// Lower values will give us high amount of nAdd, and it'll fade out over time.
			nAdd *= (float)(1.0f - ((float)nTotalTime / (float)PAIN_TIMEOUT));
		}

		nAlpha += nAdd; 
	}

	g_pDrawPrim->SetRGBA(&m_Poly, SET_ARGB(nAlpha, 255, 0, 0));
}

//
// On call, add the current time in ticks to our timer vector
//
void CHUDTakeDamage::TakeDamage()
{
	if (m_vLevelsOfPain.size() >= 5)
	{
		return;
	}

	m_vLevelsOfPain.push_back(SDL_GetTicks());
}
