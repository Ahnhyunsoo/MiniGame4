#include "stdafx.h"
#include "YMPlayer.h"
#include "CAbstractFactory.h"
#include "YMBullet.h"
#include "ObjMgr.h"
#include "YMLazer.h"
#include "YMBoom.h"

CYMPlayer::CYMPlayer()
{
}


CYMPlayer::~CYMPlayer()
{
}

void CYMPlayer::Initialize(void)
{
	m_tInfo.fCX = 50;
	m_tInfo.fCY = 80;
	m_tInfo.vPos = { 500.f,300.f,0.f };
	m_fAngle = 0.f;
	m_fSpeed = 2.f;
	m_fScale = 1.f;
	m_tInfo.vDir = { 1.f, 0.f,0.f };
	m_tInfo.vLook = { 1.f, 0.f,0.f };
	m_iHp = 100;
	m_iLevel = 1;
	m_iBoom = 4;
	m_iGameOver = false;

	m_LazerGauge = 100;

	m_sTag = "player";

	m_iCountLazer = 0;
	m_bLazer = false;

	m_iBoomCount = 0;
	m_bBoom = false;

	m_vOriVertex.push_back(D3DXVECTOR3(50.f, 0.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(-25.f, -50.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(-40.f, -7.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(-50.f, -5.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(-40.f, 0.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(50.f, 0.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(-25.f, 50.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(-40.f, 5.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(-50.f, -5.f, 0.f));
	m_vOriVertex.push_back(D3DXVECTOR3(-40.f, 5.f, 0.f));


	m_vVertex.push_back(D3DXVECTOR3(50.f, 0.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-25.f, -50.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-40.f, -7.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-50.f, -5.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-39.f, 0.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-50.f, -5.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-25.f, 50.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-40.f, 5.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-50.f, -5.f, 0.f));
	m_vVertex.push_back(D3DXVECTOR3(-40.f, 5.f, 0.f));
}

int CYMPlayer::Update(void)
{

	Update_MatWorld();
	Key_Input();

	float		fWidth = Get_Mouse().x - m_tInfo.vPos.x;
	float		fHeight = Get_Mouse().y - m_tInfo.vPos.y;

	float		fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

	float		fRadian = acosf(fWidth / fDiagonal);
	m_fAngle = (fRadian * 180.f) / PI;

	if (Get_Mouse().y < m_tInfo.vPos.y)
		m_fAngle *= -1.f;




	if (m_iCountLazer == 0 && !m_bLazer)
	{
		m_iCountLazer = GetTickCount();
		m_bLazer = true;
	}
	else if ((m_iCountLazer + 500 < GetTickCount()) && m_bLazer && m_LazerGauge <= 100)
	{
		m_LazerGauge++;
		m_iCountLazer = 0;
		m_bLazer = false;
	}


	return OBJ_NOEVENT;
}

void CYMPlayer::Late_Update(void)
{
}

void CYMPlayer::Render(HDC hDC)
{
	Render_Vertex(hDC);
}

void CYMPlayer::Release(void)
{
}

void CYMPlayer::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	CObjYM* temp = (CObjYM*)_Other;

	if (temp->Get_Tag() == "monsterbullet")
	{
		Set_Hp(1);
		if (m_iHp == 0)
			m_iGameOver = true;
	}
	else if (temp->Get_Tag() == "levelup")
	{
		m_iLevel++;
	}
	else if (temp->Get_Tag() == "heal")
	{
		m_iHp = 100;
	}
	else if (temp->Get_Tag() == "Iboom")
	{
		m_iBoom += 1;
	}
}


void CYMPlayer::Key_Input(void)
{
	if (CKeyMgr::Get_Instance()->Key_Pressing('W'))
	{
		m_tInfo.vPos.y -= m_fSpeed;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing('S'))
	{
		m_tInfo.vPos.y += m_fSpeed;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing('A'))
	{
		m_tInfo.vPos.x -= m_fSpeed;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing('D'))
	{
		m_tInfo.vPos.x += m_fSpeed;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON))
	{
		if(m_iLevel == 1)
			CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x, m_tInfo.vPos.y));
		else if (m_iLevel == 2)
		{
			CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x -15, m_tInfo.vPos.y));
			CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x +15, m_tInfo.vPos.y));
		}
		else if (m_iLevel == 3)
		{
			CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x - 20, m_tInfo.vPos.y));
			CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x, m_tInfo.vPos.y));
			CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x + 20, m_tInfo.vPos.y));
		}
		else if (m_iLevel == 4)
		{
			CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x - 15, m_tInfo.vPos.y));
			CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x + 15, m_tInfo.vPos.y));
			CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x - 35, m_tInfo.vPos.y + 20));
			CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x + 35, m_tInfo.vPos.y + 20));
		}
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RBUTTON))
	{
		if (m_LazerGauge >= 0)
		{
			CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMLazer>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x, m_tInfo.vPos.y));
			m_LazerGauge -= 1.f;
		}
	}

	if (m_iBoom >= 1)
	{
		if (CKeyMgr::Get_Instance()->Key_Pressing(VK_SPACE))
		{
			if (m_iBoomCount == 0)
			{
				m_iBoomCount = GetTickCount();
				m_bBoom = true;
				CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMBoom>::CreateBullet(m_tInfo.vDir, WINCX / 4, m_tInfo.vPos.y));
				CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMBoom>::CreateBullet(m_tInfo.vDir, WINCX*0.75, m_tInfo.vPos.y));
				m_iBoom--;
			}
			else if (m_iBoomCount + 3000 <= GetTickCount() && m_bBoom)
			{
				m_iBoomCount = 0;
				m_bBoom = false;
			}
		}
	}

}


D3DXVECTOR3	CYMPlayer::Get_Mouse(void)
{
	POINT	Pt{};

	GetCursorPos(&Pt);
	ScreenToClient(g_hWnd, &Pt);

	return D3DXVECTOR3((float)Pt.x, (float)Pt.y, 0.f);
}
