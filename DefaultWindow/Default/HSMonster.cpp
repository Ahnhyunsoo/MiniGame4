#include "stdafx.h"
#include "HSMonster.h"


CHSMonster::CHSMonster()
{
}


CHSMonster::~CHSMonster()
{
}

void CHSMonster::Initialize(void)
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;
	m_fAngle = 1.f;
	m_fSpeed = 1.f;
	m_fScale = 1.f;
	m_tInfo.vDir = { -1.f,0.f,0.f };
	m_bDead = false;

	m_vOriVertex.push_back(D3DXVECTOR3{ -15.f, -15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 15.f, -15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 15.f, 15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -15.f, 15.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });
}

int CHSMonster::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_MatWorld();
	m_tInfo.vPos.x -= m_fSpeed;
	return OBJ_NOEVENT;
}

void CHSMonster::Late_Update(void)
{
}

void CHSMonster::Render(HDC hDC)
{
	Render_Vertex(hDC);
	Draw_Triangle(hDC);
}

void CHSMonster::Release(void)
{
}

void CHSMonster::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
