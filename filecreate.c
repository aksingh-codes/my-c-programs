#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;
	char ch[100];

	fp=fopen("original.c","w");
	if(fp==NULL)
	{	printf("file doesn't exist\n");
		exit;
	}

	while(strlen(gets(ch))>0)
	{
		fputs(ch,fp);
		fputs("\n",fp);
	}
	fclose(fp);

	return 0;
}