//��������ʵ�ֽ���ͨ��
#include <iostream>
#include <windows.h>
using namespace std;
 
#define BUF_SIZE 1025
char szName[] = "NameOfMappingObject";    // �����ڴ������
 
int main()
{
	// ���������ļ����
    HANDLE hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, BUF_SIZE, szName);         
 
    char *pBuf = (char *)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, BUF_SIZE);
 
    while(1)
    {
		cout << "input again" << endl;
        char szInfo[BUF_SIZE] = {0};
        gets(szInfo); 
        strncpy(pBuf, szInfo, BUF_SIZE - 1);
		pBuf[BUF_SIZE - 1] = '\0';
    }
 
	UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);
	return 0;
}


