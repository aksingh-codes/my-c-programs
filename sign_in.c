#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct usr_data
    {
        char usr_name[20];
        char name[20];
        char usr_pass[20];
        struct usr_data *link;
    }NODE;

int sign_in();
void sign_up();
void welcome(NODE*);

NODE *head;

int main()
{
    
    
    char ch ='n';
    int choice;
    
    printf("\n@Hackerank\tOne place for all coders...$$$\n");
    while(ch == 'n')
    {   
        printf("1.sign in\n2.sign up");
        
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            sign_in();
            break;
        case 2:
            sign_up();
            break;
        }
    
    printf("\n@Hackerank\nOne place for all coders...$$$\ndo you wanna exit");
    fflush(stdin);
    scanf("%c",&ch);
    }

}

int sign_in()
{   
    if(head==NULL)
    {
        printf("no userdata found!");
        return 0;
    }
    
    NODE *t;
    char ch = 'y';
    char d1[20],p1[20]; 
    
    while(ch == 'y')
    {
    
        printf("username-->>\t");
        fflush(stdin);
        gets(d1);
        printf("password--->>\t");
        fflush(stdin);
        gets(p1);
    
    
        t = head;
        
        while(t!=NULL)
        {
            if(!strcmp(t->usr_name,d1))
                {
                    if (!strcmp(t->usr_pass,p1))
                    {
                        welcome(t);
                        return 0;
                    }
                }
            t=t->link;
        }
        printf("access denied\ndo you want try again?");
        scanf("%c",&ch);
        
        
    }
}

void sign_up()
{
    NODE *p = (NODE*)malloc(sizeof(NODE));

    printf("\nusername-->>\t");
    scanf("%s",(p->usr_name));
    printf("\nyour name-->>\t");
    scanf("%s",p->name);
    printf("\npassword--->>\t");
    scanf("%s",p->usr_pass);

    p->link = head; //if head is pointing to null p will also point to null
    head = p;

}

void welcome(NODE *t)
{
    int choice;
    
    printf("\nHi!,%s",t->name);
    printf("\n1.edit username\n2.edit password\n3.edit your name\n4.log out\n");
    scanf("%d",&choice);
    
    switch (choice)
    {
    char new[20];
    case 1:
        printf("\n-----------edit username------------\n");
        scanf("%s",new);
        strcpy(t->usr_name,new);
        break;
    case 2:
        printf("\n-----------edit password------------\n");
        scanf("%s",new);
        strcpy(t->usr_pass,new);
        break;
    case 3:
        printf("\n-----------edit your name------------\n");
        char newname[20];
        scanf("%s",new);
        strcpy(t->name,new);
        break;
    case 4:
        printf("\n-----------signing out------------\n");
        break;
    default:
        break;
    }

}
