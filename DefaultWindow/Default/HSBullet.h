#pragma once
#include "HSObj.h"
class CHSBullet :
	public CHSObj
{
public:
	CHSBullet(D3DXVECTOR3 _DIR, CObj* pObj);
	virtual ~CHSBullet();

	// CHSObj��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;

};

