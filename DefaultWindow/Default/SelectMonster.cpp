#include "stdafx.h"
#include "SelectMonster.h"


CSelectMonster::CSelectMonster()
{
}


CSelectMonster::~CSelectMonster()
{
}

void CSelectMonster::Initialize(void)
{
	m_bDead = false;
	m_fSpeed = 2.f;
}

int CSelectMonster::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	m_tInfo.vPos.x += m_fSpeed;
	return OBJ_NOEVENT;
}

void CSelectMonster::Late_Update(void)
{
}

void CSelectMonster::Render(HDC hDC)
{
	int iScrollX = CScrollMgr::Get_Instance()->Get_ScrollX();
	Rectangle(hDC, m_tInfo.vPos.x - 15 + iScrollX, m_tInfo.vPos.y - 10, m_tInfo.vPos.x + 15 + iScrollX, m_tInfo.vPos.y + 10);
	
}

void CSelectMonster::Release(void)
{
	
}

void CSelectMonster::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
