#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp,*ef;
	char ch;

	fp=fopen("encrypted.c","r");
	ef=fopen("original.c","w");


	if(fp==NULL||ef==NULL)
	{
		puts("file doesn't exist");
		exit;
	}
	while((ch=(getc(fp))!=EOF))
		putc(ch-1,ef);

	fclose(fp);
	fclose(ef);
	return 0;
}