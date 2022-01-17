#include <stdio.h>
#include <stdlib.h>

int a = 0;

void prtFun () {
	register int a = 5;
	printf("Inside prtFun %d\n", a);
	a++;
}

int main(int argc, char const *argv[])
{
	static int a = 2;
	prtFun();
	prtFun();
	return 0;
}