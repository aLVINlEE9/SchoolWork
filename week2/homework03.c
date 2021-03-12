#include<unistd.h>

int atoi(char *str)
{
	int sign = 1;
	int ret = 0;
	while(*str == '\f' || *str == '\n' || *str == '\r' || *str == '\t' || *str == '\v' || *str == ' ')
		str++;
	if(*str == '-' || *str == '+')
	{
		if(*(str + 1) < '0' || *(str + 1) > '9')
			return 0;
		if(*str == '-')
			sign *= -1;
		str++;
	}
	while(*str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret += (sign *(*str++ - '0'));
	}
	return ret;
}

int factorial(int n)
{
	if(n == 0)
		return 1;
	return (n * factorial(n - 1));
}

int sum(int n)
{
	if(n == 0)
		return 0;
	return (n + sum(n - 1));
}
#include<stdio.h>
int main(int argc, char **argv)
{
	if(argc == 3)
	{
		int n;
		n = atoi(argv[1]);
		if(n < 0)
		{
			write(2, "ERROR\n", 6);
			return 0;
		}
		if(*argv[2] == 'F')
		{
			int ret = factorial(n);
			printf("%d! = %d\n", n, ret);
		}
		else if(*argv[2] == 'S')
		{
			int ret = sum(n);
			printf("Sum of 1 to %d is %d\n", n, ret);
		}
		else
			write(2, "ERROR\n", 6);
		return 0;
	}
	write(2, "execption : only 2 arguments needed", 35);
	return 0;
}
