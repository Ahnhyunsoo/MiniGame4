#include "stdafx.h"
#include "StageHS.h"
#include "ObjMgr.h"
#include "CAbstractFactory.h"
#include "GunTower.h"
#include "HSMonster.h"
#include "BmpMgr.h"
#include "LineMgr.h"


CStageHS::CStageHS()
	:m_iSponSpeed(1000),m_iNowMonster(0),m_iMaxMonster(10),m_LSponMonster(GetTickCount())
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

	/*CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CHSMonster>::CreateObj(510.f, 60.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CHSMonster>::CreateObj(600.f, 60.f));*/
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
	
}

void CStageHS::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Back");
	BitBlt(hDC, 0, 0, 800, 600, hMemDC, 0, 0, SRCCOPY);
	Rectangle(hMemDC, 0, 0, WINCX, WINCY);
	Draw_Rect(hMemDC);
	Draw_UI(hMemDC);
	CLineMgr::Get_Instance()->Render(hMemDC);
	CObjMgr::Get_Instance()->Render(hMemDC);



	
	
}

void CStageHS::Release(void)
{
}

void CStageHS::Draw_Rect(HDC hDC)
{
	HPEN hpen;
	HPEN hpenOld;

	hpen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));	// 선 스타일, 굵기, 색상
	hpenOld = (HPEN)::SelectObject(hDC, (HGDIOBJ)hpen);	// 펜 선택
	Rectangle(hDC, 385, 240, 415, 270);
	Rectangle(hDC, 385, 280, 415, 310);
	hpen = (HPEN)SelectObject(hDC, hpenOld);	// 기존의 펜 다시 선택
	DeleteObject(hpen);	// 생성한 펜 삭제
}

void CStageHS::Draw_UI(HDC hDC)
{

}
