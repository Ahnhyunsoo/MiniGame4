#include "stdafx.h"
#include "GHObj.h"


CGHObj::CGHObj() : m_bflip{ false }
{
}


CGHObj::~CGHObj()
{
}

void CGHObj::Initialize(void)
{
}

int CGHObj::Update(void)
{
	return 0;
}

void CGHObj::Late_Update(void)
{
}

void CGHObj::Render(HDC hDC)
{
}

void CGHObj::Release(void)
{
}

void CGHObj::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}

void CGHObj::Set_GHFlip()
{
}
