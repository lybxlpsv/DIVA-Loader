#include "windows.h"
#include "vector"
#include <tchar.h>
#include <GL/freeglut.h>

void InjectCode(void* address, const std::initializer_list<uint8_t>& data);
void ApplyPatches();

const LPCWSTR CONFIG_FILE = L".\\config.ini";

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		ApplyPatches();
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

void ApplyPatches() {

	const struct { void* Address; std::initializer_list<uint8_t> Data; } patches[] =
	{
		// Disable the keychip time bomb
		{ (void*)0x0000000140210820, { 0xB8, 0x00, 0x00, 0x00, 0x00, 0xC3 } },
		// Always return true for the SelCredit enter SelPv check
		{ (void*)0x0000000140393610, { 0xB0, 0x01, 0xC3, 0x90, 0x90, 0x90 } },
		// Just completely ignore all SYSTEM_STARTUP errors
		{ (void*)0x00000001403F5080, { 0xC3 } },
		// Always exit TASK_MODE_APP_ERROR on the first frame
		{ (void*)0x00000001403F73A7, { 0x90, 0x90 } },
		{ (void*)0x00000001403F73C3, { 0x89, 0xD1, 0x90 } },
		// Ignore the EngineClear variable to clear the framebuffer at all resolutions
		{ (void*)0x0000000140501480, { 0x90, 0x90 } },
		{ (void*)0x0000000140501515, { 0x90, 0x90 } },
		// Don't update the touch slider state so we can write our own
		{ (void*)0x000000014061579B, { 0x90, 0x90, 0x90, 0x8B, 0x42, 0xE0, 0x90, 0x90, 0x90 } },
		// Write ram files to the current directory instead of Y : / SBZV / ram
		{ (void*)0x000000014066CF09, { 0xE9, 0xD8, 0x00 } },
		// Change mdata path from "C:/Mount/Option" to "mdata/"
		{ (void*)0x0000000140A8CA18, { 0x6D, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x00 } },
		{ (void*)0x000000014066CEAE, { 0x06 } },
		// *But of course we have a valid keychip*, return true
		{ (void*)0x000000014066E820, { 0xB8, 0x01, 0x00, 0x00, 0x00, 0xC3 } },
		// Skip parts of the network check state
		{ (void*)0x00000001406717B1, { 0xE9, 0x22, 0x03, 0x00 } },
		// Set the initial DHCP WAIT timer value to 0
		{ (void*)0x00000001406724E7, { 0x00, 0x00 } },
		// Ignore SYSTEM_STARTUP Location Server checks
		{ (void*)0x00000001406732A2, { 0x90, 0x90 } },
		// Toon Shader Fix by lybxlpsv
		{ (void*)0x000000014050214F, { 0x90 } },
		{ (void*)0x0000000140502150, { 0x90 } },
		// Toon Shader Outline Fix by lybxlpsv
		{ (void*)0x0000000140641102, { 0x01 } },
		// Disables call to glutFitWindowSizeToDesktop, this fixes the need to use -w for windowed mode (by Brolijah)
		{ (void*)0x0000000140194E06, { 0x90, 0x90, 0x90, 0x90, 0x90 } }
	};
	printf("[Patches] Patches loaded\n");

	for (size_t i = 0; i < _countof(patches); i++)
		InjectCode(patches[i].Address, patches[i].Data);

	auto nStereo = GetPrivateProfileIntW(L"patches", L"stereo", FALSE, CONFIG_FILE);
	auto nOldStereo = GetPrivateProfileIntW(L"patches", L"old_stereo", FALSE, CONFIG_FILE);
	auto nCursor = GetPrivateProfileIntW(L"patches", L"cursor", TRUE, CONFIG_FILE);
	auto nHideCredits = GetPrivateProfileIntW(L"patches", L"hide_credits", FALSE, CONFIG_FILE);
	auto nHideStatusIcons = GetPrivateProfileIntW(L"patches", L"hide_status_icons", FALSE, CONFIG_FILE);
	auto nHidePVWatermark = GetPrivateProfileIntW(L"patches", L"hide_pv_watermark", FALSE, CONFIG_FILE);
	auto nHideVolCtrl = GetPrivateProfileIntW(L"patches", L"hide_volume", FALSE, CONFIG_FILE);
	// Initialize Audio with dual-channels instead of quads
	if (nStereo)
	{
		InjectCode((void*)0x0000000140A860C0, { 0x02 });
		printf("[Patches] Stereo enabled\n");
	}
	// Fake stereo address
	if (nOldStereo)
	{
		InjectCode((void*)0x0000000140A85AC0, { 0x02 });
		printf("[Patches] ¯\\_(:/)_/¯ enabled\n");
	}
	// Dirty hide of CREDIT(S) counter
	if (nHideCredits)
	{
		InjectCode((void*)0x00000001409F6200, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 });
		printf("[Patches] Hide CREDIT(S) enabled\n");
	}
	// Use GLUT_CURSOR_RIGHT_ARROW instead of GLUT_CURSOR_NONE
	if (nCursor)
	{
		InjectCode((void*)0x000000014019341B, { 0x00 });	
		printf("[Patches] Cursor enabled\n");
	}
	// Override status icon states to be invalid (hides them)
	if (nHideStatusIcons)
	{
		// card icon
		// `{ 0xFD, 0x0A }` for hidden, `{ 0xFA, 0x0A }` for error icon, `{ 0xFC, 0x0A }` for OK icon
		InjectCode((void*)0x00000001403B9D6E, { 0xFD, 0x0A }); // error state
		InjectCode((void*)0x00000001403B9D73, { 0xFD, 0x0A }); // OK state
		
		// network icon
		// `{ 0x00, 0x1E }` for hidden, `{ 0x9F, 0x1E }` for error icon, `{ 0xA0, 0x1E }` for OK icon, `{ 0xA1, 0x1E }` for partial connection (yellow) icon
		InjectCode((void*)0x00000001403BA14B, { 0x00, 0x1E }); // error state
		InjectCode((void*)0x00000001403BA155, { 0x00, 0x1E }); // OK state
		InjectCode((void*)0x00000001403BA16B, { 0x00, 0x1E }); // partial state
		
		InjectCode((void*)0x00000001403BA1A5, { 0x48, 0xE9 }); // never show the error code for partial connection
		
		printf("[Patches] Status icons hidden\n");
	}
	// Dirty hack to remove PV watermark
	if (nHidePVWatermark)
	{
		InjectCode((void*)0x0000000140A13A88, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 });
		printf("[Patches] PV watermark hidden\n");
	}
	// Don't show volume control
	if (nHideVolCtrl)
	{
		// skip SE button
		InjectCode((void*)0x00000001409A4D68, { 0xC0, 0xD3 });
		
		// skip volume sliders button
		InjectCode((void*)0x0000000140A85F18, { 0xE0, 0x50 });
		
		printf("[Patches] Volume control hidden\n");
	}
}

void InjectCode(void* address, const std::initializer_list<uint8_t>& data)
{
	const size_t byteCount = data.size() * sizeof(uint8_t);

	DWORD oldProtect;
	VirtualProtect(address, byteCount, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy(address, data.begin(), byteCount);
	VirtualProtect(address, byteCount, oldProtect, nullptr);
}
