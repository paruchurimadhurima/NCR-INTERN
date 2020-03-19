#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;



DWORD WINAPI ThreadFun1(LPVOID Str)
{
	DWORD* ptr = (DWORD*)Str;
	DWORD i;
	for (i = 0; i < 100; i++) {
		(*ptr)++;
		cout << "Thread1 " << *ptr << endl;
	}
	cout << "1-----------\n";
	return 0;
}

DWORD WINAPI ThreadFun2(LPVOID Str)
{
	DWORD* ptr = (DWORD*)Str;
	DWORD i;
	for (i = 0; i < 100; i++) {
		(*ptr)++;
		cout << "Thread2 " << *ptr << endl;
	}
	cout << "2-----------\n";
	return 0;
}

int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	HANDLE CreateThreadHandle[2];
	DWORD i, n = 0;
	CreateThreadHandle[0] = CreateThread(NULL,//security attributes thread is not inherited if null
		0,//stack size for thread if 0 it uses size of executable
		ThreadFun1,//call back function
		(LPVOID)&n,//parameter to function
		0,//creation flag
		NULL);//thread id
	if (CreateThreadHandle[0] == NULL)
	{
		cout << "creation of thread  0 failed due to error (" << GetLastError() << ")" << endl;
	}
	CreateThreadHandle[1] = CreateThread(NULL,//security attributes thread is not inherited if null
		0,//stack size for thread if 0 it uses size of executable
		ThreadFun2,//call back function
		(LPVOID)&n,//parameter to function
		0,//creation flag
		NULL);//thread id
	if (CreateThreadHandle[1] == NULL)
	{
		cout << "creation of thread  1 failed due to error (" << GetLastError() << ")" << endl;

	}
	WaitForMultipleObjects(2, CreateThreadHandle, TRUE, INFINITE);
	for (i = 0; i < 2; i++) {
		CloseHandle(CreateThreadHandle[i]);//close the handle after use
	}
	cout << "---Reached end in main thread---\n";
	return 0;
}
