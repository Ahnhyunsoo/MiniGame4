#include "stdafx.h"
#include "HRSwing.h"

#include "CameraMgr.h"

CSwing::CSwing()
	: m_fDeadTime(0.f)
	, m_fOldDeadTime(0.f)
	, m_fLenth(0.f)
	, m_bFirst(false)
{
}

CSwing::~CSwing()
{
}

void CSwing::Initialize(void)
{
	m_sTag = "Swing";
	m_fSpeed = 80.f;

	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fLenth = 500.f;
	m_fDeadTime = 500.f;
	m_fOldDeadTime = GetTickCount();
}

int CSwing::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	if (m_fOldDeadTime + m_fDeadTime < GetTickCount())
		m_bDead = true;

	if (m_bFirst)
	{
		m_fLenth -= 10.f;
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

void CSwing::Late_Update(void)
{
}

void CSwing::Render(HDC hDC)
{
	HPEN hpen;
	HPEN hpenOld;

	hpen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));   // 선 스타일, 굵기, 색상
	hpenOld = (HPEN)::SelectObject(hDC, (HGDIOBJ)hpen);   // 펜 선택

	int iScrollX = CCameraMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = CCameraMgr::Get_Instance()->Get_ScrollY();
	MoveToEx(hDC, m_tInfo.vPos.x + iScrollX - m_tInfo.vDir.x * m_fLenth, m_tInfo.vPos.y + iScrollY - m_tInfo.vDir.y * m_fLenth, nullptr);
	LineTo(hDC, m_tInfo.vPos.x + iScrollX + m_tInfo.vDir.x * m_fLenth, m_tInfo.vPos.y + iScrollY + m_tInfo.vDir.y * m_fLenth);

	hpen = (HPEN)SelectObject(hDC, hpenOld);   // 기존의 펜 다시 선택
	DeleteObject(hpen);   // 생성한 펜 삭제
}

void CSwing::Release(void)
{
}

void CSwing::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
