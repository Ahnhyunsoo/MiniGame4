#include "stdafx.h"
#include "YMUi.h"
#include "YMPlayer.h"
#include "ObjMgr.h"
#include "YMScoreMgr.h"


CYMUi::CYMUi()
{
}


CYMUi::~CYMUi()
{
}

void CYMUi::Initialize(void)
{
	m_iCount2P = 0;


	m_iBoom = 0;
	m_fLazer = 0;
	m_iLevel = 0;

	m_bBossStart = false;
	m_iBossHp = 0;
	m_iScore = 0;

	m_vBoom = {175.f, 535.f, 0.f};
	m_b2P = false;
}

int CYMUi::Update(void)
{
	if (m_iCount2P == 0 && !m_b2P)
	{
		m_b2P = true;
		m_iCount2P = GetTickCount();
	}
	else if (m_iCount2P + 1000 <= GetTickCount() && m_b2P)
	{
		m_b2P = false;
		m_iCount2P = GetTickCount();
	}
	else if (m_iCount2P + 1000 <= GetTickCount() && !m_b2P)
	{
		m_b2P = true;
		m_iCount2P = GetTickCount();
	}

	m_fLazer = static_cast<CYMPlayer*>(CObjMgr::Get_Instance()->Get_ObjList(OBJ_PLAYER).back())->Get_Lazer();
	m_iHp = static_cast<CYMPlayer*>(CObjMgr::Get_Instance()->Get_ObjList(OBJ_PLAYER).back())->Get_Hp();
	m_iBoom = static_cast<CYMPlayer*>(CObjMgr::Get_Instance()->Get_ObjList(OBJ_PLAYER).back())->Get_Boom();
	m_iLevel = static_cast<CYMPlayer*>(CObjMgr::Get_Instance()->Get_ObjList(OBJ_PLAYER).back())->Get_Level();
	m_iScore = CYMScoreMgr::Get_Score();


	return 0;
}

void CYMUi::Late_Update(void)
{
}

void CYMUi::Render(HDC hDC)
{
	HPEN hpen;
	HPEN hpenOld;

	if (m_b2P == false)
	{
		TCHAR mName[30];
		wsprintf(mName, TEXT("2P  INSERT COIN"));
		TextOut(hDC, (int)(WINCX * 0.8), (int)(WINCY * 0.05), mName, lstrlen(mName));
	}

	Rectangle(hDC, 50, 500, 150, 550);

	hpen = CreatePen(PS_SOLID, 3, RGB(201, 255, 0));
	hpenOld = (HPEN)::SelectObject(hDC, (HGDIOBJ)hpen);	
	Rectangle(hDC, 50, 499, 50 + (int)m_fLazer, 549);
	hpen = (HPEN)::SelectObject(hDC, hpenOld);
	DeleteObject(hpen);



	Rectangle(hDC, 650, 499, 750, 549);
	hpen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	hpenOld = (HPEN)::SelectObject(hDC, (HGDIOBJ)hpen);
	Rectangle(hDC, 650, 499, 650 + m_iHp, 549);
	hpen = (HPEN)::SelectObject(hDC, hpenOld);
	DeleteObject(hpen);


	MoveToEx(hDC, (int)m_vBoom.x, (int)m_vBoom.y, nullptr);
	LineTo(hDC,(int)m_vBoom.x + 6, (int)m_vBoom.y - 6);
	LineTo(hDC,(int)m_vBoom.x + 18, (int)m_vBoom.y - 6);
	LineTo(hDC,(int)m_vBoom.x + 20,(int)m_vBoom.y - 2);
	LineTo(hDC,(int)m_vBoom.x + 24,(int)m_vBoom.y - 6);
	LineTo(hDC,(int)m_vBoom.x + 24,(int)m_vBoom.y - 2);
	LineTo(hDC,(int)m_vBoom.x + 22,(int)m_vBoom.y - 2);
	LineTo(hDC,(int)m_vBoom.x + 24,(int)m_vBoom.y - 2);
	LineTo(hDC,(int)m_vBoom.x + 24,(int)m_vBoom.y + 2);
	LineTo(hDC,(int)m_vBoom.x + 22,(int)m_vBoom.y + 2);
	LineTo(hDC,(int)m_vBoom.x + 24,(int)m_vBoom.y + 2);
	LineTo(hDC,(int)m_vBoom.x + 24,(int)m_vBoom.y + 6);
	LineTo(hDC,(int)m_vBoom.x + 20,(int)m_vBoom.y + 2);
	LineTo(hDC,(int)m_vBoom.x + 18, (int)m_vBoom.y + 6);
	LineTo(hDC,(int)m_vBoom.x + 6, (int)m_vBoom.y + 6);
	LineTo(hDC,(int)m_vBoom.x, (int)m_vBoom.y);

	TCHAR mName[30];
	wsprintf(mName, TEXT("x  %d") ,m_iBoom);
	TextOut(hDC, (int)m_vBoom.x + 33, (int)m_vBoom.y - 8, mName, lstrlen(mName));

	TCHAR mName2[30];
	wsprintf(mName2, TEXT("Lv %d"), m_iLevel);
	TextOut(hDC, (int)m_vBoom.x, (int)m_vBoom.y - 38, mName2, lstrlen(mName));

	if (m_bBossStart && m_iBossHp > 5)
	{
		Rectangle(hDC, 200, 50, 600, 100);
		hpen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
		hpenOld = (HPEN)::SelectObject(hDC, (HGDIOBJ)hpen);
		Rectangle(hDC, 200, 50, 200 + m_iBossHp, 100);
		hpen = (HPEN)::SelectObject(hDC, hpenOld);
		DeleteObject(hpen);
	}

	TCHAR mName3[30];
	wsprintf(mName, TEXT("SCORE  %d"), m_iScore);
	TextOut(hDC, 20, 20, mName, lstrlen(mName));
}

void CYMUi::Release(void)
{
}

void CYMUi::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
