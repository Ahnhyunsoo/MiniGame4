#include "stdafx.h"
#include "HRPlayer.h"
#include "CAbstractFactory.h"

#include "KeyMgr.h"
#include "ObjMgr.h"
#include "HRSwing.h"
#include "CameraMgr.h"
#include "TimeMgr.h"
#include "HRBullet.h"

CHRPlayer::CHRPlayer()
	: m_eState(IDLE)
	, m_eHangDir(DIR_END)
	, m_fDeshTime(0.f)
	, m_fOldDeshTime(0.f)
	, m_bGM(false)
{
}
CHRPlayer::~CHRPlayer()
{
}




void CHRPlayer::Initialize(void)
{
	m_fKnockTime = 100.f;
	m_fDeadTime = 2000.f;

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
	if (3000.f < m_tInfo.vPos.x)
	{
		
	}


	if (CKeyMgr::Get_Instance()->Key_Down('M'))
	{
		if (!m_bGM)
			m_bGM = true;
		else
			m_bGM = false;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing('P') || CTimeMgr::Get_Instance()->Get_Record())
	{
		m_eState = IDLE;
		m_bRecord = true;
	}
	else
		m_bRecord = false;

	if (!m_bRecord)
		Update_Record();
	else
	{
		Update_BackRecord();
		// PosinUpdate();
		Update_MatWorld();
		return 0;
	}
		
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
	case CHRPlayer::DEAD:
		Update_Dead();
		break;
	}

	PosinUpdate();
	Update_MatWorld();

	Update_Gravity();

	return 0;
}
void CHRPlayer::Late_Update(void)
{
	
}
void CHRPlayer::Render(HDC hDC)
{
	Render_Vertex(hDC);


	//if (!(CCameraMgr::Get_Instance()->Get_IsScaling()))
	//{
	//	int iScrollX = CCameraMgr::Get_Instance()->Get_ScrollX();
	//	int iScrollY = CCameraMgr::Get_Instance()->Get_ScrollY();
	//	MoveToEx(hDC, m_tInfo.vPos.x + iScrollX, m_tInfo.vPos.y + iScrollY, nullptr);
	//	LineTo(hDC, m_tInfo.vPos.x + m_fPosinDir.x * 30.f + iScrollX, m_tInfo.vPos.y + m_fPosinDir.y * 30.f + iScrollY);
	//}
}
void CHRPlayer::Release(void)
{
}




void CHRPlayer::PosinUpdate()
{
	D3DXVECTOR3 vMousePos = Get_Mouse();

	int iScrollX = CCameraMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = CCameraMgr::Get_Instance()->Get_ScrollY();

	vMousePos.x -= iScrollX;
	vMousePos.y -= iScrollY;

	m_fPosinDir = vMousePos - m_tInfo.vPos;
	D3DXVec3Normalize(&m_fPosinDir, &m_fPosinDir);
}
void CHRPlayer::DeshUpdate()
{
	if (m_fOldDeshTime + m_fDeshTime + CTimeMgr::Get_Instance()->Get_DelaySecond() < GetTickCount())
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



void CHRPlayer::Update_Dead()
{
	if (m_fOldDeadTime + m_fDeadTime + CTimeMgr::Get_Instance()->Get_DelaySecond() < GetTickCount())
	{
		CTimeMgr::Get_Instance()->Set_Record(true);
		m_fRemitSpeed = 5.f;
		return;
	}

	if (m_fOldDeadTime + m_fKnockTime + CTimeMgr::Get_Instance()->Get_DelaySecond() > GetTickCount())
	{
		m_bOnAir = true;
		m_fRemitSpeed = 8.f;
		m_fValX -= m_tInfo.vDir.x * 3.f;
		m_fValY -= m_tInfo.vDir.y * 1.8f;
	}
}


void CHRPlayer::Update_BackRecord()
{
	if (m_vRecords.size() == 0)
	{
		CTimeMgr::Get_Instance()->Set_Record(false);
		m_bRealDead = true;
		return;
	}

	m_tInfo.vPos = m_vRecords.back().m_vRecord;
	m_bDead = m_vRecords.back().m_bDead;
	m_vRecords.pop_back();

	if (m_vRecords.size() == 0)
	{
		m_bRealDead = true;
		return;
	}
	m_vRecords.pop_back();
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
		CCameraMgr::Get_Instance()->StartShake(5.f, 5.f, 100.f);

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





void CHRPlayer::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	if (m_bDead || m_bRecord || m_eState == DEAD)
		return;

	CHRObj* temp = (CHRObj*)_Other;

	if (temp->Get_Tag() == "Bullet" && !m_bGM)
	{
		temp->Set_Dead();

		m_eState = DEAD;
		m_tInfo.vDir = _Other->Get_Info().vDir;
		m_fOldDeadTime = GetTickCount();
		CCameraMgr::Get_Instance()->StartScale(this);

		return;
	}
	else if (temp->Get_Tag() == "Swing")
		return;

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
