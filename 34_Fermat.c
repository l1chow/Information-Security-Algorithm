#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 100
// Thuat toan sai khi gap so Carmichael

long long gcd (long long a, long long b)
{
	while(b != 0)
	{
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long power(long long a, long long k, long long m)
{
	long long b = 1;
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

long long fermatTest(long long n, long long t)
{
	long long a;
	if(n <= 1 || n == 4)
		return 0;
	if(n <= 3)
		return 1;
	while(t--)
	{
		a = rand() % (n - 3) + 2; 	// 2 <= a <= n-2
		if(gcd(a, n) != 1)
			return 0;
		else if(power(a, n - 1, n) != 1)
			return 0;
		else
			return 1;		
	}
}

int main()
{
	long long n, t;
	printf("Nhap n = ");
	scanf("%lld", &n);

	printf("Nhap so lan lap t = ");
	scanf("%lld", &t);
	
	if(fermatTest(n, t))
		printf("%lld la so nguyen to\n", n);
	else
		printf("%lld la hop so\n", n);

	return 0;
}

