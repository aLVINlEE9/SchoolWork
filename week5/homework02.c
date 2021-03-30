#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int mtx_size;

void set_matrix(int (*first_matrix)[mtx_size], int (*second_matrix)[mtx_size])
{ 
	for(int i = 0; i < mtx_size; i++)
	{
		for(int j = 0; j < mtx_size; j++)
		{
			first_matrix[i][j] = rand() % 10 + 1;
			second_matrix[i][j] = rand() % 10 + 1;
		}
	}
}

int multiply(int i, int j, int (*first_matrix)[mtx_size], int (*second_matrix)[mtx_size])
{
	int ret = 0;
	for(int n = 0; n < mtx_size; n++)
	{
		ret += (first_matrix[i][n] * second_matrix[n][j]);
	}
	return ret;
}

int **calculate(int (*first_matrix)[mtx_size], int(*second_matrix)[mtx_size])
{
	int **ret;
	if(!(ret = malloc(sizeof(int *) * mtx_size)))
		return NULL;
	for(int i = 0; i < mtx_size; i++)
	{
		if(!(ret[i] = malloc(sizeof(int) * mtx_size)))
			return NULL;
		for(int j = 0; j < mtx_size; j++)
		{
			ret[i][j] = multiply(i, j, first_matrix, second_matrix);
		}
	}
	return ret;
}

void print_arr_matrix(int (*matrix)[mtx_size])
{
	for(int i = 0; i < mtx_size; i++)
	{
		for(int j = 0; j < mtx_size; j++)
		{
			printf("%2d  ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	return ;
}

void print_ptr_matrix(int **matrix)
{
	for(int i = 0; i < mtx_size; i++)
	{
		for(int j = 0; j < mtx_size; j++)
		{
			printf("%2d  ", matrix[i][j]);
		}
		printf("\n");
	}
	return ;
}

int main()
{
	int **ret;
	printf("input matrix size :");
	scanf("%d", &mtx_size);
	
	int first_matrix[mtx_size][mtx_size], second_matrix[mtx_size][mtx_size];
	
	memset(first_matrix, 0, sizeof(first_matrix[0][0]) * mtx_size * mtx_size);
	memset(second_matrix, 0, sizeof(second_matrix[0][0]) * mtx_size * mtx_size);
	
	set_matrix(first_matrix, second_matrix);
	print_arr_matrix(first_matrix);
	print_arr_matrix(second_matrix);
	
	ret = calculate(first_matrix, second_matrix);
	
	print_ptr_matrix(ret);
	for(int i = 0; i < mtx_size; i++)
		free(ret[i]);
	free(ret);
}
