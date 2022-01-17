#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	FILE *fp;
	char s[80];
	fp = fopen("poem.txt","w");
	if (fp==NULL)
	{
		puts("cannot open file");
		exit;
	}
	printf("\nEnter a few lines of text\n");
	while(strlen(gets(s))>0)
	{
		fputs(s,fp);
		fputs("\n",fp);
	}
	fclose(fp);
	return 0;
}