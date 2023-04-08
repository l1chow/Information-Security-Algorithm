#include <stdio.h>
#include <math.h>
#define MAX 10001

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

void solve(int a, int b)
{
	int s1[MAX], s2[MAX]; 
	int cnt=0;
	for(int i=1; i<=sqrt(b); i++)
	{
		s1[i] = i*i;
		s2[i] = i*i;
	}
	for(int i=a; i<=b; i++)
	{
		if(isPrime(i))
		{
			for(int j=0; j<=sqrt(b); j++)
			{
				for(int k=j+1; k<=sqrt(b); k++)
				{
					if(s1[j] + s2[k] == i)
					{
						printf("%d = %d + %d\n", i, s1[j], s2[k]);
						cnt++;
					}
				}
			}
		}
	}
	printf("%d", cnt);
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	solve(a, b);

	return 0;
}

