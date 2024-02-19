#include<stdio.h>

void readnum(int a[],int n)
{ 
  int i;
  printf("Enter %d numbers:",n);
  for(i=0;i<n;i++)
    scanf("%d/n",&a[i]);
}

void insertsort(int a[],int n)
{
  int i,j,key;
  for(i=1;i<n;i++)
  {
    key=a[i];
    j=i-1;
    while(j>=0 && a[j]>key)
      {
        a[j+1]=a[j];
        j=j-1;
      }
    a[j+1]=key;
  }
}

void main()
{
  int a[50],n,i;
  printf("Enter the array size:");
  scanf("%d",&n);
  readnum(a,n);
  insertsort(a,n);
  printf("Sorted array is:");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
}