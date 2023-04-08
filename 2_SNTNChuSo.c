#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max (int a, int b)
{
	return a>b ? a:b;
}

void sieve (int a, int b)
{
	int size = b - a + 1;
	int *prime = (int*) malloc(sizeof(int) * size);
	for(int i=0; i<b-a+1; i++)
		prime[i] = 1;
	for(int i=2; i<=sqrt(b); i++)
	{
		for(int j=max(i*i,(a+i-1)/i*i); j<=b; j+=i)
		{
			prime[j-a] = 0;
		}
	}
	for(int i=max(a,2); i<=b; i++)
	{
		if(prime[i-a])
			printf("%d ", i);
	}	
}

int main()
{
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	long long a = pow(10, n - 1);
	long long b = pow(10, n) - 1;
	
	sieve (a, b);
	
	return 0;
}

