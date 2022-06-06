#include "stdafx.h"
#include "YMTownMoster.h"
#include "ObjMgr.h"
#include "CAbstractFactory.h"
#include "YMMonsterBullet.h"


CYMTownMoster::CYMTownMoster()
{
}


CYMTownMoster::~CYMTownMoster()
{
}

void CYMTownMoster::Initialize(void)
{
	m_fAngle = 1.f;
	m_fSpeed = 2.f;
	m_fScale = 3.f;
	m_iHp = 3;
	m_bDead = false;
	m_tInfo.vLook = { 1.f, 0.f, 0.f };
	m_sTag = "monster";
	m_iSideCount = 0;

	m_iSide = 0;

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

int CYMTownMoster::Update(void)
{

	m_tInfo.vPos.y += m_fSpeed;
	Update_MatWorld();


	if (m_bDead)
		return OBJ_DEAD;
	else
		return OBJ_NOEVENT;
}

void CYMTownMoster::Late_Update(void)
{
	if (m_tInfo.vPos.y >= 100 && m_iSide <= 2)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CYMMonsterBullet>::CreateBullet(m_tInfo.vDir, m_tInfo.vPos.x , m_tInfo.vPos.y + 50, DIR_DOWN));
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
}

void CYMTownMoster::Render(HDC hDC)
{
	Render_Vertex(hDC);
}

void CYMTownMoster::Release(void)
{
}

void CYMTownMoster::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	CObjYM* temp = (CObjYM*)_Other;
	if (temp->Get_Tag() == "bullet")
		Set_Hp(1);
	else if (temp->Get_Tag() == "lazer")
		Set_Hp(5);

	if (m_iHp == 0)
		m_bDead = true;
}
