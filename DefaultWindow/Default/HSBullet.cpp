#include "stdafx.h"
#include "HSBullet.h"


CHSBullet::CHSBullet(D3DXVECTOR3 _DIR, CObj* pObj)
{
	m_tInfo.vDir = _DIR;
}


CHSBullet::~CHSBullet()
{
}

void CHSBullet::Initialize(void)
{
	m_iHp = 1;
	m_iDamage = 1;
	m_bDead = false;
	m_fSpeed = 15.f;
	
}

int CHSBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	m_tInfo.vPos.y += m_tInfo.vDir.y * m_fSpeed;
	m_tInfo.vPos.x += m_tInfo.vDir.x * m_fSpeed;
	return OBJ_NOEVENT;
}

void CHSBullet::Late_Update(void)
{
}

void CHSBullet::Render(HDC hDC)
{
	Ellipse(hDC, (int)m_tInfo.vPos.x - 10, (int)m_tInfo.vPos.y - 10, (int)m_tInfo.vPos.x + 10, (int)m_tInfo.vPos.y + 10);
}

void CHSBullet::Release(void)
{
}

void CHSBullet::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	Set_Dead();
}
