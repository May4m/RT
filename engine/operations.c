/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 13:35:45 by smamba            #+#    #+#             */
/*   Updated: 2016/08/07 13:36:53 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_ray		refracted_ray(t_ray *ray, t_vec3f *rd,
		t_vec3f *nhit, t_vec3f *phit)
{
	t_ray	rx;

	rx = dup_ray(ray);
	rx.origin = scale_vec3f(nhit, BIAS);
	rx.origin = sub_vec3f(phit, &rx.origin);
	rx.dir = dup_vec3f(rd);
	return (rx);
}

t_color		compute_ideal_refractions(t_ray *r, t_bool inside, t_params p)
{
	t_vec3f	refrac_dir;
	t_vec3f	tmp;
	t_f64	eta;
	t_f64	cosi;
	t_f64	k;

	eta = (inside) ? (1.1) : (1 / 1.1);
	cosi = -dot_vec3f(&p.nhit, &r->dir);
	k = 1 - eta * eta * (1 - cosi * cosi);
	refrac_dir = scale_vec3f(&p.nhit, eta * cosi - sqrt(k));
	tmp = scale_vec3f(&r->dir, eta);
	refrac_dir = add_vec3f(&tmp, &refrac_dir);
	return (normal_vec3f(&refrac_dir));
}

t_vec3f		get_reflection_dir(t_vec3f *nhit, t_vec3f *dir)
{
	t_vec3f	ref_dir;

	ref_dir = scale_vec3f(nhit, 2 * dot_vec3f(dir, nhit));
	ref_dir = sub_vec3f(dir, &ref_dir);
	ref_dir = normal_vec3f(&ref_dir);
	return (ref_dir);
}

t_ray		reflected_ray(t_ray *ray, t_vec3f *rd,
		t_vec3f *nhit, t_vec3f *phit)
{
	t_ray	rx;

	rx = dup_ray(ray);
	rx.origin = scale_vec3f(nhit, BIAS);
	rx.origin = add_vec3f(&rx.origin, phit);
	rx.dir = *rd;
	return (rx);
}

t_params	get_closest_primitive(t_ray *ray, t_objects *sp)
{
	int			i;
	t_f64		t0;
	t_f64		t1;
	t_params	param;

	i = 0;
	param.sphere = NULL;
	param.tnear = INFINITY;
	while (i < sp->top)
	{
		t0 = INFINITY;
		t1 = t0;
		if (sp->store[i].intersect(ray, &sp->store[i], &t0, &t1) == TRUE)
		{
			t0 = (t0 < 0) ? (t1) : (t0);
			if (t0 < param.tnear)
			{
				param.tnear = t0;
				param.sphere = &sp->store[i];
			}
		}
		i++;
	}
	return (param);
}
