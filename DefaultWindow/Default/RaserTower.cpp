#include "stdafx.h"
#include "RaserTower.h"
#include "ObjMgr.h"
#include "RaserBullet.h"
#include "CAbstractFactory.h"


CRaserTower::CRaserTower()
	:m_LBullet(GetTickCount()), m_iShotDelay(1000)
{
}


CRaserTower::~CRaserTower()
{
}

void CRaserTower::Initialize(void)
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;
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

int CRaserTower::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	if (CObjMgr::Get_Instance()->Get_ObjList(OBJ_MONSTER).empty())
		m_bBattle = false;
	else
		m_bBattle = true;

	Update_MatWorld();
	
	m_vTarget = Find_Target(m_tInfo.vPos.x, m_tInfo.vPos.y);
	m_tInfo.vDir = m_vTarget - m_tInfo.vPos;
	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);

	if (m_bBattle)
	{
		Create_Bullet();
	}

	return OBJ_NOEVENT;
}

void CRaserTower::Late_Update(void)
{
}

void CRaserTower::Render(HDC hDC)
{
	
	Render_Vertex(hDC);
	MoveToEx(hDC, (int)m_tInfo.vPos.x, (int)m_tInfo.vPos.y, nullptr);
	LineTo(hDC, int(m_tInfo.vPos.x + m_tInfo.vDir.x * m_fScale * 30.f), int(m_tInfo.vPos.y + m_tInfo.vDir.y * m_fScale * 30.f));
	LineTo(hDC, int(m_tInfo.vPos.x + m_tInfo.vDir.x * m_fScale * 30.f), int(m_tInfo.vPos.y + m_tInfo.vDir.y * m_fScale * 15.f));
	LineTo(hDC, int(m_tInfo.vPos.x), int(m_tInfo.vPos.y + m_tInfo.vDir.y * m_fScale * -15.f));
	LineTo(hDC, int(m_tInfo.vPos.x), int(m_tInfo.vPos.y ));
}

void CRaserTower::Release(void)
{
}

void CRaserTower::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}

void CRaserTower::Create_Bullet(void)
{
	if (m_LBullet + m_iShotDelay < GetTickCount())
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CRaserBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x + m_tInfo.vDir.x * m_fScale * 30.f, m_tInfo.vPos.y + m_tInfo.vDir.y * m_fScale * 30.f,this));
		m_LBullet = GetTickCount();
	}
}