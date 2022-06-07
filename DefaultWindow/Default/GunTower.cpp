#include "stdafx.h"
#include "GunTower.h"
#include "ObjMgr.h"
#include "HSBullet.h"
#include "CAbstractFactory.h"
#include "SoundMgr.h"

CGunTower::CGunTower()
	:m_LBullet(GetTickCount()),m_iShotDelay(1000)
{
}


CGunTower::~CGunTower()
{
}




void CGunTower::Initialize(void)
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;
	//m_tInfo.vPos = { 400.f,300.f,0.f };
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
	
	if(m_bBattle == true && CObjMgr::Get_Instance()->Get_ObjList(OBJ_MONSTER).empty() == false)
	{ 
	Update_MatWorld();

	m_vTarget = Find_Target(m_tInfo.vPos.x, m_tInfo.vPos.y);
	if (m_vTarget.y > m_tInfo.vPos.y && abs(m_vTarget.x - m_tInfo.vPos.x) > 100)
	{
		m_vTarget.y -= 35;
		m_tInfo.vDir = m_vTarget - m_tInfo.vPos;
	}
	else if(m_vTarget.y < m_tInfo.vPos.y && abs(m_vTarget.x - m_tInfo.vPos.x) > 100)
	{
		m_vTarget.y += 35;
		m_tInfo.vDir = m_vTarget - m_tInfo.vPos;
	}
	else
	{
		m_tInfo.vDir = m_vTarget - m_tInfo.vPos;
	}

	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	}
	if (m_bBattle)
	{
		Create_Bullet();
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
	LineTo(hDC, int(m_tInfo.vPos.x + m_tInfo.vDir.x * m_fScale * 30.f), int(m_tInfo.vPos.y + m_tInfo.vDir.y * m_fScale * 30.f));
	
	
}

void CGunTower::Release(void)
{
}

void CGunTower::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}

void CGunTower::Create_Bullet(void)
{
	if (m_LBullet + m_iShotDelay < GetTickCount())
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CHSBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x + m_tInfo.vDir.x * m_fScale * 30.f, m_tInfo.vPos.y + m_tInfo.vDir.y * m_fScale * 30.f,this));
		CSoundMgr::Get_Instance()->StopSound(SOUND_BULLET);
		CSoundMgr::Get_Instance()->PlaySound(L"Gun.wav", SOUND_BULLET, 1.f);
		m_LBullet = GetTickCount();
	}
}