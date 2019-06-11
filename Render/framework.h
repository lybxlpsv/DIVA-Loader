#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <string>

static int(__cdecl* divaCreateWindow)(const char* title, void(__cdecl* exitfunc)(int)) = (int(__cdecl*)(const char* title, void(__cdecl * exitfunc)(int)))0x140194D00;
__int64 (__fastcall* divaParseParameters)(int a1, __int64* a2) = (__int64(__fastcall*)(int a1, __int64* a2))0x140193630;

uint8_t* fullScreenFlag = (uint8_t*)0x140EDA5D1;
DWORD* resolutionType = (DWORD*)0x140EDA5D4;

using namespace std;

string DirPath() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

string CONFIG_FILE_STRING = DirPath() + "\\plugins\\config.ini";
LPCSTR CONFIG_FILE = CONFIG_FILE_STRING.c_str();

int nFullscreen = GetPrivateProfileInt("resolution", "fullscreen", TRUE, CONFIG_FILE);
int nBorderless = GetPrivateProfileInt("resolution", "borderless", FALSE, CONFIG_FILE);
int nWidth = GetPrivateProfileInt("resolution", "width", 1280, CONFIG_FILE);
int nHeight = GetPrivateProfileInt("resolution", "height", 720, CONFIG_FILE);
int nRefreshRate = GetPrivateProfileInt("resolution", "refreshrate", 60, CONFIG_FILE);
int nBitDepth = GetPrivateProfileInt("resolution", "bitdepth", 32, CONFIG_FILE);

int nIntRes = GetPrivateProfileInt("resolution", "r.enable", FALSE, CONFIG_FILE);
int nIntResWidth = GetPrivateProfileInt("resolution", "r.width", 1280, CONFIG_FILE);
int nIntResHeight = GetPrivateProfileInt("resolution", "r.height", 720, CONFIG_FILE);

int nStereo = GetPrivateProfileInt("patches", "stereo", FALSE, CONFIG_FILE);
int nCursor = GetPrivateProfileInt("patches", "cursor", TRUE, CONFIG_FILE);
int nTAA = GetPrivateProfileInt("graphics", "TAA", TRUE, CONFIG_FILE);
int nMLAA = GetPrivateProfileInt("graphics", "MLAA", TRUE, CONFIG_FILE);

int nFPSLimit = GetPrivateProfileInt("graphics", "FPS.Limit", 0, CONFIG_FILE);

//auto nBitDepth = GetPrivateProfileIntW(L"resolution", L"bitdepth", 32, CONFIG_FILE);
//auto nRefreshRate = GetPrivateProfileIntW(L"resolution", L"refreshrate", 60, CONFIG_FILE);

