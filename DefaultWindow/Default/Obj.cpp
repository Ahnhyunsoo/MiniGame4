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

void CObj::ColRender(HDC hDC)
{
	HPEN hpen;
	HPEN hpenOld;

	hpen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));   // 선 스타일, 굵기, 색상
	hpenOld = (HPEN)::SelectObject(hDC, (HGDIOBJ)hpen);   // 펜 선택

	Rectangle(hDC,
		m_tInfo.vPos.x - m_tInfo.fCX * 0.5f,
		m_tInfo.vPos.y - m_tInfo.fCY * 0.5f,
		m_tInfo.vPos.x + m_tInfo.fCX * 0.5f,
		m_tInfo.vPos.y + m_tInfo.fCY * 0.5f);

	hpen = (HPEN)SelectObject(hDC, hpenOld);   // 기존의 펜 다시 선택
	DeleteObject(hpen);   // 생성한 펜 삭제
}

void CObj::Update_MatWorld(void)
{
	m_tInfo.vDir = { 1.f,0.f,0.f };
	D3DXMATRIX		matScale, matRotZ, matTrans;

	D3DXMatrixScaling(&matScale, m_fScale, m_fScale, 0.f);
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);

	m_tInfo.matWorld = matScale * matRotZ * matTrans;

	for (size_t i = 0; i < m_vVertex.size(); ++i)
	{
		D3DXVec3TransformCoord(&m_vVertex[i], &m_vOriVertex[i], &m_tInfo.matWorld);
	}
	D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vDir, &m_tInfo.matWorld);
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
