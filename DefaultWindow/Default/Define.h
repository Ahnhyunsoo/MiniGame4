#pragma once

#define		WINCX		800
#define		WINCY		600

#define		PI			3.141592f

#define		PURE		= 0
#define		VK_MAX		 0xff
#define		OBJ_DEAD 1
#define		OBJ_NOEVENT 0

#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif
extern HWND			g_hWnd;
extern float		g_GHfSound;
extern DWORD		g_dwGHBGMStartTime;
