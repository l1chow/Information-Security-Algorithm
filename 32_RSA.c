#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define true 1
#define false 0

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

int isPrime(int n)
{
	if(n<2)
		return false;
	for(int i=2; i<=sqrt(n); i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

int inverse(int a, int b)
{
	int z = b;
	int x1, x2, y1, y2;
	x1 = 0, x2 = 1, y1 = 1, y2 = 0;
	int q, r, x, y;
	while(b>0)
	{
		q = a/b;
		r = a - q*b;
		x = x2 - q*x1;
		y = y2 - q*y1;
		a = b;
		b = r;
		x2 = x1;
		x1 = x;
		y2 = y1;
		y1 = y;		
	}
	if(x2 < 0)
		return x2 + z;
	else
		return x2;
}

long long power(long long a, long long k, long long m)
{
	long long b = 1;
	long long A = a;
	if(k%2 == 1)
		b = a;
	k /= 2;
	while(k > 0)
	{
		A = (A*A) % m;
		if(k%2 == 1)
			b = (b*A) % m;
		k /= 2;
	}
	return b;
}

int main()
{
	srand(time(NULL));
	int p, q, n, phi, e, d, c, m;
	int sbd;
	printf("Nhap SBD: ");
	scanf("%d", &sbd);
	
	do
	{
		system("cls");		
		printf("So bao danh: %d", sbd);
		while(1)
		{
			p = rand() % (499 - 101 + 1) + 101;
			q = rand() % (499 - 101 + 1) + 101;
			if(isPrime(p) && isPrime(q) && p != q)
				break;
		}
		printf("\np = %d, q = %d\n", p, q);
		
		n = p * q;
		phi = (p - 1) * (q - 1);
		while(1)
		{
			e = rand() % ((phi-1) - 2 + 1) + 2;
			if(gcd(e, phi) == 1)
				break;
		}
		printf("n = %d, phi = %d, e = %d\n", n, phi, e);
		
		d = inverse(e, phi);
		printf("d = %d^-1 mod %d = %d\n", e, phi, d);	
		
		m = sbd + 123;	
	} 
	while (n < m);
		
	c = power(m, e, n);
	printf("Encrypt: c = %d\n", c);
	printf("Decrypt: m = %d\n", power(c, d, n));

	return 0;
}

