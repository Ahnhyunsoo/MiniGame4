#include "stdafx.h"
#include "StageSelect.h"
#include "ObjMgr.h"
#include "CAbstractFactory.h"
#include "SelectPlayer.h"
#include "SelectMonster.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"

CStageSelect::CStageSelect()
	:m_iNowRank(0),m_iTotalRank(0),m_iSecond(0),m_LTimer(GetTickCount()),m_bGoal(false),m_iGoal(5000)
{
}


CStageSelect::~CStageSelect()
{
	Release();
}

void CStageSelect::Initialize(void)
{
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CSelectPlayer>::Create());
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateObj(600.f, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateObj(1600.f, 250.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateObj(900.f, 300.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateObj(1200.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateObj(1100.f, 400.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateObj(1900.f, 450.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateObj(1500.f, 500.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateObj(1800.f, 450.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateObj(1400.f, 400.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateObj(2100.f, 350.f));
	
}

void CStageSelect::Update(void)
{
	
	if (!m_bGoal)
	{
		CObjMgr::Get_Instance()->Update();
		

		Timer();
	}
}

void CStageSelect::Late_Update(void)
{

	CObjMgr::Get_Instance()->Late_Update();
	Check_Goal(); 
	
}

void CStageSelect::Render(HDC hDC)
{

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Back");
	BitBlt(hDC, 0, 0, 800, 600, hMemDC, 0, 0, SRCCOPY);
	Rectangle(hMemDC, 0, 0, WINCX, WINCY);
	CObjMgr::Get_Instance()->Render(hMemDC);

	if (!m_bGoal) // 골인 안했으면 게임화면 출력
	{
		

		int iScrollX = CScrollMgr::Get_Instance()->Get_ScrollX();

		m_iNowRank = NowRank();
		m_iTotalRank = CObjMgr::Get_Instance()->Get_ObjList(OBJ_MONSTER).size() + 1;

		LOGFONT m_labelFontInfo{};
		m_labelFontInfo.lfHeight = 20;
		m_labelFontInfo.lfWidth = 10;
		HFONT textFont, oldFont;
		textFont = CreateFontIndirect(&m_labelFontInfo);
		oldFont = (HFONT)SelectObject(hMemDC, textFont);
		SetBkMode(hMemDC, OPAQUE);
		SetBkColor(hMemDC, RGB(0, 0, 0));
		SetTextColor(hMemDC, RGB(255, 0, 255));;
		TCHAR cRank[30];
		wsprintf(cRank, TEXT("현재 등수 : %d / %d"), m_iNowRank, m_iTotalRank);
		TextOut(hMemDC, 630, 10, cRank, lstrlen(cRank));

		TCHAR cTime[30];
		wsprintf(cTime, TEXT("시간 : %d초"), m_iSecond);
		TextOut(hMemDC, 30, 10, cTime, lstrlen(cTime));

		TCHAR cDistance[30];
		wsprintf(cDistance, TEXT("거리 : %dM / %dM"), (int)CObjMgr::Get_Instance()->Get_ObjList(OBJ_PLAYER).front()->Get_Info().vPos.x,m_iGoal);
		TextOut(hMemDC, 200, 10, cDistance, lstrlen(cDistance));
		SelectObject(hMemDC, oldFont);
		DeleteObject(textFont);



		Ellipse(hMemDC, 5000 + iScrollX, 90, 5000 + iScrollX + 10, 100);
		Ellipse(hMemDC, 5000 + iScrollX, 500, 5000 + iScrollX + 10, 510);
		MoveToEx(hMemDC, 5000 + iScrollX, 100, nullptr);
		LineTo(hMemDC, 5000 + iScrollX, 500);
	}

	if (m_bGoal) // 골인했으면 클리어 화면 출력
	{
		m_iNowRank = NowRank();
		LOGFONT m_labelFontInfo{};
		m_labelFontInfo.lfHeight = 40;
		m_labelFontInfo.lfWidth = 20;
		HFONT textFont, oldFont;
		textFont = CreateFontIndirect(&m_labelFontInfo);
		oldFont = (HFONT)SelectObject(hMemDC, textFont);
		SetBkMode(hMemDC, OPAQUE);
		SetBkColor(hMemDC, RGB(0, 0, 255));
		SetTextColor(hMemDC, RGB(255, 0, 0));;
		TCHAR cRank[30];
		wsprintf(cRank, TEXT("최종 등수 : %d등"), m_iNowRank);
		TextOut(hMemDC, 420, 40, cRank, lstrlen(cRank));

		TCHAR cTime[30];
		wsprintf(cTime, TEXT("걸린 시간 : %d초"), m_iSecond);
		TextOut(hMemDC, 70, 40, cTime, lstrlen(cTime));
		SelectObject(hMemDC, oldFont);
		DeleteObject(textFont);

		
		LOGFONT m_labelFontInfo2{};
		m_labelFontInfo2.lfHeight = 80;
		m_labelFontInfo2.lfWidth = 40;
		HFONT textFont2, oldFont2;
		textFont2 = CreateFontIndirect(&m_labelFontInfo2);
		oldFont2 = (HFONT)SelectObject(hMemDC, textFont2);
		SetBkMode(hMemDC, OPAQUE);
		SetBkColor(hMemDC, RGB(0, 255, 0));
		SetTextColor(hMemDC, RGB(0, 0, 0));;
		TCHAR cClear[30];
		wsprintf(cClear, TEXT("STAGE1 클리어!"), m_iNowRank);
		TextOut(hMemDC, 75, 300, cClear, lstrlen(cClear));
		SelectObject(hMemDC, oldFont2);
		DeleteObject(textFont2);
	}

}

void CStageSelect::Release(void)
{
	CObjMgr::Get_Instance()->Release();
}

int CStageSelect::NowRank(void)
{
	int Count = CObjMgr::Get_Instance()->Get_ObjList(OBJ_MONSTER).size()+1;
	/*list<CObj*>::iterator iter = CObjMgr::Get_Instance()->Get_ObjList(OBJ_MONSTER).begin();
	list<CObj*>::iterator iter2 = CObjMgr::Get_Instance()->Get_ObjList(OBJ_MONSTER).end();*/


	/*if ((*iter)->Get_Info().vPos.x <= (CObjMgr::Get_Instance()->Get_ObjList(OBJ_PLAYER)).front()->Get_Info().vPos.x)
	Count -= 1;
	++iter;*/

	/*for (;iter != iter2;)
	{
		
	}*/
	for (auto& iter : CObjMgr::Get_Instance()->Get_ObjList(OBJ_MONSTER))
	{
		if (iter->Get_Info().vPos.x <= CObjMgr::Get_Instance()->Get_ObjList(OBJ_PLAYER).front()->Get_Info().vPos.x)
			Count -= 1;
	}
	return Count;
}

void CStageSelect::Timer(void)
{
	if (m_LTimer + 1000 < GetTickCount())
	{
		m_iSecond += 1;
		m_LTimer = GetTickCount();
	}
}

void CStageSelect::Check_Goal(void)
{
	if (CObjMgr::Get_Instance()->Get_ObjList(OBJ_PLAYER).front()->Get_Info().vPos.x >= m_iGoal)
		m_bGoal = true;
}