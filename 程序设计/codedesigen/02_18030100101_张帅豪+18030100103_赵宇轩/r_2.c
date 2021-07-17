#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
    int value;            //������
    struct node *Next;//ָ����
}Node;

//    ����һ��ջ�ṹ
typedef struct stack
{
    Node *Top;            //ջ��
    Node *Bottom;        //ջ��
}Stack;

void InitStack(Stack *s);        //��ʼ��ջ
void Push(Stack *s ,int value);  //��ջ
int pop (Stack *s);				 //��ջ 
int gettop(Stack *s);			 //���ջ��Ԫ�� 
void PrintStack(Stack *s);       //����ջ



//��ʼ��ջ 
void InitStack(Stack *s)
{
    s->Top = (Node*)malloc(sizeof(Node));    //    �����ڴ�ռ��ջ��
    s->Bottom = s->Top;                    //    ʹջ��Ҳָ��ջ���ռ�
    s->Top->Next = NULL;                    //    ջ��ָ����ΪNULL��
    
    return ;
}

//��ջ
void Push(Stack *s,int value)
{
    Node* p1 = (Node*)malloc(sizeof(Node));    //    ����һ���½ڵ㣬�������ڴ�ռ�
    p1->value = value;                        //    ��Ҫ��ջ�����ݸ����½ڵ��member��Ա
    p1->Next = s->Top;                        //    ʹ�½ڵ��ָ��ָ��ջ��
    s->Top = p1;                                //    ���½ڵ���Ϊ��ջ��
}

//����ջ�ĺ���
void PrintStack(Stack *s)
{
    Node* p1 = s->Top;
    while(p1!= s->Bottom)                //    ֻҪջ��������ջ�ף�ѭ��
    {
        printf("%d ",p1->value);            //    ��ӡջ���ĳ�Աmember
        p1 = p1->Next;                //    ջ��ָ�������ƶ�һ��
    }
}
//��ջ 
int Pop (Stack *s){
	int value = s->Top->value;
	s->Top = s->Top->Next;
	return value; 

}	
//���ջ��Ԫ��		 
int GetTop(Stack *s){
	return s->Top->value;

}			 

int main(){
	
	Stack s;
	InitStack(&s);
	int isquit = 0;
	while(!isquit){
		
		int a = 10;
		int  i =0;
		int value = 0;
		int  num = 0;
		printf("\n******************************************\n������ѡ��\n1.��ջ\n2.��ջ\n3.����ջ\n4.���ջ��Ԫ��\n0.�˳�\n******************************************\n");
		scanf("%d",&a);
		switch(a)
    	{
    		case 0: isquit = 1;
    		break;
        	case 1:printf("��ջ  �����ջ���ݸ���\n");
			scanf("%d",&num);
			for (i = 0;i < num;i++)
    		{
        		printf("��%d������",i+1);
        		scanf("%d",&value);
        		Push(&s,value);               //    ����Push����	
    		}
    		PrintStack(&s);                //    ���ñ�������
        	break;
        	case 2:printf("��ջ  �����ջ���ݸ���\n");
			scanf("%d",&num);
			for (i = 0;i < num;i++)
    		{	 
        		printf("��%d������%d\n",i+1,Pop(&s));	
    		}
    		printf("����ջԪ��Ϊ\n");
    		PrintStack(&s);                //    ���ñ�������
        	break;
        	case 3:printf("����ջ ����ջ��Ԫ��\n");
        	PrintStack(&s);
        	break;
        	case 4:printf("ջ��Ԫ��Ϊ%d\n",GetTop(&s));
        	break;
        	default:printf("��������");
    	} 
		
	}
	
	
} 
