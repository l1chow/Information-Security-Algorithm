#include <stdio.h>
#include <math.h>
#define MAX 100

int sieve (int n)
{
	int prime[n+1];
	for(int i=0; i<n+1; i++)
		prime[i] = 1;
	prime[0] = prime[1] = 0;
	for(int i=2; i<=sqrt(n); i++)
	{
		for(int j=i*i; j<=n; j+=i)
			prime[j] = 0;
	}
	int cnt = 0;
	for(int i=2; i<=n; i++)
	{
		if(prime[i] == 1)
			cnt++;	
	}
	return cnt;
}

int main()
{
	int n;
	scanf("%d", &n);
	
	printf("%d", sieve(n));

	return 0;
}

