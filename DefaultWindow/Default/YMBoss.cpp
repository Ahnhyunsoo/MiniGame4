#include "stdafx.h"
#include "YMBoss.h"
#include "YMUIMgr.h"
#include "YMScoreMgr.h"

CYMBoss::CYMBoss()
{
}


CYMBoss::~CYMBoss()
{
}

void CYMBoss::Initialize(void)
{
	m_fAngle = 180.f;
	m_fSpeed = 2.f;
	m_fScale = 20.f;
	m_iHp = 0;
	m_bDead = false;
	m_bUi_Check = false;

	m_tInfo.vLook = { 1.f, 0.f, 0.f };
	m_tInfo.vDir = { 0.f,0.f,0.f };
	m_tInfo.fCX = 140;
	m_tInfo.fCY = 90;
	m_sTag = "monster";

	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, 0.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 0.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 0.f, 0.f });



}

int CYMBoss::Update(void)
{
	Update_MatWorld();

	if (m_tInfo.vPos.y >= 100)
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

	if (m_bDead)
	{
		CYMScoreMgr::Get_Instance()->Plus_Score(10000);
		return OBJ_DEAD;
	}
	else
		return OBJ_NOEVENT;
}

void CYMBoss::Late_Update(void)
{
	if(m_tInfo.vPos.y >= 100)
		static_cast<CYMUi*>(CYMUiMgr::Get_Instance()->Get_Ui_List().back())->Boss_Start(true);

	static_cast<CYMUi*>(CYMUiMgr::Get_Instance()->Get_Ui_List().back())->Set_BossHp(m_iHp / 5);
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

	if (m_iHp == 0)
		m_bDead = true;
}
