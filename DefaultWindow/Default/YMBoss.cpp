#include "stdafx.h"
#include "YMBoss.h"
#include "YMUIMgr.h"
#include "YMScoreMgr.h"
#include "ObjMgr.h"
#include "CAbstractFactory.h"
#include "YMMonsterBullet.h"

CYMBoss::CYMBoss()
{
}


CYMBoss::~CYMBoss()
{
}

void CYMBoss::Initialize(void)
{
	m_fSpeed = 2.f;
	m_fScale = 5.f;
	m_iHp = 4000;
	m_bDead = false;
	m_bUi_Check = false;

	m_iSide = 0;
	m_iSideCount = 0;
	m_iSide2 = 0;
	m_iSideCount2 = 0;

	m_tInfo.vLook = { 1.f, 0.f, 0.f };
	m_tInfo.vDir = { 0.f,0.f,0.f };
	m_tInfo.fCX = 140;
	m_tInfo.fCY = 90;
	m_sTag = "monster";


	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 8.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -8.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 8.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 2.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 2.f, -18.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -2.f, -18.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -2.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 6.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 6.f, -30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -6.f, -30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -6.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 6.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 6.f, -12.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 16.f, -17.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 23.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 23.f, -7.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 25.f, -7.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 25.f, -22.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 23.f, -22.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 23.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 23.f, -20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 16.f, -27.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 16.f, -17.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 16.f, -27.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 6.f, -22.f, 0.f });

	m_vOriVertex.push_back(D3DXVECTOR3{ 6.f, -30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 1.f, -30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 8.f, -36.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 8.f, -44.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 1.f, -38.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 1.f, -30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 1.f, -38.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, -44.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -1.f, -38.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -1.f, -30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -1.f, -38.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -7.f, -44.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -7.f, -36.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -1.f, -30.f, 0.f });


	m_vOriVertex.push_back(D3DXVECTOR3{ -6.f, -30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -6.f, -22.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -16.f, -27.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -16.f, -17.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -16.f, -27.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -23.f, -20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -23.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -23.f, -22.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -25.f, -22.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -25.f, -7.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -23.f, -7.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -23.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -16.f, -17.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -6.f, -12.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -6.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -8.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, 5.f, 0.f });

	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, 6.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -1.f, 6.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 2.f, 6.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 2.f, 7.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -1.f, 7.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -1.f, 6.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 1.f, 6.f, 0.f });


	m_vOriVertex.push_back(D3DXVECTOR3{ 1.f, 5.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 1.f, -1.5f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, 0.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ 0.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 8.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -8.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 0.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 8.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 2.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 2.f, -18.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -2.f, -18.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -2.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 6.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 6.f, -30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -6.f, -30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -6.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 6.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 6.f, -12.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 16.f, -17.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 23.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 23.f, -7.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 25.f, -7.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 25.f, -22.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 23.f, -22.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 23.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 23.f, -20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 16.f, -27.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 16.f, -27.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 16.f, -17.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 6.f, -22.f, 0.f });


	m_vVertex.push_back(D3DXVECTOR3{ 6.f, -30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 1.f, -30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 7.f, -36.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 7.f, -44.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 1.f, -38.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 1.f, -30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 1.f, -38.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 0.f, -44.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -1.f, -38.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -1.f, -30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -1.f, -38.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -7.f, -44.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -7.f, -36.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -1.f, -30.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -6.f, -30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -6.f, -22.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -16.f, -27.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -16.f, -17.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -16.f, -27.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -23.f, -20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -23.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -23.f, -22.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -25.f, -22.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -25.f, -7.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -23.f, -7.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -23.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -16.f, -17.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -6.f, -12.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -6.f, -10.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -8.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 0.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 0.f, 5.f, 0.f });


	m_vVertex.push_back(D3DXVECTOR3{ 0.f, 6.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -1.f, 6.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 2.f, 6.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 2.f, 7.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -1.f, 7.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -1.f, 5.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -1.f, 6.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 1.f, 6.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ 1.f, 5.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 1.f, -1.5f, 0.f });



}

int CYMBoss::Update(void)
{
	Update_MatWorld();

	if (m_tInfo.vPos.y >= 250)
		m_tInfo.vPos.x += m_fSpeed;
	else
		m_tInfo.vPos.y += m_fSpeed;

	if (m_tInfo.vPos.x >= 700)
		m_fSpeed *= -1;
	else if (m_tInfo.vPos.x <= 100)
		m_fSpeed *= -1;

	if (m_iHp >= 2000)
		m_bUi_Check = true;

	if (!m_bUi_Check && m_tInfo.vPos.y == 100)
		m_iHp += 20;



	if (m_tInfo.vPos.y >= 250 && m_iSide <= 2)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMMonsterBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x, m_tInfo.vPos.y + 50, DIR_DOWN));
		m_iSide++;
	}

	if (m_iSide == 3 && m_iSideCount == 0)
	{
		m_iSideCount = GetTickCount();
	}
	else if (m_iSide == 3 && m_iSideCount + 1000 < GetTickCount())
	{
		m_iSide = 0;
		m_iSideCount = 0;
	}

	if (m_tInfo.vPos.y >= 250 && m_iSide2 <= 5)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMMonsterBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x + 100, m_tInfo.vPos.y - 50, DIR_DOWN));
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMMonsterBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x - 100, m_tInfo.vPos.y - 50, DIR_DOWN));
		m_iSide2++;
	}

	if (m_iSide2 == 6 && m_iSideCount2 == 0)
	{
		m_iSideCount2 = GetTickCount();
	}
	else if (m_iSide2 == 6 && m_iSideCount2 + 3000 < GetTickCount())
	{
		m_iSide2 = 0;
		m_iSideCount2 = 0;
	}


	if (m_bDead)
	{
		CYMScoreMgr::Get_Instance()->Plus_Score(10000);
		CSceneMgr::Get_Instance()->Scene_Reserve(STAGE_ST);
		return OBJ_DEAD;
	}
	else
		return OBJ_NOEVENT;
}

void CYMBoss::Late_Update(void)
{
	if(m_tInfo.vPos.y >= 100)
		static_cast<CYMUi*>(CYMUiMgr::Get_Instance()->Get_Ui_List().back())->Boss_Start(true);

	static_cast<CYMUi*>(CYMUiMgr::Get_Instance()->Get_Ui_List().back())->Set_BossHp(m_iHp / 10 );
}

void CYMBoss::Render(HDC hDC)
{
	Render_Vertex(hDC);
}

void CYMBoss::Release(void)
{
}

void CYMBoss::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	CObjYM* temp = (CObjYM*)_Other;

	if (temp->Get_Tag() == "bullet")
		Set_Hp(1);
	else if (temp->Get_Tag() == "lazer")
		Set_Hp(10);

	if (m_iHp <= 0)
		m_bDead = true;
}
