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

typedef	struct	tagLinePoint
{
	float		fX;
	float		fY;

	tagLinePoint() { ZeroMemory(this, sizeof(tagLinePoint)); }
	tagLinePoint(float _fX, float _fY) : fX(_fX), fY(_fY) {	}

}LINEPOINT;

typedef	struct	tagLineInfo
{
	LINEPOINT		tLPoint;
	LINEPOINT		tRPoint;

	tagLineInfo() { ZeroMemory(this, sizeof(tagLineInfo)); }
	tagLineInfo(LINEPOINT& tLeft, LINEPOINT& tRight) : tLPoint(tLeft), tRPoint(tRight) {	}

}LINE;


typedef	struct	tagLineInfo1
{
	D3DXVECTOR3		tLPoint;
	D3DXVECTOR3		tRPoint;

	tagLineInfo1() { ZeroMemory(this, sizeof(tagLineInfo1)); }
	tagLineInfo1(D3DXVECTOR3& tLeft, D3DXVECTOR3& tRight) : tLPoint(tLeft), tRPoint(tRight) {	}

}GYULINE;
