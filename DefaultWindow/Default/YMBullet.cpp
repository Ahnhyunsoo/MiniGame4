#include "stdafx.h"
#include "YMBullet.h"


CYMBullet::CYMBullet(D3DXVECTOR3 _Dir)
{
	m_tInfo.vDir = _Dir;
}

CYMBullet::~CYMBullet()
{
}

void CYMBullet::Initialize(void)
{
	m_iCount = GetTickCount();
}

int CYMBullet::Update(void)
{
	m_tInfo.vPos.x += m_tInfo.vDir.x * 20;
	m_tInfo.vPos.y += m_tInfo.vDir.y * 20;
	return OBJ_NOEVENT;
}

void CYMBullet::Late_Update(void)
{
}

void CYMBullet::Render(HDC hDC)
{
	if(m_iCount + 20 < GetTickCount())
		Ellipse(hDC, m_tInfo.vPos.x - 5, m_tInfo.vPos.y - 50, m_tInfo.vPos.x + 5, m_tInfo.vPos.y + 10);
}

void CYMBullet::Release(void)
{
}

void CYMBullet::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
