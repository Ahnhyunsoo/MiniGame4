#pragma once
#include "HSObj.h"
class CGunTower :
	public CHSObj
{
public:
	CGunTower();
	virtual ~CGunTower();
public:
	
	// CHSObj��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;
};

