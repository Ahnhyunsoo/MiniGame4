#include "stdafx.h"
#include "HRMonster.h"
#include "CAbstractFactory.h"

#include "ObjMgr.h"
#include "CameraMgr.h"
#include "HRBullet.h"
#include "TimeMgr.h"
#include "HRSwing.h"

CHRMonster::CHRMonster()
	: m_fDeadTime(0.f)
	, m_fOldDeadTime(0.f)
	, m_fKnockTime(0.f)
	, m_eState(IDLE)
	, m_fChaseDis(0.f)
	, m_fAttackTime(0.f)
	, m_fOldAttackTime(0.f)
	, m_bCanHit(true)
{
}

CHRMonster::~CHRMonster()
{
}

void CHRMonster::Initialize(void)
{
	m_fKnockTime = 100.f;
	m_fDeadTime = 2000.f;
	m_fRemitSpeed = 0.5f;
	m_fJumpPower = 8.f;
	m_fChaseDis = 300.f;
	m_fAttackTime = 3000.f;

	m_tInfo.fCX = 40.f;
	m_tInfo.fCY = 40.f;
	m_fAngle = 0.f;
	m_fSpeed = 0.1f;
	m_fScale = 1.f;
	m_tInfo.vDir = { -1.f,0.f,0.f };
	m_bDead = false;

	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, -20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, -20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, 20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, 20.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });
}

int CHRMonster::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	switch (m_eState)
	{
	case CHRMonster::IDLE:
		Update_Idle();
		break;
	case CHRMonster::MOVE:
		Update_Move();
		break;
	case CHRMonster::CHASE:
		Update_Chase();
		break;
	case CHRMonster::ATTACK:
		Update_Attack();
		break;
	case CHRMonster::DEAD:
		Update_Dead();
		break;
	}

	Update_MatWorld();

	Update_Gravity();

	return OBJ_NOEVENT;
}


void CHRMonster::Update_Idle()
{
	D3DXVECTOR3 vDefferVec = CObjMgr::Get_Instance()->Get_Player()->Get_Info().vPos - m_tInfo.vPos;
	float fDefferDis = D3DXVec3Length(&vDefferVec);
	if (fDefferDis < m_fChaseDis)
		m_eState = ATTACK;
}
void CHRMonster::Update_Move()
{
	D3DXVECTOR3 vDefferVec = CObjMgr::Get_Instance()->Get_Player()->Get_Info().vPos - m_tInfo.vPos;
	float fDefferDis = D3DXVec3Length(&vDefferVec);
	if (fDefferDis < m_fChaseDis)
		m_eState = ATTACK;


}
void CHRMonster::Update_Attack()
{
	if (m_fOldAttackTime + m_fAttackTime + (9 * CTimeMgr::Get_Instance()->Get_DelaySecond()) < GetTickCount())
	{
		D3DXVECTOR3 vDefferVec = CObjMgr::Get_Instance()->Get_Player()->Get_Info().vPos - m_tInfo.vPos;
		D3DXVec3Normalize(&vDefferVec, &vDefferVec);

		CObj* temp = CAbstractFactory<CHRBullet>::CreateObj(m_tInfo.vPos.x, m_tInfo.vPos.y);
		((CHRBullet*)temp)->SetDir(vDefferVec);
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, temp);

		m_fOldAttackTime = GetTickCount();
	}
}
void CHRMonster::Update_Chase()
{
	D3DXVECTOR3 vDefferVec = CObjMgr::Get_Instance()->Get_Player()->Get_Info().vPos - m_tInfo.vPos;
	D3DXVec3Normalize(&vDefferVec, &vDefferVec);
	m_bMove = true;
	m_fValX += vDefferVec.x * m_fSpeed;
}
void CHRMonster::Update_Dead()
{
	if (m_fOldDeadTime + m_fDeadTime + CTimeMgr::Get_Instance()->Get_DelaySecond() < GetTickCount())
	{
		m_bDead = true;
		m_fRemitSpeed = 5.f;
		return;
	}

	if (m_fOldDeadTime + m_fKnockTime + CTimeMgr::Get_Instance()->Get_DelaySecond() > GetTickCount())
	{
		m_bOnAir = true;
		m_fRemitSpeed = 8.f;
		m_fValX += m_vDieDir.x * 3.f;
		m_fValY += m_vDieDir.y * 1.8f;
	}
}



void CHRMonster::Late_Update(void)
{
	
}

void CHRMonster::Render(HDC hDC)
{
	Render_Vertex(hDC);
}

void CHRMonster::Release(void)
{
}

void CHRMonster::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	CHRObj* temp = (CHRObj*)_Other;

	if (temp->Get_Tag() == "Swing" && m_bCanHit)
	{
		if (!((CSwing*)temp)->GetHit())
			return;

		m_eState = DEAD;
		m_vDieDir = _Other->Get_Info().vDir;
		m_fOldDeadTime = GetTickCount();
		// CCameraMgr::Get_Instance()->StartScale(this);
		m_bCanHit = false;

		return;
	}
	else if (temp->Get_Tag() == "Bullet" && m_bCanHit)
	{
		if (((CHRBullet*)temp)->GetPadding())
		{
			m_eState = DEAD;
			m_vDieDir = _Other->Get_Info().vDir;
			m_fOldDeadTime = GetTickCount();
			CCameraMgr::Get_Instance()->StartScale(this);
			m_bCanHit = false;

			_Other->Set_Dead();
			return;
		}
	}


	if (_DIR == DIR_UP)
	{
		m_bOnAir = false;
		m_bJump = false;
	}
	else if (_DIR == DIR_LEFT || _DIR == DIR_RIGHT)
	{
		m_fValX = 0.f;
		m_bOnAir = false;
		m_bJump = false;
	}
	else if (_DIR == DIR_DOWN)
	{
		m_bJump = false;
	}
}
