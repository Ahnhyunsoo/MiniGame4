#include "stdafx.h"
#include "StageST.h"
#include "ObjMgr.h"
#include "CAbstractFactory.h"
#include "SelectPlayer.h"
#include "BmpMgr.h"
#include "STStageName.h"

CStageST::CStageST()
{
}


CStageST::~CStageST()
{
	Release();
}

void CStageST::Initialize(void)
{
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CSelectPlayer>::Create(true));
	float InitialX(150.f), InitialY(150.f);
	int iNameIndex{0};
	for (int i = 0; i < 4; ++i) {
		CObjMgr::Get_Instance()->Add_Object(OBJ_UI, CAbstractFactory<CSTStageName>::CreateObj(InitialX, InitialY,i));
		InitialX += 180.f;
	}

}

void CStageST::Update(void)
{
	CObjMgr::Get_Instance()->Update();
}

void CStageST::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStageST::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"aa");
	BitBlt(hDC, 0, 0, 800, 600, hMemDC, 0, 0, SRCCOPY);
	Rectangle(hMemDC, 0, 0, WINCX, WINCY);
	CObjMgr::Get_Instance()->Render(hMemDC);

	//CObjMgr::Get_Instance()->Render(hDC);

}

void CStageST::Release(void)
{
	CObjMgr::Get_Instance()->Release();
	// CObjMgr::Get_Instance()->Destroy_Instance();

}
