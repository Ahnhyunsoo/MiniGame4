#pragma once

#include "HRObj.h"

class CHRPlayerHP
	: public CHRObj
{
	enum STATE { IDLE, MOVE, HANG, ATTACK, DESH, END };

public:
	CHRPlayerHP();
	virtual ~CHRPlayerHP();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	virtual		void	OnCollision(DIRECTION _DIR, CObj* _Other);

};
