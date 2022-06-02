#include "stdafx.h"
#include "StageYM.h"
#include "ObjMgr.h"
#include "CAbstractFactory.h"
#include "YMPlayer.h"
#include "YMMonster.h"


CStageYM::CStageYM()
{
}


CStageYM::~CStageYM()
{
	Release();
}

void CStageYM::Initialize(void)
{
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CYMPlayer>::Create());
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateSelectMonster(600.f, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateSelectMonster(610.f, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateSelectMonster(620.f, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateSelectMonster(630.f, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateSelectMonster(640.f, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateSelectMonster(650.f, 200.f));
}

void CStageYM::Update(void)
{
	CObjMgr::Get_Instance()->Update();
}

void CStageYM::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStageYM::Render(HDC hDC)
{
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStageYM::Release(void)
{
}
