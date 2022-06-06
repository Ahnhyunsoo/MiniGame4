#include "stdafx.h"
#include "YMCommon.h"
#include "YMScoreMgr.h"

CYMCommon::CYMCommon(DIRECTION _Dir)
{
	m_iDirection = _Dir;
}


CYMCommon::~CYMCommon()
{
}

void CYMCommon::Initialize(void)
{
	m_fAngle = 1.f;
	m_fSpeed = 2.f;
	m_fScale = 5.0f;
	m_tInfo.fCX = 100;
	m_tInfo.fCY = 100;
	m_iHp = 20;
	m_sTag = "monster";

	m_tInfo.vLook = { 1.f, 0.f, 0.f };
	m_bDead = false;

	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, 10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, 10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, 0.f, 0.f });


	m_vVertex.push_back(D3DXVECTOR3{ 0.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 0.f, 0.f, 0.f });
}

int CYMCommon::Update(void)
{
	if (m_iDirection == DIR_LEFT)
	{
		m_tInfo.vPos.y += m_fSpeed;
		m_tInfo.vPos.x += m_fSpeed;
	}
	else if (m_iDirection == DIR_RIGHT)
	{
		m_tInfo.vPos.y += m_fSpeed;
		m_tInfo.vPos.x -= m_fSpeed;
	}
	Update_MatWorld();

	if (m_bDead || m_tInfo.vPos.y > 800)
	{
		CYMScoreMgr::Get_Instance()->Plus_Score(500);
		return OBJ_DEAD;
	}
	else
		return OBJ_NOEVENT;
}

void CYMCommon::Late_Update(void)
{
}

void CYMCommon::Render(HDC hDC)
{
	Render_Vertex(hDC);
}

void CYMCommon::Release(void)
{
}

void CYMCommon::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	CObjYM* temp = (CObjYM*)_Other;
	if (temp->Get_Tag() == "bullet")
		Set_Hp(1);
	else if (temp->Get_Tag() == "lazer")
		Set_Hp(5);

	if (m_iHp == 0)
		m_bDead = true;
}
