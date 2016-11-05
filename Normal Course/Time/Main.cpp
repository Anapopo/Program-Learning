#include <iostream.h>
#include <stdio.h>
class Time
{
private:
	int hour;
	int minute;
public:
	Time(int h=0,int m=0):hour(h),minute(m){}
	friend istream& operator>>(istream& in, Time& t);
	friend ostream& operator<<(ostream& out, Time& t);
	Time& operator++()
	{
		++minute;
		if(minute == 60)
		{
			++hour;
			minute=0;
		}
		return *this;
	}
};
int main()
{
	Time noon;
	cin>>noon;
	++noon;
	cout<<noon<<endl;
	getchar();
	return 0;
}
istream& operator>>(istream& in, Time& t)
{
	in>>t.hour>>t.minute;
	return in;
}
ostream& operator<<(ostream& out, Time& t)
{
	out<<t.hour<<":"<<t.minute<<endl;
	return out;
}