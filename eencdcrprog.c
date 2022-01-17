#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch='a';
	char e=~ch;
	char d=~e;
	printf("encrypt %d \n",ch);
	
	printf("encrypt %d \n",e);
	printf("decrypt %d \n",d);
	printf("%d  \n",EOF );
	return 0;
}