#include "stdafx.h"
#include "HRBullet.h"

#include "CameraMgr.h"
#include "TimeMgr.h"

CHRBullet::CHRBullet()
	: m_fDeadTime(0.f)
	, m_fOldDeadTime(0.f)
	, m_fLenth(0.f)
	, m_bFirst(false)
	, m_bPadding(false)
{
}

CHRBullet::~CHRBullet()
{
}

void CHRBullet::Initialize(void)
{
	m_sTag = "Bullet";
	m_fSpeed = 10.f;

	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fLenth = 10.f;
	m_fDeadTime = 10000.f;
	m_fOldDeadTime = GetTickCount();
}

int CHRBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	if (m_fOldDeadTime + m_fDeadTime + CTimeMgr::Get_Instance()->Get_DelaySecond() < GetTickCount())
		m_bDead = true;

	if (m_bFirst)
	{
		m_tInfo.vPos.x += m_tInfo.vDir.x * m_fSpeed;
		m_tInfo.vPos.y += m_tInfo.vDir.y * m_fSpeed;
	}
	else
	{
		m_tInfo.vPos.x -= m_tInfo.vDir.x * m_fSpeed;
		m_tInfo.vPos.y -= m_tInfo.vDir.y * m_fSpeed;
		m_bFirst = true;
	}


	return OBJ_NOEVENT;
}

void CHRBullet::Late_Update(void)
{
}

void CHRBullet::Render(HDC hDC)
{
	HPEN hpen;
	HPEN hpenOld;

	hpen = CreatePen(PS_SOLID, 4, RGB(200, 200, 50));   // 선 스타일, 굵기, 색상
	hpenOld = (HPEN)::SelectObject(hDC, (HGDIOBJ)hpen);   // 펜 선택

	int iScrollX = CCameraMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = CCameraMgr::Get_Instance()->Get_ScrollY();
	MoveToEx(hDC, m_tInfo.vPos.x + iScrollX - m_tInfo.vDir.x * m_fLenth, m_tInfo.vPos.y + iScrollY - m_tInfo.vDir.y * m_fLenth, nullptr);
	LineTo(hDC, m_tInfo.vPos.x + iScrollX + m_tInfo.vDir.x * m_fLenth, m_tInfo.vPos.y + iScrollY + m_tInfo.vDir.y * m_fLenth);

	hpen = (HPEN)SelectObject(hDC, hpenOld);   // 기존의 펜 다시 선택
	DeleteObject(hpen);   // 생성한 펜 삭제
}

void CHRBullet::Release(void)
{
}

void CHRBullet::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
