#include "stdafx.h"
#include "StageGH.h"
#include "CAbstractFactory.h"
#include "GHPlayer.h"
#include "GHFloar.h"
#include "GHLineMgr.h"
#include "GHButton.h"
#include "BmpMgr.h"
#include "GHScoreMgr.h"
#include "SoundMgr.h"
#include <iostream>
#include "Include.h"


CStageGH::CStageGH()
{
}


CStageGH::~CStageGH()
{
	Release();
}

void CStageGH::Initialize(void)
{
	m_iRoutine = 0;
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CGHPlayer>::Create());
	// 66.5, 199.8, 333.1, 466.4, 599.7, 733.3

	CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_BUTTON, CAbstractFactory<CGHButton>::CreateObj(66.5, WINCY- 53.325f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_BUTTON, CAbstractFactory<CGHButton>::CreateObj(199.8f,WINCY - 53.325f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_BUTTON, CAbstractFactory<CGHButton>::CreateObj(333.1f,WINCY - 53.325f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_BUTTON, CAbstractFactory<CGHButton>::CreateObj(466.4f,WINCY - 53.325f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_BUTTON, CAbstractFactory<CGHButton>::CreateObj(599.7f,WINCY - 53.325f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_BUTTON, CAbstractFactory<CGHButton>::CreateObj(733.3f,WINCY - 53.325f));
	m_RoutineTime = 0;
	m_ScrollTime = 0;
	m_bStart = false;
	m_bFloarCreate = false;
	CGHLineMgr::Get_Instance()->Initialize();
	CGHScoreMgr::Get_Instance()->Initialize();
	
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/aa.bmp", L"aa");
	m_iRoutine1_Count = 0;
	m_iFloarIndex = 5;
	m_bMusicStart_Block = false;
}
void CStageGH::Create_Floar()
{
	if (!m_bFloarCreate) {
		if (m_iRoutine == 1) {//µû´Ù´å 141ÃÊ
			if (!m_bMusicStart_Block) {//½ÃÀÛ
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(m_iRoutine1_Count, true));
				m_bFloarCreate = true;
				m_bMusicStart_Block = true;
				m_RoutineTime = GetTickCount();
				++m_iRoutine1_Count;
				return;
			}
			else if ((m_iRoutine1_Count < 4)&&(m_RoutineTime + 141 < GetTickCount())) {//´Ù´å 141ÃÊ
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(m_iRoutine1_Count, false));
				m_RoutineTime = GetTickCount();
				++m_iRoutine1_Count;
			}
			else if ((m_iRoutine1_Count == 4) && (m_RoutineTime + 500 < GetTickCount())) {//µû¾Æ
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(m_iRoutine1_Count, false));
				m_RoutineTime = GetTickCount();
				++m_iRoutine1_Count;
			}
			else if ((m_iRoutine1_Count < 6) && (m_RoutineTime + 500 < GetTickCount())) {//¶£¶£¶£
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(m_iFloarIndex, false));
				m_RoutineTime = GetTickCount();
				++m_iRoutine1_Count;
				--m_iFloarIndex;
			}
			else if ((m_iRoutine1_Count < 9) && (m_RoutineTime + 141 < GetTickCount())) {//µÎ¶Ñ¶Ñ ·çÆ¾1³¡
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(m_iFloarIndex, false));
				m_RoutineTime = GetTickCount();
				++m_iRoutine1_Count;
				--m_iFloarIndex;
				if (m_iFloarIndex == 1) {
					++m_iRoutine;
					m_iRoutine1_Count = 0;
				}
			}//ÀÌ·çÇÁ³¡³ª¸é floarindex´Â 1
		}
		if (m_iRoutine == 2) {//µû´Ù´å 141ÃÊ
			if ((m_iRoutine1_Count < 4) && (m_RoutineTime + 141 < GetTickCount())) {//´Ù´å 141ÃÊ
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(m_iRoutine1_Count, false));
				m_RoutineTime = GetTickCount();
				++m_iRoutine1_Count;
			}
			else if ((m_iRoutine1_Count == 4) && (m_RoutineTime + 500 < GetTickCount())) {//µû¾Æ
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(m_iRoutine1_Count, false));
				m_RoutineTime = GetTickCount();
				++m_iRoutine1_Count;
			}
			else if ((m_iRoutine1_Count < 6) && (m_RoutineTime + 250 < GetTickCount())) {//¶£¶£¶£
				if (m_iFloarIndex == -1)
					m_iFloarIndex = 5;
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(m_iFloarIndex, false));
				m_RoutineTime = GetTickCount();
				++m_iRoutine1_Count;
				--m_iFloarIndex;
			}
			else if ((m_iRoutine1_Count < 9) && (m_RoutineTime + 141 < GetTickCount())) {//µÎ¶Ñ¶Ñ ·çÆ¾1³¡
				if (m_iFloarIndex == -1)
					m_iFloarIndex = 5;
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(m_iFloarIndex, false));
				m_RoutineTime = GetTickCount();
				m_iRoutine1_Count = 0;
				++m_iRoutine1_Count;
				--m_iFloarIndex;
				if (m_iFloarIndex == 1) {
					//++m_iRoutine;
					m_iRoutine1_Count = 0;
				}
			}//ÀÌ·çÇÁ³¡³ª¸é floarindex´Â 1
		}
		if (m_iRoutine == 3)
		{
			CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(6, false));

		}
		m_bFloarCreate = true;

	}
	
}
void CStageGH::Update(void)
{
	if ((g_dwGHBGMStartTime != 0) && (g_dwGHBGMStartTime + 15000 < GetTickCount()))
	{
		m_iRoutine = 3;
	}
	Key_Input();
	Create_Floar();

	CObjMgr::Get_Instance()->Update();
	CGHScoreMgr::Get_Instance()->Update();
	if(m_bStart)
		CGHScoreMgr::Get_Instance()->Set_Scale();

}

void CStageGH::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();

}

void CStageGH::Render(HDC hDC)
{

	/* 250 ~ 550 */
	// »çÀÌ°Å¸® 300 6°³¶óÀÎ ÇÑ°³ 50
	// 250-300 300-350, 350-400
	// 275, 325, 375, 425, 475, 525
	// 66.5, 199.8, 333.1, 466.4, 599.7, 733.3
	// 0 ~ 800 6°³¶óÀÎ ÇÑ°³ 133.3
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
	CGHScoreMgr::Get_Instance()->Render(hDC);

	Ellipse(hDC, 400 - 10, 100 - 10, 400 + 10, 100 + 10);

}

void CStageGH::Release(void)
{
	CGHLineMgr::Get_Instance()->Destroy_Instance();
	CObjMgr::Get_Instance()->Release();
	CGHScoreMgr::Get_Instance()->Release();

}

void CStageGH::Key_Input()
{
	if (m_bStart)
	{
		if ((m_ScrollTime == 0) || ((m_ScrollTime != 0)&&(m_ScrollTime + 1 < GetTickCount())))
		{
			m_bFloarCreate = false;
			m_ScrollTime = GetTickCount();
		}
	}
	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN)) {
		if (!m_bStart) {
			m_bStart = true;
			/*GHUndertale*/
			m_iRoutine = 1;
			cout << 0 << endl;
			m_MusicTime = GetTickCount();
		}
	}
	if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON)) {
		cout << GetTickCount() - m_MusicTime << endl;
		m_MusicTime = GetTickCount();

	}


}
