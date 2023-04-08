#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int power(int a, int k, int m)
{
	int b = 1;
	long long A = a;
	if(k % 2 == 1)
		b = a;
	k /= 2;
	while(k > 0)
	{
		A = (A * A) % m;
		if(k % 2 == 1)
			b = (b * A) % m;
		k /= 2;
	}
	return b;
}

int millerRabinTest(int n, int t)
{
	srand(time(0));	
	int s = 0, r, a;
	long long y;
	
	if(n < 2)
		return 0;
	if(n == 2 || n == 3)
		return 1;
		
	r = n-1;
	while(r % 2 == 0)
	{
		s++;
		r /= 2;
	}
	
	while(t--)
	{
		a = rand() % (n - 3) + 2;	
		y = power(a, r, n);
		
		if(y != 1 && y != n-1)
		{
			int j = 1;
			while(j <= s-1 && y != n-1)
			{
				y = y * y % n;
				if(y == 1)
					return 0;
				j++;
			}
			if(y != n-1)
				return 0;
		}		
	}	
	return 1;		
}

int main()
{
	int n, t;
	printf("Nhap n = ");
	scanf("%d", &n);
	printf("Nhap so lan lap t = ");
	scanf("%d", &t);
	
	printf("\nTheo thuat toan Miller Rabin");
	if(millerRabinTest(n, t))
	{
		printf("\n%d la so nguyen to\n", n);
		printf("Do chinh xac la: %f\n", 1 - pow(0.25, t));
	}		
	else
		printf("\n%d la hop so\n", n);


	return 0;
}

