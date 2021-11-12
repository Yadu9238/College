#include<stdio.h>
#include<math.h>

int compute(long long int a ,long long int b,long long int n)
{
	if(b ==1)
		return a;
	else
		return (((long long int)pow(a,b))%n);
}

void main()
{
	long long int p = 18,g = 7;
	long long int a = 6,b = 15;
	long long int A,B,ka,kb;

	A = compute(g,a,p);
	printf("%lld\n",A );
	B = compute(g,b,p);
	printf("%lld\n",B );
	ka = compute(B,a,p);
	kb = compute(A,b,p);

	printf("Alice:%lld \nBob:%lld",ka,kb);
}