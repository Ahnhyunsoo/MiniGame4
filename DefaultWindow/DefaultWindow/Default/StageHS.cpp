#include "stdafx.h"
#include "StageHS.h"
#include "ObjMgr.h"
#include "CAbstractFactory.h"
#include "GunTower.h"
#include "HSMonster.h"
#include "BmpMgr.h"
#include "LineMgr.h"

int CStageHS::g_iHP = 30;
int CStageHS::g_iGold = 1000;
int CStageHS::g_iKill = 0;
int CStageHS::g_iExp = 1;

CStageHS::CStageHS()
	:m_iSponSpeed(1000),m_iNowMonster(0),m_iMaxMonster(15),m_LSponMonster(GetTickCount()),m_iLevel(1),m_iMaxExp(100), m_iRound(1)
	
{
}


CStageHS::~CStageHS()
{
}

void CStageHS::Initialize(void)
{
	
	CLineMgr::Get_Instance()->Load_Line();
	CObjMgr::Get_Instance()->Add_Object(OBJ_TOWER, CAbstractFactory<CGunTower>::CreateObj(400.f,255.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_TOWER, CAbstractFactory<CGunTower>::CreateObj(400.f,295.f));


}

void CStageHS::Update(void)
{
	CObjMgr::Get_Instance()->Update();
	if (m_LSponMonster + m_iSponSpeed < GetTickCount())
	{
		if (m_iMaxMonster > m_iNowMonster)
		{
			CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CHSMonster>::CreateObj(800.f, 25.f));
			m_iNowMonster += 1;
			m_LSponMonster = GetTickCount();
		}
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
	
	HDC		hDC2 = CBmpMgr::Get_Instance()->Find_Image(L"aa");
	BitBlt(hDC, 0, 0, 800, 600, hDC2, 0, 0, SRCCOPY);
	//Rectangle(hDC, 0, 0, WINCX, WINCY);
	CLineMgr::Get_Instance()->Render(hDC);
	CObjMgr::Get_Instance()->Render(hDC);
	
	Draw_Rect(hDC);
	Draw_UI(hDC);
	

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

}

void CStageHS::Release(void)
{
}

void CStageHS::Draw_Rect(HDC hDC)
{
	HPEN hpen;
	HPEN hpenOld;

	hpen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));	// �� ��Ÿ��, ����, ����
	hpenOld = (HPEN)::SelectObject(hDC, (HGDIOBJ)hpen);	// �� ����
	Rectangle(hDC, 385, 240, 415, 270);
	Rectangle(hDC, 385, 280, 415, 310);
	hpen = (HPEN)SelectObject(hDC, hpenOld);	// ������ �� �ٽ� ����
	DeleteObject(hpen);	// ������ �� ����
}

void CStageHS::Draw_UI(HDC hDC)
{

}