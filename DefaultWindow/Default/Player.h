#pragma once
#include "Obj.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;

private:
	void		Key_Input(void);


private:
	D3DXVECTOR3			m_vPoint[4];
	D3DXVECTOR3			m_vOriginPoint[4];

	D3DXVECTOR3			m_vGunPoint;
	D3DXVECTOR3			m_vOriginGunPoint;

	float				m_fGunAngle = 0.f;



	// CObj??(??) ???? ???ӵ?
	

	/*

	D3DXVECTOR3		m_vPlayerPos;	// ??ġ ????
	
	D3DXVECTOR3		m_vPlayerDir;	// ???? ????
	D3DXVECTOR3		m_vPlayerLook;	// ???? ????

	D3DXVECTOR3		m_vPlayerNormal;	// ???? ????*/
};

	