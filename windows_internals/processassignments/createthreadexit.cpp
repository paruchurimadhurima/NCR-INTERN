#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;
/*
DWORD WINAPI ThreadFun(LPVOID Str)
{
	ExitThread(0);
	cout << "Hi" << endl;
	return 0;
}

int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	HANDLE CreateThreadHandle;
	LPVOID Str = NULL;
	CreateThreadHandle = CreateThread(NULL,//security attributes thread is not inherited if null
		0,//stack size for thread if 0 it uses size of executable
		ThreadFun,//call back function
		Str,//parameter to function
		0,//creation flag
		NULL);//thread id
	if (CreateThreadHandle == NULL)
	{
		cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;
	}
	
	LPDWORD retval = (LPDWORD)WaitForSingleObject(CreateThreadHandle, INFINITE);
	CloseHandle(CreateThreadHandle);
	cout << GetExitCodeThread(CreateThreadHandle, retval) << endl;
	//close the handle after use
	return 0;
}*/