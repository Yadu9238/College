#include<stdio.h>
#include<math.h>
#include<time.h>
#define size 150000
int h[size];

void heapify(int h[],int n)
{
	int i,j,n1,k,heap,v;
	n1=n;
	for(i=n1/2;i>=1;i--)
	{
	  k=i;
	  v=h[k];
	  heap=0;
	  while(!(heap)&&(2*k)<=n1)
	  {
	    j=2*k;
  	    if(j<n1)
             if(h[j]<h[j+1])
              j=j+1;
   	 
	    if(v>=h[j])
    		 heap=1;
            else
    	    {
		    h[k]=h[j];
		    k=j;
	    }
	    h[k]=v;
	  }
	}
}

void main()
{

	int i,n,size,t,bool arr[size]={0};;
	clock_t start,end;
	double totaltime;
	
	printf("enter value of array size\n");
	scanf("%d",&n);
	
	printf("enter array elements\n");
	
	srand(time(0));	

	for(i=0;i<n;i++)
	{	h[i]=rand()%140000+1;
		if(!arr[h[i]])
			{arr[h[i]]=1;
				count++;}
		else
			i--;
		
	}

	
	printf("Array elements before sorting\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",h[i]);
	}	
	
	start=clock();
	
	heapify(h,n);
	
	printf("Array elements in heap:\n");
	
	for(i=1;i<=n;i++)
		printf("%d\t",h[i]);
	
	for(i=n;i>=1;i--)
	{
		t=h[1];
		h[1]=h[i];
		h[i]=t;
		size=i-1;
		heapify(h,size);
	}
	
	end=clock();
	
	printf("Elements after sorting\n");
	
	for(i=1;i<=n;i++)
	printf("%d\t",h[i]);
	
	totaltime=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Total numbers in array=%d",n)
	printf("\n\ntime taken is %e",totaltime);
}
