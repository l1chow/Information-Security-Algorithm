#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define true 1
#define false 0
#define MAX 1000

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

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i=2; i<=n-2; i++)
    {
        if(isPrime(i) && isPrime(i + 2)) 
			printf("%d %d\n", i, i + 2);
    }

	return 0;
}

