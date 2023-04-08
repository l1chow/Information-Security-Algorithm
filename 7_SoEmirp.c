#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100

int isPrime (int n)
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

int reverse (int n)
{
	int rev = 0;
	while (n != 0)
	{
		int r = n % 10;	
		rev = rev * 10 + r;
		n /= 10;
	}
	return rev;
}

int main()
{
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	int cnt = 0;
	for(int i=0; i<n; i++)
	{
		if(isPrime(i) && isPrime(reverse(i)))
		{
			printf("%d ", i);
			cnt++;
		}		
	}
	printf("\n%d\n", cnt);
	
	return 0;
}

