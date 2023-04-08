#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100

int demUoc (int n)
{
	int cnt = 1;
	for(int i=1; i<=n/2; i++)
	{
		if(n % i == 0)
			cnt++;
	}
	return cnt;
}

int main()
{
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	int cnt = 0;
	for(int i=1; i<=n; i++)
	{
		if(demUoc(i) == 3)
		{
			cnt++;
			printf("%d ", i);
		}			
	}
	printf("\n%d\n", cnt);
	
	return 0;
}

