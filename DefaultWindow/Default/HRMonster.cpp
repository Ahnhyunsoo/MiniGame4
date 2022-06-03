#include "stdafx.h"
#include "HRMonster.h"
#include "CAbstractFactory.h"

#include "ObjMgr.h"

CHRMonster::CHRMonster()
	: m_fDeadTime(0.f)
	, m_fOldDeadTime(0.f)
	, m_fKnockTime(0.f)
	, m_eState(IDLE)
{
}

CHRMonster::~CHRMonster()
{
}

void CHRMonster::Initialize(void)
{
	m_fKnockTime = 100.f;
	m_fDeadTime = 1500.f;
	m_fRemitSpeed = 3.f;
	m_fJumpPower = 8.f;

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
		break;
	case CHRMonster::ATTACK:
		Update_Attack();
		break;
	case CHRMonster::DEAD:
		Update_Dead();
		break;
	}

	Update_MatWorld();

	return OBJ_NOEVENT;
}


void CHRMonster::Update_Idle()
{
}
void CHRMonster::Update_Move()
{
	m_bMove = true;
	m_fValX += -m_fSpeed;
}
void CHRMonster::Update_Attack()
{
}
void CHRMonster::Update_Dead()
{
	if (m_fOldDeadTime + m_fDeadTime < GetTickCount())
	{
		m_bDead = true;
		m_fRemitSpeed = 5.f;
		return;
	}

	if (m_fOldDeadTime + m_fKnockTime > GetTickCount())
	{
		m_bOnAir = true;
		m_fRemitSpeed = 8.f;
		m_fValX += m_vDieDir.x * 3.f;
		m_fValY += m_vDieDir.y * 1.8f;
	}
}



void CHRMonster::Late_Update(void)
{
	Update_Gravity();
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

	if (temp->Get_Tag() == "Swing")
	{
		m_eState = DEAD;
		m_vDieDir = _Other->Get_Info().vDir;
		m_fOldDeadTime = GetTickCount();
		// m_bDead = true;
		return;
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
