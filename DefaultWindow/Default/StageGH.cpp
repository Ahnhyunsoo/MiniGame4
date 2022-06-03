#include "stdafx.h"
#include "StageGH.h"
#include "CAbstractFactory.h"
#include "GHPlayer.h"
#include "GHFloar.h"
#include "GHLineMgr.h"
#include "GHButton.h"
#include "BmpMgr.h"

CStageGH::CStageGH()
{
}


CStageGH::~CStageGH()
{
	Release();
}

void CStageGH::Initialize(void)
{
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CGHPlayer>::Create());
	// 66.5, 199.8, 333.1, 466.4, 599.7, 733.3

	CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_BUTTON, CAbstractFactory<CGHButton>::CreateObj(66.5, WINCY-100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_BUTTON, CAbstractFactory<CGHButton>::CreateObj(199.8f, WINCY - 100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_BUTTON, CAbstractFactory<CGHButton>::CreateObj(333.1f, WINCY - 100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_BUTTON, CAbstractFactory<CGHButton>::CreateObj(466.4f, WINCY - 100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_BUTTON, CAbstractFactory<CGHButton>::CreateObj(599.7f, WINCY - 100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_BUTTON, CAbstractFactory<CGHButton>::CreateObj(733.3f, WINCY - 100.f));
	m_ScrollZ = 0;
	m_ScrollTime = 0;
	m_bStart = false;
	m_bFloarCreate = false;
	CGHLineMgr::Get_Instance()->Initialize();
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/aa.bmp", L"aa");

	
}
void CStageGH::Create_Floar()
{
	if (m_ScrollZ == 1) {
		if (!m_bFloarCreate) {
			CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(0));
			m_bFloarCreate = true;
		}
	}
	else if (m_ScrollZ == 2)
	{
		if (!m_bFloarCreate) {
			CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(1));
			m_bFloarCreate = true;
		}
	}
	else if (m_ScrollZ == 3)
	{
		if (!m_bFloarCreate) {
			CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(2));
			m_bFloarCreate = true;
		}
	}
	else if (m_ScrollZ == 4)
	{
		if (!m_bFloarCreate) {
			CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(3));
			m_bFloarCreate = true;
		}
	}
	else if (m_ScrollZ == 5)
	{
		if (!m_bFloarCreate) {
			CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(4));
			m_bFloarCreate = true;
		}
	}
	else if (m_ScrollZ == 6)
	{
		if (!m_bFloarCreate) {
			CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(5));
			m_bFloarCreate = true;
		}
	}

}
void CStageGH::Update(void)
{
	Key_Input();
	Create_Floar();

	CObjMgr::Get_Instance()->Update();
}

void CStageGH::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();

}

void CStageGH::Render(HDC hDC)
{

	/* 250 ~ 550 */
	// 사이거리 300 6개라인 한개 50
	// 250-300 300-350, 350-400
	// 275, 325, 375, 425, 475, 525
	// 66.5, 199.8, 333.1, 466.4, 599.7, 733.3
	// 0 ~ 800 6개라인 한개 133.3
	// 0 - 133 
	// 
	HDC		hDC2 = CBmpMgr::Get_Instance()->Find_Image(L"aa");
	BitBlt(hDC, 0, 0, 800, 600, hDC2, 0, 0, SRCCOPY);
	MoveToEx(hDC, 250, 0, nullptr);
	LineTo(hDC, 0, WINCY);
	MoveToEx(hDC, WINCX - 250, 0, nullptr);
	LineTo(hDC, WINCX, WINCY);


	CObjMgr::Get_Instance()->Render(hDC);
	CGHLineMgr::Get_Instance()->Render(hDC);

	Ellipse(hDC, 400 - 10, 100 - 10, 400 + 10, 100 + 10);

}

void CStageGH::Release(void)
{
	CGHLineMgr::Get_Instance()->Destroy_Instance();
	CObjMgr::Get_Instance()->Release();
}

void CStageGH::Key_Input()
{
	if (m_bStart)
	{
		if ((m_ScrollTime == 0) || ((m_ScrollTime != 0)&&(m_ScrollTime + 500 < GetTickCount())))
		{
			++m_ScrollZ;
			m_bFloarCreate = false;
			m_ScrollTime = GetTickCount();
		}
	}
	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN)) {
		if (!m_bStart) {
			m_bStart = true;
		}
	}

}
