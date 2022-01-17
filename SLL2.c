#include <stdio.h>
#include<stdlib.h>
typedef struct node
	{
		int data;
		struct node *link;
	}NODE;


NODE* reverse(NODE*);
void traverse(NODE*);
void insrt_last(NODE*);
int main()
{
	int temp,choice;
	char ch,ops = 'y';
    
    NODE *head = NULL;
	NODE * p = (NODE*)malloc(sizeof(NODE));
	p->data = 1;
	p->link = NULL;
	head = p;
	printf("first element of list is %d\n",head->data);
	
	traverse(head);

	while(ops == 'y')
	{	
		printf("what do you want to\n1.insert element\n2.traverse\n3.reverse\n4.exit\n");
		fflush(stdin);
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
			{
				while(ch == 'y')
				{
				insrt_last(head);
		
				printf("\ndo you want to insert more(y/n)");
				fflush(stdin);
				scanf("%c",&ch);
				}
				break;
			}
			case 2:
			{	traverse(head);
				break;
			}
			case 3:
			{
				head = reverse(head);
				break;
			}
			case 4:
			{
				ops = 'n';
			}
		}
	}
	
	
	
	traverse(head);


	return 0;
}

void insrt_last(NODE*head)
{	
	int temp_var;
	NODE *temp_ptr =head;  //temp ptr
	NODE *new = (NODE*)malloc(sizeof(NODE)); //new mode
	
	printf("\nWhat do you wanna insert ->");
	scanf("%d",&temp_var);
	
	new->data = temp_var;
	new->link = NULL;
	
	if (temp_ptr!=NULL)
	{
		while(temp_ptr->link)
		temp_ptr = temp_ptr->link;
	
		temp_ptr->link = new;
	}
	else
	{
		head = new;
	}
	
	
	
}


void traverse(NODE*y)
{
	if (y!= NULL)
	{
		printf("\n The List content is:\n[\t");
		while(y)
		{
			printf("%d\t",y->data);
			y = y->link;
		}
		printf("]\n");
	}
	else
	{
		printf("The List is empty add some data dude!");
	}
	
	
}

NODE* reverse(NODE* cur)
{
	
	if(cur||cur->link)
	{
		NODE* prev= NULL; NODE*next_node = NULL ;

		while(cur)
		{
			next_node = cur->link;
			cur->link = prev;
			prev = cur;
			cur = next_node;
		}

		return prev;

	}
	else
	{
		return cur;
	}
	

}