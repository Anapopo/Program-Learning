#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
void fun(char *s, char *c);
void main()
{	
	char *s, *c;
	char raw[1000];
	char out[1000];
	printf("Please input the secret content:");//char raw[1000] = "10181248124810181038113840810181248408104811781278116";
	cin>>raw;
	s = raw;
	c = out;
	fun(s, c);
	cout<<"The Result:";
	printf("%s\n", out);

	
}

void fun(char *s, char *c){
	char tmp = 0;
	int i=0;
	while(*s != '\0'){//foreach the whole string
		if(*s != '8'){
			if(*s >= '0' && *s <= '7')
				tmp = 8*tmp+(*s-'0');//switch 8 to 10
		}else{
			c[i] = tmp;//save the ASCII char to c pointer
			i++;
			tmp=0;//set 0 to continue the next
		}
		s++;
	}
	c[i] = tmp;//the finally ASCII string
	c[i+1] = '\0';//the end of a string
}