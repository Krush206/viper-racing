char* sub_401000(char arg1) __pure
{
    if (arg1)
        return "debug.bin";
    
    return "race.bin";
}

int32_t sub_401020(char* arg1)
{
    char var_1 = 0;
    void var_100;
    void arg_8;
    sub_402140(&var_100, arg1, &arg_8);
    void* edi = &var_100;
    int32_t i = 0xffffffff;
    
    while (i)
    {
        bool cond:0_1 = 0 != *edi;
        edi += 1;
        i -= 1;
        
        if (!cond:0_1)
            break;
    }
    
    *(edi - 1) = data_407224[0];
    *(edi + 3) = data_407224[4][0];
    *(edi + 7) = data_407224[8][0];
    *(edi + 9) = data_407224[0xa][0];
    
    if (var_1)
        return sub_4010a0();
    
    return sub_4010b0(&var_100);
}

int32_t sub_4010a0()
{
    return sub_4021e0(1);
}

int32_t sub_4010b0(PSTR arg1)
{
    int32_t result = MessageBoxA(nullptr, arg1, "Viper Racing", 0x10034) - 7;
    result = result - result;
    result = -(result);
    data_407030 = result;
    return result;
}

enum MESSAGEBOX_RESULT sub_4010e0(char* arg1)
{
    char var_1 = 0;
    void var_100;
    void arg_8;
    sub_402140(&var_100, arg1, &arg_8);
    
    if (var_1)
        return sub_4010a0();
    
    enum MESSAGEBOX_RESULT result = sub_401140(&var_100);
    data_407030 = 1;
    return result;
}

enum MESSAGEBOX_RESULT sub_401140(PSTR arg1)
{
    return MessageBoxA(nullptr, arg1, "Our Apologies", 0x10010);
}

HWND sub_401160(HWND arg1, int32_t arg2)
{
    HWND hWnd = GetDlgItem(arg1, arg2);
    
    if (!hWnd)
        return hWnd;
    
    SetWindowLongA(hWnd, 0xfffffff0, GetWindowLongA(hWnd, 0xfffffff0) | 0x8000000);
    InvalidateRect(hWnd, nullptr, 1);
    return UpdateWindow(hWnd);
}

HWND sub_4011b0(HWND arg1, int32_t arg2)
{
    HWND hWnd = GetDlgItem(arg1, arg2);
    
    if (!hWnd)
        return hWnd;
    
    SetWindowLongA(hWnd, 0xfffffff0, GetWindowLongA(hWnd, 0xfffffff0) & 0xf7ffffff);
    EnableWindow(hWnd, 1);
    InvalidateRect(hWnd, nullptr, 1);
    return UpdateWindow(hWnd);
}

