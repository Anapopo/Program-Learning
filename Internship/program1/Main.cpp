#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
void sort(int *arr);
bool writeTxt(FILE *file, int *old, int *out);

int main(){
	//define an array with N*4 bytes 0x00
	int arr[N];
	srand(time(NULL));
	//generate random data from 1000 to 9999 and save to (arr)
	for(int i=0;i<N;i++){
		int tmp;
		tmp = rand()%9000 + 1000;
		arr[i] = tmp;
	}
	//save the (arr) array to (old) array
	int old[N];
	for(int i=0;i<N;i++) old[i]=arr[i];
	//sort starting....
	sort(arr);
	//finally print...
	printf("Old:");
	for(int i=0;i<N;i++) printf("%d ", old[i]);
	printf("\n");
	printf("New:");
	for(int i=0;i<N;i++) printf("%d ", arr[i]);
	printf("\n");
	//save to txt file
	FILE *file=fopen("C:/Users/user/Desktop/GoodJob.txt","w");
	writeTxt(file, old, arr);
	return 0;
}

bool writeTxt(FILE *file, int *old, int *out)
{	
	if(file==NULL) return false;
	fprintf(file,"Old:");
	for(int i=0;i<N;i++) fprintf(file,"%d ", old[i]);
	fprintf(file,"\n");

	fprintf(file,"New:");
	for(int i=0;i<N;i++) fprintf(file,"%d ", out[i]);
	fprintf(file,"\n");

	fclose(file);
	return true;
}

void sort(int *arr)
{
	for(int i=0;i<N-1;i++)//N elements,needs sort N-1 times
	{
		for(int j=0;j<N-1-i;j++)
		{
			if((arr[j]%1000) < (arr[j+1]%1000))
			{
				int tmp  = arr[j+1];
				arr[j+1] = arr[j];
				arr[j]   = tmp;
			}
		}
	}
	//for(int k=0;k<N;k++) printf("%d ", arr[k]);
}