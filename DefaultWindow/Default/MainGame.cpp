#include "stdafx.h"
#include "MainGame.h"
#include "Monster.h"
#include "Player.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "ScrollMgr.h"
#include "ObjMgr.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "LineMgr.h"

float g_GHfSound;
DWORD g_dwGHBGMStartTime;
CMainGame::CMainGame()
	:m_dwTime(GetTickCount()) 
{
	g_GHfSound = 0.8f;
	g_dwGHBGMStartTime = 0;
	ZeroMemory(m_szFPS, sizeof(TCHAR) * 64);
	m_iFPS = 0;
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_hDC = GetDC(g_hWnd);

	CSoundMgr::Get_Instance()->Initialize();
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/aa.bmp", L"aa");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Back.bmp", L"Back");
	CSceneMgr::Get_Instance()->Scene_Change(STAGE_GH);
	


}

void CMainGame::Update(void)
{
	CSceneMgr::Get_Instance()->Update();
}

void CMainGame::Late_Update(void)
{

	CSceneMgr::Get_Instance()->Late_Update();
}

void CMainGame::Render(void)
{
	//Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Back");
	BitBlt(m_hDC, 0, 0, 800, 600, hMemDC, 0, 0, SRCCOPY);
	//Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	

	CSceneMgr::Get_Instance()->Render(hMemDC);
	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount();
	}
}

void CMainGame::Release(void)
{
	CSoundMgr::Get_Instance()->Destroy_Instance();
	CSceneMgr::Get_Instance()->Destroy_Instance();
	CScrollMgr::Get_Instance()->Destroy_Instance();
	CKeyMgr::Get_Instance()->Destroy_Instance();
	CObjMgr::Get_Instance()->Destroy_Instance();
	CLineMgr::Get_Instance()->Destroy_Instance();
	ReleaseDC(g_hWnd, m_hDC);
}

// 1. w,a,s,d Ű�� ���� 4���� �Ѿ˽��
// 2. ���� ���ΰ� 100�� ���� ��Ʈ�� ����� �簢�� ������ ����� �̻����� �����϶