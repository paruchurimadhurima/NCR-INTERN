#include<Windows.h>
#include<iostream>
#include<tchar.h>
#include <stdlib.h>
using namespace std;

struct twonum {
	int a;
	int b;
};

DWORD WINAPI ThreadFun1(LPVOID val)
{
	struct twonum* ptr = (struct twonum*) val;
	int i;
	//for (i = 0; i<10000; i++) {
	//	ptr->a++;
	//	ptr->b += 7;
		//cout << "Thread 1 :" << ptr->a <<"  " << ptr->b << endl;
	//}
	cin >> ptr->a >> ptr->b;
	return 0;
}

DWORD WINAPI ThreadFun2(LPVOID val)
{
	struct twonum* ptr = (struct twonum*) val;
	cout << "Thread 2 : sum of " << ptr->a << " "<<ptr->b << " is " << ptr->a + ptr->b<<endl;
	return 0;
}

int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	HANDLE CreateThreadHandle[2];
	int i;
	struct twonum* ptr = (struct twonum*)calloc(1, sizeof(struct twonum));
	CreateThreadHandle[0] = CreateThread(NULL,//security attributes thread is not inherited if null
		0,//stack size for thread if 0 it uses size of executable
		ThreadFun1,//call back function
		(LPVOID)ptr,//parameter to function
		0,//creation flag
		NULL);//thread id
	if (CreateThreadHandle[0] == NULL)
	{
		cout << "creation of thread  0 failed due to error (" << GetLastError() << ")" << endl;
	}
	WaitForSingleObject(CreateThreadHandle[0], INFINITE);
	CreateThreadHandle[1] = CreateThread(NULL,//security attributes thread is not inherited if null
		0,//stack size for thread if 0 it uses size of executable
		ThreadFun2,//call back function
		(LPVOID)ptr,//parameter to function
		0,//creation flag
		NULL);//thread id
	if (CreateThreadHandle[1] == NULL)
	{
		cout << "creation of thread  1 failed due to error (" << GetLastError() << ")" << endl;
	}

	//WaitForMultipleObjects(2, CreateThreadHandle, FALSE, INFINITE);
	WaitForSingleObject(CreateThreadHandle[1], 1000);
	for (i = 0; i < 2; i++) {
		CloseHandle(CreateThreadHandle[i]);//close the handle after use
	}
	return 0;
}
