#include <iostream>
#include <cstring>

using namespace std;

struct book{
	char name[50];
	int book_id;
};

void printbook( struct book book );
void printbook_s(struct book *book);
int main(){
	book book1;
	book book2;
	
	strcpy(book1.name,"��������");
	book1.book_id=1;
	
	strcpy(book2.name,"����һ��С�컨");
	book2.book_id=2;
	
	printbook(book1);
	printbook(book2);
	
	printbook_s(&book1);
	printbook_s(&book2);
	
	cout << book1.book_id << "\t" << book1.name << endl;
	cout << book2.book_id << "\t" << book2.name << endl;
	
}

void printbook( struct book book )
{
   cout << "���: " << book.book_id << "\t\t";
   cout << "Ӱ��: " << book.name <<endl;
}
void printbook_s(struct book *book){
	cout << book->book_id << "\t" << book->name << endl;
}
