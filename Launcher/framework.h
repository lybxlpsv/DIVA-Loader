#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <string>

int (__cdecl* divaMain)(int argc, const char** argv, const char** envp) = (int(__cdecl*)(int argc, const char** argv, const char** envp))0x140194D90;

using namespace std;

string arg;

string DirPath() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

string CONFIG_FILE_STRING = DirPath() + "\\plugins\\config.ini";
string DIVA_EXECUTABLE_STRING = DirPath() + "\\diva.exe";
string DIVA_EXECUTABLE_LAUNCH_STRING = DirPath() + "\\diva.exe --launch";
LPCSTR DIVA_EXECUTABLE = DIVA_EXECUTABLE_STRING.c_str();
LPSTR DIVA_EXECUTABLE_LAUNCH = const_cast<char*>(DIVA_EXECUTABLE_LAUNCH_STRING.c_str());
LPCSTR CONFIG_FILE = CONFIG_FILE_STRING.c_str();

int nFullscreen = GetPrivateProfileInt("resolution", "fullscreen", TRUE, CONFIG_FILE);
int nBorderless = GetPrivateProfileInt("resolution", "borderless", FALSE, CONFIG_FILE);
int nWidth = GetPrivateProfileInt("resolution", "width", 1280, CONFIG_FILE);
int nHeight = GetPrivateProfileInt("resolution", "height", 720, CONFIG_FILE);

int nIntRes = GetPrivateProfileInt("resolution", "r.enable", FALSE, CONFIG_FILE);
int nIntResWidth = GetPrivateProfileInt("resolution", "r.width", 1280, CONFIG_FILE);
int nIntResHeight = GetPrivateProfileInt("resolution", "r.height", 720, CONFIG_FILE);

int nStereo = GetPrivateProfileInt("patches", "stereo", FALSE, CONFIG_FILE);
int nCursor = GetPrivateProfileInt("patches", "cursor", TRUE, CONFIG_FILE);
int nHideStatusIcons = GetPrivateProfileInt("patches", "hide_status_icons", FALSE, CONFIG_FILE);
int nTAA = GetPrivateProfileInt("graphics", "TAA", TRUE, CONFIG_FILE);
int nMLAA = GetPrivateProfileInt("graphics", "MLAA", TRUE, CONFIG_FILE);

int nFPSLimit = GetPrivateProfileInt("graphics", "FPS.Limit", 0, CONFIG_FILE);

//auto nBitDepth = GetPrivateProfileIntW(L"resolution", L"bitdepth", 32, CONFIG_FILE);
//auto nRefreshRate = GetPrivateProfileIntW(L"resolution", L"refreshrate", 60, CONFIG_FILE);
