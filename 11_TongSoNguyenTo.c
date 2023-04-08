#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100

long long sieve (long long n)
{
	long long prime[n+1];
	for(long long i=0; i<n+1; i++)
		prime[i] = 1;
	prime[0] = prime[1] = 0;
	for(long long i=2; i<=sqrt(n); i++)
	{
		for(long long j=i*i; j<=n; j+=i)
			prime[j] = 0;
	}
	long long sum = 0;
	for(long long i=2; i<=n; i++)
	{
		if(prime[i] == 1)
			sum += i;	
	}
	return sum;
}

int main()
{
	long long n;
	scanf("%lld", &n);
	
	printf("%lld", sieve(n));

	return 0;
}

