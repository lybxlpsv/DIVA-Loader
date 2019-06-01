#include "windows.h"
#include "vector"
#include <tchar.h>

void InjectCode(void* address, const std::initializer_list<uint8_t>& data);
void ApplyPatches();

const LPCTSTR CONFIG_FILE = _T(".\\config.ini");

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
		// Use GLUT_CURSOR_RIGHT_ARROW instead of GLUT_CURSOR_NONE
		{ (void*)0x000000014019341B, { 0x00 } },
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
		// Dirty hide of CREDIT(S) counter
		{ (void*)0x00000001409F6200, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
		// Toon Shader Fix by lybxlpsv
		{ (void*)0x000000014050214F, { 0x90 } },
		{ (void*)0x0000000140502150, { 0x90 } },
		// Toon Shader Outline Fix by lybxlpsv
		{ (void*)0x0000000140641102, { 0x01 } },
	};
	printf("[Patches] Patches loaded\n");

	for (size_t i = 0; i < _countof(patches); i++)
		InjectCode(patches[i].Address, patches[i].Data);

	auto nStereo = GetPrivateProfileIntW(L"patches", L"stereo", FALSE, CONFIG_FILE);
	// Initialize Audio with dual-channels instead of quads
	if (nStereo)
	{
		InjectCode((void*)0x0000000140A860C0, { 0x02 });
		printf("[Patches] Stereo enabled\n");
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