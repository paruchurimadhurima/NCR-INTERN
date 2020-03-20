#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;
/*
int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	BOOL CreateProcessStatus;
	STARTUPINFO StartupInfo;
	PROCESS_INFORMATION ProcessInfo;
	SECURITY_ATTRIBUTES SecurityAttribute;
	SecurityAttribute.bInheritHandle = TRUE;//inheritance possible
	SecurityAttribute.lpSecurityDescriptor = NULL;
	SecurityAttribute.nLength = sizeof(SecurityAttribute);
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(StartupInfo);
	ZeroMemory(&ProcessInfo, sizeof(ProcessInfo));
  	CreateProcessStatus = CreateProcess(L"C:\\Program Files (x86)\\Notepad++\\notepad++.exe",//application name if NULL application name is taken through command line argument
		NULL,
		&SecurityAttribute,
		NULL,
		TRUE,
		0,
		NULL,
		NULL,
		&StartupInfo,
		&ProcessInfo);
	if (CreateProcessStatus == 0)
	{
		cout << "process creation failed due to error (" << GetLastError() << ")" << endl;
	}
	cout << "PARENT ProcessId: " << GetProcessId(ProcessInfo.hProcess) << " Curret process id : " << GetCurrentProcessId() << endl;
	cout << "PARENT ThreadId: " << GetThreadId(ProcessInfo.hThread) << " Current Thread id : " << GetCurrentThreadId() << "Process id of thread : " << GetProcessIdOfThread(ProcessInfo.hThread) << endl;
	WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
	CloseHandle(ProcessInfo.hProcess);
	CloseHandle(ProcessInfo.hThread);
	WCHAR handle[] = { (WCHAR)ProcessInfo.hProcess };//typecast handle to string
	CreateProcessStatus = CreateProcess(L"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe",//application name if NULL application name is taken through command line argument
		handle,
		&SecurityAttribute,
		NULL,
		TRUE,
		0,
		NULL,
		NULL,
		&StartupInfo,
		&ProcessInfo);
	if (CreateProcessStatus == 0)
	{
		cout << "process creation failed due to error (" << GetLastError() << ")" << endl;
	}
	cout << "CHILD ProcessId: " << GetProcessId(ProcessInfo.hProcess) << " Curret process id : " << GetCurrentProcessId() << endl;
	cout << "CHILD ThreadId: " << GetThreadId(ProcessInfo.hThread) << " Current Thread id : " << GetCurrentThreadId() << "Process id of thread : " << GetProcessIdOfThread(ProcessInfo.hThread) << endl;
	WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
	CloseHandle(ProcessInfo.hProcess);
	CloseHandle(ProcessInfo.hThread);
	return 0;
}*/
