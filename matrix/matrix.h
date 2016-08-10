/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 14:11:31 by smamba            #+#    #+#             */
/*   Updated: 2016/08/07 18:07:08 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include <vector.h>
# include <stdio.h>

typedef struct		s_matrix
{
	t_f64		**mat;
	t_i32		rows;
	t_i32		cols;
	t_i32		id;
}					t_matrix;

typedef t_matrix	t_matrix44;
typedef t_matrix	t_mat;
typedef t_matrix	t_mat44;

t_mat				multiply_mat44(t_mat *a, t_mat *b);
t_mat				dup_mat(t_mat *src);
t_mat				new_mat(int r, int c, t_f64 dvalue);
t_mat				transpose_mat(t_mat *m);
t_mat44				new_translation_mat44();
t_mat44				inverse_mat44(t_mat44 mat);
t_mat44				new_mat44(t_f64 dvalue);
t_vec3f				vector_multiply(t_vec3f v, t_mat44 *m);
t_vec3f				vector_dir_multiply(t_vec3f b, t_mat44 *m);
void				cpy_mat(t_mat *dst, t_mat *src);
void				set_row(t_mat44 m, const int r, const t_f64 *a);
void				set_col(t_mat44 m, const int c, const t_f64 *a);
void				kill_matrix(t_mat *mat);
void				garbage_collector(t_mat44 m);
void				dispose_garbage();
void				manual_dispose(t_mat *m);
#endif
