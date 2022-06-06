#pragma once
#include "Obj.h"
class CSTStageName :
	public CObj
{
public:
	CSTStageName();
	virtual ~CSTStageName();

	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;
public:
	void Set_Name(int _iNum);
	const int	Get_Name() { return m_iIndexNum; }
private:
	void Render_Name(HDC hdc);
	int	m_iIndexNum;
};

