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
		ret += (sign * (*str++ - '0'));
	}
	return ret;
}

void itoa(int num)
{
	if(num == -2147483648)
		write(1, "-2147483648", 11);
	if(num == 0)
		return ;
	if(num < 0)
	{
		num *= -1;
		write(1, "-", 1);
	}
	itoa(num / 10);
	num %= 10;
	char c = '0' + num;
	write(1, &c, 1);
}

int is_valid_arg(char *str)
{
	while(*str)
	{
		if(!(*str >= '0' && *str <= '9'))
			return 0;
		str++;
	}
	return 1;
}

int main(int argc, char **argv)
{
	if(argc == 4)
	{
		int i = 1;
		while(i < argc)
		{
			if(!is_valid_arg(argv[i]))
			{	
				write(2, "execption occured : arguments are not valid", 43);
				return 0;
			}
			i++;
		}
		int num1 = atoi(argv[1]);
		int num2 = atoi(argv[2]);
		int num3 = atoi(argv[3]);
		int max = (num1 > num2) ? num1 : num2;
		max = (max > num3) ? max : num3;
		int min = (num1 > num2) ? num2 : num1;
		min = (min > num3) ? num3 : min;
		if(max == 0)
			write(1, "0", 1);
		itoa(max);
		write(1, "\n", 1);
		if(min == 0)
			write(1, "0", 1);
		itoa(min);
		write(1, "\n", 1);
		return 0;
	}
	write(2, "execption : only 3 arguments needed", 35);
}
