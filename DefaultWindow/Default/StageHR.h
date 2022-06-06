#pragma once
#include "Scene.h"
class CStageHR :
	public CScene
{
public:
	CStageHR();
	virtual ~CStageHR();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	float m_dwOldTime;
	float m_dwLateOldTime;

};

