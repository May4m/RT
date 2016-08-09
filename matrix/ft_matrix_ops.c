/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:48:43 by smamba            #+#    #+#             */
/*   Updated: 2016/08/09 16:06:55 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	transpose_mat(t_matrix *m)
{
	t_matrix	mat;
	int			i;
	int			j;

	i = 0;
	mat = new_mat(m->cols, m->rows, 0);
	if (mat.mat == NULL)
		perror("Matrix: Error matrix creation\n");
	while (i < m->cols)
	{
		j = 0;
		while (j < m->rows)
		{
			mat.mat[i][j] = m->mat[j][i];
			j++;
		}
		i++;
	}
	return (mat);
}

t_matrix	multiply_mat44(t_matrix *a, t_matrix *b)
{
	t_matrix44	mat;
	int			i;
	int			j;

	i = 0;
	mat = new_mat44(0);
	while (i < a->rows)
	{
		j = 0;
		while (j < a->cols)
		{
			mat.mat[i][j] = a->mat[i][j] * b->mat[i][j];
			j++;
		}
		i++;
	}
	return (mat);
}

t_vec3f		vector_multiply(t_vec3f v, t_matrix44 *m)
{
	t_f64	a;
	t_f64	b;
	t_f64	c;
	t_f64	w;
	t_vec3f	dst;

	a = v.x * m->mat[0][0] + v.y * m->mat[1][0] + v.z * m->mat[2][0];
	b = v.x * m->mat[0][1] + v.y * m->mat[1][1] + v.z * m->mat[2][1];
	c = v.x * m->mat[0][2] + v.y * m->mat[1][2] + v.z * m->mat[2][2];
	w = v.x * m->mat[0][3] + v.y * m->mat[1][3] + v.z * m->mat[2][3];
	a += m->mat[3][0];
	b += m->mat[3][1];
	c += m->mat[3][2];
	w += m->mat[3][3];
	dst.x = w != 0 ? a / w : 0;
	dst.y = w != 0 ? b / w : 0;
	dst.z = w != 0 ? c / w : 0;
	return (dst);
}

t_vec3f		vector_dir_multiply(t_vec3f v, t_matrix44 *m)
{
	t_f64	a;
	t_f64	b;
	t_f64	c;
	t_vec3f	dst;

	a = v.x * m->mat[0][0] + v.y * m->mat[1][0] + v.z * m->mat[3][0];
	b = v.x * m->mat[0][1] + v.y * m->mat[1][1] + v.z * m->mat[3][1];
	c = v.x * m->mat[0][2] + v.y * m->mat[1][2] + v.z * m->mat[3][2];
	dst.x = a;
	dst.y = b;
	dst.z = c;
	return (dst);
}
