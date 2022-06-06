#pragma once
#include "GHObj.h"
class CGHSkidLine : public CGHObj
{
public:
	CGHSkidLine();
	CGHSkidLine(bool _bLeft,float _fPlayerCX);

	virtual ~CGHSkidLine();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;
private:
	void	InitialSkidLineDirecton();
	void	InitialReDirection();
	bool	m_bLeft;
	float	m_fPlayerCX;
};

