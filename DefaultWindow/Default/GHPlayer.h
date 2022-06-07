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
public:
	void	Set_Skid_Pos(int _iLeft_Middle_Right);
	void	Set_SkidBool();
private:
	void	Key_Input();
	void	Foot_Change();
	void	Jumping();
	void	ModeChange();
	void	Update_SkidWorld();
private:
	int		 m_BodyDistanceX;
	int		 m_BodyDistanceY;
	int		 m_iFloarY;

	int		 m_iFootChangeTime;
	bool	 m_bFoot;
	bool	 m_bJump;
	float	 m_fJumpTime;
	float	 m_fJumpPower;
	DWORD	 m_FootTime;
	DWORD	 m_ScaleTime;
	
	float	m_fRadius;
private:
	DWORD		 m_SororokTime;
	float		  m_fSpinAngle;
	D3DXVECTOR3	  m_vLeft_Middle_Right;
	bool  m_bSkid;
};

