#include<stdio.h>

void readnum(int a[],int n)
{ 
  int i;
  printf("Enter %d numbers:",n);
  for(i=0;i<n;i++)
    scanf("%d/n",&a[i]);
}

void selectsort(int a[],int n)
{
  int i,j,temp,minpos;
  for(i=0;i<n-1;i++)
  {
    minpos=i;
    for(j=1;j<n;j++)
    {
      if(a[j]<a[minpos])
        minpos=j;
    }
    if(minpos!=i)
      {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }

    }
  }

  void main()
 {
  int a[50],n,i;
  printf("Enter the array size:");
  scanf("%d",&n);
  readnum(a,n);
  selectsort(a,n);
  printf("Sorted array is:");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
 }