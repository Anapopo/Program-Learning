#include <iostream>
using namespace std;
class Point
{
private:
	int x;
	int y;
public:
	Point(int xx, int yy):x(xx),y(yy){}

	Point(){x=0;y=0;}

	Point& operator++()
	{
		++x;++y;
		return *this;
	}

	Point operator++(int)
	{
		Point temp;
		temp.x=x;
		temp.y=y;
		++x;++y;
		return temp;
	}

	Point operator+(Point p){return Point(x+p.x, y+p.y);}

	void show()
	{
		cout<<"("<<x<<","<<y<<")"<<endl;
	}
};
int main()
{
	Point p1(1,3),p2(2,4),p3;
	++p1;
	p3=p1+p2;
	p1.show();
	p3.show();
	return 0;
}