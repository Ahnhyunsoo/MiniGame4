#include "stdafx.h"
#include "GHPlayer.h"
#include "GHButton.h"
#include <iostream>
CGHPlayer::CGHPlayer()
{
}


CGHPlayer::~CGHPlayer()
{
}

void CGHPlayer::Initialize(void)
{
	m_bSkid = false;
	m_eString = STRING_PLAYER;
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;
	m_tInfo.vPos = { WINCX / 2, WINCY -100.f ,0.f };
	m_fAngle = 0.f;
	m_fSpeed = 6.f;
	m_fScale = 1.f;
	m_tInfo.vDir = { 1.f,0.f,0.f };
	m_bDead = false;
	
	m_BodyDistanceX = 0;
	m_BodyDistanceY = 0;

	/*m_vOriVertex.push_back(D3DXVECTOR3{ -50.f, -50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 50.f, -50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 50.f, 50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -50.f, 50.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -50.f, -50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 50.f, -50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 50.f, 50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -50.f, 50.f, 0.f });*/
	m_vOriVertex.push_back(D3DXVECTOR3{ -50.f, -50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 50.f, -50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 50.f, 50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -50.f, 50.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -50.f, -50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 50.f, -50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 50.f, 50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -50.f, 50.f, 0.f });
	m_FootTime = 0;
	m_ScaleTime = 0;
	m_bFoot = true;
	m_bJump = false;
	m_fJumpPower = 13.f;
	m_fJumpTime = 0.f;
	m_iFloarY = 0;
	m_iFootChangeTime = 100;
}
void CGHPlayer::ModeChange()
{
	//if ((g_dwGHBGMStartTime != 0) && (g_dwGHBGMStartTime + 16000 < GetTickCount())) {
	//	m_bSkid = true;
	//}
}

void CGHPlayer::Update_SkidWorld()
{
}

int CGHPlayer::Update(void)
{
	ModeChange();
	if (m_bDead)
		return OBJ_DEAD;
	Key_Input();

	Jumping();
	if (!m_bSkid)
		Update_MatWorld();
	else
		Update_SkidWorld();
	Foot_Change();

	return OBJ_NOEVENT;

}
void CGHPlayer::Jumping()
{
	if (m_bJump)
	{
		m_tInfo.vPos.y -= m_fJumpPower * m_fJumpTime - 9.8f * m_fJumpTime * m_fJumpTime * 0.5f;
		m_fJumpTime += 0.05f;
		if (m_iFloarY <m_tInfo.vPos.y)
		{
			m_iFootChangeTime = 100;
 			m_bJump = false;
			m_fJumpTime = 0.f;
			m_tInfo.vPos.y = m_iFloarY;
		}

	}
}
void CGHPlayer::Foot_Change()
{
	m_BodyDistanceX = int( abs(m_vVertex[0].x - m_vVertex[1].x) / 2);
	m_BodyDistanceY = int(abs(m_vVertex[1].y - m_vVertex[2].y) / 2);

	if (m_FootTime == 0)
	{
		m_FootTime = GetTickCount();
		return;
	}
	else
	{
		if (m_FootTime + m_iFootChangeTime < GetTickCount())
		{
			if (m_bFoot)
				m_bFoot = false;
			else if (!m_bFoot)
				m_bFoot = true;
			m_FootTime = GetTickCount();
			return;
		}
	}

}
void CGHPlayer::Late_Update(void)
{
	/*cout << "left : "<<m_vVertex[0].x << "\t" << m_vVertex[0].y << endl;
	cout << "right : " << m_vVertex[1].x << "\t" << m_vVertex[1].y << endl;*/

}

