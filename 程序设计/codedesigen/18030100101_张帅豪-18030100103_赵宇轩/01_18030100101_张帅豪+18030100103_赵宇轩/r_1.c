#include<stdio.h>
#include<string.h>

//�ӷ����� 
void add(int *num1,int *num2,int num1_length,int num2_length);
//�������� 
void sub(int *num1,int *num2,int num1_length,int num2_length); 


int main()
{
	//��ʼ������ 
	int num1[100] = {0};
	int num2[100] ={0};

	char str1[100], str2[100];
    printf("�������һ�����ִ�: ");
    scanf("%s", str1);
    printf("��һ�����ִ�Ϊ%s  ����Ϊ%d\n",str1,strlen(str1));
    printf("������ڶ������ִ�: ");
    scanf("%s", str2);
    printf("�ڶ������ִ�Ϊ%s  ����Ϊ%d\n",str2,strlen(str2));

    
    int i = 0;
    int num1_j =0;
    
    //���ַ���1ת��Ϊ�������� 1 
	for(i =strlen(str1)-1;i>=0;i--){
		num1[num1_j++] = str1[i] - '0';
	}
	//���ַ���2ת��Ϊ�������� 2 
	int num2_j =0;
	for(i =strlen(str2)-1;i>=0;i--){
		num2[num2_j++] = str2[i] - '0';
	}
	
	
	
	//�ӷ� 
	printf("%s + %s = ",str1,str2);
	add(num1,num2,num1_j,num2_j);

	//����
	//���ж����ִ�str1�Ƿ����str2 
	int isbig = 0;//Ĭ��str1 < str2 
	if(num1_j > num2_j){//str1λ���࣬��str1�� 
		isbig = 1;
	}else if(num1_j == num2_j){//λ����ȣ�str1��str2��һ������ȵ�����str1�Ĵ���str1�� 
		int right = 1;
		i = num1_j;
		isbig = 1;
		while(right){
			if(num1[i]<num2[i] || i < 0){
				isbig = 0;
				right = 0;
			}
			i = i-1;
		}	
	}

	if(isbig){
		printf("\n%s - %s =  ",str1,str2);
		sub(num1,num2,num1_j,num2_j);//���ü������� 
		printf("\n%s - %s = -",str2,str1);
		sub(num1,num2,num1_j,num2_j);//���ü������� 
	}else{
		printf("\n%s - %s =  ",str2,str1);
		sub(num2,num1,num2_j,num1_j);//���ü������� 
		printf("\n%s - %s = -",str1,str2);
		sub(num2,num1,num2_j,num1_j);//���ü������� 
	}

    
	 
}

//�ӷ����� 
void add(int *num1,int *num2,int num1_length,int num2_length){
	int num[100]={0};
	int i = 0;
	//���ҵ���ļ��� 
	int length = num1_length > num2_length ? num1_length : num2_length;
	int more = 0;
	for(i = 0;i<=length;i++){
		num[i] = (num1[i] + num2[i] + more)%10;//ȡ�����õ���ǰλ 
		more = (num1[i] + num2[i])/10;//��λ���� 
	}
	if(num[length]==0){//������λû�н�λ���ͽ��ܳ��ȼ�һ 
		length = length -1;
	}
	for(i = length;i>=0;i--){	
		printf("%d",num[i]);
	}	
}

//�������� 
void sub(int *num1,int *num2,int num1_length,int num2_length){
	int num[100]={0};
	int i = 0;

	//�ӵ�λ��ʼ�� 
	for(i = 0;i<=num1_length;i++){
		if(num1[i]<num2[i]){//����������ĵ�ǰλС����ǰ��λ 
			num[i] = 10 + num1[i] - num2[i];
			num[i+1] -= 1;
		}else{// �������ĵ�ǰλ��С��ֱ�ӽ��м��� 
			num[i] = num1[i] - num2[i];
		}
	}

    int iszero = 1;
	for(i = num1_length-1;i>=0;i--){
		if(num[i] !=0){//��ֹ���λΪ0 
			iszero = 0;
		}
		if(iszero != 1){
			printf("%d",num[i]);
		}	
	}	
}



