#include<stdio.h>

# define N 5

int a[N];

int main()
{
	int *p = a;
	int i = -1;
	int sum = 0;
	while(i++ < N - 1)
	{
		printf("input : ");
		scanf("%d", &a[i]);
		sum += p[i];
	}
	printf("result : %d\n", sum);
	//printf("%d %d\n", *(p), *(a));
	i = -1;
	int *q = p;
	while(i++ < N - 1)
	{
		*p = *(a + i) = *p * 3;
		p++;
	}
	p = q;
	i = -1;
	while(i++ < N - 1)
		printf("%d ", p[i]);
	printf("\n");
	return 0;
}
