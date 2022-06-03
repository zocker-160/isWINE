/* isWINE by zocker_160 is licensed under WFTPL v2 */

#include <Windows.h>
#include <iostream>

static const char* wineGetVersion(HMODULE& ntdllMod) {

    const char* (CDECL* w_g_v)() =
        (const char*(*)())GetProcAddress(ntdllMod, "wine_get_version");

    if (w_g_v)
        return w_g_v();
    else
        return NULL;
}

int main() {

    HMODULE ntdllMod = GetModuleHandle(L"ntdll.dll");

    if (!ntdllMod) {
        std::cout << "ERROR: could not find ntdll.dll" << std::endl;
        return -1;
    }

    const char* wineVersion = wineGetVersion(ntdllMod);

    if (wineVersion != NULL) {
        std::cout << 1 << std::endl;
        std::cout << wineVersion << std::endl;
        return 1;
    } else {
        std::cout << 0 << std::endl;
        return 0;
    }
}
