#include <stdio.h>
#include <math.h>

void solve (long long a, long long b)
{
	int flag = 0;
	for(long long i=a; i<=b; i++)
	{
		for(int j=2; j<=sqrt(b); j++)
		{
			if(i % j == 0)
			{
				flag = 0;
				break;
			}
			else
				flag = 1;
		}
		if(flag == 1)
			printf("%lld ", i);
	}
}

int main()
{
	long long n;
	printf("Nhap n = ");
	scanf("%lld", &n);
	
	long long a = pow(10, n - 1);
	long long b = pow(10, n) - 1;
	
	solve (a, b);
	
	return 0;
}

