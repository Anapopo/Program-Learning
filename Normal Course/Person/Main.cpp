#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
	long num;
	string name;
public:
	Person(long a, string b):num(a),name(b){}
	void showData()
	{cout<<"num:"<<num<<" name:"<<name<<endl;}
};
class Student:public Person
{
protected:
	int score;
public:
	Student(long a, string b, int c):Person(a,b),score(c){}
	void showData()
	{cout<<"num:"<<num<<" name:"<<name<<" score:"<<score<<endl;}
};
class Teacher:public Person
{
protected:
	int wage;
public:
	Teacher(long a, string b, int c):Person(a,b),wage(c){}
	void showData()
	{cout<<"num:"<<num<<" name:"<<name<<" wage:"<<wage<<endl;}
};
int main()
{
	Teacher kaniet(10086, "Kaniet", 12000);
	Student angus(202150431, "Angus", 100);
	kaniet.showData();
	angus.showData();
	return 0;
}