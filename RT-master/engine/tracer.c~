/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:35:59 by smamba            #+#    #+#             */
/*   Updated: 2016/07/31 15:50:10 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"
#include <stdio.h>
#define MAX_RAY_DEPTH 1

extern inline	t_vec3f atrace_back(t_params p, t_ray *ray, t_spheres *sp)
{
	double	facingratio;
	double	fresneleffect;
	t_vec3f	refldir, reflection, refraction;
	t_color	tmp;
	t_color	scolor;
	t_ray	rx, ry;

	if (dot_vec3f(&ray->dir, &p.nhit) > 0)
		p.nhit = scale_vec3f(&p.nhit, -1);
	facingratio = -dot_vec3f(&ray->dir, &p.nhit);
	fresneleffect = mix(pow(1 - facingratio, 3), 1, .28);

	refldir = scale_vec3f(&p.nhit, 2 * dot_vec3f(&ray->dir, &p.nhit));
	refldir = sub_vec3f(&ray->dir, &refldir);
	refldir = normal_vec3f(&refldir);

	rx = ry = dup_ray(ray);
	rx.origin = scale_vec3f(&p.nhit, BIAS);
	rx.origin = add_vec3f(&rx.origin, &p.phit);
	rx.dir = refldir;

	reflection = trace_ray(&rx, sp, p.depth++);

	refraction = new_uni_color(0);
	scolor = scale_vec3f(&reflection, fresneleffect);
	tmp = scale_vec3f(&refraction, (1 - fresneleffect * p.sphere->transparency));
	scolor = add_vec3f(&scolor, &tmp);
	scolor = mat_vec3f(&scolor, &p.sphere->scolor);
	//scolor = add_vec3f(&scolor, &scolor);

	return (add_vec3f(&scolor, &p.sphere->ecolor));
}

static inline t_color	compute_shadows(t_params p,
		t_ray *r, t_spheres *sp, t_vec3f ldir, int j)
{
	t_f64	t0;
	int		i;
	t_vec3f	trans;
	t_ray	sray;

	i = 0;
	trans = new_uni_color(1);
	while (i < sp->top)
	{
		if (j != i)
		{
			sray = dup_ray(r);
			sray.origin = scale_vec3f(&p.phit, BIAS);
			sray.origin = add_vec3f(&sray.origin, &p.phit);
			sray.dir = ldir;
			if (sp->store[i].intersect(&sray, &sp->store[i], &t0, &t0))
				return (new_uni_color(0));
		}
		i++;
	}
	return (new_uni_color(1));
}

t_vec3f	trace_back(t_params p, t_ray *ray, t_spheres *sp)
{
	int		i;
	t_vec3f	trans;
	t_vec3f	tmp;
	t_vec3f	light_dir;
	t_color	scolor;

	i = 0;
	if (dot_vec3f(&ray->dir, &p.nhit) > 0)
		p.nhit = scale_vec3f(&p.nhit, -1);
	scolor = new_uni_color(0);
	while (i < sp->top)
	{
		if (sp->store[i].ecolor.x > 0)
		{
			light_dir = sub_vec3f(&sp->store[i].pos, &p.phit);
			light_dir = normal_vec3f(&light_dir);
			trans = compute_shadows(p, ray, sp, light_dir, i);
			tmp = lambertian_shading(trans, p, light_dir, sp->store[i].ecolor);
			scolor = add_vec3f(&scolor, &tmp);
		}
		i++;
	}
	return (add_vec3f(&scolor, &p.sphere->ecolor));
}

t_vec3f	trace_ray(t_ray *ray, t_spheres *sp, int depth)
{
	int			i;
	double		t0;
	double		t1;
	t_params	param;

	i = 0;
	param.sphere = NULL;
	param.depth = depth;
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
	if (param.sphere == NULL)
		return (new_vec3f(.65, .65, .65));
	param.phit = scale_vec3f(&ray->dir, param.tnear);
	param.phit = add_vec3f(&ray->origin, &param.phit);
	param.nhit = param.sphere->normal(&param.phit, &param.sphere->pos);
	param.ray = ray;
	if ((param.sphere)->reflection > 0 && depth < MAX_RAY_DEPTH)
		return (atrace_back(param, ray, sp));
	return (trace_back(param, ray, sp));
}
