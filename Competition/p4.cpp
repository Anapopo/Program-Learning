#include <iostream>

using namespace std;

int main()
{
	int arr[100];
	int t=0;
	int count;
	
	cout<<"Please input:";
	cin>>count;
	//cout<<count<<endl;

	for(int i=0;i<count;i++)
		cin>>arr[i];
	/*
	for(int j=0;j<count;j++)
		cout<<arr[j]<<" ";
	cout<<endl;
	*/
	int res=0;
	for(int j=0;j<count-1;j++)
		res += (arr[j]-1);
	res+=arr[count-1];
	cout<<res<<endl;
	return 0;
}