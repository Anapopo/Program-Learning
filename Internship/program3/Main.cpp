#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void main()
{
	char *p;
	char in[100], out[100];
	//get the chars from user's input
	do{
		printf("Please input the string:");
		cin>>in;
	}while(strlen(in) > 99);
	//make an pointer towards the chars array
	p = in;

	int i=0, count=0;
	while(*p != '\0'){//use pointer
		if(*p >= '0' && *p <= '9'){//if it is number
			out[i] = *p;//store the pointer's data to the out array
			i++;//push to next
			if(*(p+1) < '0' || *(p+1) > '9')//if the next not numbers
			{	
				count++;
				out[i] = '\40';//add \40 in
				i++;//push to next
			}
		}
		p++;//point to next
	}
	//finally printf
	printf("Count:%d\n", count);
	for(int x=0;x<i;x++) printf("%c", out[x]);
	printf("\n");
}