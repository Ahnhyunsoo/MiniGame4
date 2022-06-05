#include "stdafx.h"
#include "RaserBullet.h"


CRaserBullet::CRaserBullet(D3DXVECTOR3 _DIR,CObj* pObj)
{
	m_vTarget = _DIR;
	m_pTower = pObj;
}


CRaserBullet::~CRaserBullet()
{
}

void CRaserBullet::Initialize(void)
{
	m_iHp = 100;
	m_iDamage = 1;
	m_tInfo.vDir = { -1.f,0.f,0.f };
	m_bDead = false;
	m_bRaser = false;
	m_fSpeed = 15.f;
	m_fAngle = 1.f;
	m_fScale = 1.f;
	m_LTarget = GetTickCount();

	m_vOriVertex.push_back(D3DXVECTOR3{ -5.f, -5.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 600.f, -5.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 600.f, 25.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -5.f, 25.f, 0.f });
	
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });
}

int CRaserBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	
	if (m_fScale > 0 && !m_bRaser)
	{
		m_fScale += 0.05f;
		if (m_fScale >= 2.f)
			m_bRaser = true;
	}
	else if (m_bRaser && m_fScale > 0.f)
	{
		m_fScale -= 0.05f;
		if (m_fScale <= 0.f)
			Set_Dead();
	}
	D3DXVECTOR3 vTempDir;
	
	m_vTarget = Find_Target(m_tInfo.vPos.x, m_tInfo.vPos.y) - m_tInfo.vPos;
	
	D3DXVec3Normalize
	

		/*m_vTarget = Find_Target(m_tInfo.vPos.x, m_tInfo.vPos.y);
		float Width = (m_vTarget.x - m_tInfo.vPos.x);
		float Height = (m_tInfo.vPos.y - m_vTarget.y);
		float Diagonal = sqrtf((Width * Width) + (Height * Height));
		
		m_fAngle = acosf(Width / Diagonal);
		m_fAngle = D3DXToDegree(m_fAngle);	
		if (m_tInfo.vPos.y > m_vTarget.y)
			m_fAngle *= -1.f;*/
		

	if (m_LTarget + 500 < GetTickCount())
	{

	}

	Update_MatWorld();
	

	return OBJ_NOEVENT;
}

void CRaserBullet::Late_Update(void)
{
}

void CRaserBullet::Render(HDC hDC)
{
	Render_Vertex(hDC);
}

void CRaserBullet::Release(void)
{
}

void CRaserBullet::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
