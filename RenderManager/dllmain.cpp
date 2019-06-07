// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <windows.h>
#include <detours.h>
#pragma comment(lib, "detours.lib")
#include <GL\glut.h>
#include <tchar.h>
#include <stdio.h>
#include <string>

static int(__cdecl* divaCreateWindow)(const char* title, void(__cdecl* exitfunc)(int)) = (int(__cdecl*)(const char* title, void(__cdecl * exitfunc)(int)))0x140194D00;

using namespace std;

const LPCTSTR CONFIG_FILE_NAME = _T(".\\plugins\\config.ini");

int hookedCreateWindow(const char* title, void(__cdecl* exit_function)(int))
{
	auto nFullscreen = GetPrivateProfileIntW(L"resolution", L"fullscreen", TRUE, CONFIG_FILE_NAME);
	auto nWidth = GetPrivateProfileIntW(L"resolution", L"width", 1280, CONFIG_FILE_NAME);
	auto nHeight = GetPrivateProfileIntW(L"resolution", L"height", 720, CONFIG_FILE_NAME);
	auto nBitDepth = GetPrivateProfileIntW(L"resolution", L"bitdepth", 32, CONFIG_FILE_NAME);
	auto nRefreshRate = GetPrivateProfileIntW(L"resolution", L"refreshrate", 60, CONFIG_FILE_NAME);

	glutInitWindowSize(nWidth, nHeight);

	if (nFullscreen)
	{
		if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE)) {
			char GameModeString[24];
			sprintf_s(GameModeString, sizeof(GameModeString),"%dx%d:%d@%d", nWidth, nHeight, nBitDepth ,nRefreshRate);
			printf("[Render Manager] Game Mode supported and enabled in replacement of Fullscreen.\n");
			printf(GameModeString);
			glutGameModeString(GameModeString);
			glutEnterGameMode();
		}
		else {
			
			glutCreateWindow(title);
			printf("[Render Manager] Fullscreen enabled.\n");

			// To be implemented, to replace or hook

			//cmp     cs:byte_140EDA5D1, 0
			//jz      short loc_14019341A

			//^ glutFullScreen();
		}
	}
	else
	{		
		glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - nWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - nHeight) / 2); // Center to the middle of the scree when windowed
		glutCreateWindow(title);
		printf("[Render Manager] Windowed mode.\n");
	}
	return true;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
		DisableThreadLibraryCalls(hModule);

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(PVOID&)divaCreateWindow, hookedCreateWindow);
		DetourTransactionCommit();
    }
    return TRUE;
}