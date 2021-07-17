#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
//�鼮��Ϣ�ṹ��
typedef struct ibook {
    int bookid;//���
    string name;//����
    int sum;//����
    
}Book;
typedef struct ireader {
    int num;//���
    string name;//��������
    int bookid;//����ͼ���id   
}Reader;

vector<Book> book;//�ڴ�����,ÿ�β�����Ҫ���������ݶ����ڴ棬Ȼ��д�����
vector<Reader> reader;//�ڴ����ݣ�ÿ�ζ���Ҫ������reader���ݶ����ڴ棬Ȼ��д�����
string readername;//����״̬ʱ��ǰ���û�����,ȫ�ֱ���
int readernum;//����״̬ʱ�ĵ�ǰ���û���ţ�ȫ�ֱ���
void write_to_file()//ÿ�ν�����ɾ�Ĳ�֮����Ҫˢ���������
{
    ofstream outputfile1("reader.txt", ios::out);
    ofstream outputfile2("book.txt", ios::out);
    if ((!outputfile1) || (!outputfile2))
    {
        cout << "�ļ�ϵͳ���" << endl;
        return;
    }
    for (int i = 0; i < book.size(); i++)
    {
        outputfile2 << book[i].bookid << " " << book[i].name << " " << book[i].sum << endl;
    }
    for (int i = 0; i < reader.size(); i++)
    {
        outputfile1 << reader[i].num << " " << reader[i].name << " " << reader[i].bookid << endl;

    }
    outputfile1.close();
    outputfile2.close();
}

