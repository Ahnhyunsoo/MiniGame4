#pragma once
#include "Obj.h"
class CSelectPlayer :
	public CObj
{
public:
	CSelectPlayer();
	virtual ~CSelectPlayer();

public:
	void Key_Input(void);
	void Update_Cart(void);
	void OffSet(void);

	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;



private:
	D3DXVECTOR3 m_vCart[4];
	D3DXVECTOR3 m_vOriginCart[4];
};

