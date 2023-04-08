#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100

long long max(long long a, long long b)
{
	return a>b ? a:b;
}

void sieve(long long a, long long b)
{
	long long prime[b-a+1];
	for(long long i=0; i<b-a+1; i++)
		prime[i] = 1;
	for(long long i=2; i<=sqrt(b); i++)
	{
		for(long long j=max(i*i,(a+i-1)/i*i); j<=b; j+=i)
		{
			prime[j-a] = 0;
		}
	}
	long long sum = 0;
	for(long long i=max(a,2); i<=b; i++)
	{
		if(prime[i-a])
			sum += i;		
	}	
	printf("%lld", sum);
}

int main()
{
	long long a, b;
	scanf("%lld%lld", &a, &b);
	sieve(a, b);

	return 0;
}

