#include "stdafx.h"
#include "GHFloar.h"
#include "GHLineMgr.h"

CGHFloar::CGHFloar()
{
}


CGHFloar::~CGHFloar()
{
	Release();
}
void CGHFloar::Initialize_Floar()
{// 275, 325, 375, 425, 475, 525
	if (m_iFloarIndex == 0)
	{
		m_tInfo.vPos = { 275.f,0.f,0.f };
	}
	else if (m_iFloarIndex == 1)
	{
		m_tInfo.vPos = { 325.f,0.f,0.f };
	}
	else if (m_iFloarIndex == 2)
	{
		m_tInfo.vPos = { 375.f,0.f,0.f };
	}
	else if (m_iFloarIndex == 3)
	{
		m_tInfo.vPos = { 425.f,0.f,0.f };
	}
	else if (m_iFloarIndex == 4)
	{
		m_tInfo.vPos = { 475.f,0.f,0.f };
	}
	else if (m_iFloarIndex == 5)
	{
		m_tInfo.vPos = { 525.f,0.f,0.f };
	}
	m_vOriVertex.push_back(D3DXVECTOR3{ -1.f	, -1.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 1.f	, -1.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 1.f	, 1.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -1.f	, 1.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -1.f, -1.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 1.f, -1.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 1.f, 1.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -1.f, 1.f, 0.f });
	
	LineOn();

}
void CGHFloar::Initialize(void)
{
	Initialize_Floar();
	m_fSpeed = 3.f;
	m_fScale = 25.f;
	m_fAngle = 0.f;
	m_ScaleDelayTime = GetTickCount();
	m_bDead = false;
}
void CGHFloar::LineOn()
{
	float		fY = 0.f;

	bool		bLineCol = CGHLineMgr::Get_Instance()->Collision_Line(m_tInfo.vPos.x, &fY, m_KyuLine,m_iFloarIndex);
	if (bLineCol)
	{
		m_tInfo.vPos.y = fY;
	}
}

void CGHFloar::Line_Nail_Down()
{
	float		fY = 0.f;

	float	x1 = m_KyuLine.Get_Info().tLPoint.x;
	float	x2 = m_KyuLine.Get_Info().tRPoint.x;

	float	y1 = m_KyuLine.Get_Info().tLPoint.y;
	float	y2 = m_KyuLine.Get_Info().tRPoint.y;

	fY = (((y2 - y1) / (x2 - x1)) * (m_tInfo.vPos.x - x1)) + y1;
	m_tInfo.vPos.y = fY;
}
int CGHFloar::Update(void)
{
	if ((m_fScale < 66.5f)&&(m_ScaleDelayTime + 100 <GetTickCount())) {
		++m_fScale;
		m_ScaleDelayTime = GetTickCount();
	}
	if (m_iFloarIndex == 0) 
		m_tInfo.vDir = { -1.f, 0.f, 0.f };
	else if (m_iFloarIndex == 1) 
		m_tInfo.vDir = { -0.5f, 0.f, 0.f };
	else if (m_iFloarIndex == 2)
		m_tInfo.vDir = { -0.3f, 0.f, 0.f };
	else if (m_iFloarIndex == 3)
		m_tInfo.vDir = { 0.3f, 0.f, 0.f };
	else if (m_iFloarIndex == 4)
		m_tInfo.vDir = { 0.5f, 0.f, 0.f };
	else if (m_iFloarIndex == 5)
		m_tInfo.vDir = { 1.f, 0.f, 0.f };

	Line_Nail_Down();
	if (m_bDead)
		return OBJ_DEAD;
	m_tInfo.vPos += m_tInfo.vDir ;


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


