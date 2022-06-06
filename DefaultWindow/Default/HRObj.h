#pragma once
#include "Obj.h"

typedef struct RecordData
{
	D3DXVECTOR3 m_vRecord;
	bool m_bDead;

	RecordData(float _X, float _Y, bool _Dead)
	{
		m_vRecord.x = _X;
		m_vRecord.y = _Y;
		m_vRecord.z = 0.f;
		m_bDead = _Dead;
	}

} RECORD;


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
	void Update_Record();
	void Update_BackRecord();


	void Render_Vertex(HDC hDC);

protected:
	D3DXVECTOR3 m_vTempPos;
	vector<RECORD> m_vRecords;

	float m_fValY;
	float m_fValX;
	float m_fRemitSpeed;

	float m_fJumpPower;

	bool  m_bOnAir;
	bool  m_bJump;
	bool  m_bMove;
	bool  m_bRecord;
	bool  m_bRealDead;

	string m_sTag;
};