#include <windows.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	HANDLE Pi;
	DWORD Written;
	char str[1000];
 
	if (WaitNamedPipe("\\\\.\\Pipe\\mypipe", NMPWAIT_WAIT_FOREVER) == 0)
	{
		printf("�ȴ��ܵ�ʧ��\n");
		return 0;
	}
	else
   	 	printf("�ҵ��ܵ��ˣ�\n");
	
	if ((Pi=CreateFile("\\\\.\\Pipe\\mypipe",GENERIC_READ | GENERIC_WRITE, 0 ,(LPSECURITY_ATTRIBUTES)NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, (HANDLE)NULL)) == INVALID_HANDLE_VALUE)
		printf("����ʧ��\n");
	else
		printf("�����ɹ���\n");
			
	printf("����������:");	
	gets(str);
	n=strlen(str);

	if(WriteFile(Pi,str,n,&Written, NULL) == 0)
	{
		printf("д����ʧ��\n");
		CloseHandle(Pi);
	}
	else
	 	printf("�ɹ�д�����ݣ�\n");
 
	CloseHandle(Pi);
	system("pause");
 
}


