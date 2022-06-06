#pragma once

#include "Obj.h"

class CCameraMgr
{
private:
	CCameraMgr();
	~CCameraMgr();


#pragma region Ins
public:
	static		CCameraMgr* Get_Instance(void)
	{
		if (!m_pInstance)
		{
			m_pInstance = new CCameraMgr;
		}

		return m_pInstance;
	}

	static	void	Destroy_Instance(void)
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CCameraMgr* m_pInstance;
#pragma endregion


public:
	void		StartShake(float _fShakeValue, float _fShakeSpeed, float _fTime, float _fATime = 0.f);
	void		StartScale(CObj* _pTarget);

public:
	void		Set_Target(CObj* _pTarget) 
	{ 
		if(m_pTempTarget == nullptr)
			m_pTempTarget = _pTarget;

		m_pTarget = _pTarget;
	}

	float		Get_ScrollX(void) { return m_fScrollX; }
	float		Get_ScrollY(void) { return m_fScrollY; }

	bool		Get_IsScaling(void) { return m_bScale; }

	void		ScaleObj(OBJID _eID);

public:
	void		Update_Nomal(void);
	void		Update_Shake(void);
	void		Update_Scale(void);

public:
	void		Initialize(void);
	void		Update(void);

private:
	CObj*					m_pTarget;
	CObj*					m_pTempTarget;

	float					m_fScrollX;
	float					m_fScrollY;

	bool					m_bMoveX;
	bool					m_bMoveY;

	bool					m_bShake;
	bool					m_bShakeTurn;
	float					m_bShakeTemp;
	float					m_fShakeValue;
	float					m_fShakeTime;
	float					m_fShakeOldTime;
	float					m_fShakeSpeed;

	float					m_fATime;
	float					m_fOldATime;

	bool					m_bScale;
	float					m_fScaleValue;
	float					m_fScaleTime;
	float					m_fScaleOldTime;

};

