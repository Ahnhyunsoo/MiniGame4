#include "stdafx.h"
#include "GHHeros_Of_Stone.h"


CGHHeros_Of_Stone::CGHHeros_Of_Stone()
{
}


CGHHeros_Of_Stone::~CGHHeros_Of_Stone()
{
	Release();

}

void CGHHeros_Of_Stone::Initialize(void)
{
	m_vOriVertex.push_back(D3DXVECTOR3{ -1.f	, -1.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 1.f	, -1.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 1.f	, 1.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -1.f	, 1.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -1.f, -1.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 1.f, -1.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 1.f, 1.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -1.f, 1.f, 0.f });
	m_eString = STRING_HOS;
	m_fAngle = 0.f;
	m_fScale = 25.f;
	m_fSpeed = 2.f;
	m_tInfo.vDir = { 1.0f,0.f,0.f };
	m_tInfo.vPos = { 400.f,100.f,0.f };
	m_bDead = false;
}

int CGHHeros_Of_Stone::Update(void)
{
	
	if (m_bDead)
		return OBJ_DEAD;


	
	Update_MatWorld();

	m_tInfo.fCX = abs(m_vVertex[0].x - m_vVertex[1].x);
	m_tInfo.fCY = abs(m_vVertex[1].y - m_vVertex[2].y);

	return OBJ_NOEVENT;
}

void CGHHeros_Of_Stone::Late_Update(void)
{
}

void CGHHeros_Of_Stone::Render(HDC hDC)
{

	HPEN hpen;
	HPEN hpenOld;

	hpen = CreatePen(PS_SOLID, 4, RGB(214, 214, 10));   // 선 스타일, 굵기, 색상
	hpenOld = (HPEN)::SelectObject(hDC, (HGDIOBJ)hpen);   // 펜 선택

	Render_Vertex(hDC);

	hpen = (HPEN)SelectObject(hDC, hpenOld);   // 기존의 펜 다시 선택
	DeleteObject(hpen);   // 생성한 펜 삭제


}

void CGHHeros_Of_Stone::Release(void)
{
}

void CGHHeros_Of_Stone::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	CSceneMgr::Get_Instance()->Scene_Reserve(STAGE_ST);
}
