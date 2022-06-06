#include "stdafx.h"
#include "YMMonsterBullet.h"
#include "ObjMgr.h"


CYMMonsterBullet::CYMMonsterBullet(D3DXVECTOR3 _Dir, DIRECTION _Num)
{
	m_tInfo.vDir = _Dir;
	m_iNum = _Num;
}

CYMMonsterBullet::CYMMonsterBullet(D3DXVECTOR3 _Dir)
{
	m_tInfo.vDir = _Dir;
}

CYMMonsterBullet::~CYMMonsterBullet()
{
}

void CYMMonsterBullet::Initialize(void)
{
	m_tInfo.fCX = 10;
	m_tInfo.fCY = 10;

	m_fSpeed = 1.f;
	m_sTag = "monsterbullet";
	m_bDead = false;

	if (m_iNum == DIR_LEFT)
	{
		m_tInfo.vDir = { -1.f,1.f,0.f };
	}
	else if (m_iNum == DIR_DOWN)
	{
		m_tInfo.vDir = { 0.f,1.f,0.f };
	}
	else if (m_iNum == DIR_RIGHT)
	{
		m_tInfo.vDir = { 1.f,1.f,0.f };
	}
}

int CYMMonsterBullet::Update(void)
{
	m_tInfo.vPos.x += m_tInfo.vDir.x * 5;
	m_tInfo.vPos.y += m_tInfo.vDir.y * 5;

	if (m_tInfo.vPos.y > 600 || m_tInfo.vPos.y < 0 || m_tInfo.vPos.x > 800 || m_tInfo.vPos.x < 0 || m_bDead)
		return OBJ_DEAD;
	else
		return OBJ_NOEVENT;
}

void CYMMonsterBullet::Late_Update(void)
{
}

void CYMMonsterBullet::Render(HDC hDC)
{
	Ellipse(hDC, (int)m_tInfo.vPos.x - 5, (int)m_tInfo.vPos.y - 5, (int)m_tInfo.vPos.x + 5, (int)m_tInfo.vPos.y + 5);
}

void CYMMonsterBullet::Release(void)
{
}

void CYMMonsterBullet::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	CObjYM* temp = (CObjYM*)_Other;

	if (temp->Get_Tag() == "player")
		Set_Dead();

	else if (temp->Get_Tag() == "boom")
		Set_Dead();
}
