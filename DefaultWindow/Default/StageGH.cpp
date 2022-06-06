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
	: m_WarigariFloar(nullptr)
{
}


CStageGH::~CStageGH()
{
	Release();
}

void CStageGH::Initialize(void)
{
	m_iRoutine = -1;
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CGHPlayer>::Create());
	// 66.5, 199.8, 333.1, 466.4, 599.7, 733.3
	m_Rotation_Left_Right.tLPoint.x = 67.75f;
	m_Rotation_Left_Right.tLPoint.y = 443.75f;
	m_Rotation_Left_Right.tRPoint.x = 735.25f;
	m_Rotation_Left_Right.tRPoint.y = 443.75f;

	/*MoveToEx(hDC, 250, 0, nullptr);
	LineTo(hDC, 0, WINCY);
	MoveToEx(hDC, WINCX - 250, 0, nullptr);
	LineTo(hDC, WINCX, WINCY);*/
	m_Col_Left_RightLine[0].tLPoint = { 0.f, WINCY, 0.f };
	m_Col_Left_RightLine[0].tRPoint = { 250.f, 0.f, 0.f };

	m_Col_Left_RightLine[1].tLPoint = { float(WINCX - 250), 0.f , 0.f };
	m_Col_Left_RightLine[1].tRPoint = { WINCX, WINCY , 0.f };

	D3DXVECTOR3 m_LeftLineVector = { m_Col_Left_RightLine[0].tRPoint.x - m_Col_Left_RightLine[0].tLPoint.x, m_Col_Left_RightLine[0].tRPoint.y - m_Col_Left_RightLine[0].tLPoint.y,0.f };
	D3DXVECTOR3 m_RightLineVector = { m_Col_Left_RightLine[1].tRPoint.x - m_Col_Left_RightLine[1].tLPoint.x, m_Col_Left_RightLine[1].tRPoint.y - m_Col_Left_RightLine[1].tLPoint.y,0.f };
	D3DXVec3Normalize(&m_LeftLineVector, &m_LeftLineVector);
	D3DXVec3Normalize(&m_RightLineVector, &m_RightLineVector);
	cout << "Left X :" << m_LeftLineVector.x << "\t Y : " << m_LeftLineVector.y << "\t Z : " << m_LeftLineVector.z << endl;
	cout << "Rightt X :" << m_RightLineVector.x << "\t Y : " << m_RightLineVector.y << "\t Z : " << m_RightLineVector.z << endl;

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
	m_iRoutine0_Count = 3;
	m_iFloarIndex = 5;
	m_bMusicStart_Block = false;
	m_bWarigari = false;
}
void CStageGH::Create_Floar()
{
	if (!m_bFloarCreate) {
		if (m_iRoutine == 0)
		{
			if (!m_bMusicStart_Block) {//시작
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(2, true));
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(3, false));
				m_bFloarCreate = true;
				m_bMusicStart_Block = true;
				m_RoutineTime = GetTickCount();
				return;
			}
			else if (m_RoutineTime + 1000 < GetTickCount())
			{
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(m_iRoutine0_Count % 6, false));
				++m_iRoutine0_Count;
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(m_iRoutine0_Count % 6, false));
				++m_iRoutine0_Count;
				m_RoutineTime = GetTickCount();
			}
		}
		else if (m_iRoutine == 1) {//따다닷 141초
			if ((m_iRoutine1_Count < 4) && (m_RoutineTime + 141 < GetTickCount())) {//다닷 141초
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(m_iRoutine1_Count, false));
				m_RoutineTime = GetTickCount();
				++m_iRoutine1_Count;
			}
			else if ((m_iRoutine1_Count == 4) && (m_RoutineTime + 500 < GetTickCount())) {//따아
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(m_iRoutine1_Count, false));
				m_RoutineTime = GetTickCount();
				++m_iRoutine1_Count;
			}
			else if ((m_iRoutine1_Count < 6) && (m_RoutineTime + 250 < GetTickCount())) {//땃땃땃
				if (m_iFloarIndex == -1)
					m_iFloarIndex = 5;
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(m_iFloarIndex, false));
				m_RoutineTime = GetTickCount();
				++m_iRoutine1_Count;
				--m_iFloarIndex;
			}
			else if ((m_iRoutine1_Count < 9) && (m_RoutineTime + 141 < GetTickCount())) {//두뚜뚜 루틴1끝
				if (m_iFloarIndex == -1)
					m_iFloarIndex = 5;
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(m_iFloarIndex, false));
				m_RoutineTime = GetTickCount();
				m_iRoutine1_Count = 0;
				++m_iRoutine1_Count;
				--m_iFloarIndex;
				if (m_iFloarIndex == 0) {
					//++m_iRoutine;
					m_iRoutine1_Count = 0;
				}
			}//이루프끝나면 floarindex는 1
		}
		else if (m_iRoutine == 2) {//
			if (!m_bWarigari) {
				CObjMgr::Get_Instance()->Add_Object(OBJ_GYU_FLOAR, CAbstractFactory<CGHFloar>::CreateGHFloar(6, false));
				m_WarigariFloar = CObjMgr::Get_Instance()->Get_ObjList(OBJ_GYU_FLOAR).back();
				m_bWarigari = true;
			}
			else
			{
				if (m_WarigariFloar->Get_Dead())
				{
					m_WarigariFloar = nullptr;
					m_bWarigari = false;
				}
			}
		}
		else if (m_iRoutine == 3)
		{//스키드라인.

		}
		m_bFloarCreate = true;

	}
}
	
