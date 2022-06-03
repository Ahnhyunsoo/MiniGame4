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



CMainGame::CMainGame()
	:m_dwTime(GetTickCount())
{
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
	CSceneMgr::Get_Instance()->Scene_Change(STAGE_YM);

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Back.bmp", L"Back");

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
	
	

	CSceneMgr::Get_Instance()->Render(m_hDC);
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
	ReleaseDC(g_hWnd, m_hDC);
}

// 1. w,a,s,d 키를 눌러 4방향 총알쏘기
// 2. 가로 세로가 100씩 작은 렉트를 만들고 사각형 범위를 벗어나면 미사일을 삭제하라