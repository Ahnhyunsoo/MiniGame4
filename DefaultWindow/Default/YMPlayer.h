#pragma once
#include "ObjYM.h"
class CYMPlayer :
	public CObjYM
{
public:
	CYMPlayer();
	~CYMPlayer();

public:
	void Key_Input(void);
	D3DXVECTOR3 Get_Mouse(void);

	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;

};

