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
#include "YMCommon.h"


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

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateObj(800.f, -4700.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateObj(0.f, -4700.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateObj(1000.f, -4700.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateObj(-1000.f, -4700.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateObj(1000.f, -4800.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateObj(-1000.f, -4900.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(100.f, -2000.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(150.f, -2050.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(200.f, -2100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(250.f, -2150.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(500.f, -2000.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(550.f, -2050.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(600.f, -2100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(650.f, -2150.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(100.f, -3000.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(300.f, -3100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(500.f, -3200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(700.f, -3300.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(100.f, -4700.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(150.f, -4800.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(400.f, -4900.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(450.f, -5000.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(700.f, -5100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(750.f, -5200.f));


	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(100.f, -5700.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(150.f, -5800.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(400.f, -5900.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(450.f, -6000.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(700.f, -6100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMTownMoster>::CreateObj(750.f, -6200.f));




	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMCommon>::CreateObj(-200.f, -300.f, DIR_LEFT));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMCommon>::CreateObj(-300.f, -400.f, DIR_LEFT));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMCommon>::CreateObj(-400.f, -500.f, DIR_LEFT));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMCommon>::CreateObj(-500.f, -600.f, DIR_LEFT));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMCommon>::CreateObj(1500.f, -900.f, DIR_RIGHT));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMCommon>::CreateObj(1600.f, -1000.f, DIR_RIGHT));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMCommon>::CreateObj(1700.f, -1100.f, DIR_RIGHT));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMCommon>::CreateObj(1800.f, -1200.f, DIR_RIGHT));


	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMCommon>::CreateObj(-2500.f, -2400.f, DIR_LEFT));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMCommon>::CreateObj(-2600.f, -2500.f, DIR_LEFT));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMCommon>::CreateObj(-2700.f, -2600.f, DIR_LEFT));


	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMCommon>::CreateObj(2800.f, -2700.f, DIR_RIGHT));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMCommon>::CreateObj(2900.f, -2800.f, DIR_RIGHT));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMCommon>::CreateObj(3000.f, -2900.f, DIR_RIGHT));



	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMiddleBoss>::CreateObj(200.f, -3500.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMBoss>::CreateObj(400.f, -6000.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<YMShipMonster>::CreateObj(100.f, -600.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<YMShipMonster>::CreateObj(-450.f, -1100.f));


	CObjMgr::Get_Instance()->Add_Object(OBJ_ITEM, CAbstractFactory<CYMLevelUp>::CreateObj(200.f, -2000.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_ITEM, CAbstractFactory<CYMLevelUp>::CreateObj(200.f, -1000.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_ITEM, CAbstractFactory<CYMLevelUp>::CreateObj(200.f, 0.f));
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
