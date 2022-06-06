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

	float Get_Lazer() { return m_LazerGauge;}
	int Get_Boom() { return m_iBoom; }
	int Get_Level() { return m_iLevel; }

private:
	D3DXVECTOR3 m_vTarget;
	float		m_fMouse;
	bool		m_bSlide;

	float		m_LazerGauge;
	int			m_iCountLazer;
	bool		m_bLazer;
	int			m_iLevel;

	int			m_iBoomCount;
	bool		m_bBoom;
	int			m_iBoom;
};

