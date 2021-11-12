//sort elements using selection sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define size 150000
int selectsort(int a[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}

void main()
{
	int a[size],n,i;
	time_t start,end;
	bool arr[size]={0};
	int count=0;
	
	printf("Enter array size\n");
	scanf("%d",&n);

	printf("Enter array ele\n");

	srand(time(0));	
	for(i=0;i<n;i++)
	{	a[i]=rand()%140000+1;
		if(!arr[a[i]])
			{arr[a[i]]=1;count++;}
		else
			i--;
		
	}

	printf("Before sorting\n");
	for(i=0;i<n;i++)	
		printf("%d\t",a[i]);

	start=clock();
	selectsort(a,n);
	end=clock();

	printf("After sorting\n");
	for(i=0;i<n;i++)	
		printf("%d\n ",a[i]);
	
	double timet;
	timet=(double)(end-start)/CLOCKS_PER_SEC;

	printf("\nTime:%lf\n",timet);
	printf("\nNUmber:%d\n",count);
}
