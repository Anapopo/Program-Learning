#include <iostream>
#include <string>
using namespace std;
int judgeIt(int num){
	int arr[100];
	int k=0;
	int a,b;
	int temp = num;
	while(temp!=0)
	{
		arr[k] = (temp%10);
		k++;
		temp/=10;
	}
	b = arr[0] * 5;
	a = num/10;
	int res = a-b;

	return ((res%17) == 0)?1:0;

}

int main()
{
	int old=4913;
	cout<<judgeIt(old)<<endl;
	return 0;
}