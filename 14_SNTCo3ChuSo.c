#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define true 1
#define false 0
#define MAX 1000

int reverse(int n)
{
	int rev = 0, r;
	while(n != 0)
	{
		r = n % 10;
		rev = rev * 10 + r;
		n /= 10;
	}
	return rev;
}

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

void isCubeNumber(int n)
{
	if(isPrime(n))
	{
		for(int i=5; i<=9; i++)		//STN ^3 len co 3cs chi trong khoang nay
		{
			if(i*i*i == reverse(n))
				printf("%d\n", n);
		}
	}
}

int main()
{
	for(int i=100; i<=999; i++)
	{
		isCubeNumber(i);
	}

	return 0;
}

