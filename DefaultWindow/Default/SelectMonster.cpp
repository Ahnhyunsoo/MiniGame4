#include "stdafx.h"
#include "SelectMonster.h"


CSelectMonster::CSelectMonster()
{
}


CSelectMonster::~CSelectMonster()
{
}

void CSelectMonster::Initialize(void)
{
	//m_tInfo.vPos = { 0.f,0.f,0.f };
	m_fAngle = 1.f;
	m_fSpeed = 2.f;
	m_fScale = 1.f;
	m_tInfo.vDir = { 1.f,0.f,0.f };
	m_bDead = false;

	m_vOriVertex.push_back(D3DXVECTOR3{ -30.f, -20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 30.f, -20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 30.f, 20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -30.f, 20.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -30.f, -20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 30.f, -20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 30.f, 20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -30.f, 20.f, 0.f });
}

int CSelectMonster::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	m_tInfo.vPos.x += m_fSpeed;
	Update_MatWorld();
	return OBJ_NOEVENT;
}

void CSelectMonster::Late_Update(void)
{
}

void CSelectMonster::Render(HDC hDC)
{
	Render_Vertex(hDC);
	
}

void CSelectMonster::Release(void)
{
	
}

void CSelectMonster::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
