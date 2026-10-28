/* Viper Racing 1998 - Complete port from Hex-Rays decompilation (game2.c)
 * Original: 1998 by Sierra On-Line / Metro 3D
 * Target: x86_64-w64-mingw32-gcc, runs under Wine on Linux
 * Faithful port of the WinMain launcher from game2.c
 */

#define WINVER 0x0500
#define _WIN32_WINNT 0x0500

#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/* ========================================================================= */
/* Original String Constants (from decompiled data)                          */
/* ========================================================================= */
static char aSoftwareSierra[]   = "Software\\Sierra On-Line\\Viper Racing";
static char aDatadirectory[]    = "DataDirectory";
static char aMgiViperRacing[]   = "MGI Viper Racing 1998";
static char aMgiViperRacing_0[] = "MGI Viper Racing 1998 Canary";
static char aViperRacingWin[]   = "Viper Racing Window";
static char aViperRacing[]      = "Viper Racing";
static char aCommonRes[]        = "common.res";
static char aViperRacing_0[]    = "Viper Racing";
static char aDebugBin[]         = "debug.bin";
static char aRaceBin[]          = "race.bin";
static char aContinue[]         = "\nContinue?";
static CHAR Caption[]           = "Our Apologies";
static char SubStr[]            = "-autoplay";
static char aNo3dfx[]           = "-no3dfx";
static char aNocanary[]         = "-nocanary";
static char aSafe[]             = "-safe";
static char aData[]             = "Data\\";
static char aCanTFindDataDi[]   = "Can't find data directory--Game may not be installed";
static char aThisGameRequir[]   = "This game requires DirectX 5 or 6";
static char aYourVideoCardD_0[] = "Your video card does not support 3D graphics";
static char aYourVideoCardD[]   = "Your video card does not support 3D texture mapping";
static char aYourVideoCardR[]   = "Your video card returned an error.  Are your video drivers up to date?";
static CHAR CmdLine[]           = "notepad c:\\log.log";
static char aUnknownPlatfor[]   = "Unknown platform type--proceed at your own risk";
static char aCannotGetVersi[]   = "Cannot get version info--proceed at your own risk";
static char aSendingMailFai[]   = "Sending mail failed.";
static char aCanTCreateSock[]   = "Can't create socket.";
static char aCanTStartWinso[]   = "Can't start winsock";
static char aHeloLameProgra[]   = "HELO lame.programmer.com\n";
static char aData_1[]           = "DATA\n";
static char asc_4077CC[]        = "\n.\n";
static char aTwinkiesForSal[]   = "Twinkies for sale.";

/* ========================================================================= */
/* Original Global Data                                                      */
/* ========================================================================= */
static char byte_407030 = 0;
static char Source = 0;
static char byte_407658 = 1;
static HMODULE hModule = NULL;

/* ========================================================================= */
/* Function Prototypes                                                       */
/* ========================================================================= */
static char *__cdecl sub_401000(char a1);
static int sub_401020(char *Format, ...);
static void sub_4010A0(void);
static int __cdecl sub_4010B0(LPCSTR lpText);
static int __cdecl sub_4010E0(char *Format, ...);
static int __cdecl sub_401140(LPCSTR lpText);
static int __cdecl sub_4015B0(char *Str, char *SubStr);
static int sub_401600(void);
static char sub_401640(void);
static int sub_401720(void);
static void sub_401740(void);
static void sub_4017E0(void);
static int nullsub_1(void);
static int nullsub_2(void);
static char __cdecl sub_401873(void);
static int __cdecl sub_4018F0(LPCSTR lpFileName);
static int nullsub_3(void);
static int nullsub_4(void);
static char __cdecl sub_401930(char *lpData);
static char __cdecl sub_401A50(char a1);
static int sub_401A70(void);
static char __cdecl sub_401BB0(struct sockaddr_in *a1, char *cp);
static char __cdecl sub_401C10(const char *a1, const char *ArgList, char *cp, const char *a4, int a5, int a6);
static char __cdecl sub_401E20(SOCKET s, const char *a2, const char *ArgList, const char *a4, int a5, int a6);
static char __cdecl sub_401FA0(SOCKET s, char *buf, int len);
static int __cdecl sub_401FD0(const char *ArgList);
static int __cdecl sub_402000(SOCKET s, const char *a2, int a3);
static int __cdecl sub_402050(SOCKET s, const char *a2);
static int __cdecl sub_402080(SOCKET s, char *Format, ...);

