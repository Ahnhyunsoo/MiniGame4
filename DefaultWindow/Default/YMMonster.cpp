#include "stdafx.h"
#include "YMMonster.h"


CYMMonster::CYMMonster()
{
}


CYMMonster::~CYMMonster()
{
}

void CYMMonster::Initialize(void)
{
	m_tInfo.fCX = 40;
	m_tInfo.fCY = 40;
	m_fAngle = 1.f;
	m_fSpeed = 5.f;
	m_fScale = 1.f;


	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, -20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, -20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, 20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, 20.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -20.f, -20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 20.f, -20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 20.f, 20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -20.f, 20.f, 0.f });
}

int CYMMonster::Update(void)
{
	m_tInfo.vPos.y += m_fSpeed;
	Update_MatWorld();
	return OBJ_NOEVENT;
}

void CYMMonster::Late_Update(void)
{
}

void CYMMonster::Render(HDC hDC)
{
	Render_Vertex(hDC);
}

void CYMMonster::Release(void)
{
}

void CYMMonster::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
