#include "stdafx.h"
#include "YMIBoom.h"


CYMIBoom::CYMIBoom()
{
}


CYMIBoom::~CYMIBoom()
{
}

void CYMIBoom::Initialize(void)
{
	m_fAngle = 1.f;
	m_fSpeed = 1.f;
	m_fScale = 3.f;
	m_tInfo.fCX = 50;
	m_tInfo.fCY = 50;
	m_bDead = false;
	m_sTag = "Iboom";

	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 6.f, -6.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 18.f, -6.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, -2.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 24.f, -6.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 24.f, -2.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 22.f, -2.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 24.f, -2.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 24.f, 2.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 22.f, 2.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 24.f, 2.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 24.f, 6.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, 2.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 18.f, 6.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 6.f, 6.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, 0.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ 0.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 6.f, -6.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 18.f, -6.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 20.f, -2.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 24.f, -6.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 24.f, -2.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 22.f, -2.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 24.f, -2.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 24.f, 2.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 22.f, 2.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 24.f, 2.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 24.f, 6.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 20.f, 2.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 18.f, 6.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 6.f, 6.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 0.f, 0.f, 0.f });



	//MoveToEx(hDC, (int)m_vBoom.x, (int)m_vBoom.y, nullptr);
	//LineTo(hDC, (int)m_vBoom.x + 6, (int)m_vBoom.y - 6);
	//LineTo(hDC, (int)m_vBoom.x + 18, (int)m_vBoom.y - 6);
	//LineTo(hDC, (int)m_vBoom.x + 20, (int)m_vBoom.y - 2);
	//LineTo(hDC, (int)m_vBoom.x + 24, (int)m_vBoom.y - 6);
	//LineTo(hDC, (int)m_vBoom.x + 24, (int)m_vBoom.y - 2);
	//LineTo(hDC, (int)m_vBoom.x + 22, (int)m_vBoom.y - 2);
	//LineTo(hDC, (int)m_vBoom.x + 24, (int)m_vBoom.y - 2);
	//LineTo(hDC, (int)m_vBoom.x + 24, (int)m_vBoom.y + 2);
	//LineTo(hDC, (int)m_vBoom.x + 22, (int)m_vBoom.y + 2);
	//LineTo(hDC, (int)m_vBoom.x + 24, (int)m_vBoom.y + 2);
	//LineTo(hDC, (int)m_vBoom.x + 24, (int)m_vBoom.y + 6);
	//LineTo(hDC, (int)m_vBoom.x + 20, (int)m_vBoom.y + 2);
	//LineTo(hDC, (int)m_vBoom.x + 18, (int)m_vBoom.y + 6);
	//LineTo(hDC, (int)m_vBoom.x + 6, (int)m_vBoom.y + 6);
	//LineTo(hDC, (int)m_vBoom.x, (int)m_vBoom.y);
}

int CYMIBoom::Update(void)
{
	m_tInfo.vPos.y += m_fSpeed;
	Update_MatWorld();

	if (m_bDead)
		return OBJ_DEAD;
	else
		return OBJ_NOEVENT;
}

void CYMIBoom::Late_Update(void)
{
}

void CYMIBoom::Render(HDC hDC)
{
	HPEN hpen;
	HPEN hpenOld;
	hpen = CreatePen(PS_SOLID, 3, RGB(70, 73, 100));
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

void CYMIBoom::Release(void)
{
}

void CYMIBoom::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	CObjYM* temp = (CObjYM*)_Other;
	if (temp->Get_Tag() == "player")
		Set_Dead();
}
