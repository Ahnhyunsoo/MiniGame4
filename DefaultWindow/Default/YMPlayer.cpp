#include "stdafx.h"
#include "YMPlayer.h"


CYMPlayer::CYMPlayer()
{
}


CYMPlayer::~CYMPlayer()
{
}

void CYMPlayer::Initialize(void)
{
	m_tInfo.fCX = 50;
	m_tInfo.fCY = 80;
	m_tInfo.vPos = { 100.f,300.f,0.f };
	m_fAngle = 1.f;
	m_fSpeed = 1.f;
	m_fScale = 4.f;
	m_tInfo.vDir = { 0.f, 1.f,0.f };

	m_vOriVertex.push_back(D3DXVECTOR3(-30.f, 0.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(30.f, 0.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(0.f, -30.f, 0.f));


	m_vVertex.push_back(D3DXVECTOR3{ -30.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 30.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 0.f, -30.f, 0.f });
}

int CYMPlayer::Update(void)
{
	Update_MatWorld();
	Key_Input();

	return OBJ_NOEVENT;
}

void CYMPlayer::Late_Update(void)
{
}

void CYMPlayer::Render(HDC hDC)
{
	Render_Vertex(hDC);
	Ellipse(hDC, m_tInfo.vPos.x - 35, m_tInfo.vPos.y, m_tInfo.vPos.x - 30, m_tInfo.vPos.y + 5);
	Ellipse(hDC, m_tInfo.vPos.x + 35, m_tInfo.vPos.y, m_tInfo.vPos.x + 30, m_tInfo.vPos.y + 5);
}

void CYMPlayer::Release(void)
{
}

void CYMPlayer::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}


void CYMPlayer::Key_Input(void)
{
	if (CKeyMgr::Get_Instance()->Key_Pressing('W'))
	{
		m_tInfo.vPos.y -= m_fSpeed;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing('S'))
	{
		m_tInfo.vPos.y += m_fSpeed;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing('A'))
	{
		m_tInfo.vPos.x -= m_fSpeed;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing('D'))
	{
		m_tInfo.vPos.x += m_fSpeed;
	}


}


D3DXVECTOR3	CYMPlayer::Get_Mouse(void)
{
	POINT	Pt{};

	GetCursorPos(&Pt);
	ScreenToClient(g_hWnd, &Pt);

	return D3DXVECTOR3((float)Pt.x, (float)Pt.y, 0.f);
}