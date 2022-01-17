#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>
#include<time.h>

void loader();
void procedure(int * ,int );
void procedure_part(int *,int ,int );
void printarray(int * ,int);


void quicksort(int *,int ,int );
int partition(int * ,int  , int );
void swap(int *,int *);

void merge_sort(int *, int, int);
void merge(int*,int, int,int);

void insertion(int * ,int);


int main()

{
	int faltu; 
    //clock_t t;
    

    int arr1[] = {100,50,3,1,30,2,5,4,50,-2,0,-99,555,-99,9999};
    int arr2[] = {100,50,3,1,30,2,5,4,50,-2,0,-99,555,-99,9999};
    int arr3[] = {100,50,3,1,30,2,5,4,50,-2,0,-99,555,-99,9999};


    
    int size = sizeof(arr1)/sizeof(arr1[0]) ;     //total elements in array
    printf("Un");printarray(arr1,size);
    
    //t = clock();
    insertion(arr1,size);
    //t = clock() - t;
   // double time_used_insertion = ((double)t)/CLOCKS_PER_SEC;
    //printf(":time:%f seconds",time_used_insertion);
    printf("\nInsertion ");
    printarray(arr1,size);

    merge_sort(arr2,0,size-1);
    printf("\nMerge ");
    printarray(arr2,size);

    quicksort(arr3,0,size-1);
    printf("\nQuick ");
    printarray(arr3,size);
    
    printf("\n");
    for (int i = 0; i < 100; i++)
    {
        printf("-");
    }
     
    loader();
    printf("\nInsertion ");
    printarray(arr1,size);

    printf("\nMerge ");
    printarray(arr2,size);
    
    printf("\nQuick ");
    printarray(arr3,size);
    
   
    scanf("%d",&faltu);
}



//          MERGE SORT ALGO STARTS HERE.....


void merge_sort(int a[],int f,int n)    //a ->pointer to array f->[index first element] n->[last element index]
{
    if (f<n)
    {

        int m = (f+n)/2 ;               // m -> mid element index
        merge_sort(a,f,m);
        merge_sort(a,m+1,n);
        merge(a,f,m,n);
    }
}

void merge(int a[], int p, int q ,int r)      // a-> pointr to array p->first index q->mid index r->last index
{
    
    int n = r-p+1;
    int n1 = q-p+1;     // total elements in left subarray
    int n2 = r-q;     //total elements in right subarray

    int L[n1+1];  int R[n2+1];

    for (int z = 0; z < n1 ; z++)
    {
        L[z]=a[z+p];
    }
    for (int y = 0; y < n2; y++)
    {
        R[y] = a[y+q+1];
    }
    
    L[n1]=99999999;  R[n2] = 99999999 ;  // last element

    int i=0,j=0,k=p;      //i->L   j->R   k -> array start
    
    
    while (k <= r )//array fin
    {
        if (L[i]<R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        
        k++;
    }
    printf("\nNew Merged subarray");
    procedure(a,r+1);
}




//          QUICK SORT ALGO STARTS HERE.....


void quicksort(int a[],int f,int n)
{
    if(f<n)
    {
        int pivot = partition(a,f,n);
        
        printf("\nPartioned subarray for pivot %d:\t\t\t",pivot);
        procedure_part(a,f,pivot);printf("[%d]",pivot);procedure_part(a,pivot+1,n+1);
        
        quicksort(a,f,pivot-1);
        quicksort(a,pivot+1,n);
        
    }
}

int partition(int p[] ,int f , int n)
{
    int pivot = p[n];

    int i=f;        //pointer for compare
    int j= i-1;     //pointer for swaping

    for ( i ; i < n; i++)
    {
        if (p[i] <= pivot)
        {
            j++;
            swap(&p[j],&p[i]);  //swaping lesser to its place
        }
        
    }

    swap(&p[j+1],&p[n]);    //placing pivot at right place
    
    return (j+1);
}


void swap(int *a,int *b)
{
    int temp = *a ;
    *a = *b;
    *b = temp;
}




//          INSERTION SORT ALGO STARTS HERE......


void insertion(int a[],int n)
{
    int key,j;
    for (int i = 0; i < n; i++)
    {
        key = a[i];
        j = i-1;

        while (j>=0 && key<=a[j])
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1]= key;
    printf("\nNew array after insertion %d",i);
    procedure(a,n);
    }
    
}

void printarray(int a[],int n)
{
    printf("Sorted Array is:\t[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d,",a[i]);
    }
    printf(" ]   ");
    Sleep(1000);
}

void loader()
{
    printf("\nLoading [");
    for (int d = 0; d < 50; d++)
    {
        Sleep(100);
        printf(":");
    }
    printf("]\n\n");
}
void procedure(int a[],int n)
{
    printf(" is:[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d,",a[i]);
    }
    printf(" ]   ");
    Sleep(100);

}
void procedure_part(int a[],int f,int n)
{
    printf("[ ");
    for (int i = f; i < n; i++)
    {
        printf("%d,",a[i]);
    }
    printf(" ]");
    Sleep(100);

}