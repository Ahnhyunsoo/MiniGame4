#pragma once
#include "HRObj.h"

class CHRMonster
	: public CHRObj
{
	enum STATE { IDLE, MOVE, CHASE, ATTACK, DEAD, END };

public:
	CHRMonster();
	virtual ~CHRMonster();

public:
	void Update_Idle();
	void Update_Move();
	void Update_Attack();
	void Update_Dead();

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
	D3DXVECTOR3 m_vDieDir;

	float m_fKnockTime;
	float m_fDeadTime;
	float m_fOldDeadTime;
};