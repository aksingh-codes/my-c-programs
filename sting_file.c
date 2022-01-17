#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	FILE *fp;
	char s[80];
	fp = fopen("poem.txt","r");
	if (fp==NULL)
	{
		puts("cannot open file");
		exit;
	}
	while(fgets(s,79,fp)!=NULL)
	{
			printf("%s",s);

	}
	fclose(fp);
	return 0;
}