#pragma once
#include "Obj.h"

template <typename T>
class CAbstractFactory
{
public:
	CAbstractFactory()
	{
	}

	~CAbstractFactory()
	{
	}

public:
	static CObj* Create()
	{
		CObj* _Temp = new T;
		_Temp->Initialize();
		return _Temp;
	}
};