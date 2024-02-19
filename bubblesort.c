#include<stdio.h>

void readnum(int a[],int n)
{ 
  int i;
  printf("Enter %d numbers:",n);
  for(i=0;i<n;i++)
    scanf("%d/n",&a[i]);
}

void bubblesort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		
		  for(j=0;j<n-1;j++)
			{if(a[j+1]<a[j])
			  {
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			  }
		  }
	}
}

void main()
{
	int a[50],n,i;
	printf("Enter the array size:");
	scanf("%d",&n);
	readnum(a,n);
	bubblesort(a,n);
	printf("Sorted array is:");
	for(i=0;i<n;i++)
	  printf("%d ",a[i]);
}