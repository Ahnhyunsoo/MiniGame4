#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
	: m_fSpeed(0.f),m_fAngle(0.f)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));

	D3DXMatrixIdentity(&m_tInfo.matWorld);

}

CObj::~CObj()
{
}

//void CObj::Update_MatWorld(void)
//{
//	D3DXMATRIX		matScale, matRotZ, matTrans;
//
//	D3DXMatrixScaling(&matScale, -1.f, 1.f, 0.f);
//	D3DXMatrixRotationZ(&matRotZ, m_fAngle);
//	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);
//
//	m_tInfo.matWorld = matScale * matRotZ * matTrans;
//
//	D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
//}
//인자로 백터배열을 받아서 그배열인덱스접근으로 적용해줄지말지 고민중
