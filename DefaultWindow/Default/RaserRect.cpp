#include "stdafx.h"
#include "RaserRect.h"


CRaserRect::CRaserRect(D3DXVECTOR3 _DIR)
{
	m_tInfo.vDir = _DIR;
	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
}


CRaserRect::~CRaserRect()
{
}

void CRaserRect::Initialize(void)
{
	m_iHp = 1000;
	m_iDamage = 1;
	m_bDead = false;
	m_fSpeed = 30.f;
	m_fAngle = 1.f;
}

int CRaserRect::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	m_tInfo.vPos.y += m_tInfo.vDir.y * m_fSpeed;
	m_tInfo.vPos.x += m_tInfo.vDir.x * m_fSpeed;
	if (m_tInfo.vPos.x >= WINCX || m_tInfo.vPos.x <= 0
		|| m_tInfo.vPos.y >= WINCY || m_tInfo.vPos.y <= 0)
		Set_Dead();
	return OBJ_NOEVENT;
}

void CRaserRect::Late_Update(void)
{
}

void CRaserRect::Render(HDC hDC)
{
	//Ellipse(hDC, (int)m_tInfo.vPos.x - 15, (int)m_tInfo.vPos.y - 15, (int)m_tInfo.vPos.x + 15, (int)m_tInfo.vPos.y + 15);
}

void CRaserRect::Release(void)
{
}

void CRaserRect::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
