#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 10001

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
	int s = 0, r, a;
	long long y;
	
	if(n < 2)
		return 0;
	if(n == 2 || n == 3)
		return 1;
		
	r = n - 1;
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

void randomPrimeArray (int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		while(!millerRabinTest(a[i], 10))
			a[i] = rand(); 			
	}
}

void printArray (int a[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d  ", a[i]);
	printf("\n");
}

int min(int a, int b)
{
	return a<b ? a:b;
}

void getRange (int a[], int n)
{
	int MIN = a[0];
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
			MIN = min(abs(a[i] - a[j]), MIN);
	}
	printf("Khoang cach nho nhat: %d\n", MIN);
}

int main()
{
	int n, t, A[MAX];
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &n);
	
	srand(time(0));
	printf("Mang nguyen to ngau nhien\n");
	randomPrimeArray(A, n);
	printArray(A, n);

	getRange(A, n);
	
	return 0;
}

