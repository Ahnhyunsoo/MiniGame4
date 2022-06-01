#include "stdafx.h"
#include "GunTower.h"


CGunTower::CGunTower()
{
}


CGunTower::~CGunTower()
{
}


void CGunTower::Initialize(void)
{
	m_tInfo.fCX = 60.f;
	m_tInfo.fCY = 60.f;
	m_tInfo.vPos = { 400.f,300.f,0.f };
	m_fAngle = 1.f;
	m_fSpeed = 1.f;
	m_fScale = 1.f;
	m_tInfo.vDir = { 1.f,0.f,0.f };
	m_bDead = false;

	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, 10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });
}

int CGunTower::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_MatWorld();

	return OBJ_NOEVENT;
}

void CGunTower::Late_Update(void)
{
}

void CGunTower::Render(HDC hDC)
{
	Render_Vertex(hDC);
	MoveToEx(hDC, m_tInfo.vPos.x, m_tInfo.vPos.y, nullptr);
	LineTo(hDC, m_tInfo.vPos.x + cos(m_fAngle) * 30, m_tInfo.vPos.y + sin(m_fAngle) * 30);
}

void CGunTower::Release(void)
{
}

void CGunTower::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
