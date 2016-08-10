

#include "matrix.h"

void	print(t_matrix *a)
{
	printf("printing %ix%i matrix..\n\n", a->rows, a->cols);
	int	i, j;

	i = 0;
	if (a->mat == NULL)
		printf("NULL matrix...");
	while (i < a->rows)
	{
		j = 0;
		while (j < a->cols)
		{
			printf("%f ", a->mat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("----------------------------------------\n\n\n");
}

t_mat	dup_mat(t_mat *src)
{
	int		i;
	int		j;
	t_mat	mat;

	i = 0;
	mat = new_mat44(1);
	while (i < src->rows)
	{
		j = 0;
		while (j < src->cols)
		{
			mat.mat[i][j] = src->mat[i][j];
			j++;
		}
		i++;
	}
	return (mat);
}

void	cpy_mat(t_mat *dst, t_mat *src)
{
	int	i;
	int	j;

	i = 0;
	while (i < src->rows)
	{
		j = 0;
		while (j < src->cols)
		{
			dst->mat[i][j] = src->mat[i][j];
			j++;
		}
		i++;
	}
}

void	set_row(t_matrix44 m, const int r, const t_f64 *arr)
{
	int	i;

	i = 0;
	while (i < m.cols)
	{
		m.mat[r][i] = arr[i];
		i++;
	}
}

void	set_col(t_matrix44 m, const int c, const t_f64 *arr)
{
	int	i;

	i = 0;
	while (i < m.rows)
	{
		m.mat[i][c] = arr[i];
		i++;
	}
}
