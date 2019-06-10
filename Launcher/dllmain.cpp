#include "ui.h"
#include "framework.h"
#include <detours.h>
#pragma comment(lib, "detours.lib")
#include <GL\freeglut.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int showUI() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Launcher::ui());
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		// Not working, console is shown black and nothing happens
		// Working at "hookedCreateWindow" under Render plugin but the problem is that the parameters are already loaded at that point
		// and modifying them on the launcher won't work until the next launch
		// This plugin must be loaded before any other plugin that uses any of the .ini parameters so those are read after modified.
		// DIVA-Loader loads by name order, so placing a ! before the name should always load it first

		// showUI();
	}
	return TRUE;
}