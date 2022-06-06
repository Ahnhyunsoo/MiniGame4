#include "stdafx.h"
#include "HSUI.h"
#include "Scene.h"
#include "SoundMgr.h"



CHSUI::CHSUI(CScene* _pScene)
	:m_LStop(GetTickCount())
{
	m_pScene = _pScene;
}



CHSUI::~CHSUI()
{
}

void CHSUI::Initialize(void)
{
	m_bDead = false;
}

int CHSUI::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	m_eType = static_cast<CStageHS*>(m_pScene)->Get_Tower();
	Change_Type();
	if (static_cast<CStageHS*>(m_pScene)->Get_Stop() == true)
		StopTime();

	return OBJ_NOEVENT;
}

void CHSUI::Late_Update(void)
{
}

void CHSUI::Render(HDC hDC)
{
	Rectangle(hDC, 90, 480, 190, 580);
	Rectangle(hDC, 270, 480, 370, 580);
	Rectangle(hDC, 450, 480, 550, 580);
	Rectangle(hDC, 630, 480, 730, 580);

	switch (m_eType)
	{
	case CStageHS::STOPITEM:
		Ellipse(hDC, 91, 481, 189, 579);
		break;
	case CStageHS::GUNTOWER:
		Ellipse(hDC, 271, 481, 369, 579);
		break;
	case CStageHS::RASERTOWER:
		Ellipse(hDC, 451, 481, 549, 579);
		break;
	case CStageHS::ICETOWER:
		Ellipse(hDC, 631, 481, 729, 579);
		break;
	}

	LOGFONT m_labelFontInfo{};
	m_labelFontInfo.lfCharSet = 129;
	m_labelFontInfo.lfHeight = 16;
	m_labelFontInfo.lfWidth = 6;
	m_labelFontInfo.lfWeight = 1100;
	HFONT textFont, oldFont;
	textFont = CreateFontIndirect(&m_labelFontInfo);
	oldFont = (HFONT)SelectObject(hDC, textFont);
	SetBkMode(hDC, TRANSPARENT);
	SetBkColor(hDC, RGB(0, 0, 0));

	SetTextColor(hDC, RGB(0, 0, 0));
	TCHAR mName[30];
	wsprintf(mName, TEXT("!!!!!!¸ØÃç!!!!!!"));
	TextOut(hDC, 95, 525, mName, lstrlen(mName));

	SetTextColor(hDC, RGB(0, 255, 0));
	TCHAR mLevel[30];
	wsprintf(mLevel, TEXT("GUNTOWER"));
	TextOut(hDC, 280, 525, mLevel, lstrlen(mLevel));

	SetTextColor(hDC, RGB(255, 0, 0));
	TCHAR mHP[30];
	wsprintf(mHP, TEXT("RASERTOWER"));
	TextOut(hDC, 453, 525, mHP, lstrlen(mHP));

	SetTextColor(hDC, RGB(0, 0, 255));
	TCHAR mGold[30];
	wsprintf(mGold, TEXT("ICETOWER"));
	TextOut(hDC, 645, 525, mGold, lstrlen(mGold));

	SetBkMode(hDC, TRANSPARENT);
	SetTextColor(hDC, RGB(0, 0, 0));
	SelectObject(hDC, oldFont);
	DeleteObject(textFont);


	
	
}

void CHSUI::Release(void)
{
}

void CHSUI::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}

void CHSUI::Change_Type()
{
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON))
	{
		if ((pt.x >= 90.f && pt.x <= 190.f) && (pt.y >= 480.f && pt.y <= 580.f))
		{
			static_cast<CStageHS*>(m_pScene)->Set_Tower(CStageHS::STOPITEM);
			static_cast<CStageHS*>(m_pScene)->Set_Stop(true);
			CSoundMgr::Get_Instance()->PlaySound(L"Stop.wav", SOUND_SYSTEM, 1.f);
			CStageHS::g_iGold -= 500;
			m_LStop = GetTickCount();
		}
		else if ((pt.x >= 270.f && pt.x <= 370.f) && (pt.y >= 480.f && pt.y <= 580.f))
			static_cast<CStageHS*>(m_pScene)->Set_Tower(CStageHS::GUNTOWER);
		else if ((pt.x >= 450.f && pt.x <= 550.f) && (pt.y >= 480.f && pt.y <= 580.f))
			static_cast<CStageHS*>(m_pScene)->Set_Tower(CStageHS::RASERTOWER);
		else if ((pt.x >= 630.f && pt.x <= 730.f) && (pt.y >= 480.f && pt.y <= 580.f))
			static_cast<CStageHS*>(m_pScene)->Set_Tower(CStageHS::ICETOWER);
	}
}

void CHSUI::StopTime()
{
	if (m_LStop + 3000 < GetTickCount())
	{
		static_cast<CStageHS*>(m_pScene)->Set_Stop(false);
		m_LStop = GetTickCount();
	}
}

