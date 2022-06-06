#include "stdafx.h"
#include "StageYM.h"
#include "ObjMgr.h"
#include "CAbstractFactory.h"
#include "YMPlayer.h"
#include "YMMonster.h"
#include "YMTownMoster.h"
#include "YMShipMonster.h"
#include "YMMiddleBoss.h"
#include "YMUiMgr.h"
#include "YMLevelUp.h"
#include "YMHeal.h"
#include "YMIBoom.h"
#include "YMBoss.h"


CStageYM::CStageYM()
{
}


CStageYM::~CStageYM()
{
	Release();
}

void CStageYM::Initialize(void)
{
	CYMUiMgr::Get_Instance()->Initialize();
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CYMPlayer>::Create());
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateObj(600.f, -1200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateObj(200.f, -1200.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(100.f, 100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(500.f, 400.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<YMShipMonster>::CreateObj(100.f, -500.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMiddleBoss>::CreateObj(200.f, 0.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMBoss>::CreateObj(200.f, -300.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_ITEM, CAbstractFactory<CYMLevelUp>::CreateObj(200.f, 100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_ITEM, CAbstractFactory<CYMHeal>::CreateObj(400.f, -300.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_ITEM, CAbstractFactory<CYMIBoom>::CreateObj(400.f, -500.f));
}

void CStageYM::Update(void)
{
	CObjMgr::Get_Instance()->Update();
	CYMUiMgr::Get_Instance()->Update();
}

void CStageYM::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
	CYMUiMgr::Get_Instance()->Late_Update();
}

void CStageYM::Render(HDC hDC)
{
	Rectangle(hDC, 0, 0, WINCX, WINCY);
	CObjMgr::Get_Instance()->Render(hDC);
	CYMUiMgr::Get_Instance()->Render(hDC);
}

void CStageYM::Release(void)
{
	CObjMgr::Get_Instance()->Release();
	CYMUiMgr::Get_Instance()->Release();
}
