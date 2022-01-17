#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

#define MAX 4

int queue[MAX];
int front = 0,rear = 0;

void enqueue(int);
int dequeue();
void traverse();

int main()
{
    int ch=1;int choice;
    int error;

    while(ch){
        printf("\nMENU \n1.enqueue\n2.dequeue\n3.show the queue\n4.exit\n");
        scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("what you wanna insert");
        int item;
        scanf("%d",&item);
        enqueue(item);
        break;
    case 2:
        error = dequeue();
        if(error!=-1){
            printf("deleted elemented is %d",error);
        }
        break;
    case 3:
        traverse();
        break;
    case 4:
        ch=0;
        break;
    default:
        printf("\ninvalid operation");
        break;
    }
        }
    return 0;
}
void enqueue(int temp)
{
    rear = (rear+1)%(MAX);
    if(rear == front) { 
        printf("The queue is full\n"); 
        if (front == 0)
        {
            rear = MAX-1;
        }
        else
        {
            rear--;
        }
        return;}
    else
    {
        queue[rear]=temp;
        return;
    }
    
}

int dequeue()
{
    if(front==rear)
    {
        printf("The queue is empty\n");
        return-1;
    }
    else
    {
        front=(front+1)%(MAX);
        int item = queue[front];
        return item;
    }
}

void traverse()
{
    int i= (front+1)%MAX;
    do
    {
        printf("%d\t",queue[i]);
        i= (i+1)%MAX;
    }while(i!=(rear+1)%MAX);
}