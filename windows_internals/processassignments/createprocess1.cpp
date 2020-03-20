#include<Windows.h>
#include<iostream>
#include<tchar.h>

using namespace std;
/*
int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	STARTUPINFO StartUpInfo;
	PROCESS_INFORMATION ProcessInfo;
	ZeroMemory(&StartUpInfo, sizeof(StartUpInfo));
	ZeroMemory(&ProcessInfo, sizeof(ProcessInfo));
	StartUpInfo.cb = sizeof(StartUpInfo);
	BOOL Status = 0;
	Status = CreateProcess(L"C:\\Program Files (x86)\\Notepad++\\notepad++.exe",//null if the application name is not given using variable but using command line arguments
		NULL,//application name given as command line argument 
		NULL,//process not inheritable if null
		NULL,//thread not inheritable if null
		FALSE,//handle inheritance not possible
		0,//flags
		NULL,//use parents environment variables
		NULL,//use parents directory
		&StartUpInfo,//startup information
		&ProcessInfo);//process information
	if (Status == 0)//status 0 indicates that the creation of process failed
	{
		cout << "creation of process failed due to error(" << ")" << GetLastError() << endl;
	}
	//WaitForSingleObject(ProcessInfo.hProcess, INFINITE);//wait until child process exits
	cout << "the process id is : " << ProcessInfo.dwProcessId << "the thread id is: " << ProcessInfo.dwThreadId << endl;//process if of the process opened present in the process information
	CloseHandle(ProcessInfo.hProcess);//close handles of process and thread
	CloseHandle(ProcessInfo.hThread);

	return 0;
}
*/