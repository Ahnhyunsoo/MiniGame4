#include "stdafx.h"
#include "YMMonster.h"
#include "ObjMgr.h"


CYMMonster::CYMMonster()
{
}


CYMMonster::~CYMMonster()
{
}

void CYMMonster::Initialize(void)
{
	m_fAngle = 1.f;
	m_fSpeed = 2.f;
	m_fScale = 0.5f;
	m_tInfo.vLook = { 1.f, 0.f, 0.f };

	m_vOriVertex.push_back(D3DXVECTOR3{ 64.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 60.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, -10.f, 0.f });

	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, -30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 25.f, -35.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 18.f, -50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -18.f, -50.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -25.f, -35.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, -30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -60.f, -10.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -64.f, 0.f, 0.f });

	m_vOriVertex.push_back(D3DXVECTOR3{ -20.f, 30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -15.f, 40.f, 0.f }); 
	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, 43.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, 58.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{  0.f, 64.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, 58.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, 33.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, 33.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -10.f, 58.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, 64.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, 58.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 10.f, 43.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 15.f, 40.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 20.f, 30.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 64.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -64.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 64.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 33.f, 20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -33.f, 20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 33.f, 20.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 64.f, 0.f, 0.f });


	m_vVertex.push_back(D3DXVECTOR3{ 70.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 60.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, -10.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ 10.f, -30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 25.f, -35.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 18.f, -50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -18.f, -50.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -25.f, -35.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, -30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -60.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -70.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -20.f, 30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -15.f, 40.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 43.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 58.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 0.f, 64.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 58.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 33.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 33.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 58.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 0.f, 64.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 58.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 43.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 15.f, 40.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 20.f, 30.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 64.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -64.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 64.f, 0.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 33.f, 20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -33.f, 20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 33.f, 20.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 64.f, 0.f, 0.f });
}

int CYMMonster::Update(void)
{
	Update_MatWorld();


	m_pPlayer = CObjMgr::Get_Instance()->Get_ObjList(OBJ_PLAYER).back()->Get_Info();
	m_tInfo.vDir = m_pPlayer.vPos - m_tInfo.vPos;

	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	D3DXVec3Normalize(&m_tInfo.vLook, &m_tInfo.vLook);

	float fDot = D3DXVec3Dot(&m_tInfo.vDir, &m_tInfo.vLook);

	float	fAngle = acosf(fDot);

	if (m_tInfo.vPos.y <  m_pPlayer.vPos.y)
		fAngle = 2.f * D3DX_PI - fAngle;

	m_tInfo.vPos.x += m_fSpeed * cosf(fAngle);
	m_tInfo.vPos.y -= m_fSpeed * sinf(fAngle);




	return OBJ_NOEVENT;
}

void CYMMonster::Late_Update(void)
{
}

void CYMMonster::Render(HDC hDC)
{
	Render_Vertex(hDC);
}

void CYMMonster::Release(void)
{
}

void CYMMonster::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}
