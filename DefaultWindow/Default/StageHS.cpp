#include "stdafx.h"
#include "StageHS.h"
#include "ObjMgr.h"
#include "CAbstractFactory.h"
#include "GunTower.h"
#include "HSMonster.h"
#include "BmpMgr.h"
#include "LineMgr.h"
#include "HSUI.h"
#include "RaserTower.h"

int CStageHS::g_iHP = 30;
int CStageHS::g_iGold = 1000;
int CStageHS::g_iKill = 0;
int CStageHS::g_iExp = 1;

CStageHS::CStageHS()
	:m_iSponSpeed(700),m_iNowMonster(0),m_iMaxMonster(100),m_LSponMonster(GetTickCount()),m_iLevel(1),m_iMaxExp(100), m_iRound(1)
	,m_eTowerType(GUNTOWER),m_bStop(false),m_bMonsterUpgrade(false)
{
	CObjMgr::Get_Instance()->Add_Object(OBJ_UI, CAbstractFactory<CHSUI>::CreateHSUI(this));
}


CStageHS::~CStageHS()
{
	Release();
}

void CStageHS::Initialize(void)
{
	
	CLineMgr::Get_Instance()->Load_Line();
	m_tTowerPos[0] = { 385,240,415,270 };
	m_tTowerPos[1] = { 385, 280, 415, 310 };
	m_tTowerPos[2] = { 185, 300, 215, 330 };
	m_tTowerPos[3] = { 185, 260, 215, 290 };
	m_tTowerPos[4] = { 185, 220, 215, 250 };
	m_tTowerPos[5] = { 185, 180, 215, 210 };
	m_tTowerPos[6] = { 185, 140, 215, 170 };
	m_tTowerPos[7] = { 185, 100, 215, 130 };
	m_tTowerPos[8] = { 185, 340, 215, 370 };
	m_tTowerPos[9] = { 185, 380, 215, 410 };
	m_tTowerPos[10] = { 185, 420, 215, 450 };

	m_tTowerPos[11] = { 250, 60, 280, 90 };
	m_tTowerPos[12] = { 290, 60, 320, 90 };
	m_tTowerPos[13] = { 330, 60, 360, 90 };
	m_tTowerPos[14] = { 370, 60, 400, 90 };
	m_tTowerPos[15] = { 410, 60, 440, 90 };
	m_tTowerPos[16] = { 450, 60, 480, 90 };
	m_tTowerPos[17] = { 490, 60, 520, 90 };
	m_tTowerPos[18] = { 530, 60, 560, 90 };

}

void CStageHS::Update(void)
{
	CObjMgr::Get_Instance()->Update();
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);
	if (m_LSponMonster + m_iSponSpeed < GetTickCount())
	{
		if (m_iMaxMonster > m_iNowMonster && !m_bStop)
		{
			CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CHSMonster>::CreateObj(800.f, 25.f,this));
			m_iNowMonster += 1;
			m_LSponMonster = GetTickCount();
		}
	}
	CreateTower();
	if (g_iHP <= 0)
		CSceneMgr::Get_Instance()->Scene_Change(STAGE_ST);

	if(g_iKill >= 100)
		CSceneMgr::Get_Instance()->Scene_Change(STAGE_ST);

	

	/*if (g_iKill <= 25)
		CHSMonster::g_iMonsterHp = 5.f;*/
	if (g_iKill > 25 && g_iKill <= 50)
	{
		CHSMonster::g_iMonsterHp = 15.f;
		CHSMonster::g_fMonsterSpeed = 2.5f;
		m_iSponSpeed = 500;
	}

	else if (g_iKill > 50 && g_iKill <= 75)
	{
		CHSMonster::g_iMonsterHp = 30.f;
		CHSMonster::g_fMonsterSpeed = 5.f;
		m_iSponSpeed = 300;
	}

	else if (m_iNowMonster == 99)
	{
		CHSMonster::g_iMonsterHp = 500.f;
		CHSMonster::g_fMonsterSpeed = 1.f;
	}

}

void CStageHS::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
	if (g_iExp >= m_iMaxExp)
	{
		g_iExp = 0;
		m_iLevel += 1;
		m_iMaxExp = m_iLevel * 100;
		g_iGold += 1000;
	}
}

