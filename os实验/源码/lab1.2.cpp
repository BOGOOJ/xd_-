#include<stdio.h> 
#include<stdlib.h> 
int main(){ 
printf("�ӽ������С�\n"); 
FILE *fp; 
if(fp=fopen("date.txt","w")){ 
printf("�Ѿ������ļ�!\n"); 
int i; 
for(i=48;i<58;i++) fputc(i,fp); 
fputc('\n',fp); 
fclose(fp); 
printf("�Ѿ�д������:"); 
fp=fopen("date.txt","r"); 
char ch=fgetc(fp); 
while(ch!=EOF){ 
putchar(ch); 
ch=fgetc(fp); 
} 
fclose(fp); 
} 
else printf("�����ļ�ʧ��!\n"); 
system("pause"); 
return 0; 
} 

