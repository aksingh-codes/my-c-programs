#include <stdio.h>
#include<stdlib.h>
typedef struct node
	{
		int data;
		struct node *link;
	}NODE;
NODE * head;


void traverse(NODE*);
void insrt_last();
int main()
{
	int temp;
	char ch = 'y';

	NODE * p = (NODE*)malloc(sizeof(NODE));
	p->data = 1;
	p->link = NULL;
	head = p;
	printf("first element of list is %d\n",head->data);

	printf("what do you wanna insert\n");
	scanf("%d",&temp);
	NODE * z = (NODE*)malloc(sizeof(NODE));
	z->data = temp;
	p->link = z;
	z->link = NULL;
	
	traverse(head);
	while(ch == 'y')
	{
		insrt_last();
		traverse(head);
		printf("\ndo you want to insert more(y/n)");
		fflush(stdin);
		scanf("%c",&ch);
	}

	scanf("%d",&temp);


	return 0;
}

void insrt_last()
{	
	int temp_var;
	NODE *temp_ptr =head;  //temp ptr
	NODE *new = (NODE*)malloc(sizeof(NODE)); //new mode
	
	printf("\nwhat do you wanna insert at last\n");
	scanf("%d",&temp_var);
	
	new->data = temp_var;
	new->link = NULL;
	
	while(temp_ptr->link)
		temp_ptr = temp_ptr->link;
	
	temp_ptr->link = new;
}


void traverse(NODE*y)
{
	
	while(y)
		{
			printf("%d\t",y->data);
			y = y->link;
		}

}