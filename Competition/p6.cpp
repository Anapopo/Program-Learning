#include <iostream>
using namespace std;
int main()
{
	int V;
	int N;
	int M;
	int arr[100];
	int sum=0;
	
	
	cin>>V;//输入箱子的容积
	
	cin>>N;//输入箱子中的物体个数

	for(int i=0;i<N;i++)
		cin>>arr[i];//输入每个物体的体积

	for(int j=0;j<N;j++)
		sum+=arr[j];//体积相加
	
	M = sum/V + 1;//输出
	//cout<<"sum:"<<sum<<endl;
	cout<<M<<endl;

	return 0;
}