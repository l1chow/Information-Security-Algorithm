#include <stdio.h>
#include <math.h>

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

int isSuperPrime(int n)
{
	int cnt = 0;
	for(int i=1; i<n; i++)
	{
		if(isPrime(i))
			cnt++;
	}
	if(isPrime(cnt))
		return 1;
	return 0;
}

int main()
{
	int a,b;
	printf("Nhap khoang [a, b]: ");
	scanf("%d%d", &a, &b);
	int cnt = 0;
	for(int i=a; i<=b; i++)
	{
		if(isSuperPrime(i))
		{
			printf("%d  ", i);
			cnt++;
		}			
	}
	printf("\n%d", cnt);

	return 0;
}

