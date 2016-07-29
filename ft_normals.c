/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 15:23:00 by smamba            #+#    #+#             */
/*   Updated: 2016/07/26 18:10:04 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

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
//	nhit.y = 0;
	return (normal_vec3f(&nhit));
}

t_vec3f	plane_normal(t_vec3f *phit, t_vec3f *pos)
{
	t_vec3f	nhit;

	nhit = normal_vec3f(phit);
	nhit = scale_vec3f(&nhit, 1);
	return (sphere_normal(phit, pos));
}
