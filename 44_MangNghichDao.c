#include <stdio.h>
#include <math.h>
#define MAX 10001

//euclide mo rong

void enterArray (long long A[], long long n)
{
	for(int i=0; i<n; i++)
	{
		printf("A[%d] = ", i);
		scanf("%lld", &A[i]);
	}			
}

int gcd (int a, int b)
{
	while(b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long inverse(long long a, long long b)
{
	long long tmp = b;
	long long x1, x2, y1, y2, q, r, x, y;
	x1 = 0, x2 = 1, y1 = 1, y2 = 0;

	while(b > 0)
	{
		q = a / b;
		r = a - q * b;
		x = x2 - q * x1;
		y = y2 - q * y1;
		a = b;
		b = r;
		x2 = x1;
		x1 = x;
		y2 = y1;
		y1 = y;		
	}
	if(x2 < 0)
		return x2 + tmp;
	else
		return x2;
}

int main()
{
	long long a[MAX], n, p;	
	printf("Nhap truong Fp: ");
	scanf("%lld", &p);
	printf("Nhap so phan tu cua mang: ");
	scanf("%lld", &n);
	printf("Nhap cac phan tu cua mang: \n");
	enterArray(a, n);
	
	printf("Mang B nghich dao cua A:\n");
	for(int i=0; i<n; i++)
	{
		if(gcd(a[i], p) != 1)
			printf("A[%d] khong ton tai gia tri nghich dao\n", i);
		else
			printf("A[%d]^1 = %lld^1 = %lld\n", i, a[i], inverse(a[i], p));	
	}
	
	return 0;
}