void CStageHS::Render(HDC hDC)
{
	Rectangle(hDC, 0, 0, WINCX, WINCY);
	Draw_Rect(hDC);
	Draw_UI(hDC);
	CObjMgr::Get_Instance()->Render(hDC);
	CLineMgr::Get_Instance()->Render(hDC);
	

	LOGFONT m_labelFontInfo{};
	m_labelFontInfo.lfCharSet = 129;
	m_labelFontInfo.lfHeight = 14;
	m_labelFontInfo.lfWidth = 6;
	m_labelFontInfo.lfWeight = FW_EXTRABOLD;
	HFONT textFont, oldFont;
	textFont = CreateFontIndirect(&m_labelFontInfo);
	oldFont = (HFONT)SelectObject(hDC, textFont);
	SetBkMode(hDC, TRANSPARENT);
	SetBkColor(hDC, RGB(0, 0, 0));
	
	SetTextColor(hDC, RGB(255, 0, 255));
	TCHAR mName[30];
	wsprintf(mName, TEXT("Round %d"),m_iRound);
	TextOut(hDC, 10, 30, mName, lstrlen(mName));

	SetTextColor(hDC, RGB(255, 0, 0));
	TCHAR mLevel[30];
	wsprintf(mLevel, TEXT("Level : %d"), m_iLevel);
	TextOut(hDC, 10, 60, mLevel, lstrlen(mLevel));

	SetTextColor(hDC, RGB(255, 0, 0));
	TCHAR mHP[30];
	wsprintf(mHP, TEXT("Life : %d"), g_iHP);
	TextOut(hDC, 10, 90, mHP, lstrlen(mHP));

	SetTextColor(hDC, RGB(255, 255, 0));
	TCHAR mGold[30];
	wsprintf(mGold, TEXT("Gold : %d"), g_iGold);
	TextOut(hDC, 10, 120, mGold, lstrlen(mGold));

	SetTextColor(hDC, RGB(0, 255, 0));
	TCHAR mExp[30];
	wsprintf(mExp, TEXT("Exp : %d/%d"), g_iExp,m_iMaxExp);
	TextOut(hDC, 10, 150, mExp, lstrlen(mExp));

	SetTextColor(hDC, RGB(0, 0, 0));
	TCHAR mMonster[30];
	wsprintf(mMonster, TEXT("%d / %d"), g_iKill,m_iMaxMonster);
	TextOut(hDC, 10, 300, mMonster, lstrlen(mMonster));
	SetBkMode(hDC, TRANSPARENT);
	SetTextColor(hDC, RGB(0, 0, 0));
	SelectObject(hDC, oldFont);
	DeleteObject(textFont);

	Rectangle(hDC, pt.x - 5, pt.y - 5, pt.x + 5, pt.y + 5);

}

void CStageHS::Release(void)
{
	CObjMgr::Get_Instance()->Release();
}

void CStageHS::Draw_Rect(HDC hDC)
{
	HPEN hpen;
	HPEN hpenOld;

	hpen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));	// 선 스타일, 굵기, 색상
	hpenOld = (HPEN)::SelectObject(hDC, (HGDIOBJ)hpen);	// 펜 선택
	
	for(int i = 0; i < sizeof(m_tTowerPos) / sizeof(RECT); ++i)
	Rectangle(hDC, m_tTowerPos[i].left, m_tTowerPos[i].top, m_tTowerPos[i].right, m_tTowerPos[i].bottom);
	

	hpen = (HPEN)SelectObject(hDC, hpenOld);	// 기존의 펜 다시 선택
	DeleteObject(hpen);	// 생성한 펜 삭제
}

void CStageHS::Draw_UI(HDC hDC)
{
}

void CStageHS::CreateTower(void)
{
	if (CKeyMgr::Get_Instance()->Key_Up(VK_LBUTTON))
	{
		for (int i = 0; i < sizeof(m_tTowerPos) / sizeof(RECT); ++i)
		{
			if (pt.x >= m_tTowerPos[i].left && pt.x <= m_tTowerPos[i].right
				&& pt.y >= m_tTowerPos[i].top && pt.y <= m_tTowerPos[i].bottom)
			{
				if (m_eTowerType == GUNTOWER)
				{
					CObjMgr::Get_Instance()->Add_Object(OBJ_TOWER, CAbstractFactory<CGunTower>::CreateObj(m_tTowerPos[i].left + 15.f, m_tTowerPos[i].top + 15.f));
					g_iGold -= 500;
				}
				else if (m_eTowerType == RASERTOWER)
				{
					CObjMgr::Get_Instance()->Add_Object(OBJ_TOWER, CAbstractFactory<CRaserTower>::CreateObj(m_tTowerPos[i].left + 15.f, m_tTowerPos[i].top + 15.f));
					g_iGold -= 1000;
				}
				else if (m_eTowerType == ICETOWER)
				{
					
				}
			}
		}		
	}
	/*if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RBUTTON))
	{
		for (int i = 0; i < sizeof(m_tTowerPos) / sizeof(RECT); ++i)
		{
			if (pt.x >= m_tTowerPos[i].left && pt.x <= m_tTowerPos[i].right
				&& pt.y >= m_tTowerPos[i].top && pt.y <= m_tTowerPos[i].bottom)
			{
				m_tTowerPos[i].left = pt.x - ((m_tTowerPos[i].right - m_tTowerPos[i].left) * 0.5);
				m_tTowerPos[i].top = pt.y - ((m_tTowerPos[i].bottom - m_tTowerPos[i].top) * 0.5);				
			}
		}
	}*/
}
