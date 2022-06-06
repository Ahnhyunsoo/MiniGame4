#include "stdafx.h"
#include "YMHeal.h"
#include "BmpMgr.h"


CYMHeal::CYMHeal()
{
}


CYMHeal::~CYMHeal()
{
}

void CYMHeal::Initialize(void)
{
	m_fAngle = 1.f;
	m_fSpeed = 1.f;
	m_fScale = 0.5f;
	m_bDead = false;
	m_sTag = "heal";

	m_vOriVertex.push_back(D3DXVECTOR3(50.f, 0.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(-25.f, -50.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(-40.f, -7.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(-50.f, -5.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(-40.f, 0.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(50.f, 0.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(-25.f, 50.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(-40.f, 5.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(-50.f, -5.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(-40.f, 5.f, 0.f));


	m_vVertex.push_back(D3DXVECTOR3(50.f, 0.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-25.f, -50.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-40.f, -7.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-50.f, -5.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-39.f, 0.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-50.f, -5.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-25.f, 50.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-40.f, 5.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-50.f, -5.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-40.f, 5.f, 0.f));
}

int CYMHeal::Update(void)
{
	m_tInfo.vPos.y += m_fSpeed;
	Update_MatWorld();

	if (m_bDead)
		return OBJ_DEAD;
	else
		return OBJ_NOEVENT;
}

void CYMHeal::Late_Update(void)
{
}

void CYMHeal::Render(HDC hDC)
{
	HPEN hpen;
	HPEN hpenOld;
	hpen = CreatePen(PS_SOLID, 3, RGB(255, 100, 0));
	hpenOld = (HPEN)::SelectObject(hDC, (HGDIOBJ)hpen);

	int iScrollY = CScrollMgr::Get_Instance()->Get_ScrollY();
	MoveToEx(hDC, (int)m_vVertex[0].x + iScrollY, (int)m_vVertex[0].y, nullptr);
	for (size_t i = 1; i < m_vVertex.size(); ++i)
	{
		LineTo(hDC, (int)m_vVertex[i].x + iScrollY, (int)m_vVertex[i].y);
	}
	LineTo(hDC, (int)m_vVertex[0].x + iScrollY, (int)m_vVertex[0].y);

	hpen = (HPEN)::SelectObject(hDC, hpenOld);
	DeleteObject(hpen);
}

void CYMHeal::Release(void)
{
}

void CYMHeal::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	CObjYM* temp = (CObjYM*)_Other;
	if (temp->Get_Tag() == "player")
		Set_Dead();
}
