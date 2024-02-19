#include<stdio.h>

void readnum(int a[],int n)
{ 
  int i;
  printf("Enter %d numbers:",n);
  for(i=0;i<n;i++)
    scanf("%d/n",&a[i]);
}

int binsearch(int a[],int n,int elem)
{
	int top=0,bot=n-1,mid;
	while(top<=bot)
	{
		mid=(top+bot)/2;
		if(elem==a[mid])
			return mid;
		else if(elem>a[mid])
			top=mid+1;
		else
			bot=mid-1;
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
	res=binsearch(a,n,elem);
    if(res!=-1)
      printf("Element found at index %d",res);
    else
      printf("Element not found");
}