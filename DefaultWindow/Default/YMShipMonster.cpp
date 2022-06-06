#include "stdafx.h"
#include "YMShipMonster.h"


YMShipMonster::YMShipMonster()
{
}


YMShipMonster::~YMShipMonster()
{
}

void YMShipMonster::Initialize(void)
{
	m_fAngle = -60.f;
	m_fSpeed = 0.3f;
	m_fScale = 9.f;
	m_tInfo.vLook = { 1.f, 0.f, 0.f };
	m_tInfo.fCX = 1000;
	m_tInfo.fCY = 500;
	m_iHp = 500;
	m_bDead = false;
	m_sTag = "monster";

	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, 50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, 50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, 55.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, 55.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, 50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, 25.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -27.f, 25.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -27.f, 28.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, 28.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, 25.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, 50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, 50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, 50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, -50.f, 0.f });


	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, -25.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -27.f, -25.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -27.f, -28.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, -28.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, -25.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, -50.f, 0.f });

	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, 50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, -50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, -55.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, -55.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, -50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, -50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, -50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, 0.f, 0.f });



	m_vVertex.push_back(D3DXVECTOR3{ 20.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 20.f, 50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 20.f, 50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 55.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 55.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -20.f, 50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -20.f, 25.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -27.f, 25.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -27.f, 28.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -20.f, 28.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -20.f, 25.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -20.f, 50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 20.f, 50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -20.f, 50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 20.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -20.f, -50.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -20.f, -25.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -27.f, -25.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -27.f, -28.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -20.f, -28.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -20.f, -25.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -20.f, -50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -20.f, 50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -20.f, -50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, -55.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, -55.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 20.f, -50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -20.f, -50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 20.f, -50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 20.f, 0.f, 0.f });

}

int YMShipMonster::Update(void)
{
	m_tInfo.vPos.y += m_fSpeed;
	m_tInfo.vPos.x += m_fSpeed;
	Update_MatWorld();

	if (m_bDead || m_tInfo.vPos.y > 800)
		return OBJ_DEAD;
	else
		return OBJ_NOEVENT;
}

void YMShipMonster::Late_Update(void)
{
}

void YMShipMonster::Render(HDC hDC)
{
	Render_Vertex(hDC);

}

void YMShipMonster::Release(void)
{
}

void YMShipMonster::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	CObjYM* temp = (CObjYM*)_Other;
	if(temp->Get_Tag() == "bullet")
		Set_Hp(1);
	else if (temp->Get_Tag() == "lazer")
		Set_Hp(5);

	if (m_iHp == 0)
		m_bDead = true;
}
