#include<stdio.h> 
#include<windows.h> 
static int count; 
DWORD WINAPI ThreadProc(LPVOID IpParameter){ 
printf("���߳����С�\n"); 
for(count=1;count<=5;count++){ 
printf("�߳�count=%d\n",count); 
} 
printf("�̵߳ȴ�5���ӡ�\n"); 
Sleep(5000); 
return 0; 
} 
int main(){ 
count=10; 
printf("�������С�\n����count=%d\n",count); 
HANDLE hEvent=CreateThread(NULL,0,ThreadProc,NULL,0,NULL); 
WaitForSingleObject(hEvent,INFINITE); 
CloseHandle(hEvent); 
printf("���߳̽�����\n"); 
printf("���̽�����\n"); 
return 0; 
} 

