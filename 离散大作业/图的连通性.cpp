
#include<iostream>
#define max 500
using namespace std;
int judge,n;
void Judge(int M[max][max]) //�ж��Ƿ���ǿ��ͨ������ͨ�ĺ��� 
{
	judge = 0;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(M[i][j] == 0) judge = 1;
		}
	}
}
void Warshall(int M[max][max])
{
	for(int j = 0;j < n;j++)//���ڽӾ���ת��Ϊ�ɴ��Ծ��� ��Warshall�㷨 �� 
	{
		for(int i = 0;i < n;i++)
		{
			if(M[i][j]==1)
			for(int k = 0;k<n;k++)
			{
				M[i][k] = M[i][k]||M[j][k];
			}
		}
		M[j][j] = 1;
	}	
}
int main()
{
	int Matrix[max][max];//������������500���ڵ� 
	int matrix[max][max];
	int i,j;
	cout<<"������ڵ����"<<endl;
	cin>>n;
	cout<<"�������ڽӾ���"<<endl;
	for(i = 0;i < n;i++) //�����ڽӾ��� 
	{
		for(j = 0;j < n;j++)
		{
			cin>>Matrix[i][j];
			matrix[i][j] = Matrix[i][j];
		}
	}
	Warshall(Matrix);//�ó��ɴ���� 
	Judge(Matrix);//�жϿɴ����Ԫ���Ƿ���1 
	if(judge == 0)
	{
		cout<<"ǿ��ͨ"<<endl;
		return 0; 
	}
	judge = 0;
	for(i = 0;i<n;i++)//�ж��Ƿ�Ϊ������ͨ 
	{
		for(j = 0;j<n;j++)
		{
			if(Matrix[i][j]+Matrix[j][i]<=0) judge = 1;
		}
	}
	if(judge==0)
	{
		cout<<"������ͨ"<<endl;
		return 0;
	}
	for(i =0;i<n;i++) //���ڽӾ���ת��
	{
		for(j = 0;j<n;j++)
		{
			if(matrix[i][j]==1) matrix[j][i]=1;//���ڽӾ���matrix||����ת�þ��� 
		}
	}
	Warshall(matrix);
	Judge(matrix);
	if(judge == 0)
	{
		cout<<"����ͨ"<<endl;
		return 0; 
	}
	else{
		cout<<"����ͨ"<<endl;
		return 0;
	}
}


//���̣�
//�ȸ���������ڽӾ��󣬵���warshall����ת��Ϊ�ɴ��Ծ����ٵ����жϣ�Judge�������ж��Ƿ�Ϊǿ��ͨ����Ϊǿ��ͨ��
//�������ǿ��ͨ�� ����������������ǿ��ͨ�����ж��Ƿ��ǵ�����ͨ�����ǽ������������ǵ�����ͨ����о���ת��Ϊ����
//����ת�����ľ�������Warshall����ת��Ϊ����ͼ����ͼ���Ŀɴ��Ծ��� ���ж�����ͼ������ͨ�ģ���þ���Ϊ����ͨ����
//��֮��Ϊ����ͨ 

//���⣺
//��һ�α�дʱ�����ǽ���ͼ�ٴν���Warshall������ɴ��Ծ��󣬽������ͨ����������ж�Ϊ����ͨ 
