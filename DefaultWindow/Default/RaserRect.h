#pragma once
#include "HSObj.h"
class CRaserRect :
	public CHSObj
{
public:
	CRaserRect(D3DXVECTOR3 _DIR);
	virtual ~CRaserRect();

	// CHSObj��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;
};

