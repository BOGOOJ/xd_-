#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int  main() {
	cout << "hello \nworld!" << endl;
	cout << "hello world!" << "\n";
	cout << "hello world!" << "ewrwrrw" << "fedwafsaef" <<endl;
	cout << "hello world!" << endl;
	enum color {
		red,
		green,
		white = 5,
		black
	} c ;
	
	c = black;
	cout << c << endl;
	c = white;
	cout << c << endl;
	c = green;
	cout << c << endl;
	int i,j;
 
   // ��������
   srand( (unsigned)time( NULL) );
 
   /* ���� 10 ������� */
   for( i = 0; i < 10; i++ )
   {
      // ����ʵ�ʵ������
      j= rand();
      cout <<"������� " << j << endl;
   }
   
   int balance[5] = {1000, 2, 3, 7, 50};
   int *s;
   s = &balance[1];
   cout << &balance[1]<<" "<< &balance[2] << endl;
   cout << s <<" "<< s+1 << endl;
   cout << *(s)  <<" "<< *(s+1)<< endl;
   
   int  var1;
   int var2[10];
 
   cout << "var1 �����ĵ�ַ�� ";
   cout << &var1 << endl;
 
   cout << "var2 �����ĵ�ַ�� ";
   cout << &var2 << &var2[0]<< &var2[1]<< &var2[2]<< &var2[3]<< &var2[4]<< endl;
   
    // �����򵥵ı���
   int i_1;
 
   // �������ñ���
   int&    r = i_1;
   
   i_1 = 5;
   cout << "Value of i : " << i_1 << endl;
   cout << "Value of i reference : " << r  << endl;
   r = 12;
   cout << "Value of i : " << i_1 << endl;
   cout << "Value of i reference : " << r  << endl;
  

	// ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
   time_t now = time(0);
   cout << now <<endl; 
   // �� now ת��Ϊ�ַ�����ʽ
   char* dt = ctime(&now);
 
   cout << "�������ں�ʱ�䣺" << dt << endl;
 
   // �� now ת��Ϊ tm �ṹ
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "UTC ���ں�ʱ�䣺"<< dt << endl;
   
   char name[50];
   int age;
   cout << "please input your name and age: " ;
   cin >> name >> age;
   cout << "����:" << name << "  ����:" << age << endl;
   
   
	return 0;
}












