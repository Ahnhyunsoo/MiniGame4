#include "stdafx.h"
#include "HRMonster.h"
#include "CAbstractFactory.h"

#include "ObjMgr.h"

CHRMonster::CHRMonster()
{
}

CHRMonster::~CHRMonster()
{
}

void CHRMonster::Initialize(void)
{
	m_fRemitSpeed = 5.f;
	m_fJumpPower = 8.f;

	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;
	m_fAngle = 0.f;
	m_fSpeed = 0.1f;
	m_fScale = 1.f;
	m_tInfo.vDir = { -1.f,0.f,0.f };
	m_bDead = false;

	m_vOriVertex.push_back(D3DXVECTOR3{ -15.f, -15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 15.f, -15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 15.f, 15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -15.f, 15.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });
}

int CHRMonster::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_MatWorld();

	return OBJ_NOEVENT;
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
		m_bDead = true;
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
