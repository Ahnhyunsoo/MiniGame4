#include "stdafx.h"
#include "YMLazer.h"



CYMLazer::CYMLazer(D3DXVECTOR3 _Dir)
{
	m_tInfo.vDir = _Dir;
}

CYMLazer::~CYMLazer()
{
}

void CYMLazer::Initialize(void)
{
	m_iCount = GetTickCount();

}

int CYMLazer::Update(void)
{
	m_tInfo.vPos.x += m_tInfo.vDir.x * 20;
	m_tInfo.vPos.y += m_tInfo.vDir.y * 20;
	return OBJ_NOEVENT;
}

void CYMLazer::Late_Update(void)
{
}

void CYMLazer::Render(HDC hDC)
{

	if (m_iCount + 20 < GetTickCount())
	{
		MoveToEx(hDC, m_tInfo.vPos.x - 40, m_tInfo.vPos.y + 30, nullptr);
		LineTo(hDC, m_tInfo.vPos.x - 40, m_tInfo.vPos.y - 30);

		MoveToEx(hDC, m_tInfo.vPos.x + 40, m_tInfo.vPos.y + 30, nullptr);
		LineTo(hDC, m_tInfo.vPos.x + 40, m_tInfo.vPos.y - 30);
	}

}

void CYMLazer::Release(void)
{
}

void CYMLazer::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
