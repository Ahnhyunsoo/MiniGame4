#pragma once
#include "GHObj.h"
class CGHButton : public CGHObj
{
public:
	CGHButton();
	~CGHButton();
public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;
public:
	void	Set_bPress() { m_bPress = true; }
private:
	bool	m_bPress;
};

