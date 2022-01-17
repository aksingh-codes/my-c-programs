#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

  
int search(int a[],int e,int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i]==e)
        {
            return 1;
        }
        
    }
    
    return 0;
    
    
};

void print(int a[],int n)
{
    int p=0;
    int h = (int)log((float) n) + 1;
    printf("%d",h);
    for (int i = 0; i < h; i++)
    {
        printf("\n");
        int var =0;
        int mid_temp =1;
        int mid[mid_temp];
        int mid_no = n/pow(2,mid_temp);
        for (int k = 0; k < mid_temp; k++)
        {
            mid[k] = var+mid_no;
        }
        printarray(mid,mid_temp);
        for (int j = 0; j < pow(2,h); j++)
        {
            if (search(mid,j,mid_temp))
            {
                printf("%d",a[p++]);
            }
            else
            {
                printf("[]");
            }
            

        }
        
        mid_temp++;
    }
    

};
void printarray(int a[],int n)
{
    printf("\nNow Heap is:\t[ ");
    for (int i = 0; i <= n; i++)
    {
        printf("%d,",a[i]);
    }
    printf(" ]   ");
};


// Driver program to test above function 
int main() 
{ 
    int arr[] = { 8, 2, 5, 4, 5, 6, 6, 6, 6 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    print(arr,n);
} 