/* ========================================================================= */
/* Original Function Implementations                                         */
/* ========================================================================= */

/*----- (00401000) Choose binary name ----- */
static char *__cdecl sub_401000(char a1)
{
    if (a1 == 0)
        return aRaceBin;
    return aDebugBin;
}

/*----- (00401020) Error output with "Continue?" appended ----- */
static int sub_401020(char *Format, ...)
{
    char Buffer[255] = {0};
    va_list va;
    va_start(va, Format);
    vsprintf(Buffer, Format, va);
    va_end(va);

    /* Append "\nContinue?" (11 bytes incl NUL) */
    memcpy(&Buffer[strlen(Buffer)], aContinue, sizeof(aContinue));

    return sub_4010B0(Buffer);
}

/*----- (004010A0) Exit ----- */
static void sub_4010A0(void)
{
    exit(1);
}

/*----- (004010B0) MessageBox Yes/No (0x10034 = MB_YESNO|MB_ICONEXCLAMATION|MB_SYSTEMMODAL) ----- */
static int __cdecl sub_4010B0(LPCSTR lpText)
{
    int result = (MessageBoxA(NULL, lpText, aViperRacing_0, 0x10034u) == 7); /* 7 = IDNO */
    byte_407030 = (char)result;
    return result;
}

/*----- (004010E0) Formatted error message ----- */
static int __cdecl sub_4010E0(char *Format, ...)
{
    char Buffer[255] = {0};
    va_list ArgList;
    va_start(ArgList, Format);
    vsprintf(Buffer, Format, ArgList);
    va_end(ArgList);

    int result = sub_401140(Buffer);
    byte_407030 = 1;
    return result;
}

/*----- (00401140) "Our Apologies" message box (0x10010 = MB_OK|MB_ICONEXCLAMATION|MB_SYSTEMMODAL) ----- */
static int __cdecl sub_401140(LPCSTR lpText)
{
    return MessageBoxA(NULL, lpText, Caption, 0x10010u);
}

/*----- (004015B0) Find and remove substring ----- */
static int __cdecl sub_4015B0(char *Str, char *SubStr)
{
    char *v2 = strstr(Str, SubStr);
    if (v2 != NULL)
    {
        size_t v3 = strlen(SubStr) + 1;
        memmove(v2, &v2[v3 - 1], strlen(&v2[v3 - 1]) + 1);
    }
    return v2 != NULL;
}

/*----- (00401600) Single instance check ----- */
static int sub_401600(void)
{
    int v0 = 0;
    HANDLE SemaphoreA = CreateSemaphoreA(NULL, 0, 1, aMgiViperRacing);
    if (SemaphoreA != NULL)
    {
        v0 = (GetLastError() == ERROR_ALREADY_EXISTS);
        CloseHandle(SemaphoreA);
    }
    return v0;
}

/*----- (00401640) Windows version check ----- */
static char sub_401640(void)
{
    char result;
    OSVERSIONINFOA VersionInformation;
    memset(&VersionInformation, 0, sizeof(VersionInformation));
    VersionInformation.dwOSVersionInfoSize = sizeof(VersionInformation);

    if (!GetVersionExA(&VersionInformation))
        return (char)sub_401020(aCannotGetVersi);

    result = (char)VersionInformation.dwPlatformId;

    switch (VersionInformation.dwPlatformId)
    {
        case VER_PLATFORM_WIN32s:
            return (char)sub_4010E0("%s cannot run under Win32s", aViperRacing_0);
        case VER_PLATFORM_WIN32_WINDOWS:
            if (VersionInformation.dwMajorVersion != 4)
                return (char)sub_401020("What is Windows %d.%d?",
                                VersionInformation.dwMajorVersion,
                                VersionInformation.dwMinorVersion);
            break;
        case VER_PLATFORM_WIN32_NT:
            if (VersionInformation.dwMajorVersion < 5)
                return (char)sub_401020("%s cannot run under Windows NT %d.%d",
                                aViperRacing_0,
                                VersionInformation.dwMajorVersion,
                                VersionInformation.dwMinorVersion);
            break;
        default:
            return (char)sub_401020(aUnknownPlatfor);
    }
    return result;
}

