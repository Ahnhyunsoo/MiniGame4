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
	m_tInfo.fCX = 10;
	m_tInfo.fCY = 100;

	m_iCount = GetTickCount();
	m_sTag = "bullet";
	m_bDead = false;
	m_bText = false;



	m_iCountText = 0;
}

int CYMBullet::Update(void)
{
	m_tInfo.vPos.x += m_tInfo.vDir.x * 20;
	m_tInfo.vPos.y += m_tInfo.vDir.y * 40;

	if (m_tInfo.vPos.y > 600 || m_tInfo.vPos.y < 0 || m_tInfo.vPos.x > 800 || m_tInfo.vPos.x < 0 || m_bDead)
		return OBJ_DEAD;
	else
		return OBJ_NOEVENT;
}

void CYMBullet::Late_Update(void)
{
	if (m_bText && m_iCountText == 0)
	{
		m_iCountText = GetTickCount();
	}

	else if (((m_iCountText + 300) < GetTickCount()) && m_bText)
	{
		m_bDead = true;
	}
}

void CYMBullet::Render(HDC hDC)
{
	if (m_iCount + 20 <= (int)GetTickCount())
	{
		if (m_bText)
		{
			TCHAR mName[5];
			wsprintf(mName, TEXT("10"));
			TextOut(hDC, (int)m_tInfo.vPos.x - 20, (int)m_tInfo.vPos.y - 35, mName, lstrlen(mName));
			m_tInfo.vDir.x = 0;
			m_tInfo.vDir.y = 0;
		}
		else
		{
			MoveToEx(hDC, (int)m_tInfo.vPos.x - 5, (int)m_tInfo.vPos.y - 6, nullptr);
			LineTo(hDC, (int)m_tInfo.vPos.x + 5, (int)m_tInfo.vPos.y + 10);
		}
	}
}

void CYMBullet::Release(void)
{
}

void CYMBullet::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	CObjYM* temp = (CObjYM*)_Other;

	if (temp->Get_Tag() ==  "monster" )
		m_bText = true;
}
