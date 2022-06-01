#pragma once

#include "Include.h"
#include "ScrollMgr.h"
#include "SceneMgr.h"
#include "KeyMgr.h"

class CollisionMgr;
class CObjMgr;

class CObj
{
public:
	CObj();
	virtual ~CObj();
	
public:
	const INFO&				Get_Info(void) const { return m_tInfo; }
	
	void Set_vPos(float fX, float fY) { m_tInfo.vPos.x = fX, m_tInfo.vPos.y = fY; }
	void Set_vPosX(float fX) { m_tInfo.vPos.x += fX; }
	void Set_vPosY(float fY) { m_tInfo.vPos.y += fY; }
	void Set_Dead(void) { m_bDead = true; }

public:
	virtual		void	Initialize(void)	PURE;
	virtual		int		Update(void)		PURE;
	virtual		void	Late_Update(void)   PURE;
	virtual		void	Render(HDC hDC)		PURE;
	virtual		void	Release(void)		PURE;

public:
	virtual		void	OnCollision(DIRECTION _DIR, CObj* _Other) PURE;

public:
	void Update_MatWorld(void);
	void Render_Vertex(HDC hDC);
protected:
	INFO		m_tInfo;
	float		m_fAngle;
	float		m_fSpeed;
	float		m_fScale;

	bool		m_bDead;

protected:
	vector<D3DXVECTOR3> m_vVertex;
	vector<D3DXVECTOR3> m_vOriVertex;
	//vector<int> m_vInt;
	


};