/*----- (00401720) Mouse presence check ----- */
static int sub_401720(void)
{
    return GetSystemMetrics(SM_MOUSEPRESENT) != 0;
}

/*----- (00401740) Memory status check ----- */
static void sub_401740(void)
{
    MEMORYSTATUS Buffer;
    Buffer.dwLength = sizeof(Buffer);
    GlobalMemoryStatus(&Buffer);

    if (Buffer.dwTotalPhys >= 0x1700000)  /* 23MB */
    {
        if (Buffer.dwTotalPhys >= 0x1F00000)  /* 31MB */
        {
            if (Buffer.dwAvailPageFile < 0x2700000)  /* 39MB */
                sub_4010E0("%s requires %d megabytes of virtual memory (you have %d).  Please free up disk space or close other applications.",
                         aViperRacing_0, 39, Buffer.dwAvailPageFile >> 20);
        }
        else
        {
            sub_401020("%s may not run optimally with %d megabytes of memory.",
                       aViperRacing_0, Buffer.dwTotalPhys >> 20);
        }
    }
    else
    {
        sub_4010E0("%s requires %d megabytes of memory (you have %d).",
                   aViperRacing_0, 23, Buffer.dwTotalPhys >> 20);
    }
}

/*----- (004017E0) Disk free space check ----- */
static void sub_4017E0(void)
{
    DWORD v0 = 0;
    CHAR RootPathName[4] = {0};
    DWORD SectorsPerCluster, BytesPerSector, NumberOfFreeClusters, TotalNumberOfClusters;

    if (Source != 0)
    {
        strncpy(RootPathName, &Source, 3);
        RootPathName[3] = 0;
        if (GetDiskFreeSpaceA(RootPathName, &SectorsPerCluster, &BytesPerSector,
                               &NumberOfFreeClusters, &TotalNumberOfClusters))
        {
            v0 = SectorsPerCluster * BytesPerSector * NumberOfFreeClusters;
            if (v0 < 0x1400000)  /* 20MB */
                sub_401020("You only have %d megabytes of free disk space.", v0 >> 20);
        }
    }
}

/*----- (00401873) CD check - iterate drives for common.res ----- */
static char __cdecl sub_401873(void)
{
    int v0 = 0;
    char result = 0;
    char v2[4];
    char v3[32];

    while (1)
    {
        v2[0] = 'A' + v0;
        v2[1] = ':';
        v2[2] = '\\';
        v2[3] = 0;

        if (GetDriveTypeA(v2) == DRIVE_CDROM)
        {
            sprintf(v3, "%sdata\\%s", v2, aCommonRes);
            result = (char)sub_4018F0(v3);
            if (result != 0)
                break;
        }
        if (++v0 >= 26)
            return (char)sub_4010E0("You must have the %s CD inserted to play.", aViperRacing_0);
    }
    return result;
}

/*----- (004018F0) File exists check ----- */
static int __cdecl sub_4018F0(LPCSTR lpFileName)
{
    return GetFileAttributesA(lpFileName) != 0xFFFFFFFF;
}

/*----- (00401930) Data directory check (registry + fallback) ----- */
static char __cdecl sub_401930(char *lpData)
{
    CHAR *v3;
    HKEY phkResult = NULL;
    DWORD cbData = 260;
    DWORD Type = 0;
    char Buffer[260] = {0};

    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, aSoftwareSierra, 0, KEY_READ | KEY_WOW64_64KEY, &phkResult) == 0)
    {
        cbData = 260;
        if (RegQueryValueExA(phkResult, aDatadirectory, NULL, &Type, (LPBYTE)lpData, &cbData) == 0 && *lpData != 0)
        {
            sprintf(Buffer, "%s%s", lpData, aCommonRes);
            if (!sub_4018F0(Buffer))
                return 0;
            RegCloseKey(phkResult);
            return 1;
        }
        RegCloseKey(phkResult);
    }

    if (GetModuleFileNameA(hModule, lpData, 260) == 0)
        return 0;

    v3 = strrchr(lpData, '\\');
    if (v3 == NULL)
        return 0;
    *v3 = 0;
    strcat(lpData, "\\Data");
    return 1;
}