void file_read()//�����ڴ����ݣ�ÿ�γ�ʼ����Ҫ�����ڴ�
{
    ifstream inputfile1("book.txt", ios::in);
    ifstream inputfile2("reader.txt", ios::in);
    if ((!inputfile1) || (!inputfile2))
    {
        cout << "�ļ�ϵͳ�Ѿ���" << endl;
        return;
    }
    Book tmp;
    Reader tmp2;
    while(inputfile1 >> tmp.bookid >> tmp.name >> tmp.sum)
    {
        
        
        book.push_back(tmp);
    }
    while(inputfile2 >> tmp2.num >> tmp2.name >> tmp2.bookid)
    {
        
        
        reader.push_back(tmp2);
    }
}
//��ѯ�����鱾��Ϣ
void Select_all_book()
{
    for (int i = 0; i < book.size(); i++)
    {
        cout << "�鱾id: " << book[i].bookid ;
        cout << "�鱾����: " << book[i].name ;
        cout << "��ʣ�鱾����:" << book[i].sum << endl;

    }
}
//����id��ѯ�鱾��Ϣ
void Select_by_id()
{
    int bookid;
    cout << "����bookid" << endl;
    cin >> bookid;
    for (int i = 0; i < book.size(); i++)
    {
        if (book[i].bookid == bookid)
        {
            cout << "------------------------------" << endl;
            cout << "�鱾id:" << book[i].bookid << endl;
            cout << "�鱾����:" << book[i].name << endl;
            cout << "��ʣ�鱾����:" << book[i].sum << endl;
            cout << "------------------------------" << endl;
        }
    }
}
//�������ֲ�ѯ�鱾��Ϣ
void Select_by_name()
{
    string name;
    cout << "����book������" << endl;
    cin >> name;
    for (int i = 0; i < book.size(); i++)
    {
        if (book[i].name == name)
        {
            cout << "------------------------------" << endl;
            cout << "�鱾id:" << book[i].bookid << endl;
            cout << "�鱾����:" << book[i].name << endl;
            cout << "��ʣ�鱾����:" << book[i].sum << endl;
            cout << "------------------------------" << endl;
        }
    }
}
//��ѯ���ߵı�� 
int Select_reader()
{
	for(int i=0;i<reader.size();i++)
	{
		if(reader[i].name == readername)
		{
			return reader[i].num;
		}
	}
	return -1;
}
//���߽���
void borrowbook()
{
    int bookid;
    cout << "����������鱾�ı��" << endl;
    cin >> bookid;
    for (int i = 0; i < book.size(); i++)
    {
        if (book[i].bookid == bookid)
        {
            if (book[i].sum > 0)
            {
                book[i].sum--;
                cout << "����ɹ�" << endl;

                //Ҫ����reader����;
                Reader tmp;
                tmp.bookid = bookid;
                tmp.name = readername;
                tmp.num = readernum;
                reader.push_back(tmp);
                //�������״̬
                write_to_file();
                cout << "����ɹ�" << endl;
                return;
            }
            else
            {
                cout << "û��ʣ����鱾������ʧ��" << endl;
                return;
            }
        }
    }
    cout << "û�ж�Ӧid���鱾,����ʧ��" << endl;
}
//���߻���
void givebackbook()
{
    int bookid;
    cout << "����������鱾�ı��" << endl;
    cin >> bookid;
    for (int i = 0; i < book.size(); i++)
    {
        if (book[i].bookid == bookid)
        {
            book[i].sum++;
            //ͬʱҪ����reader����,ɾ��reader�Ľ�����Ϣ
            
            for (int j = 0; j < reader.size(); j++)
            {
                if (reader[j].bookid == bookid && reader[j].name == readername)
                {
                    reader.erase(reader.begin() + j);
                }
            }
            //�����������
            write_to_file();
            cout << "����ɹ�" << endl;
            return;
        }
    }
    cout << "û�ж�Ӧ��ŵ��鱾����û�ж�Ӧ�Ķ������ݣ������鱾id���û���" << endl;
}
//��ѯÿ���鱻˭������
void Admin_select_by_bookid()
{
    int bookid;
    cout << "����bookid" << endl;
    cin >> bookid;
    cout << "��ʾ���ߴ�����û�" << endl;
    for (int i = 0; i < reader.size(); i++)
    {
        if (reader[i].bookid == bookid)
        {
            cout << reader[i].name << endl;
        }
    }
}
//����Ա���в���ͼ������
void Admin_insert_book()
{
    Book tmp;
    cout << "��������Ҫ���ӵ����id:" << endl;
    cin >> tmp.bookid;
    cout << "��������Ҫ���ӵ��������" << endl;
    cin >> tmp.name;
    cout << "��������Ҫ���ӵ��������" << endl;
    cin >> tmp.sum;
    book.push_back(tmp);
    //���������Ϣ
    write_to_file();
}
//����Ա���Ӷ�����Ϣ
void Admin_insert_reader()
{
    Reader tmp;
    cout << "��������Ҫ���ӵĶ���id" << endl;
    cin >> tmp.num;
    cout << "������������ߵ�����" << endl;
    cin >> tmp.name;
    cout << "��������߽����Ȿ���id" << endl;
    cin >> tmp.bookid;
    reader.push_back(tmp);
    //���������Ϣ
    write_to_file();
}
//����Աɾ��һ�����߽��ĵļ�¼
void Admin_delete_reader()
{
    Reader tmp;
    cout << "��������Ҫɾ�����ļ�¼�Ķ��ߵ�����" << endl;
    cin >> tmp.name;
    cout << "��������Ҫɾ�����ļ�¼�Ķ��߽���Ǳ����id" << endl;
    cin >> tmp.bookid;
    for (int i = 0; i < reader.size(); i++)
    {
        if ((reader[i].bookid == tmp.bookid)&&(reader[i].name == tmp.name))
        {
            reader.erase(reader.begin() + i);
            //ҲҪ�������book����,ʣ���鱾������+1
            for (int j = 0; j < book.size();j++)
            {
                if (book[j].bookid == tmp.bookid)
                {
                    book[j].sum++;
                }
            }
        }
    }
    //��Ҫ�����������
    write_to_file();
    cout << "ɾ���ɹ�" << endl;
}
//����Աɾ���鱾����
void Admin_delete_book()
{
    cout << "����������Ҫɾ�����鱾��id" << endl;
    int bookid;
    cin >> bookid;
    for (int i = 0; i < book.size(); i++)
    {
        if (bookid == book[i].bookid)
        {
            book.erase(book.begin() + i);
        }
    }
    write_to_file();
    cout << "ɾ���ɹ�" << endl;
}
//����Ա�����鱾��Ϣ
void Admin_update_book()
{
    cout << "��������Ҫ���µ��鱾��id" << endl;
    int bookid;
    cin >> bookid;
    cout << "�������Ȿ���������" << endl;
    int sum;
    string name;
    cin >> name;
    cout << "�������Ȿ����µ��ִ�����" << endl;
    cin >> sum;
    for (int i = 0; i < book.size(); i++)
    {
        if (book[i].bookid == bookid)
        {
            book[i].name = name;
            book[i].sum = sum;
            write_to_file();
            return;
        }
    }
    cout << "û���Ȿ���id" << endl;

}
//����Ա���¶�������
void Admin_update_reader()
{
    int id;
    cout << "���������id" << endl;
    cin >> id;
    cout << "������˶��ߵ��µ�����" << endl;
    string newname;
    cin >> newname;
    for (int i = 0; i < reader.size(); i++)
    {
        if (reader[i].num == id)
        {
            reader[i].name = newname;
        }
    }
    write_to_file();
    cout << "���³ɹ�" << endl;
}
//����Ա��ʾ����ϸ���ٽ���Ϣ
void Admin_show_all()
{
    for (int i = 0; i < book.size(); i++)
    {
        cout << "��id:" << book[i].bookid ;
        cout << "  ������:" << book[i].name ;
        cout << "  ���ִ�����:" << book[i].sum << endl;
        for (int j = 0; j < reader.size(); j++)
        {
            if (book[i].bookid == reader[j].bookid)
            {
                cout << "����id:" << reader[j].num << "  ��������:"<<reader[j].name << endl;
            }
        }
    }
}
int main(int argc,char** argv)
{
    //���Ƚ��ļ������ڴ�
    file_read();
    cout << "*************************************ͼ�����ϵͳ*************************************" << endl;
    readername = argv[2];
    string mode = argv[1];
    //����Ա
    if (mode == "-a")
    {
        while (1)
        {
        	cout << "********************************************************" << endl; 
            cout << "1.�鿴���е��鱾��������Ϣ" << endl;
            cout << "2.���Ӷ�����Ϣ" << endl;
            cout << "3.�����鱾��Ϣ" << endl;
            cout << "4.ɾ��������Ϣ" << endl;
            cout << "5.ɾ���鱾��Ϣ" << endl;
            cout << "6.���¶�����Ϣ" << endl;
            cout << "7.�����鱾��Ϣ" << endl;
            cout << "8.��ѯ��Ӧ��ű���Щ���߽���" << endl;
            cout << "9.����ͼ���Ž���ͼ����Ϣ��ѯ" << endl;
            cout << "10.�����鱾���ֽ���ͼ����Ϣ��ѯ" << endl;
         	cout << "********************************************************" << endl;            
            int m;
            cin >> m;
 	        switch(m){
        	case 1:Admin_show_all();
        	break;
        	case 2:Admin_insert_reader();
        	break;
        	case 3:Admin_insert_book();
        	break;
        	case 4:Admin_delete_reader();
        	break;
        	case 5:Admin_delete_book();
        	break;
        	case 6:Admin_update_reader();
        	break;        	
        	case 7:Admin_update_book();
        	break;
        	case 8:Admin_select_by_bookid();
        	break;			
        	case 9:Select_by_id();
        	break;			
        	case 10:Select_by_name();
        	break;					        	
        	default:printf("��������");
    	} 
            
        }
    }
    //�û�
    if (mode == "-u")
    {
    	readernum = Select_reader();
    	if(readernum == -1)
    	{
    		cout<<"û�ж�Ӧ���û�"<<endl; 
    		exit(0); 
		}
        while (1)
        {
        	cout << "********************************************************" << endl; 
            cout << "1.�鿴���е��鱾��Ϣ" << endl;
            cout << "2.����" << endl;
            cout << "3.����" << endl;
            cout << "4.��ͼ���Ž���ͼ����Ϣ��ѯ" << endl;
            cout << "5.����ͼ�����ֽ���ͼ����Ϣ��ѯ" << endl;
         	cout << "********************************************************" << endl;            
           
            int m;
            cin >> m;
             switch(m){
        	case 1:Select_all_book();
        	break;
        	case 2:borrowbook();
        	break;
        	case 3:givebackbook();
        	break;
        	case 4:Select_by_id();
        	break;
        	case 5:Select_by_name();
        	break;  	
        	default:printf("��������");
    	} 
        }
    }
}




