#include <stdio.h>
#include <math.h>
#define MAX 100

int isQPrime (int n)
{
	int cnt = 0;
	for(int i=1; i<=n; i++)
	{
		if(n % i == 0)
			cnt++;
	}
	if(cnt == 4)
		return 1;
	else
		return 0;
}

int main()
{
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	int flag = 0;
	for(int i=1; i<=n; i++)
	{
		if(isQPrime(i))
		{
			flag = 1;
			printf("%d ", i);
		}
	}
	if(flag == 0)
		printf("No");

	return 0;
}

