#include "stdafx.h"
#include "StageHS.h"
#include "ObjMgr.h"
#include "CAbstractFactory.h"
#include "GunTower.h"


CStageHS::CStageHS()
{
}


CStageHS::~CStageHS()
{
}

void CStageHS::Initialize(void)
{
	CObjMgr::Get_Instance()->Add_Object(OBJ_TOWER, CAbstractFactory<CGunTower>::Create());
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
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStageHS::Release(void)
{
}
