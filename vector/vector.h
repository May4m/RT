/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:46:23 by smamba            #+#    #+#             */
/*   Updated: 2016/08/07 17:49:57 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# include <math.h>
# include <stdlib.h>

typedef int		t_bool;
typedef double	t_f64;
typedef float	t_f32;
typedef int		t_i32;
typedef int		t_i64;

typedef struct	s_vec3f
{
	t_f64	x;
	t_f64	y;
	t_f64	z;
}				t_vec3f;

typedef struct  s_vec2f
{
	t_f64	x;
	t_f64	y;
}				t_vec2f;

t_vec3f			cpy_vec3f(t_vec3f *dest, t_vec3f *src);
t_vec3f			dup_vec3f(t_vec3f *src);
t_vec3f			new_vec3f(t_f64 x, t_f64 y, t_f64 z);
t_vec3f			mat_vec3f(t_vec3f *v1, t_vec3f *t1);
t_vec3f			add_vec3f(t_vec3f *v1, t_vec3f *v2);
t_vec3f			sub_vec3f(t_vec3f *v1, t_vec3f *v2);
t_vec3f			normal_vec3f(t_vec3f *vec);
t_vec3f			normalize_vec3f(t_vec3f vec);
t_vec3f			scale_vec3f(t_vec3f *s, t_f64 scale);
t_vec3f			cross_vec3f(t_vec3f *v1, t_vec3f *v2);
t_f64			length_vec3f(t_vec3f *vec);
t_f64			dot_vec3f(t_vec3f *v1, t_vec3f *v2);

#endif
