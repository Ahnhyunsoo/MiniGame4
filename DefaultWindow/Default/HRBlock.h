#pragma once

#include "HRObj.h"

class CHRBlock
	: public CHRObj
{
public:
	CHRBlock();
	~CHRBlock();

public:
	void Set_Scale(float _fX, float _fY);

public:
	virtual		void	Initialize(void);
	virtual		int		Update(void);
	virtual		void	Late_Update(void);
	virtual		void	Render(HDC hDC);
	virtual		void	Release(void);

public:
	virtual		void	OnCollision(DIRECTION _DIR, CObj* _Other);

private:

};