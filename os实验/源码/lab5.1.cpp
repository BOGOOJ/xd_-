#include <windows.h>
#include <stdio.h>

int diaoyongzi()//�����ӳ��� 
{
	char Path[] = "lab5.2.exe";
	STARTUPINFO si = {sizeof(si)};
	PROCESS_INFORMATION pi;
	bool m1 = CreateProcess(Path,NULL,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi); 
	
	if(m1)
		printf("�ɹ������ӽ���\n");
		
	else
		printf("Error\n");
		
	
	return 0;
} 
int main()
{
	HANDLE Pi;
	DWORD BytesRead;
	char read[1024] = {0};
 //�����ܵ� 
	if ((Pi=CreateNamedPipe("\\\\.\\Pipe\\mypipe",PIPE_ACCESS_DUPLEX, PIPE_TYPE_BYTE|PIPE_READMODE_BYTE,1,0,0,1000,NULL))==INVALID_HANDLE_VALUE)
	{
		printf("����ʧ��\n");
		return 0;
	}
 
	printf("�ܵ��Ѵ���!\n");
 	diaoyongzi();
	  
	if (ConnectNamedPipe(Pi,NULL) == 0)
	{
		printf("ʧ���ˡ�����\n");
		CloseHandle(Pi);
	}
	
	else
		printf("�ɹ���\n");
	 //��ȡ���� 
	if(ReadFile(Pi,read,sizeof(read),&BytesRead,NULL) <= 0)
	{
		printf("û�гɹ���ȡ\n");
		CloseHandle(Pi);
	}
	
	else
		printf("�յ�������Ϊ %s \n",read);
 
	DisconnectNamedPipe(Pi);		
	CloseHandle(Pi);
	system("pause");
 	return 0;
}


