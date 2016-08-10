

#include "matrix.h"

void	ft_swap(t_f64 *a, t_f64 *b)
{
	t_f64	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_rows(t_mat mat, int i, int j)
{
	int	k;
	
	k = 0;
	while (k < 4)
	{
		ft_swap(&mat.mat[i][k], &mat.mat[j][k]);
		k++;
	}
}

void	divide_row(t_mat m, int i, t_f64 temp)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		m.mat[i][j] /= temp;
		j++;
	}
}

void	sub_row(t_mat m, int i, int j, t_f64 temp)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		m.mat[i][k] -= m.mat[j][k] * temp;
		k++;
	}
}

int		get_row(t_mat m, int i)
{
	int	j;

	j = i;
	while (j < 4)
	{
		if (m.mat[j][i] != 0)
			return (j);
		j++;
	}
	return (0);
}

t_mat	inverse_mat44(t_mat44 mat)
{
	int		i;
	int		j;
	t_f64	t;
	t_mat44	temp;
	t_mat44	identity;


	i = 0;
	temp = dup_mat(&mat);
	identity = new_translation_mat44();
	while (i != 4)
	{
		j = get_row(temp, i);
		if (j != i)
		{
			swap_rows(temp, i, j);
			swap_rows(identity, i, j);
		}
		t = temp.mat[i][i];
		divide_row(temp, i, t);
		divide_row(identity, i, t);
		j = 0;
		while (j < 4)
		{
			if (j != i)
			{
				t = temp.mat[j][i];
				sub_row(temp, j, i, t);
				sub_row(identity, j, i, t);
			}
			j++;
		}
		i++;
	}
	return (identity);
}
