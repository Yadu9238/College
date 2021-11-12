#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<math.h>


int *prime_table(int num){

	int i,j,p,prime,*primes;
	primes = (int*)malloc(num*sizeof(int));
	i = 2;p = 0;
	
	while(p  < num ){
		prime = 1;	
		for(j = 2; j < i;j++)
		{
			if(i%j == 0){
				prime = 0;
				break;
			}
		}
		
		if(prime){
			primes[p] = i;
			p  = p + 1;
		}
		i = i + 1;
	}

	return primes;
}



double *sine_table(int num){
	double a;
	int i,j;
	double pi = 3.14;
	double *sines;
	
	sines = (double*)malloc(num*sizeof(double));
	
	for(i = 0;i < num;i++)
	{
		sines[i] = 0.0;
		for(j = 0; j <= i; j++)
		{
			a = (double)(j)*pi/(double)(num-1);
			sines[i] = sines[i] + sin(a);
		}
	}
	
	return sines;
}



int main(){
	omp_set_nested(1);
	int size = 10;
	int i,x;
	for(i = 0;i < 5; i++)
	{
		printf("\n\n%d\t",size);
		for(x = 0;x < 4;x++)
		{
			double t1 = omp_get_wtime();
			#pragma omp parallel sections
			{
			omp_set_num_threads(2*x);
			#pragma omp section
			{
				int* a = (int*)malloc(size*sizeof(int));
				a = prime_table(size);
				
			}
			
			#pragma omp section
			{
				double* b = (double*)malloc(size*sizeof(double));
				b = sine_table(size);
			}
			}
			double t2 = omp_get_wtime();
			printf("%lf\n",t2-t1);
		}
		size = size * 10;
	}
	return 0;
}

