#include "stdafx.h"
#include "SelectPlayer.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"

CSelectPlayer::CSelectPlayer()
{
}


CSelectPlayer::~CSelectPlayer()
{
}

void CSelectPlayer::Initialize(void)
{
	m_tInfo.fCX = 60.f;
	m_tInfo.fCY = 40.f;
	m_tInfo.vPos = { 0.f,300.f,0.f };
	m_fAngle = 1.f;
	m_fSpeed = 6.f;
	m_fScale = 1.f;
	m_tInfo.vDir = { 1.f,0.f,0.f };
	m_bDead = false;

	m_vOriVertex.push_back(D3DXVECTOR3{-30.f, - 20.f, 0.f});
	m_vOriVertex.push_back(D3DXVECTOR3{ 30.f, -20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 30.f, 20.f, 0.f	 });
	m_vOriVertex.push_back(D3DXVECTOR3{ -30.f, 20.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -30.f, -20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 30.f, -20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 30.f, 20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -30.f, 20.f, 0.f });

}

int CSelectPlayer::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	OffSet();
	Key_Input();

	Update_MatWorld();

	return OBJ_NOEVENT;
}

void CSelectPlayer::Late_Update(void)
{
	if (m_tInfo.vPos.y <= 10 - m_tInfo.vPos.y - 20.f)
		m_tInfo.vPos.y += m_fSpeed;

	if (m_tInfo.vPos.y >= 590 + m_tInfo.vPos.y + 20.f)
		m_tInfo.vPos.y -= m_fSpeed;
}

void CSelectPlayer::Render(HDC hDC)
{
	Render_Vertex(hDC);
	int iScrollX = CScrollMgr::Get_Instance()->Get_ScrollX();
	for (size_t i = 1; i < m_vVertex.size(); ++i)
	{
		if (i == 1 || i == 2)
			Ellipse(hDC, (int)m_vVertex[i].x - 5 + iScrollX, (int)m_vVertex[i].y - 5, (int)m_vVertex[i].x + 5 + iScrollX, (int)m_vVertex[i].y + 5);
	}
}

void CSelectPlayer::Release(void)
{
}

void CSelectPlayer::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}

void CSelectPlayer::Key_Input(void)
{
	if (CKeyMgr::Get_Instance()->Key_Pressing('W'))
	{
		m_tInfo.vDir.x = cos(D3DXToRadian(m_fAngle));
		m_tInfo.vDir.y = sin(D3DXToRadian(m_fAngle));

		D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);

		m_tInfo.vPos.x += m_tInfo.vDir.x * m_fSpeed;
		m_tInfo.vPos.y += m_tInfo.vDir.y * m_fSpeed;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing('S'))
	{
		m_tInfo.vDir.x = cos(D3DXToRadian(m_fAngle));
		m_tInfo.vDir.y = sin(D3DXToRadian(m_fAngle));

		D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);

		m_tInfo.vPos.x -= m_tInfo.vDir.x * m_fSpeed;
		m_tInfo.vPos.y -= m_tInfo.vDir.y * m_fSpeed;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing('A'))
		m_fAngle -= 2.f;
	

	if (CKeyMgr::Get_Instance()->Key_Pressing('D'))
		m_fAngle += 2.f;
	
}



void CSelectPlayer::OffSet(void)
{
	int		iOffSetX = WINCX >> 1;

	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iItvX = (int)m_vOriVertex[1].x;


	if (iOffSetX - iItvX > m_tInfo.vPos.x + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX((int)m_fSpeed);

	if (iOffSetX + iItvX < m_tInfo.vPos.x + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX((int)-m_fSpeed);

}