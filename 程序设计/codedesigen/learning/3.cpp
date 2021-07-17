#include <iostream>
#include <math.h>
using namespace std;
const double PI = 3.1415926;
class box{
	public:
		int id;
		double radiux;
		double getArea(void);
		double getVolume(void);
		void setRadiux(double rad);		
}; 
void box::setRadiux(double rad){
	radiux = rad;
}
double box::getArea(){
	return 4*PI*radiux*radiux;
} 
double box::getVolume(){
	return 4*PI*pow(radiux,3)/3;
}


// ���� Shape
class Shape 
{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};
 
// ���� PaintCost
class PaintCost 
{
   public:
      int getCost(int area)
      {
         return area * 70;
      }
};
 
// ������
class Rectangle: public Shape, public PaintCost
{
   public:
      int getArea()
      { 
         return (width * height); 
      }
};
 


int main(){
	box box1;
	
	box1.setRadiux(3);
	cout << "�뾶radiux��" << box1.radiux << "\t" <<"�����area��" << box1.getArea() << "\t" <<"���volume��" << box1.getVolume() <<endl; 
	
	
	
   Rectangle Rect;
   int area;
 
   Rect.setWidth(5);
   Rect.setHeight(7);
 
   area = Rect.getArea();
   
   // �����������
   cout << "Total area: " << Rect.getArea() << endl;
 
   // ����ܻ���
   cout << "Total paint cost: $" << Rect.getCost(area) << endl;
   return 0;
	
}
