#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 2000000
unsigned char file_src[MAX_CHAR];
unsigned char file_dst[MAX_CHAR];
int Isrepeat(unsigned char* src,int left)
{
	if(left<3)////�ж��Ƿ����ظ����ݣ�ע�⣬ֻ���ظ����ݴ���3��ʱ��ű��ж�Ϊi�ظ����� 
	{
		return 0;
	}
	if(src[0] == src[1]&&src[1] == src[2])
	{
		return 1;
	}
	return 0;
	
} 
//����ظ����ݵĳ��� 
int getrepeatlength(unsigned char* src,int left)
{
	unsigned char data = src[0];
	int len = 1;
	while(len<left&&len<127&&src[len] == data)
	{
		len++;
	}
	return len;
} 
//��ò��ظ����ݵĳ��� 
int getnorepeatlength(unsigned char* src,int left)
{
	if(left < 3)
	return left;
	//���ظ����ݵĳ�������Ϊ2 
	int len = 2;
	//first��second����ǰ�������ַ�����������ƶ� 
	unsigned char first = src[0];
	unsigned char second = src[1];
	while(len<left&&len<127)
	{
		if(!(first==second&&src[len]==second))
		{
		    first = second;
		    second = src[len];
		    len++;
		}
		else
		{
			break;
		}
	}
	return len;
	 
	
} 
//RLE�㷨�����룬�������ΪԴ���飬Դ���鳤�ȣ�Ŀ�����飬Ŀ�����鳤�� 
int  RLEencode(unsigned char* src,int src_len,unsigned char* dst,int dst_len)
{
	unsigned char *data =  src;
	int left = src_len;
	int point = 0;//���������ָ�� 
	while(left > 0)
	{
		int count = 0;
		if(Isrepeat(data,left))
		{
			count =getrepeatlength(data,left);
			dst[point++] = count|0x80;//д�ظ����ݵ������� 
			dst[point++] = *data;//д�ַ� 
			//ָ���ƶ� 
			data+=count;
			left-=count;
		}
		else{
			count =getnorepeatlength(data,left);
			dst[point++] = count;
			for(int i=0;i<count;i++)
			{
				dst[point++] = *data;
				data++;
			}
			left-=count;
		} 
	} 
	return point;
} 

//RLE �����㷨�������Ǳ����㷨�ķ�����
int RLEdecode(unsigned char* src,int src_len,unsigned char* dst,int dst_len)
{
	unsigned char *data =  src;
	int left = src_len;
	int point = 0;//���������ָ�� 
	while(data < src + src_len)
	{
		unsigned char zifu = *data++;
		int count = zifu & 0x7f;
		//��ע�⣬һ��Ҫע�⣬�����Ǿ޴�bug�׷����أ���Ϊ==�����ȼ���ʵ��&Ҫ�ߣ�һ��Ҫ�����ţ�һ��Ҫע�� 
		if((zifu&0x80)==0x80)//���ظ��ַ� 
		{
		    for(int i=0;i<count;i++)
			{
				dst[point++] = *data;
				
			}
			data++; 
		}else
		{
			 for(int i=0;i<count;i++)
			{
				dst[point++] = *data++;
				
			}
		}
	}
	return point;
}

int main(int argc, char** argv) {
    FILE* f1;
    FILE* f2;
    f1 = fopen(argv[1], "rb");
    if(f1 == NULL){
    	printf("�Ҳ������ļ�!\n");
    	return 0;
	}
    int t = 0;
    int a = 0;
    //��ȡ�ļ� 
    while ((a = fgetc(f1)) != EOF) {
        file_src[t++] = a;
    }
    f2 = fopen(argv[3], "wb");
    int size = t; 
    printf("�����ַ���%d",size);
    //����-dΪ���룬-eΪ���� 
    if( strcmp(argv[2], "-d") == 0){
    	size = RLEdecode(file_src, size, file_dst, MAX_CHAR);
    	printf("����ַ���%d",size);
	}else if(strcmp(argv[2], "-c") == 0){
    	size = RLEencode(file_src, size, file_dst, MAX_CHAR);
    	printf("����ַ���%d",size);
	}
	fwrite(file_dst, size, sizeof(unsigned char), f2);
	fclose(f1);
	fclose(f2);
    return 0;
}



