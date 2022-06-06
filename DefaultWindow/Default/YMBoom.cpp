#include "stdafx.h"
#include "YMBoom.h"



CYMBoom::CYMBoom(D3DXVECTOR3 _Dir)
{
	m_tInfo.vDir = _Dir;
}

CYMBoom::~CYMBoom()
{
}

void CYMBoom::Initialize(void)
{
	m_tInfo.fCX = WINCX;
	m_tInfo.fCY = 200;

	m_fAngle = 1.f;
	m_fSpeed = 1.f;
	m_fScale = 5.f;
	m_sTag = "boom";


	m_vOriVertex.push_back(D3DXVECTOR3{ 5.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 38.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 5.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 38.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 40.f, -20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 5.f, -20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 5.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 5.f, -35.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 3.f, -40.f, 0.f });

	m_vOriVertex.push_back(D3DXVECTOR3{ -3.f, -40.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -5.f, -35.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -5.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -5.f, -20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -40.f, -20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -38.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -5.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -38.f, -10.f, 0.f });

	m_vOriVertex.push_back(D3DXVECTOR3{ -5.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -5.f, 20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -3.f, 30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -5.f, 20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -15.f, 27.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -15.f, 30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 15.f, 30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 15.f, 27.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 5.f, 20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 3.f, 30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -3.f, 30.f, 0.f });	//맨아래

	m_vOriVertex.push_back(D3DXVECTOR3{ -1.f, 30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, 15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 1.f, 30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -3.f, 30.f, 0.f });

	m_vOriVertex.push_back(D3DXVECTOR3{ -2.f, 33.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 2.f, 33.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 3.f, 30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -3.f, 30.f, 0.f });

	m_vOriVertex.push_back(D3DXVECTOR3{ 3.f, 30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 5.f, 20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 5.f, 0.f, 0.f });



	m_vVertex.push_back(D3DXVECTOR3{ 5.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 38.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 5.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 38.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 40.f, -20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 5.f, -20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 5.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 5.f, -35.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 3.f, -40.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -3.f, -40.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -5.f, -35.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -5.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -5.f, -20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -40.f, -20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -38.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -5.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -38.f, -10.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -5.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -5.f, 20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -3.f, 30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -5.f, 20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -15.f, 27.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -15.f, 30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 15.f, 30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 15.f, 27.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 5.f, 20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 3.f, 30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -3.f, 30.f, 0.f });	//맨아래

	m_vVertex.push_back(D3DXVECTOR3{ -1.f, 30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 0.f, 15.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 1.f, 30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -3.f, 30.f, 0.f });


	m_vVertex.push_back(D3DXVECTOR3{ -2.f, 33.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 2.f, 33.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 3.f, 30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -3.f, 30.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ 3.f, 30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 5.f, 20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 5.f, 0.f, 0.f });
}

int CYMBoom::Update(void)
{
	m_tInfo.vPos.y -= m_fSpeed;

	Update_MatWorld();


	if (m_tInfo.vPos.y >= 1200)
	{
		return OBJ_DEAD;
	}
	else
		return OBJ_NOEVENT;
}

void CYMBoom::Late_Update(void)
{
}

void CYMBoom::Render(HDC hDC)
{
	Render_Vertex(hDC);
}

void CYMBoom::Release(void)
{
}

void CYMBoom::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
