#include<stdio.h> 
#include<windows.h> 
int main(){ 
STARTUPINFO si; 
PROCESS_INFORMATION pi; 
ZeroMemory(&pi,sizeof(pi)); 
ZeroMemory(&si,sizeof(si)); 
si.cb=sizeof(STARTUPINFO); 
if(!CreateProcess("lab3.2.exe",NULL,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,
NULL,NULL,&si,&pi)){ 
printf("�����ӽ���ʧ�ܡ�\n"); 
return 0; 
} 
printf("Wait for event.\n"); 
HANDLE hEvent=CreateEvent(NULL,FALSE,FALSE,"event"); 
if(WAIT_TIMEOUT==WaitForSingleObject(hEvent,10000)){ 
printf("�ȴ��¼��źų�ʱ��\n"); 
return 0; 
} 
printf("Get the event.\n"); 
CloseHandle(hEvent); 
return 0; 
} 

