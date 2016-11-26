#include <iostream>
#include <string>
using namespace std;
int min(int *arr, int n)
{	
	int min=arr[0];

	for(int i=1;i<n;i++){
		if(arr[i] < min)
			min = arr[i];
	}
	return min;
}
int max(int *arr, int n)
{	
	int max=arr[0];

	for(int i=1;i<n;i++){
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}
int main()
{
	//****AB**C***DE*FGH***
	string str,str2;
	cout<<"Please input the string:";
	cin>>str;
	//str = "****AB**C***DE*FGH***";
	int len=str.length();
	int arr[100],t=0,k=0;
	for(int i=0;i<len;i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			arr[t] = i;
			t++;
		}	
	}
	for(i=min(arr,t);i<=max(arr,t);i++)
		if(str[i] == '*')
			str[i] = ' ';
		
	for(i=0;i<len;i++)
		if(str[i] != ' ')
			cout<<str[i];
	cout<<endl;
	return 0;
}