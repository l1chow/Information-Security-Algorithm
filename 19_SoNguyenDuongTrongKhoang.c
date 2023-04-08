#include <stdio.h>
#include <math.h>
#define true 1
#define false 0
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

void solve(int a, int b, int c, int m, int l)
{
	for(int x=m; x<=l ; x++)
	{
		long long y = a*x*x + b*x + c;
		if(isPrime(y))
			printf("%d\t", x);
	}
}

int main()
{
	int A, B, C, m, l;
	printf("Nhap khoang [m, l]: ");
	scanf("%d%d", &m, &l);
	printf("Nhap A = ");
	scanf("%d", &A);
	printf("Nhap B = ");
	scanf("%d", &B);
	printf("Nhap C = ");
	scanf("%d", &C);
	solve(A, B, C, m, l);
	
	return 0;
}

