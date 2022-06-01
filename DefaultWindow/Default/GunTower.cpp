#include "stdafx.h"
#include "GunTower.h"
#include "ObjMgr.h"
#include "HSBullet.h"
#include "CAbstractFactory.h"

CGunTower::CGunTower()
	:m_LBullet(GetTickCount())
{
}


CGunTower::~CGunTower()
{
}


void CGunTower::Initialize(void)
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;
	m_tInfo.vPos = { 400.f,300.f,0.f };
	m_vTarget = { 0.f,0.f,0.f };
	m_fAngle = 0.f;
	m_fSpeed = 1.f;
	m_fScale = 1.f;
	m_tInfo.vDir = { 1.f,0.f,0.f };
	m_bDead = false;
	m_bBattle = false;

	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, 10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });
}

int CGunTower::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	
	if (CObjMgr::Get_Instance()->Get_ObjList(OBJ_MONSTER).empty())
		m_bBattle = false;
	else
		m_bBattle = true;


	
	


	//m_tInfo.vPos += m_tInfo.vDir * 3;
	//m_fAngle += cos(m_tInfo.vDir.x);

	Update_MatWorld();
	m_vTarget = Find_Target(m_tInfo.vPos.x, m_tInfo.vPos.y);
	m_tInfo.vDir = m_vTarget - m_tInfo.vPos;
	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);

	if (m_bBattle)
	{
		if (m_LBullet + 300 < GetTickCount())
		{
			CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CHSBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x, m_tInfo.vPos.y));
			m_LBullet = GetTickCount();
		}
	}

	return OBJ_NOEVENT;
}

void CGunTower::Late_Update(void)
{
}

void CGunTower::Render(HDC hDC)
{
	
	

	Render_Vertex(hDC);
	MoveToEx(hDC, (int)m_tInfo.vPos.x, (int)m_tInfo.vPos.y, nullptr);
	LineTo(hDC, int(m_tInfo.vPos.x + m_tInfo.vDir.x * 30.f), int(m_tInfo.vPos.y + m_tInfo.vDir.y * 30.f));
	//LineTo(hDC, int(m_tInfo.vPos.x + m_fAngle * 1.f), int(m_tInfo.vPos.y + m_fAngle * 1.f));
}

void CGunTower::Release(void)
{
}

void CGunTower::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
