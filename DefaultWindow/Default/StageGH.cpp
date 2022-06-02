#include "stdafx.h"
#include "StageGH.h"
#include "CAbstractFactory.h"
#include "GHPlayer.h"
#include "GHFloar.h"

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
	m_iScrollZ = 0;
	m_bStart = false;
	//CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(WINCX / 2, WINCY/2, 0));

	
}

void CStageGH::Update(void)
{
	Key_Input();
	CObjMgr::Get_Instance()->Update();
}

void CStageGH::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();

}

void CStageGH::Render(HDC hDC)
{
	if (!m_bStart)
	{
		MoveToEx(hDC, 250, 0, nullptr);
		LineTo(hDC, 0, WINCY);
		MoveToEx(hDC, WINCX - 250, 0, nullptr);
		LineTo(hDC, WINCX, WINCY);
	}
	CObjMgr::Get_Instance()->Render(hDC);


}

void CStageGH::Release(void)
{
	CObjMgr::Get_Instance()->Release();
}

void CStageGH::Key_Input()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN)) {
		if (!m_bStart)
			m_bStart = true;
	}

}
