#pragma once
#include "GHObj.h"
#include "GHLine.h"

class CGHFloar : public CGHObj
{
public:
	CGHFloar();
	~CGHFloar();
public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;
private:
	void	LineOn();
	void	Line_Nail_Down();
	void	Initialize_Floar();
public:
	void	SetReDirection();
	void	Set_Floar(int _iIndex, bool _bFirst) { m_iFloarIndex = _iIndex; m_bFirst = _bFirst; }
	bool	Get_First() { return m_bFirst; }
	int		Get_FloarIndex() { return m_iFloarIndex; }
private:
	int		m_iFloarIndex;
	bool	m_bLeft;
	bool	m_bFirst;
	CGHLine	m_KyuLine;
	DWORD	m_ScaleDelayTime;
	DWORD	m_RedirectionDelayTime;
};

