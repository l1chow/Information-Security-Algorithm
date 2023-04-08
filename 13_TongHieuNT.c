#include <stdio.h>
#include <math.h>
#define true 1
#define false 0
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

int main()
{
	int n;
	scanf("%d", &n);
	int index = 0, a[MAX];
	for(int i=2; i<=n; i++)
	{
		if(isPrime(i))
			a[index++] = i;
	}
	
	for(int i=0; i<index; i++)
	{
		for(int j=i+1; j<=index-1; j++)	
		{
			int tong = a[i] + a[j];
			int hieu = a[j] - a[i];
			if(isPrime(tong) == 1 && isPrime(hieu) == 1)
			{
				printf("%d %d\n", a[i], a[j]);
			}					
		}											
	}

	return 0;
}

