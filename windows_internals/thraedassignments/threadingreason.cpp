#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;

DWORD WINAPI ThreadFun(LPVOID Str)
{
	Sleep(2000);
	DWORD i;
	for (i = 0; ; i++) {
		cout << i << endl;
	}
	return 0;
}

int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	HANDLE CreateThreadHandle;
	DWORD retval;
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
	//WaitForSingleObject(CreateThreadHandle, INFINITE);
	retval = WaitForSingleObject(CreateThreadHandle, 100);
	switch (retval) {
	case WAIT_ABANDONED:
		cout << "Thread excution was abandoned" << endl;
		break;
	case WAIT_OBJECT_0:
		cout << "Thread execution is successful" << endl;
		break;
	case WAIT_TIMEOUT:
		cout << "Timeout, Thread excution was exited forecefully" << endl;
		break;
	case WAIT_FAILED:
		cout << "Function has failed" << endl;
		break;
	}
	CloseHandle(CreateThreadHandle);//close the handle after use
	cout << "---Reached end in main thread---\n";
	return 0;
}


// waitforsingleobject waits for the parituclar thread execution to complete before it execute nest step in current thread..
// during infinite its waiting for return of function without time constraints
// during 1000 it will wait only 1000ms to comlete the function execution if its not the case it stopd the thread execution
// during 2000 wait which is greater than 1000, so nothing gets executed otherthan sleep