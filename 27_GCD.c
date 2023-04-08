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

int gcd(int a, int b)
{
	while(b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int a, b;
	do
	{
		printf("Nhap 2 so: ");
		scanf("%d%d", &a, &b);
	}
	while(a<=0 || b>=1000);
	for(int i=a; i<=b; i++)
	{
		for(int j=i+1; j<=b; j++)
		{
			if(isPrime(gcd(i,j)))
			{
				printf("GCD (%d, %d) = %d\n", i, j, gcd(i,j));
			}				
		}
	}


	return 0;
}

