#include <stdio.h>
#include <math.h>
#define MAX 1001

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

int main()
{
	int n;
	scanf("%d", &n);
	int a[MAX];
	int index = 0;
	for(int i=2; i<=n; i++)
	{
		if(isPrime(i))
			a[index++] = i;
	}

	for(int i=0; i<index-3; i++)
	{
		int s = a[i] + a[i+1] + a[i+2] + a[i+3];
		if(s <= n && isPrime(s))
			printf("%d %d %d %d\n", a[i], a[i+1], a[i+2], a[i+3]);
	}

	return 0;
}

