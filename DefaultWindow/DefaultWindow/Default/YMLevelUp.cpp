#include "stdafx.h"
#include "YMLevelUp.h"


CYMLevelUp::CYMLevelUp()
{
}


CYMLevelUp::~CYMLevelUp()
{
}

void CYMLevelUp::Initialize(void)
{
	m_fAngle = 1.f;
	m_fSpeed = 1.f;
	m_fScale = 2.f;
	m_bDead = false;

	m_sTag = "levelup";

	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -3.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -3.f, 10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 3.f, 10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 3.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, 10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, 0.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 0.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -3.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -3.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 3.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 3.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 0.f, 0.f });
}

int CYMLevelUp::Update(void)
{
	m_tInfo.vPos.y += m_fSpeed;
	Update_MatWorld();


	if (m_bDead)
		return OBJ_DEAD;
	else
		return OBJ_NOEVENT;
}

void CYMLevelUp::Late_Update(void)
{

}

void CYMLevelUp::Render(HDC hDC)
{
	Render_Vertex(hDC);
}

void CYMLevelUp::Release(void)
{
}

void CYMLevelUp::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	CObjYM* temp = (CObjYM*)_Other;
	if (temp->Get_Tag() == "player")
		Set_Dead();
}
