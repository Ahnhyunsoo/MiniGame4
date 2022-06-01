#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
	: m_fSpeed(3.f), m_fAngle(1.f), m_fScale(0.f)
{
	/*ZeroMemory(&m_vVertex, sizeof(D3DXVECTOR3));
	ZeroMemory(&m_vOriVertex, sizeof(D3DXVECTOR3));*/
	ZeroMemory(&m_tInfo, sizeof(INFO));

	D3DXMatrixIdentity(&m_tInfo.matWorld);
}

CObj::~CObj()
{
}

void CObj::Update_MatWorld(void)
{
	m_tInfo.vDir = { 1.f,0.f,0.f };
	D3DXMATRIX		matScale, matRotZ, matTrans;
	
	D3DXMatrixScaling(&matScale, m_fScale, m_fScale, 0.f);
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);

	m_tInfo.matWorld = matScale * matRotZ * matTrans;

	for (int i = 0; i < m_vVertex.size(); ++i)
	{
		D3DXVec3TransformCoord(&m_vVertex[i], &m_vOriVertex[i], &m_tInfo.matWorld);
	}
	D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vDir,&m_tInfo.matWorld);
	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
}

void CObj::Render_Vertex(HDC hDC)
{
	int iScrollX = CScrollMgr::Get_Instance()->Get_ScrollX();
	MoveToEx(hDC, (int)m_vVertex[0].x + iScrollX, (int)m_vVertex[0].y, nullptr);
	for (size_t i = 1; i < m_vVertex.size(); ++i)
	{
		LineTo(hDC, (int)m_vVertex[i].x + iScrollX, (int)m_vVertex[i].y);
	}
	LineTo(hDC, (int)m_vVertex[0].x + iScrollX, (int)m_vVertex[0].y);
}
