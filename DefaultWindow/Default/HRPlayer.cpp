#include "stdafx.h"
#include "HRPlayer.h"
#include "CAbstractFactory.h"

#include "KeyMgr.h"
#include "ObjMgr.h"
#include "HRSwing.h"

CHRPlayer::CHRPlayer()
	: m_eState(IDLE)
	, m_eHangDir(DIR_END)
	, m_fDeshTime(0.f)
	, m_fOldDeshTime(0.f)
{
}

CHRPlayer::~CHRPlayer()
{
}

void CHRPlayer::Initialize(void)
{

	m_fDeshTime = 100.f;
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

int CHRPlayer::Update(void)
{
	switch (m_eState)
	{
	case CHRPlayer::IDLE:
	case CHRPlayer::MOVE:
	case CHRPlayer::HANG:
	case CHRPlayer::ATTACK:
		KeyInput();
		break;
	case CHRPlayer::DESH:
		DeshUpdate();
		break;
	}

	PosinUpdate();
	Update_MatWorld();

	return 0;
}

void CHRPlayer::Late_Update(void)
{
	Update_Gravity();
}

void CHRPlayer::Render(HDC hDC)
{
	Render_Vertex(hDC);

	int iScrollX = CScrollMgr::Get_Instance()->Get_ScrollX();
	MoveToEx(hDC, m_tInfo.vPos.x + iScrollX, m_tInfo.vPos.y, nullptr);
	LineTo(hDC, m_tInfo.vPos.x + m_fPosinDir.x * 30.f , m_tInfo.vPos.y + m_fPosinDir.y * 30.f);
}

void CHRPlayer::Release(void)
{
}

void CHRPlayer::KeyInput()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE))
	{
		if (m_eState == HANG)
		{
			if (m_eHangDir == DIR_LEFT)
			{
				m_fValX = -5.f;
				m_bJump = true;
				m_bOnAir = true;
			}
			else if (m_eHangDir == DIR_RIGHT)
			{
				m_fValX = 5.f;
				m_bJump = true;
				m_bOnAir = true;
			}
		}
		else
		{
			m_bJump = true;
			m_bOnAir = true;
		}
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing('A') && !m_bJump)
	{
		m_bMove = true;
		m_eState = MOVE;

		m_fValX -= m_fSpeed;
	}
	else if (CKeyMgr::Get_Instance()->Key_Pressing('D') && !m_bJump)
	{
		m_bMove = true;
		m_eState = MOVE;

		m_fValX += m_fSpeed;
	}
	else
	{
		m_bMove = false;
		m_eState = IDLE;
	}


	if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
	{
		m_bJump = false;
		m_eState = DESH;
		m_fOldDeshTime = GetTickCount();
		m_fDeshDir = m_fPosinDir;
		m_fValY = 0.f;
		m_fValX = 0.f;

		CObj* temp = CAbstractFactory<CSwing>::CreateObj(m_tInfo.vPos.x, m_tInfo.vPos.y);
		((CSwing*)temp)->SetDir(m_fPosinDir);
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, temp);
	}

}

void CHRPlayer::PosinUpdate()
{
	D3DXVECTOR3 vMousePos = Get_Mouse();

	m_fPosinDir = vMousePos - m_tInfo.vPos;
	D3DXVec3Normalize(&m_fPosinDir, &m_fPosinDir);
}

void CHRPlayer::DeshUpdate()
{
	if (m_fOldDeshTime + m_fDeshTime < GetTickCount())
	{
		m_eState = IDLE;
		m_fRemitSpeed = 5.f;
		return;
	}
	m_bOnAir = true;
	m_fRemitSpeed = 20.f;
	m_fValX += m_fDeshDir.x * 3.f;
	m_fValY += m_fDeshDir.y * 1.8f;
}


void CHRPlayer::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	if (_DIR == DIR_UP)
	{
		m_bOnAir = false;
		m_bJump = false;
	}
	else if (_DIR == DIR_LEFT || _DIR == DIR_RIGHT)
	{
		m_eHangDir = _DIR;
		m_eState = HANG;
		m_fValX = 0.f;
		m_bOnAir = false;
		m_bJump = false;
		m_tInfo.vPos.y += 1.f;
	}
	else if (_DIR == DIR_DOWN)
	{
		m_bJump = false;
	}

}
