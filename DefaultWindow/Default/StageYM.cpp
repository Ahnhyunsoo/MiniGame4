#include "stdafx.h"
#include "StageYM.h"


CStageYM::CStageYM()
{
}


CStageYM::~CStageYM()
{
}

void CStageYM::Initialize(void)
{
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CYMPlayer>::Create());
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateObj(600.f, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateObj(610.f, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateObj(620.f, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateObj(630.f, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateObj(640.f, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CYMMonster>::CreateObj(650.f, 200.f));
}

void CStageYM::Update(void)
{
}

void CStageYM::Late_Update(void)
{
}

void CStageYM::Render(HDC hDC)
{
}

void CStageYM::Release(void)
{
}
