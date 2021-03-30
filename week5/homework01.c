#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# define row 10
# define col 10
# define r_ch 0
# define c_ch 1

void print(int *arr, int (*arr_d)[row], char *str, int check)
{
	printf("-----------%s-----------\n\n", str);
	if(check == c_ch)
	{
		for(int i = 0; i < 10; i++)
		{
			printf("%2d ", arr[i]);
		}
		printf("\n------------------------------\n\n");
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < col; j++)
			{
				printf("%2d ", arr_d[i][j]);
			}
			printf("\n");
		}
	}
	else if(check == r_ch)
	{
		for(int i = 0; i < 10; i++)
		{
			printf("%2d   |", arr[i]);
			for(int j = 0; j < 10; j++)
			{
				printf("%2d ", arr_d[i][j]);
			}
			printf("\n");
		}
	}
	printf("\n\n\n");
}

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
	
	printf("-----------printing 10 x 10 matrix-----------\n\n");
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
	printf("\n>sum : %d\n", sum); // print sum
	print(arr_c, arr_d, "printing_column_sum", c_ch);
	print(arr_r, arr_d, "printing_row_sum", r_ch);
	printf(">sum_diag : %d\n\n\n", sum_diag); // print diag sum
}