void CStageGH::SetWarigari()
{
	if (m_WarigariFloar == nullptr)
	{
		return;
	}
	else 
	{
		/*INFO WariGariInfo(m_WarigariFloar->Get_Info());
		float iLeftResult = ((WariGariInfo.vPos.x * m_Col_Left_RightLine[0].tLPoint.x) + (WariGariInfo.vPos.y * m_Col_Left_RightLine[0].tLPoint.y)) / 
							(sqrtf(WariGariInfo.vPos.x * WariGariInfo.vPos.x + WariGariInfo.vPos.y * WariGariInfo.vPos.y)* sqrtf(m_Col_Left_RightLine[0].tLPoint.x* m_Col_Left_RightLine[0].tLPoint.x + m_Col_Left_RightLine[0].tLPoint.y * m_Col_Left_RightLine[0].tLPoint.y));
		float iRightResult = ((WariGariInfo.vPos.x * m_Col_Left_RightLine[1].tLPoint.x) + (WariGariInfo.vPos.y * m_Col_Left_RightLine[1].tLPoint.y)) / 
							((sqrtf(WariGariInfo.vPos.x * WariGariInfo.vPos.x + WariGariInfo.vPos.y * WariGariInfo.vPos.y)* sqrtf(m_Col_Left_RightLine[1].tLPoint.x* m_Col_Left_RightLine[1].tLPoint.x + m_Col_Left_RightLine[1].tLPoint.y * m_Col_Left_RightLine[1].tLPoint.y)));
		cout << "L: " << iLeftResult << "\t" << "R: " << iRightResult << endl;
		if(iLeftResult == 1.f || iRightResult == 1.f)
			dynamic_cast<CGHFloar*>(m_WarigariFloar)->SetReDirection();*/


		INFO WariGariInfo(m_WarigariFloar->Get_Info());
		D3DXVECTOR3 m_LeftLineVector = { m_Col_Left_RightLine[0].tRPoint.x - m_Col_Left_RightLine[0].tLPoint.x, m_Col_Left_RightLine[0].tRPoint.y - m_Col_Left_RightLine[0].tLPoint.y,0.f };
		D3DXVECTOR3 m_RightLineVector = { m_Col_Left_RightLine[1].tRPoint.x - m_Col_Left_RightLine[1].tLPoint.x, m_Col_Left_RightLine[1].tRPoint.y - m_Col_Left_RightLine[1].tLPoint.y,0.f };
		D3DXVec3Normalize(&m_LeftLineVector, &m_LeftLineVector);
		D3DXVec3Normalize(&m_RightLineVector, &m_RightLineVector);
		D3DXVECTOR3 ToWarigariVectorLeft = { WariGariInfo.vPos.x - m_Col_Left_RightLine[0].tLPoint.x, WariGariInfo.vPos.y - m_Col_Left_RightLine[0].tLPoint.y,0.f };
		D3DXVECTOR3 ToWarigariVectorRight = { WariGariInfo.vPos.x - m_Col_Left_RightLine[1].tLPoint.x, WariGariInfo.vPos.y - m_Col_Left_RightLine[1].tLPoint.y,0.f };
		D3DXVec3Normalize(&ToWarigariVectorRight, &ToWarigariVectorRight);
		D3DXVec3Normalize(&ToWarigariVectorLeft, &ToWarigariVectorLeft);
		float fDotLeft = D3DXVec3Dot(&m_LeftLineVector, &ToWarigariVectorLeft);
		float fDotRight = D3DXVec3Dot(&m_RightLineVector, &ToWarigariVectorRight);
		float	fAngleLeft = acosf(fDotLeft);
		float	fAngleRight = acosf(fDotRight);
		cout << "L: " << fAngleLeft << "\t" << "R: " << fAngleRight << endl;
		if (0.02f<fAngleLeft && 0.03f > fAngleLeft) {
			dynamic_cast<CGHFloar*>(m_WarigariFloar)->SetReDirection();
		}
		else if (0.02f<fAngleRight && 0.03f > fAngleRight)
		{
			dynamic_cast<CGHFloar*>(m_WarigariFloar)->SetReDirection();

		}

	}
}
void CStageGH::Update(void)
{
	if ((g_dwGHBGMStartTime != 0) && (g_dwGHBGMStartTime + 15000 < GetTickCount()))
	{
		++m_iRoutine;
		g_dwGHBGMStartTime = GetTickCount();
	}
	/*if ((g_dwGHBGMStartTime != 0) && (g_dwGHBGMStartTime + 15000 < GetTickCount()))
	{
		m_iRoutine = 2;
	}*/
	SetWarigari();
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
	// 사이거리 300 6개라인 한개 50
	// 250-300 300-350, 350-400
	// 275, 325, 375, 425, 475, 525
	// 66.5, 199.8, 333.1, 466.4, 599.7, 733.3
	// 0 ~ 800 6개라인 한개 133.3
	// 0 - 133 
	// 

	//HDC		hDC2 = CBmpMgr::Get_Instance()->Find_Image(L"aa");
	//BitBlt(hDC, 0, 0, 800, 600, hDC2, 0, 0, SRCCOPY);

	Rectangle(hDC, 0, 0, WINCX, WINCY);

	MoveToEx(hDC, (int)m_Col_Left_RightLine[0].tLPoint.x, (int)m_Col_Left_RightLine[0].tLPoint.y, nullptr);
	LineTo(hDC, (int)m_Col_Left_RightLine[0].tRPoint.x, (int)m_Col_Left_RightLine[0].tRPoint.y);
	MoveToEx(hDC, (int)m_Col_Left_RightLine[1].tLPoint.x, (int)m_Col_Left_RightLine[1].tLPoint.y, nullptr);
	LineTo(hDC, (int)m_Col_Left_RightLine[1].tRPoint.x, (int)m_Col_Left_RightLine[1].tRPoint.y);


	CObjMgr::Get_Instance()->Render(hDC);
	CGHLineMgr::Get_Instance()->Render(hDC);
	CGHScoreMgr::Get_Instance()->Render(hDC);

	Ellipse(hDC, 400- 5 , 300- 5, 400 + 5, 300 + 5);

}

void CStageGH::Release(void)
{
	CGHLineMgr::Get_Instance()->Destroy_Instance();
	CObjMgr::Get_Instance()->Release();
	CGHScoreMgr::Get_Instance()->Destroy_Instance();

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
			//m_iRoutine = 0;
			m_iRoutine = 2;
 			cout << 0 << endl;
			m_MusicTime = GetTickCount();
		}
	}
	if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON)) {
		cout <<GetTickCount() - m_MusicTime << endl;
		m_MusicTime = GetTickCount();
		CSceneMgr::Get_Instance()->Scene_Change(STAGE_HS);
	}


}
