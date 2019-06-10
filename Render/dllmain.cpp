#include "framework.h"
#include <detours.h>
#pragma comment(lib, "detours.lib")
#include <GL\freeglut.h>

int hookedCreateWindow(const char* title, void(__cdecl* exit_function)(int))
{
	glutInitWindowSize(nWidth, nHeight);

	if (nBorderless)
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_BORDERLESS);
	else
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	/* This won't work, needs to be hooked before sub_14066FD50
	if (nIntRes)
		* resolutionType = 15;
		*/

	if (nFullscreen)
	{
		/* Crashes, no idea why yet
		if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE)) {
			char GameModeString[24];
			sprintf_s(GameModeString, sizeof(GameModeString),"%dx%d:%d@%d", nWidth, nHeight, nBitDepth ,nRefreshRate);
			printf("[Render Manager] Game Mode supported and enabled in replacement of Fullscreen.\n");
			printf(GameModeString);
			glutGameModeString(GameModeString);
			glutEnterGameMode();
		}
		else {*/
		*fullScreenFlag = 1;
		glutCreateWindow(title);
		printf("[Render Manager] Fullscreen enabled.\n");
		//}
	}
	else
	{
		*fullScreenFlag = 0;
		glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - nWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - nHeight) / 2); // Center to the middle of the scree when windowed
		glutCreateWindow(title);
		printf("[Render Manager] Windowed mode.\n");
	}
	return true;
}

BOOL APIENTRY DllMain(HMODULE hModule,
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

