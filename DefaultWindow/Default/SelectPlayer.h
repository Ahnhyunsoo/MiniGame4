#pragma once
#include "Obj.h"
class CSelectPlayer :
	public CObj
{
public:
	CSelectPlayer();
	virtual ~CSelectPlayer();

public:
	void Key_Input(void);
	void OffSet(void);

	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;
public:
	void	Set_Stage_STPlayerPos();
private:
	bool	m_bStageStartPlayer;
};

