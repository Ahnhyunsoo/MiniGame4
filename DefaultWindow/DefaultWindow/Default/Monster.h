#pragma once
#include "Obj.h"
class CMonster :
	public CObj
{
public:
	CMonster();
	virtual ~CMonster();

public:
	void		Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;

private:
	CObj*		m_pPlayer = nullptr;


	// CObj을(를) 통해 상속됨
	

};

