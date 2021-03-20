#include<unistd.h>
#include<stdio.h>

const float pie = 3.14;

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

void itoa(int num)
{
	if(num == 0)
		return ;
	itoa(num / 10);
	char c = num % 10 + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if(*argv[1] == 'r')
	{
		if(argc == 4)
		{
			write(1, "The area of the rectangle is ", 29);
			int n1 = atoi(argv[2]);
			int n2 = atoi(argv[3]);
			int ret = n1 * n2;
			itoa(ret);
			write(1, " square meters.\n", 16);
			return 0;
		}
		write(2, "error\n", 6);
	}
	else if(*argv[1] == 'c')
	{
		if(argc = 3)
		{
			int n1 = atoi(argv[2]);
			float ret = n1 * n1 * pie;
			printf("The area of the circle is %g square meters.", ret);
			return 0;
		}
		write(2, "error\n", 6);
	}
	else if(*argv[1] == 't')
	{
		if(argc == 4)
		{
			int n1 = atoi(argv[2]);
			int n2 = atoi(argv[3]);
			float ret = n1 * n2 / 2;
			printf("The area of the triangle is %g square meters.", ret);
			return 0;
		}
		write(2, "error\n", 6);
	}
}
