#include "stdafx.h"
#include "HRBlock.h"

CHRBlock::CHRBlock()
{
}

CHRBlock::~CHRBlock()
{
}

void CHRBlock::Set_Scale(float _fX, float _fY)
{
	m_tInfo.fCX = _fX;
	m_tInfo.fCY = _fY;
	m_fAngle = 0.f;
	m_fSpeed = 1.f;
	m_fScale = 1.f;
	m_tInfo.vDir = { -1.f,0.f,0.f };
	m_bDead = false;

	m_vOriVertex.push_back(D3DXVECTOR3{ -m_tInfo.fCX * 0.5f, -m_tInfo.fCY * 0.5f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ m_tInfo.fCX * 0.5f, -m_tInfo.fCY * 0.5f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ m_tInfo.fCX * 0.5f, m_tInfo.fCY * 0.5f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -m_tInfo.fCX * 0.5f, m_tInfo.fCY * 0.5f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });
}

void CHRBlock::Initialize(void)
{

}

int CHRBlock::Update(void)
{
	Update_MatWorld();
	return 0;
}

void CHRBlock::Late_Update(void)
{
}

void CHRBlock::Render(HDC hDC)
{
	Render_Vertex(hDC);
}

void CHRBlock::Release(void)
{
}

void CHRBlock::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
