#include<stdio.h>

void readnum(int a[],int n)
{ 
  int i;
  printf("Enter %d numbers:",n);
  for(i=0;i<n;i++)
    scanf("%d/n",&a[i]);
}

int linsearch(int a[],int n,int elem)
{ 
	int i;
	for(i=0;i<n;i++)
	{ if(a[i]==elem)
	    return i;
	}
	return -1;
}

void main()
{
	int a[50],n,elem,res;
	printf("Enter the array size:");
	scanf("%d",&n);
	readnum(a,n);
	printf("Enter the element to be searched:");
	scanf("%d",&elem);
	res=linsearch(a,n,elem);
  if(res==-1)
    printf("Element not found");
  else
    printf("Element found at index %d",res);
}