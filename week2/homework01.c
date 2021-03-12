#include<unistd.h>

int atoi(char *str)
{
	int sign = 1;
	int ret = 0;
	while(*str == '\f' || *str == '\n' || *str == '\r' || *str == '\t' || *str == '\v' || *str == ' ')
		str++;
	if(*str == '-' || *str == '+')
	{
		if(*str == '-')
			sign *= -1;
		if(*(str + 1) < '0' || *(str + 1) > '9')
			return 0;
		str++;
	}
	while(*str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret += (sign *(*str++ - '0'));
	}
	return ret;
}

void print_rec(int num, int x)
{
	if(num == 0)
		return ;
	print_rec(num / x, x);
	num %= x;
	unsigned char c;
	if(x == 16)
	{
		if(num >= 10)
			c = num - 10 + 'A';
		else
			c = num + '0';
	}
	else
		c = num + '0';
	write(1, &c, 1);
}

void print(int num1, int num2, int x)
{
	print_rec(num1, x);
	write(1, " + ", 3);
	print_rec(num2, x);
	int sum = num1 + num2;
	write(1, " = ", 3);
	print_rec(sum, x);
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	int num1;
	int num2;
	if(argc == 3)
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
		if(num1 <= 0 || num2 <= 0)
		{
			write(2, "execption occured : arguments are not valid", 43);
			return 0;
		}
		print(num1, num2, 2);
		print(num1, num2, 10);
		print(num1, num2, 8);
		print(num1, num2, 16);
		return 0;
	}
	write(2, "execption : only 2 arguments needed", 35);
	return 0;
}
