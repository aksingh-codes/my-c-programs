#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<math.h>
#define MAX 11 
#define minus_infinity -999999

void BUILD_HEAP(int*);
void MAX_HEAPIFY(int *,int);
void exchange(int *a ,int *b);
void printarray(int * ,int);
void print_heap(int *,int);
int search(int *,int );
int heap_extract_max(int *);
void heap_increase_key(int*,int ,int);
void heap_insert_key(int* ,int);
void heap_sort(int *);

int heap_size;

int main()
{
  int arr1[MAX] = {1,5,6,8,12,14,16};
  double asehi = 7;
  //printf("%f\n", log(asehi));
  int n = 7;
  heap_size = n-1;
  
  
  BUILD_HEAP(arr1);
  //print_heap(arr1,heap_size+1);
  int e = heap_extract_max(arr1);
  
  heap_increase_key(arr1,4,300);
  heap_insert_key(arr1,200);
  
  printf("heap sort:");
  heap_sort(arr1);
  printarray(arr1,heap_size);
  scanf("%d",&asehi);
  

}


void BUILD_HEAP(int a[])
{
    
    for (int i = (heap_size/2) ; i >=  0 ; i--)
    {
      
      MAX_HEAPIFY(a,i);
     
      
    }
    
}

void MAX_HEAPIFY(int a[],int i)
{
  
  int l = 2*i+1;                    //  left and right child
  int r = 2*i+2;
  int largest;

  
  if (l<=heap_size && a[l]>a[i])
  {
    largest = l;
  }
  else
  {
    largest = i;
  }
  

  if (r<=heap_size && a[r]>a[largest])
  {
    largest = r;
  }
  
  if(largest != i)
  {
    exchange(&a[largest],&a[i]);
  	MAX_HEAPIFY(a,largest);
  }
  


  
}

void exchange(int *a ,int *b)
{
  
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
 
}

void printarray(int a[],int n)
{
    printf("\nNow Heap is:\t[ ");
    for (int i = 0; i <= n; i++)
    {
        printf("%d,",a[i]);
    }
    printf(" ]   ");
}

int heap_extract_max(int a[])
{
    exchange(&a[0],&a[heap_size]);
    heap_size = heap_size-1;
    
    MAX_HEAPIFY(a,0);
    
    return a[heap_size+1];//as if it is present

}

void heap_increase_key(int a[],int i,int key)
{
    if(key<a[i])
    {
      printf("error");
    }
    else
    {
      a[i]=key;
      while (i>0&&a[i/2]<a[i])
      {
        exchange(&a[i/2],&a[i]);
        i=i/2;
      }
      
    }
    
}

void heap_insert_key(int a[],int key)
{
    if (heap_size > MAX-1)
    {
      printf("overflow");
    }
    else
    {
      heap_size++;
      //a[heap_size] = key;
      a[heap_size] = minus_infinity;
      heap_increase_key(a,heap_size,key);
    }
    
    
}

void heap_sort(int a[])
{
  int temp1 = heap_size;
  printf("%d",heap_size);
  printarray(a,heap_size);
  while (heap_size>=0)
  {
    exchange(&a[0],&a[heap_size]);
    heap_size--;
    MAX_HEAPIFY(a,0);
    if(heap_size>=0)
    {printarray(a,heap_size);}
  }
  heap_size = temp1;
  

}
















void print_heap(int a[],int n)    ///print heap
{
  printf("\n");
  char str[] = " [][][][][]  ";
  int arr_indx = 0;
  double val = n;
 
  double val1 = log(val)+1;
  
  int h = (int)val1;
  

  
  
  int x = pow(2,h);

  int row = x +x-1;
  int col = h;
  int mid_no = 1;
  
  while (arr_indx<n)
  {
  		for (int i = 0; i <= row; i++)
  		{
            int arr_mids[mid_no];
          	int m = mid_no+1;
          	 
            for (int k = 0; k < mid_no; k++)
          	  m=m/2;
          	for (int l = 0; l < mid_no; l++)
            	arr_mids[l] = l + m;
          	printarray(arr_mids,mid_no);
            
            for (int j = 0; j < col; j++)
  			    {
  				    if (search(arr_mids,j))
         			{
                   if (i%2==0)
         			      {
         				      printf("%d",a[arr_indx]);
              		    arr_indx++;
         			      }
         			      else
                     {
                       if (j < mid_no/2)
            		          printf("/");
            			     else
            			        printf("\\");
                     }
              }
         		  else
         		    printf("%s",str);
         		}
  	  mid_no++;
    	printf("\n");
  		}
  }
  
}

int search(int a[],int x)
{
  int n = heap_size;
  for (int i = 0; i <= n; i++)
  {
    if (a[i]==x)
    {
      return 1;
    }
    
  }
  return 0;
} 


