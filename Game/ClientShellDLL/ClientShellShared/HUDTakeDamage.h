#pragma once
#include <vector>
#include <SDL.h>
#include "BaseHUDItem.h"

// HUD Take Damage
// Replacement for TakingHealth FX
// -------------------------------
// I couldn't figure out how spriteFX were drawn, 
// so I disabled the current one in PlayerMgr 
// and re-created it as a HUD item.
//
class CHUDTakeDamage : public CBaseHUDItem
{
public:
	CHUDTakeDamage();
	~CHUDTakeDamage();

	LTBOOL  Init();

	void    Render();
	void    Update();

	void	TakeDamage();

private:
	LTPoly_GT4 m_Poly;
	HTEXTURE m_hDamageTex;

	std::vector<Uint32> m_vLevelsOfPain;
};