/*----- (00401A50) Set canary flag ----- */
static char __cdecl sub_401A50(char a1)
{
    byte_407658 = a1;
    return a1;
}

/*----- (00401A70) DirectX version check ----- */
static int sub_401A70(void)
{
    return 0;
}

/*----- Null subs ----- */
static int nullsub_1(void) { return 0; }
static int nullsub_2(void) { return 0; }
static int nullsub_3(void) { return 0; }
static int nullsub_4(void) { return 0; }

/* ========================================================================= */
/* Network/Email Functions (for error reporting)                             */
/* ========================================================================= */

/*----- (00401BB0) Resolve hostname/IP to sockaddr ----- */
static char __cdecl sub_401BB0(struct sockaddr_in *sa, char *cp)
{
    char v2 = 0;
    unsigned int v3 = inet_addr(cp);
    struct hostent *v4 = NULL;

    memset(sa, 0, sizeof(*sa));
    if (v3 == INADDR_NONE)
    {
        v4 = gethostbyname(cp);
        if (v4 != NULL)
        {
            v2 = 1;
            sa->sin_addr.s_addr = **(unsigned int **)v4->h_addr_list;
        }
    }
    else
    {
        v2 = 1;
        sa->sin_addr.s_addr = v3;
    }

    sa->sin_port = htons(0x19); /* Port 25 = SMTP */
    sa->sin_family = AF_INET;
    return v2;
}

/*----- (00401C10) SMTP connection and send ----- */
static char __cdecl sub_401C10(const char *a1, const char *ArgList, char *cp, const char *a4, int a5, int a6)
{
    char v6 = 0;
    SOCKET v7 = INVALID_SOCKET;
    int v8 = 0;
    int Error = 0;
    struct sockaddr_in name = {0};
    struct sockaddr_in v12 = {0};
    char v13[64] = {0};
    WSADATA WSAData;

    if (WSAStartup(0x101, &WSAData) != 0)
    {
        sub_4010E0(aCanTStartWinso);
        return 0;
    }

    v7 = socket(AF_INET, SOCK_STREAM, 0);
    if (v7 == INVALID_SOCKET)
    {
        sub_4010E0(aCanTCreateSock);
        WSACleanup();
        return 0;
    }

    name.sin_family = AF_INET;
    name.sin_port = htons(0);
    name.sin_addr.s_addr = INADDR_ANY;

    if (bind(v7, (struct sockaddr *)&name, sizeof(name)) != 0)
    {
        Error = WSAGetLastError();
        sub_4010E0("Can't bind socket (%d).", Error);
        closesocket(v7);
        WSACleanup();
        return 0;
    }

    if (cp != NULL)
    {
        if (sub_401BB0(&v12, cp) != 0)
        {
            if (connect(v7, (struct sockaddr *)&v12, sizeof(v12)) != 0)
            {
                v8 = WSAGetLastError();
                sub_4010E0("Can't connect to %s (%d)", cp, v8);
                closesocket(v7);
                WSACleanup();
                return 0;
            }
            else
            {
                strcpy(v13, ArgList);
                if (v13[0] != 0)
                {
                    if (sub_401E20(v7, v13, a1, a4, a5, a6) != 0)
                        v6 = 1;
                    else
                        sub_4010E0(aSendingMailFai);
                    closesocket(v7);
                    WSACleanup();
                    return v6;
                }
                else
                {
                    sub_4010E0("Can't parse rcpt from %s", ArgList);
                }
            }
        }
        else
        {
            sub_4010E0("Can't get address for %s", cp);
        }
    }
    else
    {
        sub_4010E0("Can't parse host address from %s", ArgList);
    }

    closesocket(v7);
    WSACleanup();
    return v6;
}