int32_t __stdcall sub_401200(int32_t arg1, int32_t arg2 @ 0xc)
{
    int32_t i = 0xffffffff;
    int32_t edi = arg2;
    
    while (i)
    {
        bool cond:0_1 = 0 != *edi;
        edi += 1;
        i -= 1;
        
        if (!cond:0_1)
            break;
    }
    
    int32_t ecx = ~i;
    char var_200[0x200];
    int32_t esi_1;
    int32_t edi_2;
    edi_2 = __builtin_memcpy(&var_200, edi - ecx, ecx & 0xfffffffc);
    __builtin_memcpy(edi_2, esi_1, ecx & 3);
    char* lpName = "MGI Viper Racing 1998 Canary";
    data_408598 = arg1;
    HANDLE hObject = CreateSemaphoreA(nullptr, 0, 1, lpName);
    
    if (hObject && GetLastError() != ERROR_ALREADY_EXISTS)
    {
        if (sub_401600())
        {
            HWND hWnd = FindWindowA("Viper Racing Window", "Viper Racing");
            
            if (hWnd)
                ShowWindow(hWnd, SW_RESTORE);
        }
        else
        {
            DWORD (* commandLine)() = sub_401640;
            int32_t (* var_404)() = sub_401720;
            enum MESSAGEBOX_RESULT (* var_400_1)() = sub_401740;
            enum MESSAGEBOX_RESULT (* var_3fc_1)() = sub_401a70;
            int32_t (* var_3f8_1)() __pure = sub_401870;
            int32_t (* var_3f4_1)() __pure = sub_401860;
            void (* var_3f0_1)() = sub_4017e0;
            sub_4015b0(&var_200, "-autoplay");
            
            if (sub_4015b0(&var_200, "-no3dfx"))
                sub_401a50(0);
            
            char* var_474_3 = "-nocanary";
            uint8_t var_304 = 1;
            
            if (!sub_4015b0(&var_200, var_474_3))
            {
                DWORD (** i_1)() = &commandLine;
                void var_3ec;
                
                do
                {
                    (*i_1)();
                    
                    if (data_407030)
                    {
                        var_304 = 0;
                        break;
                    }
                    
                    i_1 = &i_1[1];
                } while (i_1 < &var_3ec);
            }
            
            int32_t ebx;
            ebx = 0;
            
            if (sub_4015b0(&var_200, "-safe"))
                ebx = 1;
            
            if (var_304)
            {
                var_304 = data_407268;
                void var_303;
                int16_t* edi_3 = __builtin_memset(&var_303, 0, 0x100);
                *edi_3 = 0;
                edi_3[1] = 0;
                char* edi_6 = "Data\";
                int32_t i_2 = 0xffffffff;
                
                while (i_2)
                {
                    bool cond:1_1 = 0 != *edi_6;
                    edi_6 = &edi_6[1];
                    i_2 -= 1;
                    
                    if (!cond:1_1)
                        break;
                }
                
                int32_t ecx_5 = ~i_2;
                int32_t esi_3;
                int32_t edi_8;
                edi_8 = __builtin_memcpy(&var_304, edi_6 - ecx_5, ecx_5 & 0xfffffffc);
                __builtin_memcpy(edi_8, esi_3, ecx_5 & 3);
                char (* var_474_5)[0x200] = &var_200;
                char* var_478_6 = sub_401000(ebx);
                uint8_t* lpCurrentDirectory = nullptr;
                char ebx_1 = 1;
                uint8_t* var_47c_1 = &var_304;
                sub_4022c0(&commandLine, "%s%s %s");
                
                if (!sub_401930(&var_304))
                {
                    ebx_1 = 0;
                    sub_4010e0("Can't find data directory--Game may not be installed");
                }
                else
                    lpCurrentDirectory = &var_304;
                
                PROCESS_INFORMATION var_45c;
                __builtin_memset(&var_45c, 0, 0x10);
                STARTUPINFOA var_44c;
                __builtin_memset(&var_44c, 0, 0x44);
                var_44c.cb = 0x44;
                var_44c.dwFlags = 1;
                
                if (ebx_1)
                {
                    PROCESS_INFORMATION* lpProcessInformation = &var_45c;
                    STARTUPINFOA* lpStartupInfo = &var_44c;
                    SECURITY_ATTRIBUTES* lpProcessAttributes;
                    __builtin_memset(&lpProcessAttributes, 0, 0x14);
                    SECURITY_ATTRIBUTES* lpThreadAttributes;
                    BOOL bInheritHandles;
                    enum PROCESS_CREATION_FLAGS dwCreationFlags;
                    int32_t lpEnvironment;
                    
                    if (!CreateProcessA(nullptr, &commandLine, lpProcessAttributes, 
                        lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, 
                        lpCurrentDirectory, lpStartupInfo, lpProcessInformation))
                    {
                        DWORD (** var_474_17)() = &commandLine;
                        sub_4010e0("Can't start game. (%s)");
                    }
                    else
                    {
                        Sleep(0x9c4);
                        WaitForSingleObject(var_45c.hProcess, 0xffffffff);
                        uint32_t exitCode;
                        
                        if (GetExitCodeProcess(var_45c.hProcess, &exitCode) && exitCode)
                        {
                            if (exitCode - 2 > 4)
                            {
                                uint32_t exitCode_1 = exitCode;
                                char* var_478_9 = "Viper Racing";
                                sub_4010e0("%s has aborted (%d).  Let's check out the log.");
                                WinExec("notepad c:\log.log", 5);
                            }
                            else
                                switch (exitCode)
                                {
                                    case 2:
                                    {
                                        sub_4010e0("This game requires DirectX 5 or 6");
                                        break;
                                    }
                                    case 3:
                                    {
                                        sub_4010e0("
                                            Your video card does not support 3D texture mapping");
                                        break;
                                    }
                                    case 4:
                                    {
                                        sub_4010e0("Your video card does not support 3D graphics");
                                        break;
                                    }
                                    case 5:
                                    {
                                        sub_4010e0("Your video card returned an error.  Are your "
                                        "video drivers up to date?");
                                        break;
                                    }
                                    case 6:
                                    {
                                        char* var_474_16 = "Viper Racing";
                                        sub_4010e0("
                                            %s is not installed properly.  Run setup from the CD");
                                        break;
                                    }
                                }
                        }
                    }
                }
            }
        }
        
        CloseHandle(hObject);
    }
    
    return 0;
}

char* sub_4015b0(char* arg1, char* arg2)
{
    char* edi = arg2;
    char* result = sub_402480(arg1, edi);
    char* result_1 = result;
    
    if (result_1)
    {
        int32_t i = 0xffffffff;
        
        while (i)
        {
            bool cond:0_1 = 0 != *edi;
            edi = &edi[1];
            i -= 1;
            
            if (!cond:0_1)
                break;
        }
        
        void* edi_1 = &result_1[~i - 1];
        int32_t i_1 = 0xffffffff;
        
        while (i_1)
        {
            bool cond:1_1 = 0 != *edi_1;
            edi_1 += 1;
            i_1 -= 1;
            
            if (!cond:1_1)
                break;
        }
        
        result = sub_402330(0, &result_1[~i - 1], result_1, &result_1[~i - 1], ~i_1 - 1);
    }
    
    result = result - result;
    result += 1;
    return result;
}

HANDLE sub_401600()
{
    char ebx = 0;
    HANDLE hObject = CreateSemaphoreA(nullptr, 0, 1, "MGI Viper Racing 1998");
    
    if (hObject)
    {
        if (GetLastError() == ERROR_ALREADY_EXISTS)
            ebx = 1;
        
        hObject = CloseHandle(hObject);
    }
    
    hObject = ebx;
    return hObject;
}

DWORD sub_401640()
{
    OSVERSIONINFOA versionInformation;
    __builtin_memset(&versionInformation, 0, 0x94);
    versionInformation.dwOSVersionInfoSize = 0x94;
    
    if (!GetVersionExA(&versionInformation))
        return sub_401020("Cannot get version info--proceed at your own risk");
    
    DWORD dwPlatformId = versionInformation.dwPlatformId;
    
    if (!dwPlatformId)
    {
        char* var_9c_2 = "Viper Racing";
        return sub_4010e0("%s cannot run under Win32s");
    }
    
    if (dwPlatformId != 1)
    {
        if (dwPlatformId != 2)
            return sub_401020("Unknown platform type--proceed at your own risk");
        
        if (versionInformation.dwMajorVersion < 5)
        {
            DWORD dwMinorVersion_1 = versionInformation.dwMinorVersion;
            DWORD dwMajorVersion_1 = versionInformation.dwMajorVersion;
            char* var_a4_1 = "Viper Racing";
            return sub_401020("%s cannot run under Windows NT %d.%d");
        }
    }
    else if (versionInformation.dwMajorVersion != 4)
    {
        DWORD dwMinorVersion = versionInformation.dwMinorVersion;
        DWORD dwMajorVersion = versionInformation.dwMajorVersion;
        return sub_401020("What is Windows %d.%d?");
    }
    
    return dwPlatformId;
}

int32_t sub_401720()
{
    int32_t result = GetSystemMetrics(SM_MOUSEPRESENT);
    
    if (result)
        return result;
    
    char* var_4_1 = "Viper Racing";
    return sub_4010e0("%s cannot run without a mouse.");
}

enum MESSAGEBOX_RESULT sub_401740()
{
    MEMORYSTATUS buffer;
    buffer.dwLength = 0x20;
    enum MESSAGEBOX_RESULT result = GlobalMemoryStatus(&buffer);
    
    if (buffer.dwTotalPhys < 0x1700000)
    {
        uint32_t var_24_1 = buffer.dwTotalPhys >> 0x14;
        int32_t var_28_1 = 0x17;
        char* var_2c_1 = "Viper Racing";
        return sub_4010e0("%s requires %d megabytes of memory (you have %d).");
    }
    
    if (buffer.dwTotalPhys < 0x1f00000)
    {
        uint32_t var_24_2 = buffer.dwTotalPhys >> 0x14;
        char* var_28_2 = "Viper Racing";
        return sub_401020("%s may not run optimally with %d megabytes of memory.");
    }
    
    if (buffer.dwAvailPageFile >= 0x2700000)
        return result;
    
    uint32_t var_24_3 = buffer.dwAvailPageFile >> 0x14;
    int32_t var_28_3 = 0x27;
    char* var_2c_2 = "Viper Racing";
    return sub_4010e0("%s requires %d megabytes of virtual memory (you have %d).  Please free up "
    "disk space or close other applications.");
}

void sub_4017e0()
{
    if (!data_407038)
        return;
    
    void rootPathName;
    sub_4024c0(&rootPathName, &data_407038, 3);
    char var_11_1 = 0;
    uint32_t numberOfFreeClusters;
    uint32_t bytesPerSector;
    uint32_t sectorsPerCluster;
    uint32_t totalNumberOfClusters;
    
    if (!GetDiskFreeSpaceA(&rootPathName, &sectorsPerCluster, &bytesPerSector, 
            &numberOfFreeClusters, &totalNumberOfClusters))
        return;
    
    BOOL eax = numberOfFreeClusters * bytesPerSector * sectorsPerCluster;
    
    if (eax < 0x1400000)
    {
        uint32_t var_18_2 = eax >> 0x14;
        sub_401020("You only have %d megabytes of free disk space.");
    }
}

int32_t sub_401860() __pure
{
    return;
}

int32_t sub_401870() __pure
{
    return;
}

int32_t sub_401873()
{
    for (int32_t i = 0; i < 0x1a; i += 1)
    {
        __return_addr = data_407608;
        __return_addr = i + 0x41;
        
        if (GetDriveTypeA(&__return_addr) == 5)
        {
            char* var_10_2 = "common.res";
            void arg_4;
            sub_4022c0(&arg_4, "%sdata\%s");
            char result = sub_4018f0(&arg_4);
            
            if (result)
                return result;
        }
    }
    
    char* var_10_4 = "Viper Racing";
    return sub_4010e0("You must have the %s CD inserted to play.");
}

uint32_t sub_4018f0(PSTR arg1)
{
    uint32_t result = GetFileAttributesA(arg1);
    result = (result + 1) - (result + 1) + 1;
    return result;
}

int32_t sub_401910() __pure
{
    return;
}

int32_t sub_401920() __pure
{
    return;
}

uint32_t sub_401930(uint8_t* arg1)
{
    HKEY hKey_1;
    uint8_t* edi;
    
    if (RegOpenKeyExA(0x80000002, "Software\Sierra On-Line\Viper Racing", 0, 0x2001f, &hKey_1))
        edi = arg1;
    else
    {
        edi = arg1;
        HKEY hKey = hKey_1;
        uint32_t lpcbData = 0x104;
        enum REG_VALUE_TYPE type;
        
        if (!RegQueryValueExA(hKey, "DataDirectory", nullptr, &type, edi, &lpcbData) && *edi)
        {
            char* var_118_2 = "common.res";
            uint8_t* var_11c_2 = edi;
            void var_104;
            sub_4022c0(&var_104, "%s%s");
            
            if (!sub_4018f0(&var_104))
                return 0;
            
            enum WIN32_ERROR eax_4 = RegCloseKey(hKey_1);
            eax_4 = 1;
            return eax_4;
        }
        
        RegCloseKey(hKey_1);
    }
    
    uint32_t eax_7 = GetModuleFileNameA(data_408598, edi, 0x104);
    
    if (eax_7)
    {
        eax_7 = sub_4024f0(edi, 0x5c);
        
        if (eax_7)
        {
            int32_t i = 0xffffffff;
            *eax_7 = 0;
            
            while (i)
            {
                bool cond:0_1 = 0 != *edi;
                edi = &edi[1];
                i -= 1;
                
                if (!cond:0_1)
                    break;
            }
            
            int32_t eax_8 = data_40764c[0];
            *(edi - 1) = eax_8;
            eax_8 = 1;
            *(edi + 3) = data_40764c[4][0];
            return eax_8;
        }
    }
    
    eax_7 = 0;
    return eax_7;
}

int32_t sub_401a50(char arg1)
{
    data_407658 = arg1;
    return arg1;
}

int32_t sub_401a60() __pure
{
    return;
}

enum MESSAGEBOX_RESULT sub_401a70()
{
    sub_402520(0x1210);
    char lptstrFilename = data_40765c;
    void arg_10d;
    int16_t* edi = __builtin_memset(&arg_10d, 0, 0x100);
    *edi = 0;
    edi[1] = 0;
    uint8_t buffer = data_407660;
    uint32_t uSize = 0x104;
    void arg_9;
    int16_t* edi_3 = __builtin_memset(&arg_9, 0, 0x100);
    *edi_3 = 0;
    edi_3[1] = 0;
    GetSystemDirectoryA(&buffer, uSize);
    uint8_t* var_8 = &buffer;
    sub_4022c0(&lptstrFilename, "%s\ddraw.dll");
    void arg_210;
    __builtin_memset(&arg_210, 0, 0x1000);
    uint32_t puLen;
    
    if (GetFileVersionInfoA(&lptstrFilename, 0, 0x1000, &arg_210)
        && VerQueryValueA(&arg_210, &data_407674, &__return_addr, &puLen))
    {
        enum MESSAGEBOX_RESULT result = __return_addr;
        
        if (*(result + 0x10) >= 0x40005)
            return result;
    }
    
    return sub_4010e0("This product requires DirectX 5.0 or better");
}

char* sub_401b50(char* arg1, char* arg2)
{
    char* esi = arg2;
    char* result = sub_402550(esi, 0x40);
    
    if (!result)
    {
        *arg1 = 0;
        return result;
    }
    
    char* ecx = arg1;
    
    if (result <= esi)
    {
        *ecx = 0;
        return result;
    }
    
    do
    {
        char edx_1 = *esi;
        esi = &esi[1];
        *ecx = edx_1;
        ecx = &ecx[1];
    } while (result > esi);
    
    *ecx = 0;
    return result;
}

void* sub_401b90(char* arg1)
{
    char* eax = sub_402550(arg1, 0x40);
    
    if (!eax)
        return 0;
    
    return &eax[1];
}

uint16_t sub_401bb0(int32_t arg1 @ esi, int32_t arg2, PSTR arg3, int16_t* arg4)
{
    char ebx = 0;
    uint32_t* entry_argp;
    int32_t eax = ioctlsocket(arg3, arg1, entry_argp);
    int16_t* esi_1;
    
    if (eax != 0xffffffff)
    {
        esi_1 = arg4;
        ebx = 1;
        *(esi_1 + 4) = eax;
    }
    else
    {
        HOSTENT* eax_1 = gethostbyname(arg3);
        
        if (!eax_1)
            esi_1 = arg4;
        else
        {
            esi_1 = arg4;
            ebx = 1;
            *(esi_1 + 4) = **eax_1->h_addr_list;
        }
    }
    
    uint16_t result = htons(0x19);
    esi_1[1] = result;
    result = ebx;
    *esi_1 = 2;
    return result;
}

int32_t sub_401c10(int32_t arg1 @ 0x8, int32_t arg2, int32_t arg3 @ 0x14, int32_t arg4, SOCKET arg5)
{
    int32_t ebx;
    int32_t var_1f4 = ebx;
    int32_t esi;
    int32_t var_1f8 = esi;
    char ebx_1 = 0;
    int32_t edi;
    int32_t var_1fc = edi;
    SOCKET s_2;
    SOCKET s_1 = s_2;
    WSADATA wSAData;
    int32_t result;
    int32_t* esp;
    
    if (WSAStartup(0x101, &wSAData))
    {
        result = sub_4010e0("Can't start winsock");
        esp = &s_1;
    }
    else
    {
        SOCKET s = socket(2, SOCK_STREAM, 0);
        
        if (s == 0xffffffff)
        {
            sub_4010e0("Can't create socket.");
            esp = &s_1;
            result = WSACleanup();
        }
        else
        {
            SOCKADDR name;
            name.sa_data[2] = 0;
            name.sa_data[3] = 0;
            name.sa_data[4] = 0;
            name.sa_data[5] = 0;
            name.sa_family = 2;
            uint16_t eax_1 = htons(0);
            name.sa_data[0] = eax_1;
            name.sa_data[1] = *(&eax_1 + 1);
            
            if (bind(s, &name, 0x10))
            {
                enum WSA_ERROR var_204_7 = WSAGetLastError();
                sub_4010e0("Can't bind socket (%d).");
                closesocket(s);
                esp = &s_1;
                result = WSACleanup();
            }
            else
            {
                int32_t var_1e0 = 0;
                SOCKADDR name_1;
                name_1.sa_family = 0;
                name_1.sa_data[0] = 0;
                name_1.sa_data[1] = 0;
                name_1.sa_data[2] = 0;
                name_1.sa_data[3] = 0;
                name_1.sa_data[4] = 0;
                name_1.sa_data[5] = 0;
                name_1.sa_data[6] = 0;
                name_1.sa_data[7] = 0;
                name_1.sa_data[8] = 0;
                name_1.sa_data[9] = 0;
                
                if (!arg2)
                {
                    int32_t var_204_5 = arg1;
                    sub_4010e0("Can't parse host address from %s");
                    closesocket(s);
                    esp = &s_1;
                    result = WSACleanup();
                }
                else if (!sub_401bb0(arg2, &var_1e0, arg2, s_1))
                {
                    s_1 = &data_401c9c;
                    sub_4010e0("Can't get address for %s");
                    s_1 = s;
                    closesocket(s_1);
                    esp = &var_1fc;
                    result = WSACleanup();
                }
                else
                {
                    s_1 = 0x10;
                    
                    if (connect(s, &name_1, s_1))
                    {
                        s_1 = WSAGetLastError();
                        void* const var_204_4 = &data_401c9c;
                        sub_4010e0("Can't connect to %s (%d)");
                        s_1 = s;
                        closesocket(s_1);
                        esp = &var_1fc;
                        result = WSACleanup();
                    }
                    else
                    {
                        int32_t i = 0xffffffff;
                        int32_t edi_1 = arg2;
                        
                        while (i)
                        {
                            bool cond:2_1 = 0 != *edi_1;
                            edi_1 += 1;
                            i -= 1;
                            
                            if (!cond:2_1)
                                break;
                        }
                        
                        int32_t ecx_1 = ~i;
                        char var_1cc;
                        int32_t esi_3;
                        int32_t edi_3;
                        edi_3 = __builtin_memcpy(&var_1cc, edi_1 - ecx_1, ecx_1 & 0xfffffffc);
                        __builtin_memcpy(edi_3, esi_3, ecx_1 & 3);
                        
                        if (!var_1cc)
                        {
                            s_1 = arg2;
                            sub_4010e0("Can't parse rcpt from %s");
                            s_1 = s;
                            closesocket(s_1);
                            esp = &var_1fc;
                            result = WSACleanup();
                        }
                        else
                        {
                            s_1 = arg5;
                            
                            if (!sub_401e20(s, &var_1cc, arg1, arg3, arg4, s_1))
                            {
                                s_1 = "Sending mail failed.";
                                sub_4010e0(s_1);
                                s_1 = s;
                                closesocket(s_1);
                                esp = &var_1fc;
                                result = WSACleanup();
                            }
                            else
                            {
                                ebx_1 = 1;
                                s_1 = s;
                                closesocket(s_1);
                                esp = &var_1fc;
                                result = WSACleanup();
                            }
                        }
                    }
                }
            }
        }
    }
    
    result = ebx_1;
    *esp;
    esp[1];
    esp[2];
    esp[3];
    return result;
}

char sub_401e20(SOCKET arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5, int32_t arg6)
{
    int32_t ebx = 0;
    char result = 0;
    void var_100;
    
    if (sub_401fa0(arg1, &var_100, 0x100))
    {
        char i;
        
        do
        {
            if (sub_401fd0(&var_100))
                break;
            
            char var_101_1 = 0;
            
            if (ebx > 5)
                sub_4010e0("Twinkies for sale.");
            else
                switch (ebx)
                {
                    case 0:
                    {
                        var_101_1 = sub_402050(arg1, "HELO lame.programmer.com\n");
                        break;
                    }
                    case 1:
                    {
                        int32_t var_114_2 = arg3;
                        var_101_1 = sub_402080(arg1, "MAIL FROM: %s\n");
                        break;
                    }
                    case 2:
                    {
                        int32_t var_114_3 = arg2;
                        var_101_1 = sub_402080(arg1, "RCPT TO: %s\n");
                        break;
                    }
                    case 3:
                    {
                        var_101_1 = sub_402050(arg1, "DATA\n");
                        break;
                    }
                    case 4:
                    {
                        int32_t var_114_4 = arg4;
                        i = sub_402080(arg1, "Subject: %s\n\n\n");
                        char i_1 = i;
                        
                        if (i)
                            i_1 = sub_402000(arg6, arg1, arg5, arg6);
                        
                        if (!i_1)
                            break;
                        
                        var_101_1 = sub_402050(arg1, 0x4077cc);
                        break;
                    }
                    case 5:
                    {
                        result = 1;
                        var_101_1 = 0;
                        break;
                    }
                }
            
            if (!var_101_1)
                break;
            
            ebx += 1;
            i = sub_401fa0(arg1, &var_100, 0x100);
        } while (i);
    }
    
    return result;
}

int32_t sub_401fa0(SOCKET arg1, PSTR arg2, int32_t arg3)
{
    int32_t result = recv(arg1, arg2, arg3, 0);
    
    if (result <= 0)
    {
        result = 0;
        return result;
    }
    
    arg2[result] = 0;
    result = 1;
    return result;
}

char sub_401fd0(char* arg1)
{
    if (*arg1 == 0x35)
    {
        char* var_8_1 = arg1;
        sub_4010e0("Got error: %s");
    }
    
    char eax = *arg1 - 0x35;
    return -((eax - eax));
}

int32_t __convention("regparm") sub_402000(int32_t arg1, SOCKET arg2 @ 0x4, int32_t arg3 @ 0x8, int32_t arg4 @ 0xc)
{
    int32_t ebx = 0;
    
    if (arg4 > 0)
    {
        do
        {
            arg1 = send(arg2, arg3 + ebx, arg4 - ebx, 0);
            
            if (arg1 <= 0)
                break;
            
            ebx += arg1;
            arg1 = Sleep(0x64);
        } while (ebx < arg4);
    }
    
    arg1 = arg1 - arg1;
    arg1 = -(arg1);
    return arg1;
}

int32_t sub_402050(int32_t arg1, int32_t arg2)
{
    int32_t edi = arg2;
    int32_t i = 0xffffffff;
    
    while (i)
    {
        bool cond:0_1 = 0 != *edi;
        edi += 1;
        i -= 1;
        
        if (!cond:0_1)
            break;
    }
    
    return sub_402000(arg1, arg1, arg2, ~i - 1);
}

enum MESSAGEBOX_RESULT sub_402080(int32_t arg1, char* arg2)
{
    char var_1 = 0;
    void var_400;
    void arg_c;
    sub_402140(&var_400, arg2, &arg_c);
    
    if (!var_1)
        return sub_402050(arg1, &var_400);
    
    enum MESSAGEBOX_RESULT result = sub_4010e0("tried to send way too much!");
    result = 0;
    return result;
}

uint16_t __stdcall htons(uint16_t hostshort)
{
    /* tailcall */
    return htons(hostshort);
}

HOSTENT* __stdcall gethostbyname(PSTR name)
{
    /* tailcall */
    return gethostbyname(name);
}

int32_t __stdcall ioctlsocket(SOCKET s, int32_t cmd, uint32_t* argp)
{
    /* tailcall */
    return ioctlsocket(s, cmd, argp);
}

int32_t __stdcall WSACleanup()
{
    /* tailcall */
    return WSACleanup();
}

int32_t __stdcall closesocket(SOCKET s)
{
    /* tailcall */
    return closesocket(s);
}

enum WSA_ERROR __stdcall WSAGetLastError()
{
    /* tailcall */
    return WSAGetLastError();
}

int32_t __stdcall connect(SOCKET s, SOCKADDR* name, int32_t namelen)
{
    /* tailcall */
    return connect(s, name, namelen);
}

int32_t __stdcall bind(SOCKET s, SOCKADDR* name, int32_t namelen)
{
    /* tailcall */
    return bind(s, name, namelen);
}

SOCKET __stdcall socket(int32_t af, enum WINSOCK_SOCKET_TYPE type, int32_t protocol)
{
    /* tailcall */
    return socket(af, type, protocol);
}

int32_t __stdcall WSAStartup(uint16_t wVersionRequested, WSADATA* lpWSAData)
{
    /* tailcall */
    return WSAStartup(wVersionRequested, lpWSAData);
}

int32_t __stdcall recv(SOCKET s, PSTR buf, int32_t len, enum SEND_RECV_FLAGS flags)
{
    /* tailcall */
    return recv(s, buf, len, flags);
}

int32_t __stdcall send(SOCKET s, PSTR buf, int32_t len, enum SEND_RECV_FLAGS flags)
{
    /* tailcall */
    return send(s, buf, len, flags);
}

BOOL __stdcall VerQueryValueA(void* pBlock, PSTR lpSubBlock, void** lplpBuffer, uint32_t* puLen)
{
    /* tailcall */
    return VerQueryValueA(pBlock, lpSubBlock, lplpBuffer, puLen);
}

BOOL __stdcall GetFileVersionInfoA(PSTR lptstrFilename, uint32_t dwHandle, uint32_t dwLen, void* lpData)
{
    /* tailcall */
    return GetFileVersionInfoA(lptstrFilename, dwHandle, dwLen, lpData);
}

int32_t sub_402140(char* arg1, char* arg2, int32_t arg3)
{
    int32_t var_28 = arg3;
    int32_t var_14 = 0x42;
    char* var_18 = arg1;
    char* var_20 = arg1;
    int32_t var_1c = 0x7fffffff;
    int32_t result = sub_402880(&var_20, arg2);
    int32_t var_1c_1 = var_1c - 1;
    
    if (var_1c - 1 < 0)
    {
        int32_t var_2c_1 = 0;
        sub_402730(&var_20);
        return result;
    }
    
    *var_20 = 0;
    var_20 = &var_20[1];
    return result;
}

int32_t sub_4021b0()
{
    int32_t eax_1 = data_4097c8;
    
    if (eax_1)
        eax_1();
    
    sub_4022a0(0x407008, 0x407010);
    return sub_4022a0(0x407000, 0x407004);
}

int32_t sub_4021e0(uint32_t arg1)
{
    return sub_402220(arg1, 0, 0);
}

int32_t sub_402200(uint32_t arg1)
{
    return sub_402220(arg1, 1, 0);
}

int32_t sub_402220(uint32_t arg1, int32_t arg2, int32_t arg3)
{
    data_407854 = 1;
    data_407850 = arg3;
    
    if (!arg2)
    {
        if (data_4097cc)
        {
            for (int32_t* i = data_4097c4 - 4; i >= data_4097cc; i -= 4)
            {
                int32_t eax_1 = *i;
                
                if (eax_1)
                    eax_1();
            }
        }
        
        sub_4022a0(0x407014, 0x40701c);
    }
    
    int32_t result = sub_4022a0(0x407020, 0x407024);
    
    if (arg3)
        return result;
    
    ExitProcess(arg1);
    /* no return */
}

void sub_4022a0(int32_t* arg1, int32_t arg2)
{
    for (int32_t* i = arg1; arg2 > i; i = &i[1])
    {
        int32_t eax = *i;
        
        if (eax)
            eax();
    }
}

int32_t sub_4022c0(char* arg1, char* arg2)
{
    int32_t var_14 = 0x42;
    char* var_18 = arg1;
    void arg_c;
    void* var_28 = &arg_c;
    char* var_20 = arg1;
    int32_t var_1c = 0x7fffffff;
    int32_t result = sub_402880(&var_20, arg2);
    int32_t var_1c_1 = var_1c - 1;
    
    if (var_1c - 1 < 0)
    {
        int32_t var_2c_1 = 0;
        sub_402730(&var_20);
        return result;
    }
    
    *var_20 = 0;
    var_20 = &var_20[1];
    return result;
}

int32_t __convention("regparm") sub_402330(int32_t arg1, int32_t arg2, int32_t arg3 @ 0x4, int32_t arg4 @ 0x8, int32_t arg5 @ 0xc)
{
    if (arg3 > arg4 && arg3 < arg4 + arg5)
    {
        int32_t esi_3 = arg4 + arg5;
        int32_t edi_3 = arg3 + arg5;
        void* esi_5;
        void* edi_5;
        
        if (edi_3 & 3)
        {
            if (arg5 <= 0xc)
            {
                __builtin_memcpy(edi_3 - 1 - arg5, esi_3 - 1 - arg5, arg5);
                return arg3;
            }
            
            int32_t count_1 = -(arg2) & 3;
            int32_t ecx_7 = arg5 - count_1;
            int32_t esi_7;
            int32_t edi_7;
            edi_7 = __builtin_memcpy(edi_3 - 1 - count_1, esi_3 - 1 - count_1, count_1);
            uint32_t ecx_10 = ecx_7 >> 2;
            edi_5 =
                __builtin_memcpy(edi_7 - 3 - (ecx_10 << 2), esi_7 - 3 - (ecx_10 << 2), ecx_10 << 2);
            
            switch (ecx_7 & 3)
            {
                case 0:
                {
                    return arg3;
                    break;
                }
                case 1:
                {
                    *(edi_5 + 3) = *(esi_5 + 3);
                    return arg3;
                    break;
                }
                case 2:
                {
                    *(edi_5 + 2) = *(esi_5 + 2);
                    return arg3;
                    break;
                }
                case 3:
                {
                    goto label_402410;
                }
            }
        }
        else
        {
            uint32_t ecx_6 = arg5 >> 2;
            edi_5 =
                __builtin_memcpy(edi_3 - 4 - (ecx_6 << 2), esi_3 - 4 - (ecx_6 << 2), ecx_6 << 2);
            
            switch (arg5 & 3)
            {
                case 0:
                {
                    return arg3;
                    break;
                }
                case 1:
                {
                    *(edi_5 + 3) = *(esi_5 + 3);
                    return arg3;
                    break;
                }
                case 2:
                {
                    *(edi_5 + 2) = *(esi_5 + 2);
                    return arg3;
                    break;
                }
                case 3:
                {
                label_402410:
                    int16_t eax_9 = *(esi_5 + 2);
                    *(edi_5 + 2) = eax_9;
                    eax_9 = *(esi_5 + 1);
                    *(edi_5 + 1) = eax_9;
                    return arg3;
                    break;
                }
            }
        }
    }
    
    char* esi_1;
    char* edi_1;
    
    if (!(arg3 & 3))
    {
        edi_1 = __builtin_memcpy(arg3, arg4, arg5 & 0xfffffffc);
        
        switch (arg5 & 3)
        {
            case 0:
            {
                return arg3;
                break;
            }
            case 1:
            {
                *edi_1 = *esi_1;
                return arg3;
                break;
            }
            case 2:
            {
                *edi_1 = *esi_1;
                return arg3;
                break;
            }
            case 3:
            {
            label_402378:
                int16_t eax_1 = *esi_1;
                *edi_1 = eax_1;
                eax_1 = esi_1[2];
                edi_1[2] = eax_1;
                return arg3;
                break;
            }
        }
        
        return;
    }
    
    if (arg5 <= 0xc)
    {
        __builtin_memcpy(arg3, arg4, arg5);
        return arg3;
    }
    
    int32_t count = -(arg3) & 3;
    int32_t ecx_2 = arg5 - count;
    int32_t esi_2;
    int32_t edi_2;
    edi_2 = __builtin_memcpy(arg3, arg4, count);
    edi_1 = __builtin_memcpy(edi_2, esi_2, ecx_2 & 0xfffffffc);
    
    switch (ecx_2 & 3)
    {
        case 0:
        {
            return arg3;
            break;
        }
        case 1:
        {
            *edi_1 = *esi_1;
            return arg3;
            break;
        }
        case 2:
        {
            *edi_1 = *esi_1;
            return arg3;
            break;
        }
        case 3:
        {
            goto label_402378;
        }
    }
}

char* sub_402480(char* arg1, char* arg2)
{
    char* result_1 = arg1;
    char* result = result_1;
    char* edi = arg2;
    char* edx = edi;
    
    while (true)
    {
        int16_t eax;
        eax = *edi;
        eax = eax;
        
        if (!eax)
            return result;
        
        *(&eax + 1) = *result_1;
        *(&eax + 1) = *(&eax + 1);
        
        if (!*(&eax + 1))
            break;
        
        if (eax == *(&eax + 1))
        {
            edi = &edi[1];
            result_1 = &result_1[1];
        }
        else
        {
            edi = edx;
            result = &result[1];
            result_1 = result;
        }
    }
    
    return nullptr;
}

char* sub_4024c0(char* arg1, char* arg2, int32_t arg3)
{
    char* result_1 = arg1;
    char* esi = arg2;
    char* result = result_1;
    int32_t count = arg3;
    
    if (count)
    {
        do
        {
            char eax_1 = *esi;
            esi = &esi[1];
            
            if (!eax_1)
                break;
            
            *result_1 = eax_1;
            result_1 = &result_1[1];
            count -= 1;
        } while (count);
        
        __builtin_memset(result_1, 0, count);
    }
    
    return result;
}

char* sub_4024f0(int32_t arg1, char arg2)
{
    int32_t edi = arg1;
    int32_t i = 0xffffffff;
    
    while (i)
    {
        bool cond:0_1 = 0 != *edi;
        edi += 1;
        i -= 1;
        
        if (!cond:0_1)
            break;
    }
    
    int32_t i_1 = -((i + 1));
    void* edi_1 = edi - 1;
    
    while (i_1)
    {
        bool cond:1_1 = arg2 != *edi_1;
        edi_1 -= 1;
        i_1 -= 1;
        
        if (!cond:1_1)
            break;
    }
    
    if (*(edi_1 + 1) == arg2)
        return edi_1 + 1;
    
    return nullptr;
}

void* const __convention("regparm") sub_402520(int32_t arg1)
{
    void arg_4;
    void* ecx = &arg_4;
    
    while (arg1 >= 0x1000)
    {
        ecx -= 0x1000;
        arg1 -= 0x1000;
        *ecx;
    }
    
    void* ecx_1 = ecx - arg1;
    *ecx_1;
    *(ecx_1 - 4) = __return_addr;
    return __return_addr;
}

char* sub_402550(char* arg1, char arg2)
{
    char* result = arg1;
    
    while (true)
    {
        char edx_1 = *result;
        
        if (arg2 == edx_1)
            return result;
        
        if (!edx_1)
            break;
        
        result = &result[1];
    }
    
    return nullptr;
}

struct _EXCEPTION_REGISTRATION_RECORD* _start()
{
    int32_t var_8 = 0xffffffff;
    int32_t var_c = 0x406020;
    int32_t var_10 = 0x404020;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t __saved_edi;
    int32_t* var_1c = &__saved_edi;
    data_40781c = GetVersion();
    int32_t eax_1 = 0;
    eax_1 = *(data_40781c + 1);
    data_407828 = eax_1;
    char eax_2 = data_40781c;
    data_40781c u>>= 0x10;
    uint32_t eax_3 = eax_2;
    data_407824 = eax_3;
    data_407820 = (eax_3 << 8) + data_407828;
    sub_404000();
    int32_t var_8_1 = 0;
    sub_403e20();
    sub_403e10();
    data_4097c0 = GetCommandLineA();
    PSTR eax_7 = sub_4039b0();
    data_407858 = eax_7;
    
    if (!eax_7 || !data_4097c0)
        sub_4021e0(0xffffffff);
    
    sub_403730();
    sub_403650();
    sub_4021b0();
    char* esi = data_4097c0;
    char eax_9 = *esi;
    
    if (eax_9 == 0x22)
    {
        esi = &esi[1];
        
        if (*esi == 0x22)
            esi = &esi[1];
        else
        {
            do
            {
                char ebx_1 = *esi;
                
                if (!ebx_1)
                    break;
                
                if (sub_4035f0(ebx_1))
                    esi = &esi[1];
                
                esi = &esi[1];
            } while (*esi != 0x22);
            
            if (*esi == 0x22)
                esi = &esi[1];
        }
    }
    else if (eax_9 > 0x20)
    {
        do
            esi = &esi[1];
         while (*esi > 0x20);
    }
    
    if (*esi)
    {
        while (*esi <= 0x20)
        {
            esi = &esi[1];
            
            if (!*esi)
                break;
        }
    }
    
    STARTUPINFOA startupInfo;
    startupInfo.dwFlags = 0;
    GetStartupInfoA(&startupInfo);
    uint32_t wShowWindow_1;
    
    if (startupInfo.dwFlags & 1)
    {
        WORD wShowWindow = startupInfo.wShowWindow;
        *(&wShowWindow + 2) = startupInfo.cbReserved2;
        wShowWindow_1 = wShowWindow;
    }
    
    uint32_t wShowWindow_2 = wShowWindow_1;
    int32_t var_8c = 0;
    sub_401200(GetModuleHandleA(nullptr), esi);
    sub_4021e0(0);
    int32_t var_8_2 = 0xffffffff;
    struct _EXCEPTION_REGISTRATION_RECORD* result = ExceptionList;
    fsbase->NtTib.ExceptionList = result;
    return result;
}

int32_t sub_4026b5(void* arg1 @ ebp)
{
    *(arg1 - 0x20) = ***(arg1 - 0x14);
    return sub_403460(*(arg1 - 0x20), *(arg1 - 0x14));
}

int32_t sub_402700(int32_t arg1)
{
    if (data_407864 == 1)
        sub_404100();
    
    sub_404140(arg1);
    return data_407860(0xff);
}

uint32_t sub_402730(int32_t* arg1 @ 0x8)
{
    int32_t edi = arg1[4];
    int32_t eax = arg1[3];
    
    if (!(eax & 0x82) || eax & 0x40)
    {
        arg1[3] = eax | 0x20;
        return 0xffffffff;
    }
    
    if (eax & 1)
    {
        arg1[1] = 0;
        int32_t eax_1 = arg1[3];
        
        if (!(eax_1 & 0x10))
        {
            arg1[3] = eax_1 | 0x20;
            return 0xffffffff;
        }
        
        *arg1 = arg1[2];
        arg1[3] &= 0xfffffffe;
    }
    
    uint32_t ebp = 0;
    int32_t eax_4 = arg1[3] | 2;
    arg1[3] = eax_4;
    arg1[3] = eax_4 & 0xffffffef;
    arg1[1] = 0;
    
    if (!(arg1[3] & 0x10c))
    {
        if (arg1 == 0x407ed0 || arg1 == 0x407ef0)
        {
            if (!sub_404670(edi))
                sub_404620(arg1);
        }
        else
            sub_404620(arg1);
    }
    
    int32_t arg_4;
    uint32_t ebx_1;
    
    if (!(arg1[3] & 0x108))
    {
        ebx_1 = 1;
        ebp = sub_404330(edi, &arg_4, 1);
    }
    else
    {
        int32_t eax_7 = arg1[2];
        ebx_1 = *arg1 - eax_7;
        *arg1 = eax_7 + 1;
        arg1[1] = arg1[6] - 1;
        
        if (ebx_1 <= 0)
        {
            uint32_t eax_12 = 0x407b50;
            
            if (edi != 0xffffffff)
                eax_12 = *(((edi & 0xffffffe7) >> 3) + &data_4096c0) + ((edi & 0x1f) << 3);
            
            if (*(eax_12 + 4) & 0x20)
                sub_404560(edi, 0, FILE_END);
        }
        else
            ebp = sub_404330(edi, arg1[2], ebx_1);
        
        *arg1[2] = arg_4;
    }
    
    if (ebx_1 == ebp)
        return arg_4;
    
    arg1[3] |= 0x20;
    return 0xffffffff;
}

int32_t sub_402880(int32_t* arg1, char* arg2)
{
    char* eax = arg2;
    arg2 = &arg2[1];
    int32_t i = 0;
    char ebx = *eax;
    int32_t var_218 = 0;
    
    if (ebx)
    {
        int32_t* var_200;
        int32_t* esi_1 = var_200;
        int32_t* edi_1 = var_200;
        
        while (i >= 0)
        {
            int32_t eax_2;
            
            if (ebx < 0x20 || ebx > 0x78)
                eax_2 = 0;
            else
            {
                int32_t eax_1 = 0;
                eax_1 = *(ebx + &data_406010);
                eax_2 = eax_1 & 0xf;
            }
            
            int32_t ecx_3 = *(var_218 + (eax_2 << 3) + 0x406030) >> 4;
            var_218 = ecx_3;
            int32_t var_23c;
            int32_t var_224;
            int32_t* var_220;
            int32_t var_21c;
            int32_t var_210;
            int32_t var_20c;
            void* arg_c;
            
            switch (ecx_3)
            {
                case 0:
                {
                    goto label_402a64;
                }
                case 1:
                {
                    var_20c = 0;
                    var_210 = 0;
                    var_224 = 0;
                    var_220 = nullptr;
                    var_23c = 0xffffffff;
                    esi_1 = nullptr;
                    var_21c = 0;
                    break;
                }
                case 2:
                {
                    if (ebx - 0x20 <= 0x10)
                    {
                        int32_t ecx_4 = 0;
                        ecx_4 = *(ebx + &jump_table_403150[6]);
                        
                        switch (ecx_4)
                        {
                            case 0:
                            {
                                esi_1 |= 2;
                                break;
                            }
                            case 1:
                            {
                                esi_1 |= 0x80;
                                break;
                            }
                            case 2:
                            {
                                esi_1 |= 1;
                                break;
                            }
                            case 3:
                            {
                                esi_1 |= 4;
                                break;
                            }
                            case 4:
                            {
                                esi_1 |= 8;
                                break;
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    if (ebx != 0x2a)
                        var_224 = ebx + var_224 * 0xa - 0x30;
                    else
                    {
                        int32_t eax_7 = sub_403330(&arg_c);
                        var_224 = eax_7;
                        
                        if (eax_7 < 0)
                        {
                            esi_1 |= 4;
                            var_224 = -(eax_7);
                        }
                    }
                    break;
                }
                case 4:
                {
                    var_23c = 0;
                    break;
                }
                case 5:
                {
                    if (ebx != 0x2a)
                        var_23c = ebx + var_23c * 0xa - 0x30;
                    else
                    {
                        int32_t eax_10 = sub_403330(&arg_c);
                        var_23c = eax_10;
                        
                        if (eax_10 < 0)
                            var_23c = 0xffffffff;
                    }
                    break;
                }
                case 6:
                {
                    if (ebx - 0x49 <= 0x2e)
                    {
                        int32_t eax_12 = 0;
                        eax_12 = *(ebx + (&jump_table_403150[5] + 3));
                        
                        switch (eax_12)
                        {
                            case 0:
                            {
                                if (*arg2 != 0x36 || arg2[1] != 0x34)
                                {
                                    var_218 = 0;
                                label_402a64:
                                    int32_t eax_14 = 0;
                                    eax_14 = ebx;
                                    var_21c = 0;
                                    
                                    if (*(&(**&data_408150)[eax_14] + 1) & 0x80)
                                    {
                                        sub_403260(ebx, arg1, &i);
                                        ebx = *arg2;
                                        arg2 = &arg2[1];
                                    }
                                    
                                    sub_403260(ebx, arg1, &i);
                                }
                                else
                                {
                                    arg2 = &arg2[2];
                                    esi_1 |= 0x8000;
                                }
                                break;
                            }
                            case 1:
                            {
                                esi_1 |= 0x20;
                                break;
                            }
                            case 2:
                            {
                                esi_1 |= 0x10;
                                break;
                            }
                            case 3:
                            {
                                esi_1 |= 0x800;
                                break;
                            }
                        }
                    }
                    break;
                }
                case 7:
                {
                    char var_246;
                    char* var_240;
                    
                    if (ebx - 0x43 <= 0x35)
                    {
                        int32_t eax_17 = 0;
                        eax_17 = *(ebx + (&jump_table_4031e0[0] + 1));
                        int32_t var_214;
                        int32_t edi_4;
                        
                        switch (eax_17)
                        {
                            case 0:
                            {
                                if (!(esi_1 & 0x830))
                                    esi_1 |= 0x800;
                                
                                goto label_402b31;
                            }
                            case 1:
                            case 2:
                            {
                                var_20c = 1;
                                ebx += 0x20;
                            label_402b70:
                                esi_1 |= 0x40;
                                var_240 = &var_200;
                                
                                if (var_23c < 0)
                                    var_23c = 6;
                                else if (!var_23c && ebx == 0x67)
                                    var_23c = 1;
                                
                                arg_c += 8;
                                void* eax_47 = arg_c;
                                int32_t edx_12 = *(eax_47 - 4);
                                int32_t var_208 = *(eax_47 - 8);
                                int32_t var_204_1 = edx_12;
                                data_408138(&var_208, &var_200, ebx, var_23c, var_20c);
                                void* edi_6 = esi_1 & 0x80;
                                
                                if (edi_6 && !var_23c)
                                    data_408144(&var_200);
                                
                                if (ebx == 0x67 && !edi_6)
                                    data_40813c(&var_200);
                                
                                if (var_200 == 0x2d)
                                {
                                    esi_1 |= 0x100;
                                    var_240 = (&var_200 + 1);
                                }
                                
                                char* edi_7 = var_240;
                                int32_t j = 0xffffffff;
                                
                                while (j)
                                {
                                    bool cond:12_1 = 0 != *edi_7;
                                    edi_7 = &edi_7[1];
                                    j -= 1;
                                    
                                    if (!cond:12_1)
                                        break;
                                }
                                
                                edi_1 = ~j - 1;
                                break;
                            }
                            case 3:
                            {
                                if (!(esi_1 & 0x830))
                                    esi_1 |= 0x800;
                                
                                goto label_402ba6;
                            }
                            case 4:
                            {
                                goto label_402ce8;
                            }
                            case 5:
                            {
                                int16_t* eax_21 = sub_403330(&arg_c);
                                char* ecx_17;
                                
                                if (eax_21)
                                    ecx_17 = *(eax_21 + 4);
                                
                                if (!eax_21 || !ecx_17)
                                {
                                    char* eax_22 = data_407884;
                                    int32_t j_1 = 0xffffffff;
                                    char* edi_3 = eax_22;
                                    var_240 = eax_22;
                                    
                                    while (j_1)
                                    {
                                        bool cond:8_1 = 0 != *edi_3;
                                        edi_3 = &edi_3[1];
                                        j_1 -= 1;
                                        
                                        if (!cond:8_1)
                                            break;
                                    }
                                    
                                    edi_1 = ~j_1 - 1;
                                }
                                else if (!(esi_1 & 0x800))
                                {
                                    var_21c = 0;
                                    edi_1 = *eax_21;
                                    var_240 = ecx_17;
                                }
                                else
                                {
                                    var_21c = 1;
                                    edi_1 = *eax_21 >> 1;
                                    var_240 = ecx_17;
                                }
                                break;
                            }
                            case 6:
                            {
                            label_402b31:
                                int32_t* var_25c_5 = &arg_c;
                                
                                if (!(esi_1 & 0x810))
                                {
                                    edi_1 = 1;
                                    var_200 = sub_403330(var_25c_5);
                                }
                                else
                                {
                                    edi_1 = sub_404790(&var_200, sub_403360(var_25c_5));
                                    
                                    if (edi_1 < 0)
                                        var_210 = 1;
                                }
                                
                                var_240 = &var_200;
                                break;
                            }
                            case 7:
                            case 9:
                            {
                                esi_1 |= 0x40;
                                edi_4 = 0xa;
                            label_402d1a:
                                int32_t var_238_1;
                                int32_t var_234_1;
                                
                                if (esi_1 & 0x8000)
                                {
                                    int32_t eax_26;
                                    int32_t edx_5;
                                    eax_26 = sub_403340(&arg_c);
                                    var_238_1 = eax_26;
                                    var_234_1 = edx_5;
                                }
                                else if (!(esi_1 & 0x20))
                                {
                                    int32_t* var_25c_13 = &arg_c;
                                    
                                    if (!(esi_1 & 0x40))
                                    {
                                        var_238_1 = sub_403330(var_25c_13);
                                        var_234_1 = 0;
                                    }
                                    else
                                    {
                                        int32_t eax_32 = sub_403330(var_25c_13);
                                        var_238_1 = eax_32;
                                        int32_t eax_33;
                                        int32_t edx_7;
                                        edx_7 = HIGHD(eax_32);
                                        eax_33 = LOWD(eax_32);
                                        var_234_1 = edx_7;
                                    }
                                }
                                else
                                {
                                    int32_t* var_25c_12 = &arg_c;
                                    
                                    if (!(esi_1 & 0x40))
                                    {
                                        var_238_1 = sub_403330(var_25c_12);
                                        var_234_1 = 0;
                                    }
                                    else
                                    {
                                        int32_t eax_28 = sub_403330(var_25c_12);
                                        var_238_1 = eax_28;
                                        int32_t eax_29;
                                        int32_t edx_6;
                                        edx_6 = HIGHD(eax_28);
                                        eax_29 = LOWD(eax_28);
                                        var_234_1 = edx_6;
                                    }
                                }
                                
                                int32_t var_22c_1;
                                int32_t var_228_1;
                                
                                if (!(esi_1 & 0x40) || var_234_1 > 0
                                    || (var_234_1 >= 0 && var_238_1 >= 0))
                                {
                                    var_22c_1 = var_238_1;
                                    var_228_1 = var_234_1;
                                }
                                else
                                {
                                    var_22c_1 = -(var_238_1);
                                    esi_1 |= 0x100;
                                    var_228_1 = -((var_234_1 + 0));
                                }
                                
                                if (!(esi_1 & 0x8000))
                                {
                                    var_22c_1 &= 0xffffffff;
                                    var_228_1 = 0;
                                }
                                
                                if (var_23c >= 0)
                                    esi_1 &= 0xfffffff7;
                                else
                                    var_23c = 1;
                                
                                if (!var_228_1 && !var_22c_1)
                                    var_220 = nullptr;
                                
                                void var_1;
                                char* var_240_1 = &var_1;
                                
                                while (true)
                                {
                                    int32_t eax_37 = var_23c;
                                    var_23c -= 1;
                                    
                                    if (eax_37 <= 0 && !var_228_1 && !var_22c_1)
                                        break;
                                    
                                    int32_t eax_39;
                                    uint32_t edx_8;
                                    edx_8 = HIGHD(edi_4);
                                    eax_39 = LOWD(edi_4);
                                    int32_t ebx_3 =
                                        __aullrem(var_22c_1, var_228_1, edi_4, edx_8) + 0x30;
                                    uint32_t eax_43;
                                    int32_t edx_11;
                                    eax_43 = __aulldiv(var_22c_1, var_228_1, edi_4, edx_8);
                                    var_22c_1 = eax_43;
                                    var_228_1 = edx_11;
                                    
                                    if (ebx_3 > 0x39)
                                        ebx_3 += var_214;
                                    
                                    char* eax_44 = var_240_1;
                                    var_240_1 -= 1;
                                    *eax_44 = ebx_3;
                                }
                                
                                edi_1 = &var_1 - var_240_1;
                                var_240 = &var_240_1[1];
                                
                                if (esi_1 & 0x200 && (*var_240 != 0x30 || !edi_1))
                                {
                                    edi_1 += 1;
                                    var_240 -= 1;
                                    *var_240 = 0x30;
                                }
                                break;
                            }
                            case 8:
                            {
                                goto label_402b70;
                            }
                            case 0xa:
                            {
                                int16_t* eax_23 = sub_403330(&arg_c);
                                int32_t i_1 = i;
                                
                                if (!(esi_1 & 0x20))
                                    *eax_23 = i_1;
                                else
                                    *eax_23 = i_1;
                                
                                var_210 = 1;
                                break;
                            }
                            case 0xb:
                            {
                                edi_4 = 8;
                                
                                if (esi_1 & 0x80)
                                    esi_1 |= 0x200;
                                
                                goto label_402d1a;
                            }
                            case 0xc:
                            {
                                var_23c = 8;
                            label_402ce8:
                                var_214 = 7;
                            label_402cf6:
                                edi_4 = 0x10;
                                
                                if (esi_1 & 0x80)
                                {
                                    var_246 = 0x30;
                                    var_220 = 2;
                                    char var_245_1 = var_214 + 0x51;
                                }
                                
                                goto label_402d1a;
                            }
                            case 0xd:
                            {
                            label_402ba6:
                                int32_t ebx_1 = 0x7fffffff;
                                
                                if (var_23c != 0xffffffff)
                                    ebx_1 = var_23c;
                                
                                char* eax_20 = sub_403330(&arg_c);
                                var_240 = eax_20;
                                
                                if (!(esi_1 & 0x810))
                                {
                                    if (!var_240)
                                        var_240 = data_407884;
                                    
                                    char* edi_8 = var_240;
                                    int32_t ebx_4 = ebx_1 - 1;
                                    
                                    if (ebx_1)
                                    {
                                        while (*edi_8)
                                        {
                                            edi_8 = &edi_8[1];
                                            int32_t eax_52 = ebx_4;
                                            ebx_4 -= 1;
                                            
                                            if (!eax_52)
                                                break;
                                        }
                                    }
                                    
                                    edi_1 = edi_8 - var_240;
                                }
                                else
                                {
                                    if (!eax_20)
                                    {
                                        eax_20 = data_407888;
                                        var_240 = eax_20;
                                    }
                                    
                                    int16_t* ebp_1 = var_240;
                                    edi_1 = nullptr;
                                    var_21c = 1;
                                    
                                    if (ebx_1 > 0)
                                    {
                                        do
                                        {
                                            eax_20 = *ebp_1;
                                            
                                            if (!eax_20)
                                                break;
                                            
                                            void var_248;
                                            eax_20 = sub_404790(&var_248, eax_20);
                                            
                                            if (!eax_20)
                                                break;
                                            
                                            edi_1 += eax_20;
                                            ebp_1 = &ebp_1[1];
                                        } while (edi_1 < ebx_1);
                                    }
                                }
                                break;
                            }
                            case 0xe:
                            {
                                edi_4 = 0xa;
                                goto label_402d1a;
                            }
                            case 0xf:
                            {
                                var_214 = 0x27;
                                goto label_402cf6;
                            }
                        }
                    }
                    
                    if (!var_210)
                    {
                        if (esi_1 & 0x40)
                        {
                            if (esi_1 & 0x100)
                            {
                                var_246 = 0x2d;
                                var_220 = 1;
                            }
                            else if (esi_1 & 1)
                            {
                                var_246 = 0x2b;
                                var_220 = 1;
                            }
                            else if (esi_1 & 2)
                            {
                                var_246 = 0x20;
                                var_220 = 1;
                            }
                        }
                        
                        int32_t* eax_55 = var_224 - edi_1 - var_220;
                        
                        if (!(esi_1 & 0xc))
                            sub_4032b0(0x20, eax_55, arg1, &i);
                        
                        sub_4032f0(&var_246, var_220, arg1, &i);
                        
                        if (esi_1 & 8 && !(esi_1 & 4))
                            sub_4032b0(0x30, eax_55, arg1, &i);
                        
                        if (!var_21c || edi_1 <= 0)
                            sub_4032f0(var_240, edi_1, arg1, &i);
                        else
                        {
                            char* ebp_3 = var_240;
                            void* j_3 = edi_1 - 1;
                            void* j_2;
                            
                            do
                            {
                                char* eax_56 = ebp_3;
                                eax_56 = *eax_56;
                                ebp_3 = &ebp_3[2];
                                void var_244;
                                int32_t* eax_57 = sub_404790(&var_244, eax_56);
                                
                                if (eax_57 <= 0)
                                    break;
                                
                                sub_4032f0(&var_244, eax_57, arg1, &i);
                                j_2 = j_3;
                                j_3 -= 1;
                            } while (j_2);
                        }
                        
                        if (esi_1 & 4)
                            sub_4032b0(0x20, eax_55, arg1, &i);
                    }
                    break;
                }
            }
            
            char* eax_15 = arg2;
            arg2 = &arg2[1];
            ebx = *eax_15;
            
            if (!ebx)
                break;
        }
    }
    
    return i;
}

int32_t* sub_403260(int32_t arg1, int32_t* arg2, int32_t* arg3)
{
    int32_t eax = arg2[1];
    arg2[1] = eax - 1;
    uint32_t eax_3;
    
    if (eax - 1 < 0)
    {
        int32_t var_8_1 = arg1;
        eax_3 = sub_402730(arg2);
    }
    else
    {
        **arg2 = arg1;
        char* ecx_1 = *arg2;
        eax_3 = 0;
        eax_3 = *ecx_1;
        *arg2 = &ecx_1[1];
    }
    
    if (eax_3 != 0xffffffff)
    {
        *arg3 += 1;
        return arg3;
    }
    
    *arg3 = 0xffffffff;
    return arg3;
}

int32_t* sub_4032b0(int32_t arg1, int32_t* arg2, int32_t* arg3, int32_t* arg4)
{
    int32_t* result_1 = arg2;
    int32_t* result;
    
    do
    {
        result = result_1;
        result_1 -= 1;
        
        if (result <= 0)
            break;
        
        result = sub_403260(arg1, arg3, arg4);
    } while (*arg4 != 0xffffffff);
    
    return result;
}

int32_t* sub_4032f0(char* arg1, int32_t* arg2, int32_t* arg3, int32_t* arg4)
{
    char* esi = arg1;
    int32_t* result_1 = arg2;
    int32_t* result;
    
    do
    {
        result = result_1;
        result_1 -= 1;
        
        if (result <= 0)
            break;
        
        char* eax_1 = esi;
        esi = &esi[1];
        result = sub_403260(*eax_1, arg3, arg4);
    } while (*arg4 != 0xffffffff);
    
    return result;
}

int32_t sub_403330(int32_t* arg1)
{
    void* ecx_1 = *arg1 + 4;
    *arg1 = ecx_1;
    return *(ecx_1 - 4);
}

int32_t sub_403340(int32_t* arg1)
{
    void* ecx_1 = *arg1 + 8;
    *arg1 = ecx_1;
    *(ecx_1 - 4);
    return *(ecx_1 - 8);
}

int32_t* sub_403360(int32_t* arg1)
{
    int32_t* result = arg1;
    void* ecx_1 = *result + 4;
    *result = ecx_1;
    result = *(ecx_1 - 4);
    return result;
}

int32_t sub_403370(int32_t arg1)
{
    int32_t ebp;
    int32_t var_4 = ebp;
    int32_t* var_14 = &var_4;
    return RtlUnwind(arg1, 0x403388, nullptr, nullptr);
}

int32_t sub_403390(int32_t arg1, int32_t arg2, int32_t* arg3 @ 0x10)
{
    if (!(*(arg1 + 4) & 6))
        return 1;
    
    *arg3 = arg2;
    return 3;
}

void* sub_4033b2(void* arg1, int32_t arg2)
{
    void* var_10 = arg1;
    int32_t var_14 = 0xfffffffe;
    int32_t (* var_18)(int32_t arg1, int32_t arg2, int32_t* arg3 @ 0x10) = sub_403390;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    
    while (true)
    {
        int32_t ebx_1 = *(arg1 + 8);
        int32_t esi_1 = *(arg1 + 0xc);
        
        if (esi_1 == 0xffffffff || esi_1 == arg2)
        {
            fsbase->NtTib.ExceptionList = ExceptionList;
            return arg1;
        }
        
        int32_t esi_2 = esi_1 * 3;
        int32_t ecx_1 = *(ebx_1 + (esi_2 << 2));
        int32_t var_14_1 = ecx_1;
        *(arg1 + 0xc) = ecx_1;
        
        if (!*(ebx_1 + (esi_2 << 2) + 4))
        {
            int32_t var_20_1 = 0x101;
            void* ebp;
            sub_403446(*(ebx_1 + (esi_2 << 2) + 8), ebp);
            (*(ebx_1 + (esi_2 << 2) + 8))();
        }
    }
}

int32_t __abnormal_termination()
{
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    
    if (ExceptionList->Handler == sub_403390
            && *(ExceptionList + 8) == *(*(ExceptionList + 0xc) + 0xc))
        return 1;
    
    return 0;
}

void __convention("regparm") sub_403446(int32_t arg1, void* arg2 @ ebp)
{
    data_407894 = *(arg2 + 8);
    data_407890 = arg1;
    data_407898 = arg2;
}

int32_t sub_403460(int32_t arg1, EXCEPTION_POINTERS* arg2)
{
    int32_t* eax = sub_4035c0(arg1);
    
    if (eax)
    {
        int32_t edx_1 = eax[2];
        
        if (edx_1)
        {
            if (edx_1 == 5)
            {
                eax[2] = 0;
                return 1;
            }
            
            if (edx_1 == 1)
                return 0xffffffff;
            
            int32_t esi = data_407928;
            data_407928 = arg2;
            
            if (eax[1] != 8)
            {
                eax[2] = 0;
                edx_1(eax[1]);
            }
            else
            {
                if (data_407918 < data_40791c + data_407918)
                {
                    int32_t* edi_1 = data_407918 * 0xc + &data_4078a8;
                    int32_t i_1 = data_40791c;
                    int32_t i;
                    
                    do
                    {
                        *edi_1 = 0;
                        edi_1 = &edi_1[3];
                        i = i_1;
                        i_1 -= 1;
                    } while (i != 1);
                }
                
                int32_t edi_2 = data_407924;
                
                switch (*eax)
                {
                    case 0xc000008d:
                    {
                        data_407924 = 0x82;
                        break;
                    }
                    case 0xc000008e:
                    {
                        data_407924 = 0x83;
                        break;
                    }
                    case 0xc000008f:
                    {
                        data_407924 = 0x86;
                        break;
                    }
                    case 0xc0000090:
                    {
                        data_407924 = 0x81;
                        break;
                    }
                    case 0xc0000091:
                    {
                        data_407924 = 0x84;
                        break;
                    }
                    case 0xc0000092:
                    {
                        data_407924 = 0x8a;
                        break;
                    }
                    case 0xc0000093:
                    {
                        data_407924 = 0x85;
                        break;
                    }
                }
                
                edx_1(8, data_407924);
                data_407924 = edi_2;
            }
            
            data_407928 = esi;
            return 0xffffffff;
        }
    }
    
    return UnhandledExceptionFilter(arg2);
}

void* sub_4035c0(int32_t arg1)
{
    int32_t* edx = &data_4078a0;
    
    while (*edx != arg1)
    {
        edx = &edx[3];
        
        if (data_407920 * 0xc + &data_4078a0 <= edx)
            break;
    }
    
    int32_t eax_5 = *edx - arg1;
    return (eax_5 - eax_5) & edx;
}

int32_t sub_4035f0(char arg1)
{
    return sub_403610(arg1, 0, 4);
}

int32_t sub_403610(char arg1, int32_t arg2, int32_t arg3)
{
    void* edx = nullptr;
    int32_t ecx = 0;
    edx = arg1;
    ecx = *(edx + 0x407939);
    
    if (!(arg3 & ecx))
    {
        int32_t ecx_1 = 0;
        
        if (arg2)
        {
            int32_t ecx_2 = 0;
            ecx_2 = data_40815a[edx];
            ecx_1 = ecx_2 & arg2;
        }
        
        if (!ecx_1)
            return 0;
    }
    
    return 1;
}

BOOL sub_403650()
{
    char* edx = data_407858;
    int32_t esi = 0;
    
    while (*edx)
    {
        if (*edx != 0x3d)
            esi += 1;
        
        char* edi_1 = edx;
        int32_t i = 0xffffffff;
        
        while (i)
        {
            bool cond:0_1 = 0 != *edi_1;
            edi_1 = &edi_1[1];
            i -= 1;
            
            if (!cond:0_1)
                break;
        }
        
        edx = &edx[~i];
    }
    
    int32_t* eax_1 = sub_404940((esi << 2) + 4);
    data_407838 = eax_1;
    int32_t* ebx = eax_1;
    
    if (!ebx)
        sub_402700(9);
    
    char* ebp = data_407858;
    
    while (*ebp)
    {
        char* edi_2 = ebp;
        int32_t i_1 = 0xffffffff;
        
        while (i_1)
        {
            bool cond:1_1 = 0 != *edi_2;
            edi_2 = &edi_2[1];
            i_1 -= 1;
            
            if (!cond:1_1)
                break;
        }
        
        int32_t ecx_2 = ~i_1;
        
        if (*ebp != 0x3d)
        {
            int32_t eax_3 = sub_404940(ecx_2);
            *ebx = eax_3;
            
            if (!eax_3)
                sub_402700(9);
            
            char* edi_3 = ebp;
            int32_t i_2 = 0xffffffff;
            
            while (i_2)
            {
                bool cond:2_1 = 0 != *edi_3;
                edi_3 = &edi_3[1];
                i_2 -= 1;
                
                if (!cond:2_1)
                    break;
            }
            
            int32_t ecx_3 = ~i_2;
            int32_t edi_5 = *ebx;
            ebx = &ebx[1];
            int32_t esi_2;
            int32_t edi_6;
            edi_6 = __builtin_memcpy(edi_5, edi_3 - ecx_3, ecx_3 & 0xfffffffc);
            __builtin_memcpy(edi_6, esi_2, ecx_3 & 3);
        }
        
        ebp = &ebp[ecx_2];
    }
    
    BOOL result = sub_404920(data_407858);
    *ebx = 0;
    return result;
}

int32_t sub_403730()
{
    char* esi = &data_4085a0;
    GetModuleFileNameA(nullptr, &data_4085a0, 0x104);
    char* eax = data_4097c0;
    data_407848 = &data_4085a0;
    
    if (*eax)
        esi = data_4097c0;
    
    int32_t var_8;
    int32_t var_4;
    sub_4037d0(esi, nullptr, nullptr, &var_8, &var_4);
    int32_t* eax_4 = sub_404940((var_8 << 2) + var_4);
    
    if (!eax_4)
        sub_402700(8);
    
    sub_4037d0(esi, eax_4, &eax_4[var_8], &var_8, &var_4);
    int32_t result = var_8 - 1;
    data_407830 = eax_4;
    data_40782c = result;
    return result;
}

char* sub_4037d0(char* arg1, int32_t* arg2, char* arg3, int32_t* arg4, int32_t* arg5)
{
    int32_t ebx;
    int32_t var_4 = ebx;
    char* esi = arg1;
    char* result = arg3;
    *arg5 = 0;
    *arg4 = 1;
    
    if (arg2)
    {
        int32_t* edx = arg2;
        arg2 = &arg2[1];
        *edx = result;
    }
    
    if (*esi == 0x22)
    {
        esi = &esi[1];
        
        while (*esi != 0x22)
        {
            char ebx_3 = *esi;
            
            if (!ebx_3)
                break;
            
            void* edx_3 = nullptr;
            edx_3 = ebx_3;
            
            if (*(edx_3 + 0x407939) & 4)
            {
                *arg5 += 1;
                
                if (result)
                {
                    char edx_4 = *esi;
                    esi = &esi[1];
                    *result = edx_4;
                    result = &result[1];
                }
            }
            
            *arg5 += 1;
            
            if (result)
            {
                *result = *esi;
                result = &result[1];
            }
            
            esi = &esi[1];
        }
        
        *arg5 += 1;
        
        if (result)
        {
            *result = 0;
            result = &result[1];
        }
        
        if (*esi == 0x22)
            esi = &esi[1];
    }
    else
    {
        while (true)
        {
            *arg5 += 1;
            
            if (result)
            {
                *result = *esi;
                result = &result[1];
            }
            
            char edx_1 = *esi;
            esi = &esi[1];
            void* ebx_1 = nullptr;
            ebx_1 = edx_1;
            
            if (*(ebx_1 + 0x407939) & 4)
            {
                *arg5 += 1;
                
                if (result)
                {
                    *result = *esi;
                    result = &result[1];
                }
                
                esi = &esi[1];
            }
            
            if (edx_1 == 0x20)
            {
            label_40383c:
                
                if (edx_1)
                {
                    if (result)
                        result[0xffffffff] = 0;
                    
                    break;
                }
            }
            else if (edx_1)
            {
                if (edx_1 == 9)
                    goto label_40383c;
                
                continue;
            }
            
            esi -= 1;
            break;
        }
    }
    
    int32_t edi = 0;
    
    while (*esi)
    {
        while (true)
        {
            char edx_5 = *esi;
            
            if (edx_5 != 0x20 && edx_5 != 9)
                break;
            
            esi = &esi[1];
        }
        
        if (!*esi)
            break;
        
        if (arg2)
        {
            int32_t* edx_6 = arg2;
            arg2 = &arg2[1];
            *edx_6 = result;
        }
        
        *arg4 += 1;
        
        while (true)
        {
            int32_t ebx_4 = 1;
            uint32_t ebp_1 = 0;
            
            while (*esi == 0x5c)
            {
                esi = &esi[1];
                ebp_1 += 1;
            }
            
            if (*esi == 0x22)
            {
                if (!(ebp_1 & 1))
                {
                    if (!edi || esi[1] != 0x22)
                        ebx_4 = 0;
                    else
                        esi = &esi[1];
                    
                    edi = -((edi - edi));
                }
                
                ebp_1 u>>= 1;
            }
            
            uint32_t i_1 = ebp_1 - 1;
            
            if (ebp_1)
            {
                uint32_t i;
                
                do
                {
                    if (result)
                    {
                        *result = 0x5c;
                        result = &result[1];
                    }
                    
                    i = i_1;
                    *arg5 += 1;
                    i_1 -= 1;
                } while (i);
            }
            
            char edx_9 = *esi;
            
            if (!edx_9)
                break;
            
            if (!edi)
            {
                if (edx_9 == 0x20)
                    break;
                
                if (edx_9 == 9)
                    break;
            }
            
            if (ebx_4)
            {
                if (!result)
                {
                    void* ebx_6 = nullptr;
                    ebx_6 = edx_9;
                    
                    if (*(ebx_6 + 0x407939) & 4)
                    {
                        esi = &esi[1];
                        *arg5 += 1;
                    }
                    
                    *arg5 += 1;
                }
                else
                {
                    void* ebx_5 = nullptr;
                    ebx_5 = edx_9;
                    
                    if (*(ebx_5 + 0x407939) & 4)
                    {
                        *result = edx_9;
                        esi = &esi[1];
                        result = &result[1];
                        *arg5 += 1;
                    }
                    
                    edx_9 = *esi;
                    result = &result[1];
                    esi = &esi[1];
                    result[0xffffffff] = edx_9;
                    *arg5 += 1;
                    continue;
                }
            }
            
            esi = &esi[1];
        }
        
        if (result)
        {
            *result = 0;
            result = &result[1];
        }
        
        *arg5 += 1;
    }
    
    if (arg2)
        *arg2 = 0;
    
    *arg4 += 1;
    return result;
}

PSTR sub_4039b0()
{
    PWSTR penv;
    PWSTR penv_3;
    PWSTR penv_1;
    
    if (data_407930)
    {
        penv_3 = penv_1;
        penv = penv_1;
    }
    else
    {
        penv_3 = GetEnvironmentStringsW();
        
        if (!penv_3)
        {
            penv = GetEnvironmentStrings();
            
            if (!penv)
                return 0;
            
            data_407930 = 2;
        }
        else
        {
            data_407930 = 1;
            penv = penv_1;
        }
    }
    
    if (data_407930 != 1)
    {
        if (data_407930 != 2)
            return 0;
        
        if (!penv)
        {
            penv = GetEnvironmentStrings();
            
            if (!penv)
                return 0;
        }
        
        PWSTR penv_2 = penv;
        
        if (*penv)
        {
            while (true)
            {
                penv_2 += 1;
                
                if (!*penv_2)
                {
                    penv_2 += 1;
                    
                    if (!*penv_2)
                        break;
                }
            }
        }
        
        int32_t eax_12 = sub_404940(penv_2 - penv + 1);
        
        if (!eax_12)
        {
            FreeEnvironmentStringsA(penv);
            return 0;
        }
        
        int32_t esi_4;
        int32_t edi_1;
        edi_1 = __builtin_memcpy(eax_12, penv, (penv_2 - penv + 1) & 0xfffffffc);
        __builtin_memcpy(edi_1, esi_4, (penv_2 - penv + 1) & 3);
        FreeEnvironmentStringsA(penv);
        return eax_12;
    }
    
    if (!penv_3)
    {
        penv_3 = GetEnvironmentStringsW();
        
        if (!penv_3)
            return 0;
    }
    
    PWSTR penv_4 = penv_3;
    
    if (*penv_3)
    {
        while (true)
        {
            penv_4 = &penv_4[1];
            
            if (!*penv_4)
            {
                penv_4 = &penv_4[1];
                
                if (!*penv_4)
                    break;
            }
        }
    }
    
    int32_t cbMultiByte = WideCharToMultiByte(0, 0, penv_3, ((penv_4 - penv_3) >> 1) + 1, nullptr, 
        0, nullptr, nullptr);
    
    if (cbMultiByte)
    {
        PSTR lpMultiByteStr = sub_404940(cbMultiByte);
        
        if (lpMultiByteStr)
        {
            if (!WideCharToMultiByte(0, 0, penv_3, ((penv_4 - penv_3) >> 1) + 1, lpMultiByteStr, 
                cbMultiByte, nullptr, nullptr))
            {
                sub_404920(lpMultiByteStr);
                lpMultiByteStr = nullptr;
            }
            
            FreeEnvironmentStringsW(penv_3);
            return lpMultiByteStr;
        }
    }
    
    FreeEnvironmentStringsW(penv_3);
    return 0;
}

int32_t sub_403b50(int32_t arg1)
{
    uint32_t CodePage = sub_403d30(arg1);
    
    if (data_407a3c == CodePage)
        return 0;
    
    if (!CodePage)
    {
        sub_403de0();
        return 0;
    }
    
    int32_t var_18 = 0;
    
    for (int32_t* i = &data_407a60; i < 0x407b50; )
    {
        if (*i == CodePage)
        {
            void* j = nullptr;
            *__builtin_memset(0x407938, 0, 0x100) = 0;
            
            do
            {
                char* esi_2 = ((j + var_18 * 6) << 3) + &data_407a70;
                
                while (*esi_2)
                {
                    char ecx_5 = esi_2[1];
                    
                    if (!ecx_5)
                        break;
                    
                    void* edx_3 = nullptr;
                    int32_t ebx_1 = 0;
                    edx_3 = *esi_2;
                    ebx_1 = ecx_5;
                    
                    if (ebx_1 >= edx_3)
                    {
                        ecx_5 = *(j + 0x407a58);
                        int32_t ebx_2;
                        
                        do
                        {
                            *(edx_3 + 0x407939) |= ecx_5;
                            edx_3 += 1;
                            ebx_2 = 0;
                            ebx_2 = esi_2[1];
                        } while (ebx_2 >= edx_3);
                    }
                    
                    esi_2 = &esi_2[2];
                }
                
                j += 1;
            } while (j < 4);
            
            data_407a3c = CodePage;
            data_407a40 = sub_403d80(CodePage);
            int32_t eax_7 = var_18 << 4;
            int32_t ebx_3 = *(eax_7 * 3 + &data_407a68);
            int32_t ecx_7 = *(eax_7 * 3 + 0x407a6c);
            data_407a48 = *(eax_7 * 3 + 0x407a64);
            data_407a4c = ebx_3;
            data_407a50 = ecx_7;
            return 0;
        }
        
        i = &i[0xc];
        var_18 += 1;
    }
    
    CPINFO cPInfo;
    
    if (GetCPInfo(CodePage, &cPInfo) != 1)
    {
        if (!data_407a54)
            return 0xffffffff;
        
        sub_403de0();
        return 0;
    }
    
    *__builtin_memset(0x407938, 0, 0x100) = 0;
    int32_t eax_4;
    
    if (cPInfo.MaxCharSize <= 1)
    {
        eax_4 = 0;
        data_407a3c = 0;
    }
    else
    {
        var_e;
        char* esi_1 = &var_e;
        
        if (cPInfo.LeadByte[0])
        {
            do
            {
                char ecx_1 = esi_1[1];
                
                if (!ecx_1)
                    break;
                
                void* eax_3 = nullptr;
                int32_t edx_1 = 0;
                eax_3 = *esi_1;
                edx_1 = ecx_1;
                
                if (edx_1 >= eax_3)
                {
                    int32_t ecx_2;
                    
                    do
                    {
                        *(eax_3 + 0x407939) |= 4;
                        eax_3 += 1;
                        ecx_2 = 0;
                        ecx_2 = esi_1[1];
                    } while (ecx_2 >= eax_3);
                }
                
                esi_1 = &esi_1[2];
            } while (*esi_1);
        }
        
        for (void* i_1 = 1; i_1 < 0xff; i_1 += 1)
            *(i_1 + 0x407939) |= 8;
        
        data_407a3c = CodePage;
        eax_4 = sub_403d80(CodePage);
    }
    
    data_407a40 = eax_4;
    data_407a48 = 0;
    data_407a4c = 0;
    data_407a50 = 0;
    return 0;
}

int32_t sub_403d30(int32_t arg1)
{
    data_407a54 = 0;
    
    if (arg1 == 0xfffffffe)
    {
        data_407a54 = 1;
        /* tailcall */
        return GetOEMCP();
    }
    
    if (arg1 == 0xfffffffd)
    {
        data_407a54 = 1;
        /* tailcall */
        return GetACP();
    }
    
    if (arg1 != 0xfffffffc)
        return arg1;
    
    data_407a54 = 1;
    return data_408378;
}

int32_t sub_403d80(int32_t arg1)
{
    if (arg1 - 0x3a4 <= 0x12)
    {
        int32_t ecx_1 = 0;
        ecx_1 = *(arg1 + sub_4039b0+0x78);
        
        switch (ecx_1)
        {
            case 0:
            {
                return 0x411;
                break;
            }
            case 1:
            {
                return 0x804;
                break;
            }
            case 2:
            {
                return 0x412;
                break;
            }
            case 3:
            {
                return 0x404;
                break;
            }
        }
    }
    
    return 0;
}

int32_t sub_403de0()
{
    *__builtin_memset(0x407938, 0, 0x100) = 0;
    data_407a48 = 0;
    data_407a3c = 0;
    data_407a40 = 0;
    data_407a4c = 0;
    data_407a50 = 0;
    return 0;
}

int32_t sub_403e10()
{
    return sub_403b50(0xfffffffd);
}

uint32_t sub_403e20()
{
    void* i = sub_404940(0x100);
    
    if (!i)
        sub_402700(0x1b);
    
    data_4096c0 = i;
    data_4096b4 = 0x20;
    
    if (i + 0x100 > i)
    {
        do
        {
            *(i + 4) = 0;
            i += 8;
            *(i - 8) = 0xffffffff;
            *(i - 3) = 0xa;
        } while (data_4096c0 + 0x100 > i);
    }
    
    STARTUPINFOA startupInfo;
    GetStartupInfoA(&startupInfo);
    
    if (startupInfo.cbReserved2 && startupInfo.lpReserved2)
    {
        LPBYTE lpReserved2 = startupInfo.lpReserved2;
        void* const i_1 = *lpReserved2;
        char* ebx_1 = &lpReserved2[4];
        int32_t* esi = i_1 + ebx_1;
        
        if (i_1 >= 0x800)
            i_1 = 0x800;
        
        if (i_1 > data_4096b4)
        {
            int32_t* ebp_1 = &data_4096c4;
            
            do
            {
                void* j = sub_404940(0x100);
                
                if (!j)
                {
                    i_1 = data_4096b4;
                    break;
                }
                
                *ebp_1 = j;
                data_4096b4 += 0x20;
                
                if (j + 0x100 > j)
                {
                    do
                    {
                        *(j + 4) = 0;
                        j += 8;
                        *(j - 8) = 0xffffffff;
                        *(j - 3) = 0xa;
                    } while (*ebp_1 + 0x100 > j);
                }
                
                ebp_1 = &ebp_1[1];
            } while (i_1 > data_4096b4);
        }
        
        int32_t ebp_2 = 0;
        
        if (i_1 > 0)
        {
            do
            {
                HANDLE hFile = *esi;
                
                if (hFile != 0xffffffff && *ebx_1 & 1 && GetFileType(hFile))
                {
                    int32_t* ecx_4 =
                        *(((ebp_2 & 0xffffffe7) >> 3) + &data_4096c0) + ((ebp_2 & 0x1f) << 3);
                    *ecx_4 = *esi;
                    ecx_4[1] = *ebx_1;
                }
                
                ebp_2 += 1;
                ebx_1 = &ebx_1[1];
                esi = &esi[1];
            } while (ebp_2 < i_1);
        }
    }
    
    for (int32_t i_2 = 0; i_2 < 3; i_2 += 1)
    {
        int32_t* ebx_3 = (i_2 << 3) + data_4096c0;
        
        if (*ebx_3 != 0xffffffff)
            ebx_3[1] |= 0x80;
        else
        {
            enum STD_HANDLE nStdHandle = STD_INPUT_HANDLE;
            ebx_3[1] = 0x81;
            
            if (i_2)
                nStdHandle = 0xfffffff5 - 1;
            
            HANDLE hFile_1 = GetStdHandle(nStdHandle);
            enum FILE_TYPE eax_10;
            
            if (hFile_1 != 0xffffffff)
                eax_10 = GetFileType(hFile_1);
            
            if (hFile_1 == 0xffffffff || !eax_10)
                ebx_3[1] |= 0x40;
            else
            {
                int32_t eax_11 = eax_10 & 0xff;
                *ebx_3 = hFile_1;
                
                if (eax_11 == 2)
                    ebx_3[1] |= 0x40;
                else if (eax_11 == 3)
                    ebx_3[1] |= 8;
            }
        }
    }
    
    return SetHandleCount(data_4096b4);
}

HANDLE sub_404000()
{
    HANDLE result = HeapCreate(HEAP_NO_SERIALIZE, 0x1000, 0);
    data_4096b0 = result;
    return result;
}

int32_t __convention("regparm") sub_404018(char* arg1, int16_t arg2, void* arg3 @ 0x4, void* arg4 @ 0x8, int32_t arg5 @ 0xc)
{
    char* esi;
    char* var_4 = esi;
    *(&arg2 + 1) ^= *arg1;
    char* eax = var_4;
    *eax ^= *(&arg2 + 1);
    char* ebp;
    var_4 = ebp;
    char** ebp_1 = &var_4;
    int32_t entry_ebx;
    int32_t var_10 = entry_ebx + 2;
    char* var_14 = esi;
    void* ebx_2 = arg4;
    
    if (*(arg3 + 4) & 6)
    {
        char** var_20_5 = &var_4;
        sub_4033b2(ebx_2, 0xffffffff);
        return 1;
    }
    
    void* var_c = arg3;
    int32_t var_8_1 = arg5;
    *(ebx_2 - 4) = &var_c;
    int32_t i = *(ebx_2 + 0xc);
    int32_t edi_1 = *(ebx_2 + 8);
    
    for (; i != 0xffffffff; i = *(edi_1 + i * 0xc))
    {
        int32_t ecx_1 = i * 3;
        
        if (*(edi_1 + (ecx_1 << 2) + 4))
        {
            int32_t eax_3 = (*(edi_1 + (ecx_1 << 2) + 4))(ebp_1, i, &var_4);
            ebx_2 = ebp_1[3];
            
            if (eax_3)
            {
                if (eax_3 < 0)
                    return 0;
                
                int32_t edi_2 = *(ebx_2 + 8);
                sub_403370(ebx_2);
                ebp_1 = ebx_2 + 0x10;
                sub_4033b2(ebx_2, i);
                int32_t ecx_2 = i * 3;
                int32_t var_20_4 = 1;
                sub_403446(*(edi_2 + (ecx_2 << 2) + 8), ebp_1);
                *(ebx_2 + 0xc) = *(edi_2 + (ecx_2 << 2));
                (*(edi_2 + (ecx_2 << 2) + 8))();
            }
        }
        
        edi_1 = *(ebx_2 + 8);
    }
    
    return 1;
}

void* __stdcall __seh_longjmp_unwind@4(int32_t* arg1)
{
    *arg1;
    return sub_4033b2(arg1[6], arg1[7]);
}

BOOL sub_404100()
{
    BOOL result = data_407864;
    
    if (result != 1 && (result || data_407868 != 1))
        return result;
    
    sub_404140(0xfc);
    int32_t eax = data_407e48;
    
    if (eax)
        eax();
    
    return sub_404140(0xff);
}

BOOL sub_404140(int32_t arg1)
{
    BOOL result = 0;
    int32_t* ecx = &data_407dc0;
    
    while (*ecx != arg1)
    {
        ecx = &ecx[2];
        result += 1;
        
        if (ecx >= 0x407e48)
            break;
    }
    
    int32_t ebx = result << 3;
    
    if (*((result << 3) + &data_407dc0) == arg1)
    {
        uint32_t var_1bc;
        
        if (data_407864 == 1 || (!data_407864 && data_407868 == 1))
        {
            HANDLE hFile = *(data_4096c0 + 0x10);
            
            if (hFile == 0xffffffff)
            {
                var_1bc = 0xfffffff4;
                hFile = GetStdHandle(var_1bc);
            }
            
            uint8_t* lpBuffer = *(ebx + 0x407dc4);
            var_1bc = 0;
            uint8_t* lpBuffer_1 = lpBuffer;
            int32_t i = 0xffffffff;
            
            while (i)
            {
                bool cond:1_1 = 0 != *lpBuffer_1;
                lpBuffer_1 = &lpBuffer_1[1];
                i -= 1;
                
                if (!cond:1_1)
                    break;
            }
            
            uint32_t numberOfBytesWritten;
            return WriteFile(hFile, lpBuffer, ~i - 1, &numberOfBytesWritten, var_1bc);
        }
        
        if (arg1 != 0xfc)
        {
            var_1bc = 0x104;
            uint8_t filename[0x104];
            
            if (!GetModuleFileNameA(nullptr, &filename, var_1bc))
            {
                int16_t* esi_1;
                int16_t* edi_1;
                edi_1 = __builtin_memcpy(&filename, "<program name unknown>", 0x14);
                *edi_1 = *esi_1;
                edi_1[1] = esi_1[1];
            }
            
            uint8_t (* ebp)[0x104] = &filename;
            uint8_t (* edi_4)[0x104] = &filename;
            int32_t i_1 = 0xffffffff;
            
            while (i_1)
            {
                bool cond:2_1 = 0 != *edi_4;
                edi_4 = &(*edi_4)[1];
                i_1 -= 1;
                
                if (!cond:2_1)
                    break;
            }
            
            if (~i_1 > 0x3c)
            {
                uint8_t (* edi_5)[0x104] = &filename;
                int32_t i_2 = 0xffffffff;
                var_1bc = 3;
                
                while (i_2)
                {
                    bool cond:9_1 = 0 != *edi_5;
                    edi_5 = &(*edi_5)[1];
                    i_2 -= 1;
                    
                    if (!cond:9_1)
                        break;
                }
                
                ebp = &var_1bc + ~i_2 + 0x7c;
                sub_4024c0(ebp, "...", var_1bc);
            }
            
            void var_1a4;
            int16_t* esi_4;
            int16_t* edi_6;
            edi_6 = __builtin_memcpy(&var_1a4, "Runtime Error!\n\nProgram: ", 0x18);
            *edi_6 = *esi_4;
            uint8_t (* edi_8)[0x104] = ebp;
            int32_t i_3 = 0xffffffff;
            
            while (i_3)
            {
                bool cond:3_1 = 0 != *edi_8;
                edi_8 = &(*edi_8)[1];
                i_3 -= 1;
                
                if (!cond:3_1)
                    break;
            }
            
            int32_t ecx_3 = ~i_3;
            int32_t i_4 = 0xffffffff;
            void* edi_10 = &var_1a4;
            
            while (i_4)
            {
                bool cond:4_1 = 0 != *edi_10;
                edi_10 += 1;
                i_4 -= 1;
                
                if (!cond:4_1)
                    break;
            }
            
            int32_t esi_7;
            int32_t edi_12;
            edi_12 = __builtin_memcpy(edi_10 - 1, edi_8 - ecx_3, ecx_3 & 0xfffffffc);
            __builtin_memcpy(edi_12, esi_7, ecx_3 & 3);
            void* edi_13 = &data_407e74;
            int32_t i_5 = 0xffffffff;
            
            while (i_5)
            {
                bool cond:5_1 = 0 != *edi_13;
                edi_13 += 1;
                i_5 -= 1;
                
                if (!cond:5_1)
                    break;
            }
            
            int32_t ecx_8 = ~i_5;
            int32_t i_6 = 0xffffffff;
            void* edi_15 = &var_1a4;
            
            while (i_6)
            {
                bool cond:6_1 = 0 != *edi_15;
                edi_15 += 1;
                i_6 -= 1;
                
                if (!cond:6_1)
                    break;
            }
            
            int32_t esi_9;
            int32_t edi_17;
            edi_17 = __builtin_memcpy(edi_15 - 1, edi_13 - ecx_8, ecx_8 & 0xfffffffc);
            __builtin_memcpy(edi_17, esi_9, ecx_8 & 3);
            int32_t edi_18 = *(ebx + 0x407dc4);
            int32_t i_7 = 0xffffffff;
            
            while (i_7)
            {
                bool cond:7_1 = 0 != *edi_18;
                edi_18 += 1;
                i_7 -= 1;
                
                if (!cond:7_1)
                    break;
            }
            
            int32_t ecx_13 = ~i_7;
            void* edi_20 = &var_1a4;
            int32_t i_8 = 0xffffffff;
            
            while (i_8)
            {
                bool cond:8_1 = 0 != *edi_20;
                edi_20 += 1;
                i_8 -= 1;
                
                if (!cond:8_1)
                    break;
            }
            
            int32_t esi_11;
            int32_t edi_22;
            edi_22 = __builtin_memcpy(edi_20 - 1, edi_18 - ecx_13, ecx_13 & 0xfffffffc);
            var_1bc = 0x12010;
            __builtin_memcpy(edi_22, esi_11, ecx_13 & 3);
            return sub_4049c0(&var_1a4, "Microsoft Visual C++ Runtime Library", var_1bc);
        }
    }
    
    return result;
}

int32_t sub_404330(int32_t arg1, char* arg2, uint32_t arg3)
{
    if (data_4096b4 > arg1)
    {
        char eax_8 = *(*(((arg1 & 0xffffffe7) >> 3) + 0x4096c0) + ((arg1 & 0x1f) << 3) + 4);
        
        if (eax_8 & 1)
        {
            int32_t esi = 0;
            uint32_t numberOfBytesWritten_1 = 0;
            
            if (!arg3)
                return 0;
            
            if (eax_8 & 0x20)
                sub_404560(arg1, 0, FILE_END);
            
            int32_t* ecx_3 = &(*(((arg1 & 0xffffffe7) >> 3) + 0x4096c0))[(arg1 & 0x1f) * 2];
            enum WIN32_ERROR var_418_1;
            uint32_t numberOfBytesWritten;
            
            if (!(ecx_3[1] & 0x80))
            {
                if (!WriteFile(*ecx_3, arg2, arg3, &numberOfBytesWritten, nullptr))
                {
                label_40447b:
                    var_418_1 = GetLastError();
                }
                else
                {
                    var_418_1 = NO_ERROR;
                    numberOfBytesWritten_1 = numberOfBytesWritten;
                }
            }
            else
            {
                var_418_1 = NO_ERROR;
                char* edi_1 = arg2;
                
                while (edi_1 - arg2 < arg3)
                {
                    uint8_t buffer[0x404];
                    uint8_t (* ebx_2)[0x404] = &buffer;
                    
                    while (edi_1 - arg2 < arg3)
                    {
                        char eax_15 = *edi_1;
                        edi_1 = &edi_1[1];
                        
                        if (eax_15 == 0xa)
                        {
                            *ebx_2 = 0xd;
                            esi += 1;
                            ebx_2 = &(*ebx_2)[1];
                        }
                        
                        *ebx_2 = eax_15;
                        ebx_2 = &(*ebx_2)[1];
                        
                        if (ebx_2 - &buffer >= 0x400)
                            break;
                    }
                    
                    uint32_t nNumberOfBytesToWrite = ebx_2 - &buffer;
                    
                    if (!WriteFile((*(((arg1 & 0xffffffe7) >> 3) + 0x4096c0))[(arg1 & 0x1f) * 2], 
                            &buffer, nNumberOfBytesToWrite, &numberOfBytesWritten, nullptr))
                        goto label_40447b;
                    
                    uint32_t numberOfBytesWritten_2 = numberOfBytesWritten;
                    numberOfBytesWritten_1 += numberOfBytesWritten_2;
                    
                    if (numberOfBytesWritten_2 < nNumberOfBytesToWrite)
                        break;
                }
            }
            
            if (numberOfBytesWritten_1)
                return numberOfBytesWritten_1 - esi;
            
            if (!var_418_1)
            {
                if ((*(((arg1 & 0xffffffe7) >> 3) + 0x4096c0))[(arg1 & 0x1f) * 2 + 1] & 0x40
                        && *arg2 == 0x1a)
                    return 0;
                
                data_407810 = 0x1c;
                data_407814 = 0;
                return 0xffffffff;
            }
            
            if (var_418_1 != ERROR_ACCESS_DENIED)
            {
                sub_404a60(var_418_1);
                return 0xffffffff;
            }
            
            data_407810 = 9;
            data_407814 = var_418_1;
            return 0xffffffff;
        }
    }
    
    data_407810 = 9;
    data_407814 = 0;
    return 0xffffffff;
}

uint32_t sub_404560(int32_t arg1, int32_t arg2, enum SET_FILE_POINTER_MOVE_METHOD arg3)
{
    if (arg1 < data_4096b4)
    {
        int32_t esi_1 = (arg1 & 0x1f) << 3;
        
        if (*(*(((arg1 & 0xffffffe7) >> 3) + 0x4096c0) + esi_1 + 4) & 1)
        {
            HANDLE hFile = sub_404b60(arg1);
            
            if (hFile == 0xffffffff)
            {
                data_407810 = 9;
                return 0xffffffff;
            }
            
            uint32_t result = SetFilePointer(hFile, arg2, nullptr, arg3);
            enum WIN32_ERROR eax_7 = NO_ERROR;
            
            if (result == 0xffffffff)
                eax_7 = GetLastError();
            
            if (eax_7)
            {
                sub_404a60(eax_7);
                return 0xffffffff;
            }
            
            int32_t eax_9 = *(((arg1 & 0xffffffe7) >> 3) + 0x4096c0);
            *(eax_9 + esi_1 + 4) &= 0xfd;
            return result;
        }
    }
    
    data_407810 = 9;
    data_407814 = 0;
    return 0xffffffff;
}

int32_t sub_404620(int32_t* arg1)
{
    data_408130 += 1;
    int32_t eax = sub_404940(0x1000);
    arg1[2] = eax;
    
    if (!eax)
    {
        arg1[3] |= 4;
        arg1[2] = &arg1[5];
        arg1[6] = 2;
    }
    else
    {
        arg1[3] |= 8;
        arg1[6] = 0x1000;
    }
    
    int32_t result = arg1[2];
    *arg1 = result;
    arg1[1] = 0;
    return result;
}

int32_t sub_404670(int32_t arg1)
{
    if (data_4096b4 <= arg1)
        return 0;
    
    int32_t eax_4 = 0;
    eax_4 = *(*(((arg1 & 0xffffffe7) >> 3) + 0x4096c0) + ((arg1 & 0x1f) << 3) + 4);
    return eax_4 & 0x40;
}

int32_t sub_4046a0()
{
    if (!data_4086a8)
        data_4086a8 = 0x200;
    else if (data_4086a8 < 0x14)
        data_4086a8 = 0x14;
    
    int32_t eax_1 = sub_404bb0(data_4086a8, 4);
    data_4086ac = eax_1;
    
    if (!eax_1)
    {
        data_4086a8 = 0x14;
        int32_t eax_2 = sub_404bb0(0x14, 4);
        data_4086ac = eax_2;
        
        if (!eax_2)
            sub_402700(0x1a);
    }
    
    int32_t ecx = 0x407eb0;
    
    for (int32_t i = 0; i < 0x50; )
    {
        i += 4;
        *(data_4086ac + i - 4) = ecx;
        ecx += 0x20;
    }
    
    int32_t esi = 0;
    int32_t result;
    
    for (int32_t* i_1 = &data_407ec0; i_1 < 0x407f20; )
    {
        result = *(*(((esi & 0xffffffe7) >> 3) + &data_4096c0) + ((esi & 0x1f) << 3));
        
        if (result == 0xffffffff || !result)
            *i_1 = 0xffffffff;
        
        i_1 = &i_1[8];
        esi += 1;
    }
    
    return result;
}

int32_t sub_404770()
{
    int32_t result = sub_404d50();
    
    if (!data_407850)
        return result;
    
    /* tailcall */
    return sub_404c10();
}

int32_t sub_404790(char* arg1, wchar16 arg2)
{
    if (!arg1)
        return 0;
    
    if (!data_408368)
    {
        if (arg2 <= 0xff)
        {
            *arg1 = arg2;
            return 1;
        }
        
        data_407810 = 0x2a;
        return 0xffffffff;
    }
    
    int32_t cbMultiByte = data_408530;
    BOOL usedDefaultChar = 0;
    int32_t result = WideCharToMultiByte(data_408378, 0x220, &arg2, 1, arg1, cbMultiByte, nullptr, 
        &usedDefaultChar);
    
    if (result && !usedDefaultChar)
        return result;
    
    data_407810 = 0x2a;
    return 0xffffffff;
}

uint32_t __stdcall __aulldiv(int32_t arg1, uint32_t arg2, int32_t arg3, uint32_t arg4) __pure
{
    if (!arg4)
        return COMBINE(COMBINE(0, arg2) % arg3, arg1) / arg3;
    
    uint32_t i = arg4;
    int32_t ebx_1 = arg3;
    uint32_t edx_3 = arg2;
    int32_t eax_6 = arg1;
    
    do
    {
        ebx_1 = RRCD(ebx_1, 1, i & 1);
        uint32_t temp4_1 = edx_3;
        edx_3 u>>= 1;
        eax_6 = RRCD(eax_6, 1, temp4_1 & 1);
        i u>>= 1;
    } while (i);
    
    uint32_t result = COMBINE(edx_3, eax_6) / ebx_1;
    int32_t eax_8 = result * arg4;
    int32_t eax_10;
    int32_t edx_4;
    edx_4 = HIGHD(arg3 * result);
    eax_10 = LOWD(arg3 * result);
    int32_t edx_5 = edx_4 + eax_8;
    
    if (edx_4 + eax_8 >= edx_4 && edx_5 <= arg2 && (edx_5 < arg2 || eax_10 <= arg1))
        return result;
    
    return result - 1;
}

uint32_t __stdcall __aullrem(int32_t arg1, uint32_t arg2, int32_t arg3, uint32_t arg4) __pure
{
    uint32_t result;
    
    if (arg4)
    {
        uint32_t i = arg4;
        int32_t ebx_1 = arg3;
        uint32_t edx_4 = arg2;
        int32_t eax_4 = arg1;
        
        do
        {
            ebx_1 = RRCD(ebx_1, 1, i & 1);
            uint32_t temp4_1 = edx_4;
            edx_4 u>>= 1;
            eax_4 = RRCD(eax_4, 1, temp4_1 & 1);
            i u>>= 1;
        } while (i);
        
        uint32_t temp0_3 = COMBINE(edx_4, eax_4) / ebx_1;
        int32_t eax_6 = temp0_3 * arg4;
        int32_t eax_8;
        int32_t edx_5;
        edx_5 = HIGHD(temp0_3 * arg3);
        eax_8 = LOWD(temp0_3 * arg3);
        int32_t edx_6 = edx_5 + eax_6;
        
        if (edx_5 + eax_6 < edx_5 || edx_6 > arg2)
            eax_8 -= arg3;
        else if (edx_6 >= arg2 && eax_8 > arg1)
            eax_8 -= arg3;
        
        result = -((eax_8 - arg1));
    }
    else
        result = COMBINE(COMBINE(0, arg2) % arg3, arg1) % arg3;
    
    return result;
}

BOOL sub_404920(BOOL arg1)
{
    if (!arg1)
        return arg1;
    
    return HeapFree(data_4096b0, HEAP_NONE, arg1);
}

int32_t sub_404940(uint32_t arg1)
{
    return sub_404960(arg1, data_40853c);
}

int32_t sub_404960(uint32_t arg1, int32_t arg2)
{
    uint32_t esi = arg1;
    
    if (esi > 0xffffffe0)
        return 0;
    
    if (!esi)
        esi = 1;
    
    int32_t i;
    
    do
    {
        int32_t result = sub_4049a0(esi);
        
        if (result || !arg2)
            return result;
        
        i = sub_404de0(esi);
    } while (i);
    return 0;
}

int32_t sub_4049a0(uint32_t arg1)
{
    return HeapAlloc(data_4096b0, HEAP_NONE, arg1);
}

int32_t sub_4049c0(int32_t arg1, int32_t arg2, int32_t arg3)
{
    int32_t esi = 0;
    
    if (!data_40837c)
    {
        HMODULE hModule = LoadLibraryA("user32.dll");
        int32_t eax_1;
        
        if (hModule)
        {
            eax_1 = GetProcAddress(hModule, "MessageBoxA");
            data_40837c = eax_1;
        }
        
        if (!hModule || !eax_1)
            return 0;
        
        data_408380 = GetProcAddress(hModule, "GetActiveWindow");
        data_408384 = GetProcAddress(hModule, "GetLastActivePopup");
    }
    
    int32_t eax_4 = data_408380;
    
    if (eax_4)
        esi = eax_4();
    
    if (esi && data_408384)
        esi = data_408384(esi);
    
    return data_40837c(esi, arg1, arg2, arg3);
}

int32_t sub_404a60(int32_t arg1)
{
    int32_t ecx = 0;
    int32_t* i = &data_4083c8;
    data_407814 = arg1;
    
    do
    {
        if (*i == arg1)
        {
            int32_t eax = *((ecx << 3) + &data_4083cc);
            data_407810 = eax;
            return eax;
        }
        
        i = &i[2];
        ecx += 1;
    } while (i < 0x408530);
    
    if (arg1 >= 0x13 && arg1 <= 0x24)
    {
        data_407810 = 0xd;
        return arg1;
    }
    
    if (arg1 >= 0xbc && arg1 <= 0xca)
    {
        data_407810 = 8;
        return arg1;
    }
    
    data_407810 = 0x16;
    return arg1;
}

int32_t sub_404ad0(int32_t arg1)
{
    if (data_4096b4 > arg1)
    {
        int32_t* eax_7 = *(((arg1 & 0xffffffe7) >> 3) + &data_4096c0) + ((arg1 & 0x1f) << 3);
        
        if (eax_7[1] & 1 && *eax_7 != 0xffffffff)
        {
            if (data_407868 == 1)
            {
                if (!arg1)
                {
                    int32_t var_c_1 = 0;
                    SetStdHandle(STD_INPUT_HANDLE, nullptr);
                }
                else if (arg1 == 1)
                {
                    int32_t var_c_2 = 0;
                    SetStdHandle(STD_OUTPUT_HANDLE, nullptr);
                }
                else if (arg1 == 2)
                {
                    int32_t var_c_3 = 0;
                    SetStdHandle(STD_ERROR_HANDLE, nullptr);
                }
            }
            
            (*(((arg1 & 0xffffffe7) >> 3) + &data_4096c0))[(arg1 & 0x1f) * 2] = 0xffffffff;
            return 0;
        }
    }
    
    data_407810 = 9;
    data_407814 = 0;
    return 0xffffffff;
}

int32_t sub_404b60(int32_t arg1)
{
    if (data_4096b4 > arg1)
    {
        int32_t* eax_4 = *(((arg1 & 0xffffffe7) >> 3) + 0x4096c0) + ((arg1 & 0x1f) << 3);
        
        if (eax_4[1] & 1)
            return *eax_4;
    }
    
    data_407810 = 9;
    data_407814 = 0;
    return 0xffffffff;
}

int32_t sub_404bb0(int32_t arg1, int32_t arg2)
{
    uint32_t dwBytes = arg1 * arg2;
    
    if (!dwBytes)
        dwBytes = 1;
    
    HANDLE hHeap = data_4096b0;
    
    while (true)
    {
        int32_t result;
        
        if (dwBytes <= 0xffffffe0)
            result = HeapAlloc(hHeap, HEAP_ZERO_MEMORY, dwBytes);
        else
            result = 0;
        
        if (result || !data_40853c)
            return result;
        
        bool cond:0_1 = sub_404de0(dwBytes);
        hHeap = data_4096b0;
        
        if (!cond:0_1)
            break;
        
        continue;
    }
    
    return 0;
}

int32_t sub_404c10()
{
    int32_t result = 0;
    int32_t i = 3;
    
    if (data_4086a8 > 3)
    {
        int32_t ebx_1 = 0xc;
        
        do
        {
            int32_t* eax_2 = *(data_4086ac + ebx_1);
            
            if (eax_2)
            {
                if (eax_2[3] & 0x83 && sub_404e10(eax_2) != 0xffffffff)
                    result += 1;
                
                if (ebx_1 >= 0x50)
                {
                    sub_404920(*(data_4086ac + ebx_1));
                    *(data_4086ac + ebx_1) = 0;
                }
            }
            
            ebx_1 += 4;
            i += 1;
        } while (data_4086a8 > i);
    }
    
    return result;
}

int32_t sub_404c90(int32_t* arg1)
{
    if (!arg1)
        return sub_404d60(0);
    
    if (sub_404ce0(arg1))
        return 0xffffffff;
    
    if (!(*(arg1 + 0xd) & 0x40))
        return 0;
    
    return 0 - 1;
}

int32_t sub_404ce0(int32_t* arg1)
{
    int32_t result = 0;
    int32_t eax = arg1[3];
    
    if ((eax & 3) == 2 && eax & 0x108)
    {
        char* eax_1 = arg1[2];
        uint32_t ebx_2 = *arg1 - eax_1;
        
        if (ebx_2 > 0)
        {
            if (sub_404330(arg1[4], eax_1, ebx_2) != ebx_2)
            {
                arg1[3] |= 0x20;
                result = 0xffffffff;
            }
            else
            {
                int32_t eax_4 = arg1[3];
                
                if (eax_4 & 0x80)
                    arg1[3] = eax_4 & 0xfffffffd;
            }
        }
    }
    
    *arg1 = arg1[2];
    arg1[1] = 0;
    return result;
}

int32_t sub_404d50()
{
    return sub_404d60(1);
}

int32_t sub_404d60(int32_t arg1)
{
    int32_t ebx = 0;
    int32_t i = 0;
    int32_t ebp = 0;
    
    do
    {
        int32_t* ecx_1 = *(data_4086ac + i);
        
        if (ecx_1)
        {
            char eax_2 = ecx_1[3];
            
            if (eax_2 & 0x83)
            {
                if (arg1 == 1)
                {
                    if (sub_404c90(ecx_1) != 0xffffffff)
                        ebx += 1;
                }
                else if (!arg1 && eax_2 & 2 && sub_404c90(ecx_1) == 0xffffffff)
                    ebp = 0xffffffff;
            }
        }
        
        i += 4;
    } while (i < 0x800);
    
    if (arg1 == 1)
        return ebx;
    
    return ebp;
}

int32_t sub_404dd0()
{
    return sub_402700(2);
}

int32_t sub_404de0(int32_t arg1)
{
    int32_t ecx = data_4086a4;
    
    if (ecx && ecx(arg1))
        return 1;
    
    return 0;
}

int32_t sub_404e10(int32_t* arg1)
{
    int32_t result = 0xffffffff;
    char eax = arg1[3];
    
    if (eax & 0x40)
    {
        arg1[3] = 0;
        return 0xffffffff;
    }
    
    if (eax & 0x83)
    {
        result = sub_404ce0(arg1);
        sub_404fc0(arg1);
        
        if (sub_404ef0(arg1[4]) >= 0)
        {
            BOOL eax_5 = arg1[7];
            
            if (eax_5)
            {
                sub_404920(eax_5);
                arg1[7] = 0;
            }
        }
        else
            result = 0xffffffff;
    }
    
    arg1[3] = 0;
    return result;
}

enum WIN32_ERROR sub_404e80(int32_t arg1)
{
    if (arg1 >= data_4096b4
        || !(*(*(((arg1 & 0xffffffe7) >> 3) + &data_4096c0) + ((arg1 & 0x1f) << 3) + 4) & 1))
    {
        data_407810 = 9;
        return ~NO_ERROR;
    }
    
    enum WIN32_ERROR result = NO_ERROR;
    
    if (!FlushFileBuffers(sub_404b60(arg1)))
        result = GetLastError();
    
    if (!result)
        return result;
    
    data_407810 = 9;
    data_407814 = result;
    return 0xffffffff;
}

int32_t sub_404ef0(int32_t arg1)
{
    if (data_4096b4 > arg1)
    {
        int32_t esi_1 = (arg1 & 0x1f) << 3;
        
        if (*(*(((arg1 & 0xffffffe7) >> 3) + &data_4096c0) + esi_1 + 4) & 1)
        {
            enum WIN32_ERROR ebp_2;
            
            if (arg1 == 1 || arg1 == 2)
            {
                if (sub_404b60(1) != sub_404b60(2))
                    goto label_404f55;
                
                ebp_2 = NO_ERROR;
            }
            else
            {
            label_404f55:
                
                if (CloseHandle(sub_404b60(arg1)))
                    ebp_2 = NO_ERROR;
                else
                    ebp_2 = GetLastError();
            }
            
            sub_404ad0(arg1);
            
            if (!ebp_2)
            {
                *(*(((arg1 & 0xffffffe7) >> 3) + &data_4096c0) + esi_1 + 4) = 0;
                return 0;
            }
            
            sub_404a60(ebp_2);
            return 0xffffffff;
        }
    }
    
    data_407810 = 9;
    data_407814 = 0;
    return 0xffffffff;
}

char sub_404fc0(int32_t* arg1)
{
    char result = arg1[3];
    
    if (result & 0x83 && result & 8)
    {
        result = sub_404920(arg1[2]);
        *arg1 = 0;
        arg1[3] &= 0xfffffbf7;
        arg1[2] = 0;
        arg1[1] = 0;
    }
    
    return result;
}

int32_t sub_405000(int32_t arg1, char* arg2, int32_t arg3)
{
    int32_t result_1 = arg1;
    int32_t result = result_1;
    int32_t i = 0xffffffff;
    
    while (i)
    {
        bool cond:0_1 = 0 != *result_1;
        result_1 += 1;
        i -= 1;
        
        if (!cond:0_1)
            break;
    }
    
    bool cond:2 = result_1 != 1;
    char* edi_1 = arg2;
    char* var_10 = edi_1;
    int32_t i_1 = arg3;
    
    while (i_1)
    {
        char temp1_1 = *edi_1;
        cond:2 = 0 != temp1_1;
        edi_1 = &edi_1[1];
        i_1 -= 1;
        
        if (0 == temp1_1)
            break;
    }
    
    if (!cond:2)
        i_1 += 1;
    
    *__builtin_memcpy(result_1 - 1, var_10, -((i_1 - arg3))) = 0;
    return result;
}

void __stdcall RtlUnwind(void* TargetFrame, void* TargetIp, EXCEPTION_RECORD* ExceptionRecord, void* ReturnValue)
{
    /* tailcall */
    return RtlUnwind(TargetFrame, TargetIp, ExceptionRecord, ReturnValue);
}

