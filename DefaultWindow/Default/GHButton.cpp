#include "stdafx.h"
#include "GHButton.h"


CGHButton::CGHButton()
{
}


CGHButton::~CGHButton()
{
	Release();
}

void CGHButton::Initialize(void)
{
	m_vOriVertex.push_back(D3DXVECTOR3{ -40.f	, -40.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 40.f	, -40.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 66.65f	, 66.65f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -66.65f	, 66.65f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -40.f, -40.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 40.f, -40.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 66.65f, 66.65f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -66.65f, 66.65f, 0.f });
	m_fSpeed = 1.f;
	m_fScale = 1.f;
	m_fAngle = 0.f;
	m_bDead = false;
	m_bPress = false;
	m_tInfo.vDir = { 1.f,1.f,1.f };
	m_tInfo.fCX = 133.3f;
	m_tInfo.fCY = 50.f;
}

int CGHButton::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	/*m_tInfo.vPos += m_tInfo.vDir;*/


	Update_MatWorld();
	m_bPress = false;

	return OBJ_NOEVENT;
}

void CGHButton::Late_Update(void)
{
}

void CGHButton::Render(HDC hDC)
{
	if(m_bPress)
		Render_Vertex(hDC);

}

void CGHButton::Release(void)
{
}

void CGHButton::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
