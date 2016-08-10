/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:41:57 by smamba            #+#    #+#             */
/*   Updated: 2016/08/07 17:50:45 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	length_vec3f(t_vec3f *vec)
{
	return (sqrtf(dot_vec3f(vec, vec)));
}

t_vec3f	normalize_vec3f(t_vec3f vec)
{
	return (normal_vec3f(&vec));
}

t_vec3f	normal_vec3f(t_vec3f *vec)
{
	t_vec3f	norm;
	float	len;
	float	inv_norm;

	len = dot_vec3f(vec, vec);
	if (len > 0)
	{
		inv_norm = 1.0f / sqrtf(len);
		norm.x = vec->x * inv_norm;
		norm.y = vec->y * inv_norm;
		norm.z = vec->z * inv_norm;
		return (norm);
	}
	return (*vec);
}

t_vec3f	mat_vec3f(t_vec3f *v1, t_vec3f *v2)
{
	t_vec3f	res;

	res.x = v1->x * v2->x;
	res.y = v1->y * v2->y;
	res.z = v1->z * v2->z;
	return (res);
}
