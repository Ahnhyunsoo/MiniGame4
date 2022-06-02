#include "stdafx.h"
#include "GHFloar.h"


CGHFloar::CGHFloar()
{
}


CGHFloar::~CGHFloar()
{
	Release();
}
void CGHFloar::Initialize_Floar()
{
	if (m_iFloarIndex == 0)
	{
		/*m_vOriVertex.push_back(D3DXVECTOR3{ -300.f	, -300.f, 0.f });
		m_vOriVertex.push_back(D3DXVECTOR3{ 300.f	, -300.f, 0.f });
		m_vOriVertex.push_back(D3DXVECTOR3{ 350.f	, 300.f, 0.f });
		m_vOriVertex.push_back(D3DXVECTOR3{ -350.f	, 300.f, 0.f });

		m_vVertex.push_back(D3DXVECTOR3{ -300.f, -300.f, 0.f });
		m_vVertex.push_back(D3DXVECTOR3{ 300.f, -300.f, 0.f });
		m_vVertex.push_back(D3DXVECTOR3{ 350.f, 300.f, 0.f });
		m_vVertex.push_back(D3DXVECTOR3{ -350.f, 300.f, 0.f });*/
		
	}
}
void CGHFloar::Initialize(void)
{
	Initialize_Floar();
	m_fScale = 0.f;
	m_bDead = false;
}

int CGHFloar::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	
	Update_MatWorld();

	return OBJ_NOEVENT;
}

void CGHFloar::Late_Update(void)
{
}

void CGHFloar::Render(HDC hDC)
{
	Render_Vertex(hDC);

}

void CGHFloar::Release(void)
{
}

void CGHFloar::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}


