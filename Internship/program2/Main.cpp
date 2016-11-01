#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void cycle(int a[][10], int n);
int main()
{
	int arr[10][10];//define the raw array
	int step;
	//get the step from user's input
	do{
		printf("Please input the step N:");
		cin>>step;
	}while(step > 10 || step%2 == 1);
	//generate data for the raw array
	int in=1;
	for(int i=0;i<step;i++){
		for(int j=0;j<step;j++){
			arr[i][j]= in;
			in++;
		}
	}

	printf("Step: %d\n", step);//show the current step
	printf("The Raw Array.\n");//printf the raw array
	for(int i=0;i<step;i++) {
		for(int j=0;j<step;j++){
			if(step == 10) printf("%03d ",arr[i][j]);
			else printf("%02d ",arr[i][j]);
		}
		printf("\n");
	}
	//do the cycle function
	cycle(arr, step);
	printf("The Out Array.\n");//printf the out array
	for(int i=0;i<step;i++){
		for(int j=0;j<step;j++){
			if(step == 10) printf("%03d ",arr[i][j]);
			else printf("%02d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void cycle(int a[][10], int n)
{	
	int tmp[10][10];
	for(int i=0;i<n/2;i++)
		for(int j=0;j<n/2;j++)
			tmp[i][j] = a[i+n/2][j];
	for(int i=0;i<n/2;i++)
		for(int j=n/2;j<n;j++)
			tmp[i][j] = a[i][j-n/2];
	for(int i=n/2;i<n;i++)
		for(int j=0;j<n/2;j++)
			tmp[i][j] = a[i][j+n/2];
	for(int i=n/2;i<n;i++)
		for(int j=n/2;j<n;j++)
			tmp[i][j] = a[i-n/2][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j] = tmp[i][j];
}