#include<stdio.h>
# define N 5

int a[N];

int main()
{
	int *p;
	int *r;
	int i = -1;
	int sum = 0;
	while(i++ < N - 1)
	{
		printf("input : ");
		scanf("%d", &a[i]);
		sum += a[i];
	}
	printf("result : %d\n", sum);
	i = 0;
	r = p = a;
	r++;
	while(*r++)
	{
		*a *= 3;
		printf("%d\n", *a);
	}
	while(i++ < N)
		printf("%d ", p[i]);
	printf("\n");
	return 0;
}
