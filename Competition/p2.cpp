#include <iostream>
using namespace std;
int main()
{
	int x,y,z;
	cout<<"一分硬币 两分硬币 五分硬币"<<endl;
	for(x=0;x<=100;x++)
	{
		for(y=0;y<=50;y++)
		{
			for(z=0;z<=20;z++)
			{
				if(x+2*y+5*z == 100)
					cout<<x<<" "<<y<<" "<<z<<endl;
			}
		}
	}
	return 0;
}