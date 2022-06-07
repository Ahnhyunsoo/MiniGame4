#pragma once
#include "Obj.h"
class CGHObj :
	public CObj
{
public:
	CGHObj();
	~CGHObj();
public:
	enum eGHObjString { STRING_PLAYER, STRING_FLOAR, STRING_BUTTON,STRING_HOS };
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;
public:
	 int Get_GHString() { return m_eString; }
	 void Set_GHFlip();
protected:
	bool		m_bflip;
	float		m_SkidAngle;
	 
	eGHObjString m_eString;
};

