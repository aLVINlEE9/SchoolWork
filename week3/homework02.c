#include<stdlib.h>
#include<stdio.h>

int g_ret[26];

int main()
{
	int i = 0;
	int sum = 0;
	float avg = 0;
	while(i++ < 25)
		g_ret[i] = rand() % 100 + 1;
	i = 0;
	while(i++ < 25)
		sum += g_ret[i];
	avg = (float)sum / 25;
	i = 0;
	int rec = 0;
	float close = abs(avg - g_ret[0]);
	while(i++ < 25)
		if(abs(avg - g_ret[i]) < close)
		{
			close = abs(avg - g_ret[i]);
			rec = i;
		}
	printf("\n%d %f %d", sum, avg, g_ret[rec]);
}
