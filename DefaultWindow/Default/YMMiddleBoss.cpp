#include "stdafx.h"
#include "YMMiddleBoss.h"
#include "CAbstractFactory.h"
#include "ObjMgr.h"
#include "YMMonsterBullet.h"


CYMMiddleBoss::CYMMiddleBoss()
{
}


CYMMiddleBoss::~CYMMiddleBoss()
{
}

void CYMMiddleBoss::Initialize(void)
{
	m_fAngle = 180.f;
	m_fSpeed = 2.f;
	m_fScale = 2.f;
	m_iHp = 1000;
	m_bDead = false;
	m_tInfo.vLook = { 1.f, 0.f, 0.f };
	m_tInfo.vDir = { 0.f,0.f,0.f };
	m_tInfo.fCX = 140;
	m_tInfo.fCY = 90;
	m_sTag = "monster";
	m_iBulletCount = 0;
	m_bBulletCount = false;

	m_iSide = 0;
	m_iSideCount = 0;

	m_vOriVertex.push_back(D3DXVECTOR3{ 70.f, 5.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 50.f, -5.f, 0.f });

	m_vOriVertex.push_back(D3DXVECTOR3{ 50.f, -15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 45.f, -15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 45.f, -7.5f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 50.f, -5.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 40.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 40.f, -25.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 35.f, -25.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 35.f, -12.5f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 40.f, -10.f, 0.f });

	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, -20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, -45.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, -60.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, -45.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, -45.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, -45.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, -20.f, 0.f });


	m_vOriVertex.push_back(D3DXVECTOR3{ -40.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -40.f, -25.f, 0.f });//
	m_vOriVertex.push_back(D3DXVECTOR3{ -35.f, -25.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -35.f, -12.5f, 0.f });

	m_vOriVertex.push_back(D3DXVECTOR3{ -40.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -50.f, -5.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -45.f, -7.5f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -45.f, -15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -50.f, -15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -50.f, -5.f, 0.f });

	m_vOriVertex.push_back(D3DXVECTOR3{ -70.f, 10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -5.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -5.f, 35.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -25.f, 40.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 25.f, 40.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 5.f, 35.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 5.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 70.f, 5.f, 0.f }); 



	m_vVertex.push_back(D3DXVECTOR3{ 70.f, 5.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 50.f, -5.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 45.f, -15.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 45.f, -7.5f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 50.f, -15.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ 50.f, -5.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 40.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 40.f, -25.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ 35.f, -25.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 35.f, -12.5f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 40.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 20.f, -20.f, 0.f });



	m_vVertex.push_back(D3DXVECTOR3{ 10.f, -45.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 0.f, -60.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, -45.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, -45.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, -45.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -20.f, -20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -40.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -40.f, -25.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -35.f, -25.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -35.f, -12.5f, 0.f });


	m_vVertex.push_back(D3DXVECTOR3{ -40.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -50.f, -5.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -45.f, -7.5f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -45.f, -15.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -50.f, -15.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -50.f, -5.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -70.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -5.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -5.f, 35.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -25.f, 40.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 25.f, 40.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 5.f, 35.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 5.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 70.f, 5.f, 0.f });
}

int CYMMiddleBoss::Update(void)
{
	if(m_tInfo.vPos.y == 100)
		m_tInfo.vPos.x += m_fSpeed;
	else
		m_tInfo.vPos.y += m_fSpeed;


	if (m_tInfo.vPos.x >= 700)
		m_fSpeed *= -1;
	else if(m_tInfo.vPos.x <= 100)
		m_fSpeed *= -1;

	Update_MatWorld();


	if (m_iBulletCount == 0)
	{
		m_iBulletCount = GetTickCount();
		m_bBulletCount = true;
	}
	else if (m_iBulletCount + 500 < GetTickCount() && m_bBulletCount)
	{
		m_iBulletCount = 0;
		m_bBulletCount = false;
	}


	if (m_bDead)
		return OBJ_DEAD;
	else

		return OBJ_NOEVENT;
}

void CYMMiddleBoss::Late_Update(void)
{
	if (m_tInfo.vPos.y == 100 && m_iSide <= 5)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMMonsterBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x + 75, m_tInfo.vPos.y + 50, DIR_DOWN));
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMMonsterBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x - 75, m_tInfo.vPos.y + 50, DIR_DOWN));
		m_iSide++;
	}

	if(m_tInfo.vPos.y == 100 && !m_bBulletCount)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMMonsterBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x + 3, m_tInfo.vPos.y + 100, DIR_LEFT));
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMMonsterBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x, m_tInfo.vPos.y + 100, DIR_DOWN));
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMMonsterBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x - 3, m_tInfo.vPos.y + 100,DIR_RIGHT));
	}



	if (m_iSide == 6 && m_iSideCount == 0)
	{
		m_iSideCount = GetTickCount();
	}
	else if (m_iSide == 6 && m_iSideCount + 3000 < GetTickCount())
	{
		m_iSide = 0;
		m_iSideCount = 0;
	}
}

void CYMMiddleBoss::Render(HDC hDC)
{
	Render_Vertex(hDC);
}

void CYMMiddleBoss::Release(void)
{
}

void CYMMiddleBoss::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	CObjYM* temp = (CObjYM*)_Other;
	if (temp->Get_Tag() == "bullet")
		Set_Hp(1);
	else if (temp->Get_Tag() == "lazer")
		Set_Hp(5);

	if (m_iHp == 0)
		m_bDead = true;
}
