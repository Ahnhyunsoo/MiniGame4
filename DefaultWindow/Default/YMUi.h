#pragma once
#include "ObjYM.h"
class CYMUi :
	public CObjYM
{
public:
	CYMUi();
	virtual ~CYMUi();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;

	void	Boss_Start(bool _Boss) {  m_bBossStart = _Boss; }
	void	Set_BossHp(int _BossHp) { m_iBossHp = _BossHp; }
	
private:
	int		m_iCount2P;
	bool	m_b2P;
	float	m_fLazer;

	int		m_iBoom;
	int		m_iLevel;
	D3DXVECTOR3	m_vBoom;

	bool	m_bBossStart;
	int		m_iBossHp;
};

