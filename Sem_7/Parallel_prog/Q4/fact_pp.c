#include<stdio.h>
#include<omp.h>

void main()
{
	int fact1 = 1, fact2 = 1, a, i;
	
	printf("Enter a number to check its factorial\n");
	scanf("%d", &a);
	
	#pragma omp parallel for firstprivate(a)
	for(i = 2; i <= a; i++)
		fact1 = fact1 * i;
		
		
	printf("When first private is not used\n");
	printf("Factorial of %d is %d \n",a,fact1);
	
	
	#pragma omp parallel for firstprivate(a,fact2)
	for(i = 2; i <= a; i++)
		fact2 = fact2 * i;
		
	printf("When first private is used\n");
	printf("Factorial of %d is %d \n",a ,fact2);
}
