/* isWINE by zocker_160 is licensed under WFTPL v2 */

#include <Windows.h>
#include <iostream>

extern "C" __declspec(dllexport) bool isWine();
extern "C" __declspec(dllexport) const char* getWineVersion();

__declspec(dllexport) bool isWine()
{
    HMODULE ntdllMod = GetModuleHandle(L"ntdll.dll");

    return ntdllMod && GetProcAddress(ntdllMod, "wine_get_version");
}

__declspec(dllexport) const char* getWineVersion() {

    HMODULE ntdllMod = GetModuleHandle(L"ntdll.dll");
    const char* (CDECL * w_g_v)() = NULL;

    if (ntdllMod)
        w_g_v = (const char* (*)())GetProcAddress(ntdllMod, "wine_get_version");

    if (w_g_v)
        return w_g_v();
    return NULL;
}