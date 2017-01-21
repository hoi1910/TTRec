﻿#ifndef INCLUDE_UTIL_H
#define INCLUDE_UTIL_H

#include <Windows.h>

#define CMD_OPTION_MAX      512
#define EVENT_NAME_MAX      128
#define MATCH_PATTERN_MAX   128
// メニューリストの最大項目数(実用上現実的な数)
#define MENULIST_MAX        100
// タスクトリガ設定の最大個数
#define TASK_TRIGGER_MAX    20

#define FILETIME_MILLISECOND    10000LL
#define FILETIME_SECOND         (1000LL*FILETIME_MILLISECOND)
#define FILETIME_MINUTE         (60LL*FILETIME_SECOND)
#define FILETIME_HOUR           (60LL*FILETIME_MINUTE)

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

#ifndef _DEBUG
#define NO_CRT
#endif

#ifdef NO_CRT
#undef RtlFillMemory
EXTERN_C NTSYSAPI VOID NTAPI RtlFillMemory(LPVOID UNALIGNED Dst, SIZE_T Length, BYTE Pattern);
extern "C" void * __cdecl memset(void *, int, size_t);
#pragma intrinsic(memset)
int _purecall(void);
void *operator new(size_t size);
void *operator new[](size_t size);
void operator delete(void *ptr);
void operator delete[](void *ptr);
#endif

void WriteFileForSpinUp(LPCTSTR dirName);
DWORD ReadTextFileToEnd(LPCTSTR fileName, LPTSTR str, DWORD max);
bool IsMatch(LPCTSTR str, LPCTSTR patterns);
bool GetRundll32Path(LPTSTR rundllPath);
void GetToken(LPCTSTR str, LPTSTR token, int max);
TCHAR NextToken(LPCTSTR *str);
void ReplaceTokenDelimiters(LPTSTR str);

bool FlagStrToArray(LPCTSTR str, bool *flags, int len);
void FlagArrayToStr(const bool *flags, LPTSTR str, int len);
bool StrToTimeSpan(LPCTSTR str, int *pSpan);
void TimeSpanToStr(int span, LPTSTR str);
bool StrToFileTime(LPCTSTR str, FILETIME *pTime);
void FileTimeToStr(const FILETIME *pTime, LPTSTR str);

FILETIME &operator+=(FILETIME &ft,LONGLONG Offset);
LONGLONG operator-(const FILETIME &ft1,const FILETIME &ft2);
void GetLocalTimeAsFileTime(FILETIME *pTime);
int CalcDayOfWeek(int Year,int Month,int Day);
LPCTSTR GetDayOfWeekText(int DayOfWeek);
bool BrowseFolderDialog(HWND hwndOwner,LPTSTR pszDirectory,LPCTSTR pszTitle);

void SetComboBoxList(HWND hDlg,int ID,LPCTSTR const *pList,int Length);
BOOL WritePrivateProfileInt(LPCTSTR pszSection,LPCTSTR pszKey,int Value,LPCTSTR pszFileName);

const bool AribToSystemTime(const BYTE *pHexData, SYSTEMTIME *pSysTime);
void SplitAribMjd(const WORD wAribMjd, WORD *pwYear, WORD *pwMonth, WORD *pwDay, WORD *pwDayOfWeek);
void SplitAribBcd(const BYTE *pAribBcd, WORD *pwHour, WORD *pwMinute, WORD *pwSecond);

int FormatFileName(LPTSTR pszFileName, int MaxFileName, WORD EventID, FILETIME StartTimeSpec, LPCTSTR pszEventName, LPCTSTR pszFormat);
int FormatEventName(LPTSTR pszEventName, int MaxEventName, int num, LPCTSTR pszFormat);

#endif // INCLUDE_UTIL_H
