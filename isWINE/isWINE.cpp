/* isWINE by zocker_160 is licensed under WFTPL v2 */

#include <Windows.h>
#include <iostream>

bool runsWINE() {
    HMODULE ntdllMod = GetModuleHandle(L"ntdll.dll");

    return ntdllMod && GetProcAddress(ntdllMod, "wine_get_version");
}

int main() {
    if (runsWINE()) {
        std::cout << 1;
        return 1;
    } else {
        std::cout << 0;
        return 0;
    }
}
