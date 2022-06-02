#pragma once
#include "Obj.h"
#include "Include.h"
#include "ScrollMgr.h"
#include "SceneMgr.h"
#include "KeyMgr.h"


class CObjYM :
	public CObj
{
public:
	CObjYM();
	virtual ~CObjYM();


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
};

