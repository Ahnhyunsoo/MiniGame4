#include "stdafx.h"
#include "StageSelect.h"
#include "ObjMgr.h"
#include "CAbstractFactory.h"
#include "SelectPlayer.h"
#include "SelectMonster.h"

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
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateSelectMonster(600.f, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateSelectMonster(1600.f, 250.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateSelectMonster(900.f, 300.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateSelectMonster(1200.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateSelectMonster(1100.f, 400.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateSelectMonster(1900.f, 450.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateSelectMonster(1500.f, 500.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateSelectMonster(1800.f, 450.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateSelectMonster(1400.f, 400.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSelectMonster>::CreateSelectMonster(2100.f, 350.f));
	
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

	if (!m_bGoal) // 골인 안했으면 게임화면 출력
	{
		CObjMgr::Get_Instance()->Render(hDC);

		m_iNowRank = NowRank();
		m_iTotalRank = CObjMgr::Get_Instance()->Get_ObjList(OBJ_MONSTER).size() + 1;

		LOGFONT m_labelFontInfo{};
		m_labelFontInfo.lfHeight = 20;
		m_labelFontInfo.lfWidth = 10;
		HFONT textFont, oldFont;
		textFont = CreateFontIndirect(&m_labelFontInfo);
		oldFont = (HFONT)SelectObject(hDC, textFont);
		SetBkMode(hDC, OPAQUE);
		SetBkColor(hDC, RGB(0, 0, 0));
		SetTextColor(hDC, RGB(255, 0, 255));;
		TCHAR cRank[30];
		wsprintf(cRank, TEXT("현재 등수 : %d / %d"), m_iNowRank, m_iTotalRank);
		TextOut(hDC, 630, 10, cRank, lstrlen(cRank));

		TCHAR cTime[30];
		wsprintf(cTime, TEXT("시간 : %d초"), m_iSecond);
		TextOut(hDC, 30, 10, cTime, lstrlen(cTime));

		TCHAR cDistance[30];
		wsprintf(cDistance, TEXT("거리 : %dM / %dM"), (int)CObjMgr::Get_Instance()->Get_ObjList(OBJ_PLAYER).front()->Get_Info().vPos.x,m_iGoal);
		TextOut(hDC, 200, 10, cDistance, lstrlen(cDistance));
		SelectObject(hDC, oldFont);
		DeleteObject(textFont);
	}

	if (m_bGoal) // 골인했으면 클리어 화면 출력
	{
		m_iNowRank = NowRank();
		LOGFONT m_labelFontInfo{};
		m_labelFontInfo.lfHeight = 40;
		m_labelFontInfo.lfWidth = 20;
		HFONT textFont, oldFont;
		textFont = CreateFontIndirect(&m_labelFontInfo);
		oldFont = (HFONT)SelectObject(hDC, textFont);
		SetBkMode(hDC, OPAQUE);
		SetBkColor(hDC, RGB(0, 0, 255));
		SetTextColor(hDC, RGB(255, 0, 0));;
		TCHAR cRank[30];
		wsprintf(cRank, TEXT("최종 등수 : %d등"), m_iNowRank);
		TextOut(hDC, 420, 40, cRank, lstrlen(cRank));

		TCHAR cTime[30];
		wsprintf(cTime, TEXT("걸린 시간 : %d초"), m_iSecond);
		TextOut(hDC, 70, 40, cTime, lstrlen(cTime));
		SelectObject(hDC, oldFont);
		DeleteObject(textFont);

		
		LOGFONT m_labelFontInfo2{};
		m_labelFontInfo2.lfHeight = 80;
		m_labelFontInfo2.lfWidth = 40;
		HFONT textFont2, oldFont2;
		textFont2 = CreateFontIndirect(&m_labelFontInfo2);
		oldFont2 = (HFONT)SelectObject(hDC, textFont2);
		SetBkMode(hDC, OPAQUE);
		SetBkColor(hDC, RGB(0, 255, 0));
		SetTextColor(hDC, RGB(0, 0, 0));;
		TCHAR cClear[30];
		wsprintf(cClear, TEXT("STAGE1 클리어!"), m_iNowRank);
		TextOut(hDC, 75, 300, cClear, lstrlen(cClear));
		SelectObject(hDC, oldFont2);
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
	/*for (auto& iter = CObjMgr::Get_Instance()->Get_ObjList(OBJ_MONSTER).begin(); iter != CObjMgr::Get_Instance()->Get_ObjList(OBJ_MONSTER).end();)
	{
		터짐 이유가뭘까 조득우가 필요해!!	
		if ((*iter)->Get_Info().vPos.x <= CObjMgr::Get_Instance()->Get_ObjList(OBJ_PLAYER).front()->Get_Info().vPos.x)
			Count += 1;
		++iter;
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