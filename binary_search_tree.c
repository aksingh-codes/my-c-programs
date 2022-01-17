#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


typedef struct bstnode
    {
    int data;
    struct bstnode* left;
    struct bstnode* right;
    }NODE;

NODE* rootptr = NULL;

int findmin();
int findmax();
NODE* getnode(int);
int search(int);
int insert(int);

int main()
{
    
    insert(15);
    insert(20);
    insert(12);
    insert(0);
    insert(13);
    insert(10);
    insert(50);
    insert(25);
    insert(23);
    insert(22);
    insert(12);
    search(15);
    findmax();
    findmin();
    return 0;
}

int insert(int data)
{
    if (rootptr==NULL)                 //for the first node
    {
        rootptr = getnode(data);
        printf("first node\n");
        return 0;
    }
    
    NODE* root = rootptr;           
    
    while(1){
    
    if(data <= root->data)
    {
        if (root->left == NULL)
        {
            root ->left = getnode(data);
            printf("new left node\n");
            return 0;
        }
        root  = root->left;
    }
    else if(data > root->data)
    {
        
        if (root->right == NULL)
        {
            root->right = getnode(data);
            printf("new right node\n");
            return 0;
        }
        root = root->right;
    }
    }
}


NODE* getnode(int data)
{
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->data = data; new->left=NULL;new->right=NULL;
    return new;
}

int search( int data)
{
    
    
    if (rootptr == NULL)
    {
        printf("EMPTY");
        return 1;
    }
    
    NODE* root=rootptr;

    while(data!=root->data){
        if (root == NULL)
        {
            printf("not found");
            return 1;
        }
        else if (data<=root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }    
    }
    printf("found babe! :):)");
}

int findmax()
{
    NODE* current = rootptr;

    if (rootptr == NULL)
    {
        printf("empty cant find");
        return 1;
    }
    

    while (current->right!= NULL)
    {
        current = current->right;
    }
    printf("\nMAXIMUM is %d",current->data);

    

}
int findmin()
{
    NODE* current = rootptr;

    if (rootptr == NULL)
    {
        printf("empty cant find");
        return 1;
    }
    

    while (current->left!= NULL)
    {
        current = current->left;
    }
    printf("\nMINIMUM is %d",current->data);

    

}
