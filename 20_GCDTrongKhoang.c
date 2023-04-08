#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define true 1
#define false 0
#define MAX 100

int gcd(int a, int b)
{
	while(b!=0)
	{
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

void solve(int a, int b, int d)
{
	for(int i=a; i<=b; i++)
	{
		for(int j=i+1; j<=b; j++)
		{
			if(gcd(i, j) == d)
				printf("%d %d\n", i, j);
		}
	}
}

int main()
{
	int M, N, D;
	printf("Nhap khoang (M, N): ");
	scanf("%d%d", &M, &N);
	printf("Nhap gia tri D: ");
	scanf("%d", &D);
	solve(M, N, D);

	return 0;
}

