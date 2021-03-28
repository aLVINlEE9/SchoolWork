#include<unistd.h>
#include<stdlib.h>

char *strrev(char *str, int cnt)
{
	int i = -1;
	char *ret;
	char *rec;
	if(!(ret = malloc(sizeof(char) * (cnt + 1))))
		return NULL;
	while(*str++)
		;
	str -= 2;
	rec = ret;
	while(++i < cnt)
		*ret++ = *str--;
	ret[i] = 0;
	return rec;
}

void print_str(char *str)
{
	while(*str)
		write(1, str++, 1);
	write(1, "\n", 1);
	return ;
}

int main(int argc, char **argv)
{
	char *ret;
	if(argc == 2)
	{
		int cnt = 0;
		while(argv[1][cnt++])
			;
		if(cnt - 1 != 10)
		{
			write(2, "error\n", 6);
			return 0;
		}	
		ret = strrev(argv[1], cnt - 1);
		print_str(ret);
		free(ret);
		return 0;
	}
	write(2, "error\n", 6);
	return 0;
}
