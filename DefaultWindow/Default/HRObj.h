#pragma once
#include "Obj.h"
class CHRObj :
	public CObj
{
public:
	CHRObj();
	virtual ~CHRObj();

public:
	const string Get_Tag() { return m_sTag; }
	

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

protected:
	void Update_Gravity();
	void Render_Vertex(HDC hDC);

protected:
	D3DXVECTOR3 m_vTempPos;

	float m_fValY;
	float m_fValX;
	float m_fRemitSpeed;

	float m_fJumpPower;

	bool  m_bOnAir;
	bool  m_bJump;
	bool  m_bMove;

	string m_sTag;
};