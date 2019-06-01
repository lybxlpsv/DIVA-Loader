#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#pragma once
#include <string>
#include <shlobj.h>
#include <set>
#include "ModuleList.h"
#include <intrin.h>
#pragma intrinsic(_ReturnAddress)

struct shared
{
	FARPROC DllCanUnloadNow;
	FARPROC DllGetClassObject;
	FARPROC DllRegisterServer;
	FARPROC DllUnregisterServer;
	FARPROC DebugSetMute;

	void LoadOriginalLibrary(HMODULE dll)
	{
		DllCanUnloadNow = GetProcAddress(dll, "DllCanUnloadNow");
		DllGetClassObject = GetProcAddress(dll, "DllGetClassObject");
		DllRegisterServer = GetProcAddress(dll, "DllRegisterServer");
		DllUnregisterServer = GetProcAddress(dll, "DllUnregisterServer");
		DebugSetMute = GetProcAddress(dll, "DebugSetMute");
	}
} shared;

struct dnsapi_dll
{
	HMODULE dll;

	// only some functions are implemented.
	// PDAFT doesn't use many, so this should hopefully be fine
	FARPROC DnsFree;
	FARPROC DnsQuery_A;
	FARPROC DnsQueryEx;
	FARPROC DnsCancelQuery;

	// DnsQueryEx and DnsCancelQuery take pointers to structs as parameters
	// (three for DnsQueryEx and one for DnsCancelQuery)
	// fortunately they should fit in registers so the stack doesn't matter
	// hopefully this works fine... I have no clue what I'm doing
	static LONG WINAPI DnsQueryExStub()
	{
		return 9004; // DNS_ERROR_RCODE_NOT_IMPLEMENTED
	}
	static LONG WINAPI DnsCancelQueryStub()
	{
		return 9004; // DNS_ERROR_RCODE_NOT_IMPLEMENTED
	}

	void LoadOriginalLibrary(HMODULE module)
	{
		dll = module;
		shared.LoadOriginalLibrary(dll);
		DnsFree = GetProcAddress(dll, "DnsFree");
		DnsQuery_A = GetProcAddress(dll, "DnsQuery_A");
		DnsQueryEx = GetProcAddress(dll, "DnsQueryEx");
		DnsCancelQuery = GetProcAddress(dll, "DnsCancelQuery");

		// if entry points aren't found, GetProcAddress should return null
		// I hope this is correct
		// Thanks to somewhatlurker
		if (DnsQueryEx == NULL) { DnsQueryEx = (FARPROC)& DnsQueryExStub; };
		if (DnsCancelQuery == NULL) { DnsCancelQuery = (FARPROC)& DnsCancelQueryStub; };
	}
} dnsapi;

void _DnsFree() { dnsapi.DnsFree(); }
void _DnsQuery_A() { dnsapi.DnsQuery_A(); }
void _DnsQueryEx() { dnsapi.DnsQueryEx(); }
void _DnsCancelQuery() { dnsapi.DnsCancelQuery(); }

#pragma runtime_checks( "", off )

#ifdef _DEBUG
#pragma message ("You are compiling the code in Debug - be warned that wrappers for export functions may not have correct code generated")
#endif

void _DllRegisterServer() { shared.DllRegisterServer(); }
void _DllUnregisterServer() { shared.DllUnregisterServer(); }
void _DllCanUnloadNow() { shared.DllCanUnloadNow(); }
void _DllGetClassObject() { shared.DllGetClassObject(); }

#pragma runtime_checks( "", restore )