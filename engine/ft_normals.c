/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 15:23:00 by smamba            #+#    #+#             */
/*   Updated: 2016/08/08 13:48:47 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_vec3f	object_normal(t_vec3f *phit, t_object *obj)
{
	t_vec3f	normal;

	if (obj->type == CONE)
		normal = (t_vec3f){phit->x, phit->y, -.1 * phit->z};
	else if (obj->type == PLANE)
		normal = (t_vec3f){0, 0, 100};
	else if (obj->type == CYLINDER)
		normal = (t_vec3f){phit->x, phit->y, 20};
	else if (obj->type == SPHERE)
		normal = (t_vec3f){phit->x, phit->y, phit->z};
	return (normal);
}

t_vec3f	sphere_normal(t_vec3f *phit, t_vec3f *pos)
{
	t_vec3f	nhit;

	nhit = sub_vec3f(phit, pos);
	return (normal_vec3f(&nhit));
}

t_vec3f	cylinder_normal(t_vec3f *phit, t_vec3f *pos)
{
	t_vec3f	nhit;

	nhit = sub_vec3f(phit, pos);
	nhit.y = 0;
	return (normal_vec3f(&nhit));
}

t_vec3f	plane_normal(t_vec3f *phit, t_vec3f *pos)
{
	t_vec3f	nhit;

	nhit = dup_vec3f(pos);
	nhit.z = nhit.z < 0 ? -1 : (nhit.z > 0 ? 1 : 0);
	nhit.x = nhit.x < 0 ? -1 : (nhit.x > 0 ? 1 : 0);
	nhit.y = nhit.y < 0 ? -1 : (nhit.y > 0 ? 1 : 0);
	return (nhit);
}

t_vec3f	cone_normal(t_vec3f *phit, t_vec3f *pos)
{
	t_vec3f nhit;

	return ((nhit = (t_vec3f){phit->x, phit->y, -.1 * phit->z}));
}
