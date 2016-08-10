/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 16:18:01 by smamba            #+#    #+#             */
/*   Updated: 2016/07/21 12:40:03 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3f	new_vec3f(double x, double y, double z)
{
	t_vec3f	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

t_vec3f	cpy_vec3f(t_vec3f *dest, t_vec3f *src)
{
	dest->x = src->x;
	dest->y = src->y;
	dest->z = src->z;
	return (*dest);
}

t_vec3f	dup_vec3f(t_vec3f *src)
{
	t_vec3f	dest;

	dest.x = src->x;
	dest.y = src->y;
	dest.z = src->z;
	return (dest);
}
