#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10001

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

int millerRabinTest(int n)
{
	srand(time(0));	
	int s = 0, r, a, t=10;
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

long long nearestPrime(long long msv)
{
	long long min, max;
	if(msv == 2)
        min = 0;
    else if(msv == 1)
    	min = -1;
    else
    {
    	for(long long i=msv-1; i>=0; i--)
	    {
	        if(millerRabinTest(i))
	        {
	            min = i;
	            break;
	        }
	    }
    }
    for(long long i=msv+1; ; i++)
    {
        if(millerRabinTest(i)==1)
        {
            max = i;
            break;
        }
    }
    
    if(msv - min <= max - msv)
    	return min;
    else
    	return max;
}

int main()
{
	long long sbd, msv, min, max;	
	printf("Nhap MSV: ");
	scanf("%lld", &msv);
	printf("Nhap SBD: ");
	scanf("%lld", &sbd);
	

	printf("%lld", power(sbd, nearestPrime(msv), 123456));
	
	return 0;
}

