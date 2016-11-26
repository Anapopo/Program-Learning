#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int arr[16];
	//str = "5432123456788881";
	cout<<"Please input the credit card number:";
	cin>>str;

	for(int i=0;i<16;i++)
		arr[i] = str[i] - '0';
	
	int ji_sum=0;
	int ou_sum=0;
	for(int j=15;j>=0;j--)
	{
		if((j+1)%2 == 0)
		{
			ji_sum+=arr[j];
			//cout<<"奇数加上"<<arr[j]<<endl;
		}

		else{
			int temp = ((2*arr[j])>=10)? (2*arr[j]-9) : (2*arr[j]);
			ou_sum += temp;
			//cout<<"偶数加上"<<temp<<endl;

		}
		
	}
	int sum = ji_sum + ou_sum;
	if(sum%10 == 0)
		cout<<"成功"<<endl;
	else
		cout<<"失败"<<endl;

	return 0;
}