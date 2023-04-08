#include <stdio.h>
#include <math.h>
#define true 1
#define false 0

int tongUoc(int n)
{
	int sum = 0;
	for(int i=1; i<=n/2; i++)
	{
		if(n % i == 0)
		{
			sum += i;
		}
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d", &n);
	
	printf("Cap so than thiet la\n");
	for(int i=1; i<n; i++)
	{
		int x = tongUoc(i);
		if(x > i && x < n && tongUoc(x) == i)
			printf("%d %d\n", i, x);
	}

	return 0;
}

