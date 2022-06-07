#include "stdafx.h"
#include "GHFloar.h"
#include "GHLineMgr.h"
#include "GHPlayer.h"
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
	else if (m_iFloarIndex == 6)
	{
		m_tInfo.vPos = { 275.f,0.f,0.f };
	}
	else if (m_iFloarIndex == 7)
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
	if(m_iFloarIndex != 6 && m_iFloarIndex != 7)
		LineOn();

}
void CGHFloar::SetReDirection()
{
	if (m_RedirectionDelayTime + 1000 < GetTickCount()) {
		if (m_bLeft) {
			m_RedirectionDelayTime = GetTickCount();
			m_bLeft = false;
		}
		else {
			m_RedirectionDelayTime = GetTickCount();
			m_bLeft = true;
		}
	}
}
void CGHFloar::Initialize(void)
{
	Initialize_Floar();
	m_eString = STRING_FLOAR;
	m_RedirectionDelayTime = 0;
	m_fSpeed = 2.f;
	m_fScale = 25.f;
	m_fAngle = 0.f;
	
	m_ScaleDelayTime = GetTickCount();
	m_bDead = false;
	m_bLeft = false;
	//CStageGH::
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
		m_fScale += 4.f;
		m_tInfo.fCX = abs(m_vVertex[0].x - m_vVertex[1].x);
		m_tInfo.fCY = abs(m_vVertex[1].y - m_vVertex[2].y);
		m_ScaleDelayTime = GetTickCount();
	}
	if (m_iFloarIndex == 0) 
		m_tInfo.vDir = { -1.f, 0.f, 0.f };
	else if (m_iFloarIndex == 1) 
		m_tInfo.vDir = { -0.6f, 0.f, 0.f };
	else if (m_iFloarIndex == 2)
		m_tInfo.vDir = { -0.2f, 0.f, 0.f };
	else if (m_iFloarIndex == 3)
		m_tInfo.vDir = { 0.2f, 0.f, 0.f };
	else if (m_iFloarIndex == 4)
		m_tInfo.vDir = { 0.6f, 0.f, 0.f };
	else if ((m_iFloarIndex == 5))
		m_tInfo.vDir = { 1.f, 0.f, 0.f };
	else if (m_iFloarIndex == 6)
	{
		m_tInfo.vDir = { 1.f, 0.5f, 0.f };

		if (m_bLeft == true)
			m_tInfo.vDir.x = -1;
		else 
			m_tInfo.vDir.x = 1;
		m_fAngle += 5.f;
		//m_fSpeed += 0.5f;

	}
	else if (m_iFloarIndex == 7)
	{
		m_tInfo.vDir = { -1.f, 0.5f, 0.f };

		if (m_bLeft == true)
			m_tInfo.vDir.x = 1;
		else
			m_tInfo.vDir.x = -1;
		m_fAngle -= 5.f;
		//m_fSpeed += 0.5f;

	}
	if (m_iFloarIndex != 6 && m_iFloarIndex != 7)
		Line_Nail_Down();
	
	if (m_bDead)
		return OBJ_DEAD;
	
	m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;


	Update_MatWorld();

	return OBJ_NOEVENT;
}

void CGHFloar::Late_Update(void)
{
}

void CGHFloar::Render(HDC hDC)
{
	if (m_iFloarIndex == 6||m_iFloarIndex == 7) {
		HPEN hpen;
		HPEN hpenOld;

		hpen = CreatePen(PS_SOLID, 3, RGB(214, 214, 10));   // 선 스타일, 굵기, 색상
		hpenOld = (HPEN)::SelectObject(hDC, (HGDIOBJ)hpen);   // 펜 선택

		Render_Vertex(hDC);

		hpen = (HPEN)SelectObject(hDC, hpenOld);   // 기존의 펜 다시 선택
		DeleteObject(hpen);   // 생성한 펜 삭제
	}
	else
		Render_Vertex(hDC);

	if (m_bFirst)
		ColRender(hDC);

}

void CGHFloar::Release(void)
{
	
}

void CGHFloar::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	if(dynamic_cast<CGHObj*>(_Other)->Get_GHString() == 0)
		if (m_iFloarIndex == 6)
			dynamic_cast<CGHPlayer*>(_Other)->Set_SkidBool();
}


