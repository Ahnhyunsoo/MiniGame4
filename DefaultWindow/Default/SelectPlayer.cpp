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
	
	ZeroMemory(m_vCart, sizeof(D3DXVECTOR3) * 4);
	ZeroMemory(m_vOriginCart, sizeof(D3DXVECTOR3) * 4);
	ZeroMemory(&m_tInfo, sizeof(INFO));
	D3DXMatrixIdentity(&m_tInfo.matWorld);

	m_tInfo.vPos = { 0.f,300.f,0.f };
	m_tInfo.vDir = { 1.f,0.f,0.f };
	m_tInfo.vLook = { 1.f,0.f,0.f };

	m_fAngle = 1.f;
	m_fSpeed = 6.f;
	m_bDead = false;

	

	m_vOriginCart[0].x = -30.f;
	m_vOriginCart[0].y = -20.f;
	m_vOriginCart[1].x = 30.f;
	m_vOriginCart[1].y = -20.f;
	m_vOriginCart[2].x = 30.f;
	m_vOriginCart[2].y = +20.f;
	m_vOriginCart[3].x = -30.f;
	m_vOriginCart[3].y = 20.f;

}

int CSelectPlayer::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	OffSet();
	Key_Input();

	Update_Cart();

	return OBJ_NOEVENT;
}

void CSelectPlayer::Late_Update(void)
{
}

void CSelectPlayer::Render(HDC hDC)
{
	int ScrollX = CScrollMgr::Get_Instance()->Get_ScrollX();
	MoveToEx(hDC, (int)m_vCart[0].x+ScrollX, (int)m_vCart[0].y, nullptr);
	LineTo(hDC, (int)m_vCart[1].x + ScrollX, (int)m_vCart[1].y);
	LineTo(hDC, (int)m_vCart[2].x+ScrollX, (int)m_vCart[2].y);
	LineTo(hDC, (int)m_vCart[3].x+ScrollX, (int)m_vCart[3].y);
	LineTo(hDC, (int)m_vCart[0].x+ScrollX, (int)m_vCart[0].y);

	Ellipse(hDC, (int)m_vCart[1].x - 5 + ScrollX, (int)m_vCart[1].y - 5, (int)m_vCart[1].x + 5 + ScrollX, (int)m_vCart[1].y + 5);
	Ellipse(hDC, (int)m_vCart[2].x - 5 + ScrollX, (int)m_vCart[2].y - 5, (int)m_vCart[2].x + 5 + ScrollX, (int)m_vCart[2].y + 5);
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

void CSelectPlayer::Update_Cart(void)
{
	D3DXMATRIX	matScale, matRotZ, matTrans;

	// dx에서 제공하는 행렬 함수는 매개 변수로 넣어주는 행렬을 먼저 항등 행렬로 초기화 한 후, 값 적용을 수행한다.

	// 크기 변환 행렬 생성 함수
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);

	// z축 회전 행렬 생성 함수
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));

	// 이동 행렬 생성 함수
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);

	m_tInfo.matWorld = matScale * matRotZ * matTrans;

	for (int i = 0; i < 4; ++i)
		D3DXVec3TransformCoord(&m_vCart[i], &m_vOriginCart[i], &m_tInfo.matWorld);

	if (m_tInfo.vPos.y <= 10 - m_vOriginCart[1].y)
		m_tInfo.vPos.y += m_fSpeed;

	if (m_tInfo.vPos.y >= 590 + m_vOriginCart[1].y)
		m_tInfo.vPos.y -= m_fSpeed;
}

void CSelectPlayer::OffSet(void)
{
	int		iOffSetX = WINCX >> 1;

	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iItvX = (int)m_vOriginCart[1].x;


	if (iOffSetX - iItvX > m_tInfo.vPos.x + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX((int)m_fSpeed);

	if (iOffSetX + iItvX < m_tInfo.vPos.x + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX((int)-m_fSpeed);

}