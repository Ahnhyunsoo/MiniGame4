#include "stdafx.h"
#include "HSBullet.h"


CHSBullet::CHSBullet(D3DXVECTOR3 _DIR)
{
	m_tInfo.vDir = _DIR;
}


CHSBullet::~CHSBullet()
{
}

void CHSBullet::Initialize(void)
{
	m_bDead = false;
}

int CHSBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	m_tInfo.vPos.x += m_tInfo.vDir.x * 2;
	m_tInfo.vPos.y += m_tInfo.vDir.y * 2;
	return OBJ_NOEVENT;
}

void CHSBullet::Late_Update(void)
{
}

void CHSBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tInfo.vPos.x - 5, m_tInfo.vPos.y - 5, m_tInfo.vPos.x + 5, m_tInfo.vPos.y + 5);
}

void CHSBullet::Release(void)
{
}

void CHSBullet::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
