#include <iostream>

using namespace std;

//Base Class
class Shape
{
	public:
		Shape(int a=0, int b=0)
		{
			width = a;
			height = b;
		}
		virtual int area() = 0;
		virtual int getHeight()
		{
			cout << "Parent class height" << endl;
			return height;
		}
		int getWidth(void)
		{
			cout << "Parent class width" << endl;
			return width;
		}
	protected:
		int width;
		int height;
};

//Base Class 2
class PaintCost
{
	public: 
	virtual int getCost(int area)
	{
		cout << "Estimating paint cost" << endl;
		return area*70;
	}
};

class Rectangle: public Shape, public PaintCost{
	public:
		Rectangle(int a=0, int b=0):Shape(a,b) { }
		
		//member function within class
		int area()
		{
			cout << "Rectangle class area "<<endl;
			return (width * height);
		}
		//declare out-of-class memeber functions
		int getHeight(void);
		int getWidth(void)
		{
			cout << "Rectangle class width" << endl;
			return width;
		}
		//Operator overloading
		Rectangle operator+(const Rectangle &r)
		{
			Rectangle rectangle;
			rectangle.height = this->height+r.height;
			rectangle.width = this->width+r.width;
			return rectangle;
		}
};

int Rectangle::getHeight(void) {
	cout << "Rectangle height" << endl;
	return height;
}

int main(int argc, char *argv[]) {
	Shape * shape;
	Rectangle rec(10,7);
	
	rec.getHeight();
	rec.getCost(rec.area());
	
	shape = &rec;
	cout << endl;
	
	//Without virutal function
	rec.getWidth();
	shape->getWidth();
	cout << endl;
	
	//With virtual function
	rec.getHeight();
	shape->getHeight();
	cout << endl;
	
	//operator overloading
	Rectangle rec2(5, 3);
	Rectangle rec3 = rec + rec2;
	cout << rec3.area() << endl;
	
	shape->area();
	
	return 0;
}