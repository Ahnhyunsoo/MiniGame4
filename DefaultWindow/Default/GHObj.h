#pragma once
#include "Obj.h"
class CGHObj :
	public CObj
{
public:
	CGHObj();
	~CGHObj();
public:
	enum eGHObjString { STRING_PLAYER, STRING_FLOAR, STRING_BUTTON };
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;
public:
	 int Get_GHString() { return m_eString; }



	eGHObjString m_eString;
};

