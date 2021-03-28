int atoi(char *str)
{
	int sign = 1;
	int ret = 0;
	while((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if(*str == '-' || *str == '+')
	{
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

void sort_num(int *i, int *j, int *k)
{
	int n, m;
	int arr[3] = {*i, *j, *k};
	for(n = 0; n < 3; n++)
	{
		for(m = 0; m < 3 - n - 1; m++)
		{
			if(arr[m] > arr[m + 1])
			{
				int temp;
				temp = arr[m];
				arr[m] = arr[m + 1];
				arr[m + 1] = temp;
			}
		}
	}
	*i = arr[0];
	*j = arr[1];
	*k = arr[2];
	return ;
}

//#include<stdio.h>
#include<unistd.h>

int main(int argc, char **argv)
{
	if(argc == 4)
	{
		int i, j, k;
		i = atoi(argv[1]);
		j = atoi(argv[2]);
		k = atoi(argv[3]);
		sort_num(&i, &j, &k);
		write(1, "all integer inputs were swapped in order\n", 41);
		//printf("%d %d %d\n", i, j, k);
		return 0;
	}
	write(1, "error\n", 6);
	return 0;
}
