#pragma once
#include "Scene.h"
class CStageGH : public CScene
{
public:
	CStageGH();
	virtual ~CStageGH();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
private:
	void	Create_Floar();
	void	Key_Input();
private:
	bool	m_bFloarCreate;
	bool	m_bStart;
	DWORD	m_ScrollZ;
	DWORD	m_ScrollTime;
};
