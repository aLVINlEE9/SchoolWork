#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# define row 10
# define col 10

int main()
{
	int arr_d[row][col];
	int arr_c[col];
	int arr_r[row];
	memset(arr_c, 0, sizeof(arr_c[0]) * col);// set arr_c to 0
	memset(arr_r, 0, sizeof(arr_r[0]) * col);// set arr_r to 0
	int sum = 0;
	int sum_util; // sum of each row
	int sum_diag = 0;
	for(int i = 0; i < row; i++)
	{
		sum_util = 0;
		for(int j = 0; j < col; j++)
		{
			arr_d[i][j] = rand() % 10 + 1;// random (1~10)
			printf("%2d  ", arr_d[i][j]);
			sum_util += arr_d[i][j];// add all element of j row
			arr_c[j] += arr_d[i][j];// add and put each elements of j columns in arr_c
			if(i == j)
				sum_diag += arr_d[i][j];// add diag elements
		}
		arr_r[i] = sum_util;// put each elements of i rows sum in arr_r
		sum += sum_util;
		printf("\n");
	}
	printf("\nsum : %d\n", sum); // print sum
	for(int i = 0; i < 10; i++)
	{
		printf("%d ", arr_c[i]); // print column sum
	}
	printf("\n\n");
	for(int i = 0; i < 10; i++)
	{
		printf("%d\n", arr_r[i]); // print row sum
	}
	printf("\n%d", sum_diag); // print diag sum
}
