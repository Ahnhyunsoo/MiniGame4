#pragma once
#include "Scene.h"
class CStageHS :
	public CScene
{
public:
	CStageHS();
	virtual ~CStageHS();

public:
	void Draw_Rect(HDC hDC);
	void Draw_UI(HDC hDC);

public:
	// CScene을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	static int g_iHP;
	static int g_iGold;
	static int g_iKill;
private:
	DWORD m_LSponMonster;
	int m_iMaxMonster;
	int m_iNowMonster;
	int m_iSponSpeed;

};

