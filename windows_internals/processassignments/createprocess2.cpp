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
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(StartupInfo);
	ZeroMemory(&ProcessInfo, sizeof(ProcessInfo));
	CreateProcessStatus = CreateProcess(L"C:\\Program Files (x86)\\Notepad++\\notepad++.exe",//application name if NULL application name is taken through command line argument
		NULL,//command line argument
		NULL,//process not inheritable
		FALSE,//thread not inheritable
		TRUE,//handle inheritance not possible
		0,//flags
		NULL,//use parents environment variables
		NULL,//use parents directory
		&StartupInfo,//startup information
		&ProcessInfo);//process information
	if (CreateProcessStatus == 0)
	{
		cout << "process creation failed due to error (" << GetLastError() << ")" << endl;
	}
	else {

		cout << "process 1 creation success" << endl;
		cout << "ProcessId: " << GetProcessId(ProcessInfo.hProcess) << " Curret process id : " << GetCurrentProcessId() << endl;
		cout << "ThreadId: " << GetThreadId(ProcessInfo.hThread) << " Current Thread id : " << GetCurrentThreadId() << "Process id of thread : " << GetProcessIdOfThread(ProcessInfo.hThread) << endl;
	}
	cout << ProcessInfo.hProcess << endl;

	CloseHandle(ProcessInfo.hProcess);
	CloseHandle(ProcessInfo.hThread);
}*/
