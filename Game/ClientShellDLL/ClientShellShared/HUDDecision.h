// ----------------------------------------------------------------------- //
//
// MODULE  : HUDDecision.h
//
// PURPOSE : Definition of CHUDDecision to display transmission messages
//
// (c) 2001 Monolith Productions, Inc.  All Rights Reserved
//
// ----------------------------------------------------------------------- //

#ifndef __HUD_DECISION_H
#define __HUD_DECISION_H

#include "BaseHUDItem.h"
#include "ClientServerShared.h"

//******************************************************************************************
//** HUD Message Queue
//******************************************************************************************
class CHUDDecision : public CBaseHUDItem
{
public:
	CHUDDecision();
	

    virtual LTBOOL      Init();
	virtual void		Term();

    virtual void        Render();
    virtual void        Update();

	virtual void        UpdateLayout();

	void	OnObjectRemove(HLOCALOBJ hObj);

	//hide or show based on messages from the server
	void	Show(ILTMessage_Read *pMsg);

	//close window and tell server
	void	Hide();

	void	ApplyPosition(float fScale, int nOffset);

	LTBOOL	IsVisible() {return m_bVisible;}

	void	Choose(uint8 nChoice);

	HOBJECT GetObject() { return m_hObject; }
	float	GetRadius() { return m_fRadius; }

protected:

    LTIntPt					m_BasePos;

	CUIFont*	m_pFont;				// The font for this control
	uint8		m_nFontSize;			// The scaled font size to use.
	uint8		m_nBaseFontSize;		// The font size before scaling
	uint32		m_nTextColor;
	float		m_fScale;
	LTBOOL		m_bVisible;
	uint16		m_nWidth;
	LTIntPt		m_Offset;

	HOBJECT		m_hObject;
	LTVector	m_vObjPos;
	float		m_fRadius;

	CLTGUIWindow	    m_Dlg;
	CLTGUIColumnCtrl*	m_pText[MAX_DECISION_CHOICES];

};



#endif