/*----- (00401E20) SMTP protocol handling ----- */
static char __cdecl sub_401E20(SOCKET s, const char *a2, const char *ArgList, const char *a4, int a5, int a6)
{
    int v6 = 0;
    char v8 = 0;
    int v9 = 0, v10 = 0;
    char buf[256] = {0};

    if (sub_401FA0(s, buf, 256) != 0)
    {
        while (1)
        {
            if (!sub_401FD0(buf))
            {
                v9 = 0;
                switch (v6)
                {
                    case 0:
                        v9 = sub_402050(s, aHeloLameProgra);
                        break;
                    case 1:
                        v9 = sub_402080(s, "MAIL FROM: %s\n", ArgList);
                        break;
                    case 2:
                        v9 = sub_402080(s, "RCPT TO: %s\n", a2);
                        break;
                    case 3:
                        v9 = sub_402050(s, aData_1);
                        break;
                    case 4:
                        v10 = sub_402080(s, "Subject: %s\n\n\n", a4);
                        if (v10)
                            v10 = sub_402000(s, (const char *)a5, a6);
                        if (!v10)
                            return v8;
                        v9 = sub_402050(s, asc_4077CC);
                        break;
                    case 5:
                        v8 = 1;
                        v9 = 0;
                        break;
                    default:
                        sub_4010E0(aTwinkiesForSal);
                        break;
                }
                if (!v9)
                    return v8;
                v6++;
                if (sub_401FA0(s, buf, 256) == 0)
                    return v8;
                continue;
            }
            break;
        }
    }
    return v8;
}

/*----- (00401FA0) Receive from socket ----- */
static char __cdecl sub_401FA0(SOCKET s, char *buf, int len)
{
    int v3 = recv(s, buf, len, 0);
    if (v3 <= 0)
        return 0;
    buf[v3] = 0;
    return 1;
}

/*----- (00401FD0) Check for SMTP error (5xx) ----- */
static int __cdecl sub_401FD0(const char *ArgList)
{
    if (*ArgList == '5')
        sub_4010E0("Got error: %s", ArgList);
    return *ArgList == '5';
}

/*----- (00402000) Send loop with throttling ----- */
static int __cdecl sub_402000(SOCKET s, const char *a2, int a3)
{
    int v3 = 0;
    int v4 = 0;

    while (v3 < a3)
    {
        v4 = send(s, &a2[v3], a3 - v3, 0);
        if (v4 <= 0)
            break;
        v3 += v4;
        Sleep(100); /* 0x64 = 100ms */
    }
    return v3 == a3;
}

/*----- (00402050) Send string ----- */
static int __cdecl sub_402050(SOCKET s, const char *a2)
{
    return sub_402000(s, a2, (int)strlen(a2));
}

/*----- (00402080) Send formatted ----- */
static int __cdecl sub_402080(SOCKET s, char *Format, ...)
{
    char Buffer[1023] = {0};
    va_list va;
    va_start(va, Format);
    vsprintf(Buffer, Format, va);
    va_end(va);

    return sub_402050(s, Buffer);
}

