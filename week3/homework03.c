#include<stdio.h>

int atoi(char *str)
{
	int sign = 1;
	int ret = 0;
	while(*str == '\f' || *str == '\n' || *str == '\r' || *str == '\t' || *str == '\v' || *str == ' ')
		str++;
	if(*str == '-' || *str == '+')
	{
		if(*str = '-')
			sign *= -1;
		str++;
	}
	while(*str >= '0' && *str <= '9')
	{
	       ret *= 10;
	       ret += (sign *(*str - '0'));
	       str++;
	}
	return ret;
}
int main(int argc, char **argv)
{
	if(argc == 2)
	{
		int j = 0, i = 0;
		int n = atoi(argv[1]);
		if(!(n % 2))
			printf("Input is an even number. Assume the input was %d.\n", n += 1);
		n /= 2;
		for(i = 0; i < n; i++)
		{
			for(j = i; j < n; j++)
				printf(" ");
			for(j = 0; j < i + 1; j++)
				printf("*");
			for(j = 0; j < i; j++)
				printf("*");
			printf("\n");
		}
		for(i = 0; i < n + 1; i++)
		{
			for(j = 0; j < i; j++)
				printf(" ");
			for(j = i; j < n + 1; j++)
				printf("*");
			for(j = i; j < n; j++)
				printf("*");
			printf("\n");
		}
	}
}
