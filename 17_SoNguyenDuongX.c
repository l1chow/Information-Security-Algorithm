#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100

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

int solve(int a, int b, int c)
{
	int x = 1;
	while(1)
	{
		long long y = a*x*x + b*x + c;
		if(isPrime(y))
			return x;	
		else
			x++;
	}
}

int main()
{
	int A, B, C;
	printf("Nhap A = ");
	scanf("%d", &A);
	printf("Nhap B = ");
	scanf("%d", &B);
	printf("Nhap C = ");
	scanf("%d", &C);
	printf("Xmin = %d\n", solve(A, B, C));

	return 0;
}

