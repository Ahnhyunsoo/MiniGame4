#pragma once
#include "GHObj.h"
class CGHPlayer : public CGHObj
{
public:
	CGHPlayer();
	virtual ~CGHPlayer();
public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;
private:
	void	Key_Input();
	void	Foot_Change();
	void	Jumping();
private:
	int	  m_BodyDistanceX;
	int	  m_BodyDistanceY;
	int	  m_iFloarY;

	int	  m_iFootChangeTime;
	bool  m_bFoot;
	bool  m_bJump;
	float m_fJumpTime;
	float m_fJumpPower;
	DWORD m_FootTime;
	DWORD m_ScaleTime;
};

