#pragma once
#include "GHObj.h"
class CGHHeros_Of_Stone :public CGHObj
{
public:
	CGHHeros_Of_Stone();
	~CGHHeros_Of_Stone();

	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;

};

