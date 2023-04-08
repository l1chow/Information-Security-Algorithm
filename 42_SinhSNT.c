#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 10001

int isPrime(int n)
{
	if(n < 2)
		return 0;
	for(int i=2; i<=sqrt(n); i++)
	{
		if(n % i == 0)
			return 0;
	}
	return 1;
}

void randomNumber(long long *p, long long *q)
{
	srand(time(0));
	*p = rand() % (999 - 1 + 1) + 1;
	*q = rand() % (999 - 1 + 1) + 1;
	printf("Random: p = %lld, q = %lld\n", *p, *q);
}

long long power(long long a, long long k, long long m)
{	
	long long b = 1;
	long long A = a;
	if(k % 2 == 1)
		b = a;
	k /= 2;
	while(k > 0)
	{
		A = (A * A) % m;
		if(k % 2 == 1)
			b = (b * A) % m;
		k /= 2;
	}
	return b;
}

int main()
{
	long long p, q;
	randomNumber(&p, &q);
		
	for(long long i=1; i<100; i++)
	{
		if(isPrime(power(i, p, q)))
			printf("%lld ^ %lld mod %lld = %lld is prime\n", i, p, q, power(i, p, q));
	}

	return 0;
}

