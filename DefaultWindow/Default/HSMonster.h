#pragma once
#include "HSObj.h"
#include "Include.h"
class CHSMonster :
	public CHSObj
{
public:
	CHSMonster(CScene* _pScene);
	virtual ~CHSMonster();

public:
	void Update_Dir();
	void Move_Monster();
public:
	// CHSObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;

	static int g_iMonsterHp;
	static float g_fMonsterSpeed;
private:
	DWORD m_LCollision;
	D3DXVECTOR3 m_vPt[15];
	int m_iDirNum;
	CScene* m_pScene;
};

