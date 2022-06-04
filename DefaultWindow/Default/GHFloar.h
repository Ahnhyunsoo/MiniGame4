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
	void	Set_Floar(int _iIndex, bool _bFirst) { m_iFloarIndex = _iIndex; m_bFirst = _bFirst; }
	bool	Get_First() { return m_bFirst; }
private:
	int		m_iFloarIndex;
	bool	m_bFirst;
	CGHLine  m_KyuLine;
	DWORD	 m_ScaleDelayTime;
};

