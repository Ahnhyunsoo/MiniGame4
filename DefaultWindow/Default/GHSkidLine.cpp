#include "stdafx.h"
#include "GHSkidLine.h"


CGHSkidLine::CGHSkidLine()
{
}

CGHSkidLine::CGHSkidLine(bool _bLeft,float _fPlayerCX)
{
	m_bLeft = _bLeft;
	m_fPlayerCX = _fPlayerCX;
}


CGHSkidLine::~CGHSkidLine()
{
	Release();

}
void CGHSkidLine::InitialSkidLineDirecton()
{//플레이어가 닿는 첫 부분이 레프트
	m_vOriVertex.push_back(D3DXVECTOR3{ -2.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 2.f, -1.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 2.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -2.f, +1.f, 0.f });

	for (int i = 0; i < 4; ++i)
		m_vVertex[i] = m_vOriVertex[i];
}
void CGHSkidLine::InitialReDirection()
{
	m_vOriVertex[0].x = 67.75f;
	m_vOriVertex[1].x = 733.25f;
	m_vOriVertex[2].x = 733.25f;
	m_vOriVertex[3].x = 67.75f;
	for (int i = 0; i < 4; ++i)
		m_vVertex[i] = m_vOriVertex[i];
}
void CGHSkidLine::Initialize(void)
{
	InitialSkidLineDirecton();
	if (m_bLeft)
		m_fScale = m_fPlayerCX;
	else
		m_fScale = -m_fPlayerCX;
	InitialReDirection();
	m_tInfo.vDir = { 0.f,1.f, 0.f };
	m_fAngle = 0.f;  
}

int CGHSkidLine::Update(void)
{
	return 0;
}

void CGHSkidLine::Late_Update(void)
{
}

void CGHSkidLine::Render(HDC hDC)
{
}

void CGHSkidLine::Release(void)
{
}

void CGHSkidLine::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