void CGHPlayer::Render(HDC hDC)
{
	
	if (m_bFoot)
	{//오른쪽 발
		Ellipse(hDC, int(m_tInfo.vPos.x + m_BodyDistanceX - 30), int(m_tInfo.vPos.y + m_BodyDistanceY - 20), int(m_tInfo.vPos.x + m_BodyDistanceX - 10), int(m_tInfo.vPos.y + m_BodyDistanceY + 10));
		//왼쪽 손
		Ellipse(hDC, int(m_tInfo.vPos.x - m_BodyDistanceX - 20), int(m_tInfo.vPos.y - 10), int(m_tInfo.vPos.x - m_BodyDistanceX + 5), int(m_tInfo.vPos.y  + 25));

	}
	else if (!m_bFoot)
	{//왼쪽 발
		Ellipse(hDC, int(m_tInfo.vPos.x - m_BodyDistanceX + 10), int(m_tInfo.vPos.y + m_BodyDistanceY - 20), int(m_tInfo.vPos.x - m_BodyDistanceX + 30), int(m_tInfo.vPos.y + m_BodyDistanceY + 10));
		//오른쪽 손
		Ellipse(hDC, int(m_tInfo.vPos.x + m_BodyDistanceX - 5), int(m_tInfo.vPos.y - 10), int(m_tInfo.vPos.x + m_BodyDistanceX + 20), int(m_tInfo.vPos.y + 25));

	}
	Render_Vertex(hDC);
	Ellipse(hDC, (int)m_vVertex[0].x, (int)m_vVertex[0].y, (int)m_vVertex[2].x, (int)m_vVertex[2].y);
	MoveToEx(hDC, int(m_tInfo.vPos.x), int(m_tInfo.vPos.y), nullptr);
	LineTo(hDC, int(m_tInfo.vPos.x + m_tInfo.vDir.x * 100), int(m_tInfo.vPos.y + m_tInfo.vDir.y * 100));

}

void CGHPlayer::Release(void)
{
}

void CGHPlayer::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	dynamic_cast<CGHButton*>(_Other)->Set_bPress();
}
void CGHPlayer::Set_Skid_Pos(int _iLeft_Middle_Right)
{
	if (_iLeft_Middle_Right < 0) {
		m_vLeft_Middle_Right.x = 67.75f;
	}
	else if (_iLeft_Middle_Right > 0)
	{
		m_vLeft_Middle_Right.x = 735.25f;
	}
	else 
	{
		m_vLeft_Middle_Right = m_tInfo.vPos;
	}
	m_vLeft_Middle_Right.y = 443.75f;

}
void CGHPlayer::Key_Input()
{
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
	{
		if (m_tInfo.vPos.x > WINCX)
			m_tInfo.vPos.x = 0;
		m_tInfo.vPos.x += m_tInfo.vDir.x * m_fSpeed;
		m_tInfo.vPos.y += m_tInfo.vDir.y * m_fSpeed;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
	{
		if (m_tInfo.vPos.x < 0)
			m_tInfo.vPos.x = WINCX;
		
		m_tInfo.vPos.x -= m_tInfo.vDir.x * m_fSpeed;
		m_tInfo.vPos.y -= m_tInfo.vDir.y * m_fSpeed;
	}

	if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE)) {
		if (!m_bJump) {
			m_bJump = true;
			m_iFloarY =m_tInfo.vPos.y;
			m_iFootChangeTime = 5;
			return;
		}
		//m_fAngle += 3.f;
	}
	if ((m_ScaleTime == 0) || ((m_ScaleTime != 0) && (m_ScaleTime + 500 < GetTickCount())))
	{
		if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP)) {
			m_fScale *= 1.5f;
			m_tInfo.fCX *= 1.5f;
			m_tInfo.fCY *= 1.5f;
			m_fSpeed -= 5.f;
			m_ScaleTime = GetTickCount();
		}
		if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN)) {
			m_tInfo.fCX *= 0.5f;
			m_tInfo.fCY *= 0.5f;
			m_fScale *= 0.5f;
			m_fSpeed += 5.f;
			m_ScaleTime = GetTickCount();
		}
	}


	

}