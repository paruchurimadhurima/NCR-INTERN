#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;

DWORD WINAPI ThreadFun1(LPVOID Str)
{
	Sleep(4000);
	int i;
	for (i = 0; i<10000; i++) {
		cout << i << endl;
	}
	cout << "1-----------\n";
	return 0;
}

DWORD WINAPI ThreadFun2(LPVOID Str)
{
	Sleep(3000);
	int i;
	for (i = 0; i < 10000; i++) {
		cout << i << endl;
	}
	cout << "2-----------\n";
	return 0;
}

int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	HANDLE CreateThreadHandle[2];
	int i;
	LPVOID Str = NULL;
	CreateThreadHandle[0] = CreateThread(NULL,//security attributes thread is not inherited if null
		0,//stack size for thread if 0 it uses size of executable
		ThreadFun1,//call back function
		Str,//parameter to function
		0,//creation flag
		NULL);//thread id
	if (CreateThreadHandle[0] == NULL)
	{
		cout << "creation of thread  0 failed due to error (" << GetLastError() << ")" << endl;
	}
	CreateThreadHandle[1] = CreateThread(NULL,//security attributes thread is not inherited if null
		0,//stack size for thread if 0 it uses size of executable
		ThreadFun2,//call back function
		Str,//parameter to function
		0,//creation flag
		NULL);//thread id
	if (CreateThreadHandle[1] == NULL)
	{
		cout << "creation of thread  1 failed due to error (" << GetLastError() << ")" << endl;
	}
	
	DWORD retval = WaitForMultipleObjects(2, CreateThreadHandle, FALSE, 2000);
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
	for (i = 0; i < 2; i++) {
		CloseHandle(CreateThreadHandle[i]);//close the handle after use
	}
	cout << "---Reached end in main thread---\n";
	return 0;
}


// bWaitAll = TRUE and timeout interval INFINITE : waits for execution of all threds and their exit
// bWaitAll = FALSE and timeout interval INFINITE, thread1 Sleep(4000) and thread2 Sleep(3000) : exits if any one of the treads completes the execution after sleeping, second thread ends first
// bWaitAll = FALSE and timeout interval INFINITE, thread1 Sleep(2000) and thread2 Sleep(3000): exits if any one of the treads completes the execution after sleeping, first thread ends first
// bWaitAll = FALSE and timeout interval 2000, thread1 Sleep(4000) and thread2 Sleep(3000) : no threads print anything as both of them are sleeping for more time than given time limit i.e, 2000ms
