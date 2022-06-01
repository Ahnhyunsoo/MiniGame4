#include "stdafx.h"
#include "StageHS.h"
#include "ObjMgr.h"
#include "CAbstractFactory.h"
#include "GunTower.h"
#include "HSMonster.h"
#include "BmpMgr.h"


CStageHS::CStageHS()
{
}


CStageHS::~CStageHS()
{
}

void CStageHS::Initialize(void)
{
	CObjMgr::Get_Instance()->Add_Object(OBJ_TOWER, CAbstractFactory<CGunTower>::CreateObj(400.f,100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_TOWER, CAbstractFactory<CGunTower>::CreateObj(400.f,300.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_TOWER, CAbstractFactory<CGunTower>::CreateObj(400.f, 500.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CHSMonster>::CreateObj(400.f,100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CHSMonster>::CreateObj(510.f, 220.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CHSMonster>::CreateObj(600.f, 400.f));
}

void CStageHS::Update(void)
{
	CObjMgr::Get_Instance()->Update();
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
	CObjMgr::Get_Instance()->Render(hMemDC);
}

void CStageHS::Release(void)
{
}
