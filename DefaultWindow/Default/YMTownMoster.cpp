#include "stdafx.h"
#include "YMTownMoster.h"


CYMTownMoster::CYMTownMoster()
{
}


CYMTownMoster::~CYMTownMoster()
{
}

void CYMTownMoster::Initialize(void)
{
	m_fAngle = 1.f;
	m_fSpeed = 2.f;
	m_fScale = 1.f;
	m_tInfo.vLook = { 1.f, 0.f, 0.f };

	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, 20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, 20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, -20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, -20.f, 0.f }); 

	m_vVertex.push_back(D3DXVECTOR3{ -20.f, 20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 20.f, 20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 20.f, -20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -20.f, -20.f, 0.f });
}

int CYMTownMoster::Update(void)
{

	m_tInfo.vPos.y += m_fSpeed;
	Update_MatWorld();

	return OBJ_NOEVENT;
}

void CYMTownMoster::Late_Update(void)
{
}

void CYMTownMoster::Render(HDC hDC)
{
	Render_Vertex(hDC);
}

void CYMTownMoster::Release(void)
{
}

void CYMTownMoster::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
