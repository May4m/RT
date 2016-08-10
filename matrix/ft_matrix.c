/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 14:52:49 by smamba            #+#    #+#             */
/*   Updated: 2016/08/07 16:27:26 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static t_f64	**new_2d_arr(int r, int c, int dvalue)
{
	t_f64	**arr;
	int		j;
	int		k;

	j = 0;
	if (!(arr = (t_f64**)malloc(sizeof(t_f64*) * r)))
		return (NULL);
	while (j < r)
	{
		k = 0;
		arr[j] = (t_f64*)malloc(sizeof(t_f64) * c + 1);
		if (arr[j] == NULL)
			return (NULL);
		while (k < c)
		{
			arr[j][k] = dvalue;
			k++;
		}
		j++;
	}
	return (arr);
}

t_matrix		new_mat(int r, int v, t_f64 dv)
{
	t_matrix	mat;
	t_f64		**arr;

	arr = new_2d_arr(r, v, dv);
	mat.mat = arr;
	mat.rows = r;
	mat.cols = v;
	mat.id = (t_i32)arr;
	garbage_collector(mat);
	return (mat);
}

t_mat44		new_mat44(t_f64 f)
{
	return ((t_matrix44)new_mat(4, 4, f));
}

t_mat44		new_translation_mat44()
{
	int		c;
	t_mat	m;

	m = new_mat44(0);
	c = 0;
	while (c < 4)
	{
		m.mat[c][c] = 1;
		c++;
	}
	return (m);
}

void			kill_matrix(t_matrix *mat)
{
	int	r;

	r = 0;
	if (mat->mat != NULL)
	{
		while (r < mat->rows)
			free(mat->mat[r++]);
		free(mat->mat);
		mat->mat = NULL;
		manual_dispose(mat);
	}
}
