#include<stdio.h>
#include<stdlib.h>
typedef struct node
	{
		char data;
		struct node *link;
	}NODE;
/*
NODE* createnode(int);
void traversefor(NODE*);
*/
int main()
{
	char ch='y';
	int val;
	int choice;
	
	
	NODE *head = (NODE*)malloc(sizeof(NODE));
	head = NULL;
	printf("%u\n",head);
	printf("what do you want to do with list\n");
	printf("1.createnode\n2.deletenode\n3.reverse sll\n");
	scanf("%d",&choice);
	
	while(ch=='y')
	{
		switch(choice)
		{
			case 1:
				printf("value to insert\n");
				scanf("%d",&val);
				head = createnode(val);
			default:
				traversefor(head);
		puts("do you want more ops (y/n) ");
		gets(&ch);
		}
	}
}
/*NODE* createnode(int value)
{
	NODE *p = (NODE*)malloc(sizeof(NODE));
	p->data = value;
	p->link = NULL;
	return p;
}

void traversefor(NODE *p)
{
	if(p)
	{
		printf("%c\n",p->data);
		traversefor(p->link);
	}
}
*/