#include <iostream>
#include <vector>
#include <Windows.h>
#include <Dbt.h>
#include <stdio.h>
#include "Constants.h"
#include "framework.h"
#include "Input/Mouse/Mouse.h"
#include "Input/Xinput/Xinput.h"
#include "Input/Keyboard/Keyboard.h"
#include "Input/DirectInput/DirectInput.h"
#include "Input/DirectInput/Ds4/DualShock4.h"
#include "Components/ComponentsManager.h"
#include <tchar.h>
LRESULT CALLBACK MessageWindowProcessCallback(HWND, UINT, WPARAM, LPARAM);
DWORD WINAPI WindowMessageDispatcher(LPVOID);
VOID RegisterMessageWindowClass();

struct
{
	DWORD ID = NULL;
	HANDLE Handle = NULL;
} MessageThread;

const wchar_t *MessageWindowClassName = TEXT("MessageWindowClass");
const wchar_t *MessageWindowName = TEXT("MessageWindowTitle");

namespace TLAC
{
	Components::ComponentsManager ComponentsManager;
	bool DeviceConnected = true;
	bool FirstUpdateTick = true;
	bool HasWindowFocus, HadWindowFocus;

	void InstallCustomResolution()
	{

	}

	void* InstallHook(void* source, void* destination, int length)
	{
		const DWORD minLen = 0xE;

		if (length < minLen)
			return NULL;

		BYTE stub[] =
		{
			0xFF, 0x25, 0x00, 0x00, 0x00, 0x00, // jmp qword ?ptr [$+6]
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 // ptr???
		};

		void* trampoline = VirtualAlloc(0, length + sizeof(stub), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

		DWORD oldProtect;
		VirtualProtect(source, length, PAGE_EXECUTE_READWRITE, &oldProtect);

		DWORD64 returnAddress = (DWORD64)source + length;

		// trampoline
		memcpy(stub + 6, &returnAddress, 8);

		memcpy((void*)((DWORD_PTR)trampoline), source, length);
		memcpy((void*)((DWORD_PTR)trampoline + length), stub, sizeof(stub));

		// orig
		memcpy(stub + 6, &destination, 8);
		memcpy(source, stub, sizeof(stub));

		for (int i = minLen; i < length; i++)
			*(BYTE*)((DWORD_PTR)source + i) = NOP_OPCODE;

		VirtualProtect(source, length, oldProtect, &oldProtect);

		return (void*)((DWORD_PTR)trampoline);
	}

	void InitializeTick()
	{
		RegisterMessageWindowClass();
		if ((MessageThread.Handle = CreateThread(0, 0, WindowMessageDispatcher, 0, 0, 0)) == NULL)
			printf("[TLAC] InitializeTick(): CreateThread() Error: %d\n", GetLastError());

		framework::DivaWindowHandle = FindWindow(0, framework::DivaWindowName);
		if (framework::DivaWindowHandle == NULL)
			framework::DivaWindowHandle = FindWindow(0, framework::GlutDefaultName);

		HRESULT diInitResult = Input::InitializeDirectInput(framework::Module);
		if (FAILED(diInitResult))
			printf("[TLAC] InitializeTick(): Failed to initialize DirectInput. Error: 0x%08X\n", diInitResult);

		ComponentsManager.Initialize();
	}

	void UpdateTick()
	{
		if (FirstUpdateTick)
		{
			FirstUpdateTick = false;
			InitializeTick();
		}

		if (DeviceConnected)
		{
			DeviceConnected = false;

			if (!Input::DualShock4::InstanceInitialized())
			{
				if (Input::DualShock4::TryInitializeInstance())
					printf("[TLAC] UpdateTick(): DualShock4 connected and initialized\n");
			}
		}

		ComponentsManager.Update();

		HadWindowFocus = HasWindowFocus;
		HasWindowFocus = framework::DivaWindowHandle == NULL || GetForegroundWindow() == framework::DivaWindowHandle;

		if ((HasWindowFocus) && (!framework::inputDisable))
		{
			Input::Keyboard::GetInstance()->PollInput();
			Input::Mouse::GetInstance()->PollInput();
			Input::Xinput::GetInstance()->PollInput();

			if (Input::DualShock4::GetInstance() != nullptr)
			{
				if (!Input::DualShock4::GetInstance()->PollInput())
				{
					Input::DualShock4::DeleteInstance();
					printf("[TLAC] UpdateTick(): DualShock4 connection lost\n");
				}
			}

			ComponentsManager.UpdateInput();
		}

		if ((framework::inputDisable))
		{
			Input::Keyboard::GetInstance()->PollInput();
			Input::Mouse::GetInstance()->PollInput();
			Input::Xinput::GetInstance()->PollInput();

			if (Input::DualShock4::GetInstance() != nullptr)
			{
				if (!Input::DualShock4::GetInstance()->PollInput())
				{
					Input::DualShock4::DeleteInstance();
					printf("[TLAC] UpdateTick(): DualShock4 connection lost\n");
				}
			}
		}

		if (HasWindowFocus && !HadWindowFocus)
			ComponentsManager.OnFocusGain();

		if (!HasWindowFocus && HadWindowFocus)
			ComponentsManager.OnFocusLost();
	}

	void InitializeExtraSettings()
	{
		const LPCTSTR RESOLUTION_CONFIG_FILE_NAME = _T(".\\config.ini");
		auto nCustomRes = GetPrivateProfileIntW(L"resolution", L"r.enable", FALSE, RESOLUTION_CONFIG_FILE_NAME);
		auto nMaxWidth = GetPrivateProfileIntW(L"resolution", L"r.width", NULL, RESOLUTION_CONFIG_FILE_NAME);
		auto nMaxHeight = GetPrivateProfileIntW(L"resolution", L"r.height", NULL, RESOLUTION_CONFIG_FILE_NAME);
		auto nTAA = GetPrivateProfileIntW(L"graphics", L"taa", TRUE, RESOLUTION_CONFIG_FILE_NAME);
		auto nMLAA = GetPrivateProfileIntW(L"graphics", L"mlaa", TRUE, RESOLUTION_CONFIG_FILE_NAME);

		int maxWidth = 2560;
		int maxHeight = 1440;

		if (nCustomRes)
		{
			printf("[TLAC] Custom internal resolution enabled\n");
			if (nMaxWidth != NULL)
			{
				maxWidth = nMaxWidth;
			}
			if (nMaxHeight != NULL)
			{
				maxHeight = nMaxHeight;
			}
			printf("[TLAC] X: %d Y: %d\n", nMaxWidth, nMaxHeight);
			{
				DWORD oldProtect, bck;
				VirtualProtect((BYTE*)0x00000001409B8B30, 4, PAGE_EXECUTE_READWRITE, &oldProtect);
				*((int*)0x00000001409B8B30) = maxWidth;
				VirtualProtect((BYTE*)0x00000001409B8B30, 6, oldProtect, &bck);
			}
			{
				DWORD oldProtect, bck;
				VirtualProtect((BYTE*)0x00000001409B8B34, 4, PAGE_EXECUTE_READWRITE, &oldProtect);
				*((int*)0x00000001409B8B34) = maxHeight;
				VirtualProtect((BYTE*)0x00000001409B8B34, 6, oldProtect, &bck);
			}
			//*((int*)0x00000001409B8B6C) = maxHeight;
			//*((int*)0x00000001409B8B14) = maxWidth;
			//*((int*)0x00000001409B8B18) = maxHeight;
		}
		if (!nTAA)
		{
			DWORD oldProtect, bck;
			VirtualProtect((BYTE*)0x00000001411AB67C, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
			*((byte*)0x00000001411AB67C + 0) = 0x00;
			VirtualProtect((BYTE*)0x00000001411AB67C, 1, oldProtect, &bck);

			printf("[TLAC] TAA disabled\n");
		}
		if (!nMLAA)
		{
			DWORD oldProtect, bck;
			VirtualProtect((BYTE*)0x00000001411AB680, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
			*((byte*)0x00000001411AB680 + 0) = 0x00;
			VirtualProtect((BYTE*)0x00000001411AB680, 1, oldProtect, &bck);

			printf("[TLAC] MLAA disabled\n");
		}


	}

	void InstallHooks()
	{
		HWND consoleHandle = GetConsoleWindow();
		ShowWindow(consoleHandle, SW_HIDE);
		InstallHook((void*)ENGINE_UPDATE_HOOK_TARGET_ADDRESS, (void*)UpdateTick, 0xE);
		InitializeExtraSettings();
	}

	void Dispose()
	{
		ComponentsManager.Dispose();

		delete Input::Keyboard::GetInstance();
		delete Input::Mouse::GetInstance();
		delete Input::DualShock4::GetInstance();

		Input::DisposeDirectInput();

		PostThreadMessage(MessageThread.ID, WM_QUIT, 0, 0);
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		printf("[TLAC] DllMain(): Installing hooks...\n");

		TLAC::InstallHooks();
		TLAC::framework::Module = hModule;
		break;

	case DLL_PROCESS_DETACH:
		TLAC::Dispose();
		break;
	}

	return TRUE;
}

DWORD WINAPI WindowMessageDispatcher(LPVOID lpParam)
{
	HWND windowHandle = CreateWindowW(
		MessageWindowClassName,
		MessageWindowName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL,
		TLAC::framework::Module,
		NULL);

	if (!windowHandle)
	{
		printf("[TLAC] WindowMessageDispatcher(): CreateWindowW() Error: %d\n", GetLastError());
		return 1;
	}

	MessageThread.ID = GetCurrentThreadId();

	MSG message;
	DWORD returnValue;

	printf("[TLAC] WindowMessageDispatcher(): Entering message loop...\n");

	while (1)
	{
		returnValue = GetMessage(&message, NULL, 0, 0);
		if (returnValue != -1)
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			printf("[TLAC] WindowMessageDispatcher(): GetMessage() Error: %d\n", returnValue);
		}
	}

	DestroyWindow(windowHandle);
	return 0;
}

BOOL RegisterDeviceInterface(HWND hWnd, HDEVNOTIFY *hDeviceNotify)
{
	DEV_BROADCAST_DEVICEINTERFACE NotificationFilter = {};

	NotificationFilter.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
	NotificationFilter.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;

	*hDeviceNotify = RegisterDeviceNotification(hWnd, &NotificationFilter, DEVICE_NOTIFY_ALL_INTERFACE_CLASSES);

	return *hDeviceNotify != NULL;
}

LRESULT CALLBACK MessageWindowProcessCallback(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		HDEVNOTIFY hDevNotify = NULL;

		if (!RegisterDeviceInterface(hWnd, &hDevNotify))
			printf("[TLAC] MessageWindowProcessCallback(): RegisterDeviceInterface() Error: %d\n", GetLastError());

		break;
	}

	case WM_DEVICECHANGE:
	{
		switch (wParam)
		{
		case DBT_DEVICEARRIVAL:
			TLAC::DeviceConnected = true;
			break;

		default:
			break;
		}
	}

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

VOID RegisterMessageWindowClass()
{
	WNDCLASS windowClass = { };

	windowClass.lpfnWndProc = MessageWindowProcessCallback;
	windowClass.hInstance = TLAC::framework::Module;
	windowClass.lpszClassName = MessageWindowClassName;

	RegisterClass(&windowClass);
}
