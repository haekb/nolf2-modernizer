#pragma once
#include "HUDItem.h"
class CHUDTakeDamage :
    public CHUDItem
{
public:
	CHUDTakeDamage();
	~CHUDTakeDamage();

	LTBOOL      Init();

	void        Render();
	void        Update();

	//void        UpdateLayout();

private:
	LTIntPt		m_BasePos;
	uint16 		m_nIconHt;

	LTBOOL		m_bDraw;


	LTPoly_GT4 m_Poly;
	HTEXTURE* m_hIcon;			//  icon

};

