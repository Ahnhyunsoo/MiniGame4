#pragma once

typedef	struct tagInfo
{
	D3DXVECTOR3		vPos;
	D3DXVECTOR3		vDir;
	D3DXVECTOR3		vLook;

	D3DXMATRIX		matWorld;		

	float fCX;
	float fCY;

}INFO;


typedef	struct	tagLineInfo
{
	D3DXVECTOR3		tLPoint;
	D3DXVECTOR3		tRPoint;

	tagLineInfo() { ZeroMemory(this, sizeof(tagLineInfo)); }
	tagLineInfo(D3DXVECTOR3& tLeft, D3DXVECTOR3& tRight) : tLPoint(tLeft), tRPoint(tRight) {	}

}GYULINE;