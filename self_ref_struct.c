#include <stdio.h>
int main(int argc, char const *argv[])
{
	struct ex
	{
		int a;
		struct ex *l;
	};

	printf("%d",sizeof(struct ex));

	return 0;
}