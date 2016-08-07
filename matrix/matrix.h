/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 14:11:31 by smamba            #+#    #+#             */
/*   Updated: 2016/08/07 14:24:36 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include <vector.h>

typedef struct		s_matrix
{
	t_f64		**mat;
	t_i32		rows;
	t_i32		cols;
}					t_matrix;

typedef t_matrix	t_matrix44;

t_matrix44			new_mat44(t_f64 dvalue);
t_vec3f				vector_multiply(t_vec3f *v, t_matrix44 *m);
#endif
