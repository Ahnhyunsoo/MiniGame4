#pragma once
#include "HRObj.h"

class CHRMonster
	: public CHRObj
{
	enum STATE { IDLE, MOVE, HANG, ATTACK, DESH, END };

public:
	CHRMonster();
	virtual ~CHRMonster();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	virtual		void	OnCollision(DIRECTION _DIR, CObj* _Other);

private:


};