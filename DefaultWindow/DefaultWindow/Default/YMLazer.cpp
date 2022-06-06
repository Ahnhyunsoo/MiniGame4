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
	m_sTag = "lazer";

	m_bDead = false;
}

int CYMLazer::Update(void)
{
	m_tInfo.vPos.x += m_tInfo.vDir.x * 20;
	m_tInfo.vPos.y += m_tInfo.vDir.y * 20;


	if (m_tInfo.vPos.y > 600 || m_tInfo.vPos.y < 0 || m_tInfo.vPos.x > 800 || m_tInfo.vPos.x < 0 )
		return OBJ_DEAD;
	else
		return OBJ_NOEVENT;
}

void CYMLazer::Late_Update(void)
{
}

void CYMLazer::Render(HDC hDC)
{
	HPEN hpen;
	HPEN hpenOld;

	hpen = CreatePen(PS_SOLID, 100, RGB(201, 255, 0));   // 선 스타일, 굵기, 색상
	hpenOld = (HPEN)::SelectObject(hDC, (HGDIOBJ)hpen);   // 펜 선택

	int iScrollX = CScrollMgr::Get_Instance()->Get_ScrollX();
	if (m_iCount + 20 < GetTickCount())
	{
		MoveToEx(hDC, (int)m_tInfo.vPos.x - 40, (int)m_tInfo.vPos.y + 30, nullptr);
		LineTo(hDC, (int)m_tInfo.vPos.x - 40, (int)m_tInfo.vPos.y - 30);
		MoveToEx(hDC, (int)m_tInfo.vPos.x + 40, (int)m_tInfo.vPos.y + 30, nullptr);
		LineTo(hDC, (int)m_tInfo.vPos.x + 40, (int)m_tInfo.vPos.y - 30);
	}

	hpen = (HPEN)SelectObject(hDC, hpenOld);   // 기존의 펜 다시 선택
	DeleteObject(hpen);   // 생성한 펜 삭제

}

void CYMLazer::Release(void)
{
}

void CYMLazer::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	CObjYM* temp = (CObjYM*)_Other;

	if (temp->Get_Tag() != "player")
		Set_Dead();
}
