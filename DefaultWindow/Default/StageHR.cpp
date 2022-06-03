#include "stdafx.h"
#include "StageHR.h"

#include "BmpMgr.h"
#include "ObjMgr.h"
#include "CAbstractFactory.h"
#include "HRPlayer.h"
#include "HRBlock.h"
#include "HRMonster.h"


CStageHR::CStageHR()
{
}


CStageHR::~CStageHR()
{
	Release();
}

void CStageHR::Initialize(void)
{
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CHRPlayer>::CreateObj(300.f, 400.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CHRMonster>::CreateObj(400.f, 400.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_HR_BLOCK, CAbstractFactory<CHRBlock>::CreateHRBlock(300.f, WINCY, 600.f, 100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_HR_BLOCK, CAbstractFactory<CHRBlock>::CreateHRBlock(650.f, WINCY, 200.f, 600.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_HR_BLOCK, CAbstractFactory<CHRBlock>::CreateHRBlock(300.f, 300.f, 100.f, 300.f));
}

void CStageHR::Update(void)
{
	CObjMgr::Get_Instance()->Update();
}

void CStageHR::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStageHR::Render(HDC hDC)
{
	/*HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Back");
	BitBlt(hDC, 0, 0, 800, 600, hMemDC, 0, 0, SRCCOPY);*/
	Rectangle(hDC, 0, 0, WINCX, WINCY);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStageHR::Release(void)
{
}
