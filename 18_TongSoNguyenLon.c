#include <stdio.h>
#include <math.h>
#define MAX 1000

long long w = 8;

void printArray (long long a[], long long t)
{
	printf("[");
	for(long long i=t-1; i>=0; i--)
	{
		printf("%lld", a[i]);
		if(i != 0)
			printf(", ");		
	}
	printf("]");
}

void numberToArray(long long A[], long long t, long long n)
{
	for (long long i=t-1; i>=0; i--)
	{
		A[i] = n / pow(2, i*w);
		n %= (long long)pow(2, i*w);
	}
}

long long arrayToNumber(long long A[], long long t)
{
	long long n = 0;
	for (long long i=t-1; i>=0; i--)
	{
		n += A[i]*pow(2, i*w);
	}
	return n;
} 

void multiprecision_addition(long long A[], long long B[], long long t)
{
	long long C[t], e = 0;
	for(long long i=0; i<=t-1; i++)
	{
		C[i] = A[i] + B[i] + e;
		if(C[i] >= pow(2, w))
		{
			C[i] %= (long long)pow(2, w);
			e = 1;
		}
		else
			e = 0;
	}
	printf("\nA + B = (%lld, ", e);
	printArray(C, t);
	printf(")");
	printf("\nA + B = %lld", arrayToNumber(C, t));
}

int main()
{	
	long long p;
	printf("Nhap truong Fp: ");
	scanf("%lld", &p);	
	long long m = ceil(log2(p)); 
	long long t = ceil((float)m/w);
	
	long long a, b, A[t], B[t];
	printf("Nhap 2 so nguyen: ");
	scanf("%lld%lld", &a, &b);
	
	numberToArray(A, t, a);
	printf("A = ");
	printArray(A, t);
	
	numberToArray(B, t, b);	
	printf("\nB = ");
	printArray(B, t);
	
	multiprecision_addition(A, B, t);	
	
	return 0;
}

