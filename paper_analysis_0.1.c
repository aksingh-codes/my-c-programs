#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//var denoting ques..stat..etc
    
    char e[]="easy",m[]="medium",h[] = "hard";
    char r[] = "right",w[] = "wrong",l[]="left";
    char c[]= "conceptual",s[]="silly",t[] = "time";
	
	int tot_que;//total question
	int ist_que;//first question

// main node containing data
typedef struct analyse_basis
    {
        char difficulty_lvl[20];
        char que_stat[20];
        char reason[20];
        char topic[50];
        struct analyse_basis *link;
    }NODE;

//void reverse();
void newque_data(char,char,char,char*);
void printanalysis();
NODE *head;

int main()
{
    
    
    int exitcode;
    char ch ='n';
    int choice;
    
    //only for once message
    printf("\n\t\t\t\t\tWelcome to paperanalyser...ver0.1  $$$\n");
    
    printf("Enter total no. of questions in your exam\n");
    scanf("%d",&tot_que);
    printf("Enter first question no.\n");
    scanf("%d",&ist_que);
    system("cls");
    printf("keywords \ndifficultylevel:\te=%s,m=%s,h=%s\nquestion status:\tr=%s,w=%s,l=%s\nreason:\t\tc=%s,s=%s,t=%s\n\n",e,m,h,r,w,l,c,s,t);
    
    while(ch == 'n')
    {   
        for (int i = ist_que; i <= tot_que; i++)
        {
        //temp vars    
        char temp_difficulty_lvl;
        char temp_que_stat;
        char temp_reason;
        char temp_topic[50];
        
        printf("Question%d:\n",i);
        fflush(stdin);

        printf("difficulty level:");fflush(stdin);
        scanf("%c",&temp_difficulty_lvl);
        printf("\nquestion status:");fflush(stdin);
        scanf("%c",&temp_que_stat);
        printf("\nreason:");fflush(stdin);
        scanf("%c",&temp_reason);
        printf("\ntopic:");fflush(stdin);
        scanf("%s",&temp_topic);
        

        newque_data(temp_difficulty_lvl,temp_que_stat,temp_reason,temp_topic);
        }
    
    ch ='y';
    }
    //reverse();
    printanalysis();
    scanf("%d",&exitcode);

}


void newque_data(char d1,char d2,char d3,char *d4)
{
    NODE *p = (NODE*)malloc(sizeof(NODE));
    
    if (d1 == 'e')
    {
        strcpy(p->difficulty_lvl,e);
    }
    else if (d1 == 'm')
    {
        strcpy(p->difficulty_lvl,m);
    }
    else
    {
        strcpy(p->difficulty_lvl,h);
    }
    
    
    if (d2 == 'r')
    {
        strcpy(p->que_stat,r);
    }
    else if (d2 == 'w')
    {
        strcpy(p->que_stat,w);
    }
    else
    {
        strcpy(p->que_stat,l);
    }
    
    
    
    if (d3 == 'c')
    {
        strcpy(p->reason,c);
    }
    else if (d3 == 's')
    {
        strcpy(p->reason,s);
    }
    else
    {
        strcpy(p->reason,t);
    }

    strcpy(p->topic,d4);



    p->link = head; //if head is pointing to null p will also point to null
    head = p;

}
void printanalysis()
{
FILE *fp;
fp = fopen("paper ka data.txt","w");


NODE *y;
	
   
    if (y!= NULL)
	{
        int temporary = tot_que;
		printf("\n Paper analysis:\n");
        printf("QUESTION\tDIFF.level\t\tQUES.STATUS\tREASON\t\tTOPIC\n");
        fprintf(fp,"\n Paper analysis:\n");
        fprintf(fp,"QUESTION\tDIFF.level\t\tQUES.STATUS\tREASON\t\tTOPIC\n");

		while(y)
		{

			printf("Question%d\t%s\t\t\t%s\t\t%s\t\t%s\n",temporary,y->difficulty_lvl,y->que_stat,y->reason,y->topic);
            fprintf(fp,"Question%d\t%s\t\t\t%s\t\t%s\t\t%s\n",temporary,y->difficulty_lvl,y->que_stat,y->reason,y->topic);


			y = y->link;
            temporary--;
		}
	}
	else
	{
		printf("The Question List is empty add some data dude!");
	}
	fclose(fp);
    
	printf("Thank You for using paper analyser!!\n Have a good day :) :)");
    fprintf(fp,"Thank You for using paper analyser!!\n Have a good day :) :)");
}

/*void reverse()
{
    NODE *cur = head;
	
	NODE* prev= NULL; NODE*next_node = NULL ;
    while(cur)
		{
			next_node = cur->link;
			cur->link = prev;
			prev = cur;
			cur = next_node;
		}
    head = prev;
	

}
*/
