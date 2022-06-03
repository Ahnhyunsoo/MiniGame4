#pragma once

#include "HRObj.h"

class CHRPlayer
	: public CHRObj
{
	enum STATE{IDLE, MOVE, HANG, ATTACK, DESH, END};

public:
	CHRPlayer();
	virtual ~CHRPlayer();

public:
	void KeyInput();
	void PosinUpdate();
	void DeshUpdate();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	virtual		void	OnCollision(DIRECTION _DIR, CObj* _Other);

private:
	STATE m_eState;
	DIRECTION m_eHangDir;

	D3DXVECTOR3 m_fPosinDir;
	D3DXVECTOR3 m_fDeshDir;

	float m_fDeshTime;
	float m_fOldDeshTime;
};