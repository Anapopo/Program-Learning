#include <iostream>
using namespace std;
int main()
{
	int V;
	int N;
	int M;
	int arr[100];
	int sum=0;
	
	
	cin>>V;//�������ӵ��ݻ�
	
	cin>>N;//���������е��������

	for(int i=0;i<N;i++)
		cin>>arr[i];//����ÿ����������

	for(int j=0;j<N;j++)
		sum+=arr[j];//������
	
	M = sum/V + 1;//���
	//cout<<"sum:"<<sum<<endl;
	cout<<M<<endl;

	return 0;
}