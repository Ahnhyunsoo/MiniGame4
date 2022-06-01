#include "stdafx.h"
#include "BmpMgr.h"


CBmpMgr*		CBmpMgr::m_pInstance = nullptr;

CBmpMgr::CBmpMgr()
{
}

CBmpMgr::~CBmpMgr()
{
	Release();
}

void CBmpMgr::Insert_Bmp(const TCHAR * pFilePath, const TCHAR * pImageKey)
{
	auto		iter = find_if(m_mapBit.begin(), m_mapBit.end(), CTag_Finder(pImageKey));

	if (iter == m_mapBit.end())
	{
		CMyBmp*		pBmp = new CMyBmp;
		pBmp->Load_Bmp(pFilePath);

		m_mapBit.emplace(pImageKey, pBmp);
	}
}

void CBmpMgr::Release_Bmp(const TCHAR * pImageKey)
{
	m_mapBit.erase(pImageKey);
	//for (auto& iter = m_mapBit.begin(); iter != m_mapBit.end();)
	//{
	//	if ((*iter).first == pImageKey)
	//	{

	//	}
	//}	
}

HDC CBmpMgr::Find_Image(const TCHAR * pImageKey)
{
	auto		iter = find_if(m_mapBit.begin(), m_mapBit.end(), CTag_Finder(pImageKey));

	if (iter == m_mapBit.end())
		return nullptr;


	return iter->second->Get_MemDC();
}

void CBmpMgr::Release(void)
{
	for_each(m_mapBit.begin(), m_mapBit.end(), CDeleteMap());
	m_mapBit.clear();
}