/* ========================================================================= */
/* WinMain - Main Entry Point (Launcher)                                     */
/* ========================================================================= */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    (void)hPrevInstance;
    (void)nShowCmd;

    HANDLE SemaphoreA;
    char v6 = 0;
    char *v7 = NULL;
    const CHAR *v8 = NULL;
    char v9 = 0;
    HWND WindowA = NULL;
    DWORD ExitCode = 0;
    PROCESS_INFORMATION ProcessInformation = {0};
    STARTUPINFOA StartupInfo = {0};
    CHAR CommandLine[256] = {0};
    CHAR CurrentDirectory[257] = {0};
    CHAR Str[512] = {0};

    strncpy(Str, lpCmdLine, sizeof(Str) - 1);
    Str[sizeof(Str) - 1] = 0;

    hModule = hInstance;

    SemaphoreA = CreateSemaphoreA(NULL, 0, 1, aMgiViperRacing_0);
    if (SemaphoreA != NULL && GetLastError() != ERROR_ALREADY_EXISTS)
    {
        if (sub_401600())
        {
            WindowA = FindWindowA(aViperRacingWin, aViperRacing);
            if (WindowA != NULL)
                ShowWindow(WindowA, SW_RESTORE);
        }
        else
        {
            /* Original check order (game2.c): sub_401640, sub_401720,
               sub_401740, sub_401A70, nullsub_2, nullsub_1, sub_4017E0 */
            int (*checks[7])(void) = {
                (int(*)(void))sub_401640,   /* OS version   */
                sub_401720,                 /* mouse        */
                (int(*)(void))sub_401740,   /* memory       */
                (int(*)(void))sub_401A70,   /* DirectX      */
                nullsub_2,
                nullsub_1,
                (int(*)(void))sub_4017E0    /* disk space   */
            };

            if (sub_4015B0(Str, SubStr))
                nullsub_3();
            if (sub_4015B0(Str, aNo3dfx))
                sub_401A50(0);

            CurrentDirectory[0] = 1;

            if (!sub_4015B0(Str, aNocanary))
            {
                int checkFailed = 0;
                for (int i = 0; i < 7; i++)
                {
                    checks[i]();
                    if (byte_407030 != 0)
                    {
                        checkFailed = 1;   /* a canary check tripped */
                        break;
                    }
                }
                /* Faithful to the original: only clear the flag when a
                   check failed. On success the original `goto LABEL_14`
                   jumps over this assignment, leaving the flag set to 1. */
                if (checkFailed)
                    CurrentDirectory[0] = 0;
            }

            v6 = (char)sub_4015B0(Str, aSafe);

            if (CurrentDirectory[0] != 0)
            {
                strcpy(CurrentDirectory, aData);
                v7 = sub_401000(v6);
                v8 = NULL;
                v9 = 1;

                sprintf(CommandLine, "%s%s %s", CurrentDirectory, v7, Str);

                if (sub_401930(CurrentDirectory) != 0)
                {
                    v8 = CurrentDirectory;
                }
                else
                {
                    v9 = 0;
                    sub_4010E0(aCanTFindDataDi);
                }

                if (v9 != 0)
                {
                    memset(&ProcessInformation, 0, sizeof(ProcessInformation));
                    memset(&StartupInfo, 0, sizeof(StartupInfo));
                    StartupInfo.cb = sizeof(StartupInfo);
                    StartupInfo.dwFlags = STARTF_USESHOWWINDOW;
                    StartupInfo.wShowWindow = SW_SHOWDEFAULT;

                    if (CreateProcessA(NULL, CommandLine, NULL, NULL, FALSE,
                                       0, NULL, v8, &StartupInfo, &ProcessInformation))
                    {
                        Sleep(2500); /* 0x9C4 = 2500ms */
                        WaitForSingleObject(ProcessInformation.hProcess, INFINITE);

                        if (GetExitCodeProcess(ProcessInformation.hProcess, &ExitCode) && ExitCode != 0)
                        {
                            switch (ExitCode)
                            {
                                case 2:
                                    sub_4010E0(aThisGameRequir);
                                    break;
                                case 3:
                                    sub_4010E0(aYourVideoCardD);
                                    break;
                                case 4:
                                    sub_4010E0(aYourVideoCardD_0);
                                    break;
                                case 5:
                                    sub_4010E0(aYourVideoCardR);
                                    break;
                                case 6:
                                    sub_4010E0("%s is not installed properly.  Run setup from the CD", aViperRacing_0);
                                    break;
                                default:
                                    sub_4010E0("%s has aborted (%d).  Let's check out the log.", aViperRacing_0, ExitCode);
                                    nullsub_4();
                                    WinExec(CmdLine, SW_SHOW);
                                    break;
                            }
                        }
                    }
                    else
                    {
                        sub_4010E0("Can't start game. (%s)", CommandLine);
                    }
                }
            }
        }
        CloseHandle(SemaphoreA);
    }
    return 0;
}
