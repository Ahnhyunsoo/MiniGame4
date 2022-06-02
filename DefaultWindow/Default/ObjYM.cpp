#include "stdafx.h"
#include "ObjYM.h"


CObjYM::CObjYM()
{
}


CObjYM::~CObjYM()
{
}

void CObjYM::Initialize(void)
{
}

int CObjYM::Update(void)
{
	return 0;
}

void CObjYM::Late_Update(void)
{
}

void CObjYM::Render(HDC hDC)
{
}

void CObjYM::Release(void)
{
}

void CObjYM::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}

void CObjYM::Update_MatWorld(void)
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
	D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vDir, &m_tInfo.matWorld);
	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
}

void CObjYM::Render_Vertex(HDC hDC)
{
	int iScrollY = CScrollMgr::Get_Instance()->Get_ScrollY();
	MoveToEx(hDC, (int)m_vVertex[0].x + iScrollY, (int)m_vVertex[0].y, nullptr);
	for (size_t i = 1; i < m_vVertex.size(); ++i)
	{
		LineTo(hDC, (int)m_vVertex[i].x + iScrollY, (int)m_vVertex[i].y);
	}
	LineTo(hDC, (int)m_vVertex[0].x + iScrollY, (int)m_vVertex[0].y);
}
