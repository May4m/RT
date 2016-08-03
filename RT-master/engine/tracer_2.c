/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:35:59 by smamba            #+#    #+#             */
/*   Updated: 2016/07/13 16:13:34 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/tracer.h"
#include <stdio.h>

float	ftmax2(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

t_vec3f	trace_back_2(t_params p, t_ray *ray, t_spheres *spheres,
		t_sphere *sphere)
{
	int		i;
	int		j;
	t_vec3f	trans;
	t_ray	temp;
	t_vec3f	tmp;
	t_vec3f	light_dir;
	t_bool	inside;
	t_color	scolor;
	float	t0;
	float	t1;
	float	bias;

	bias = 1e-4;
	inside = FALSE;
	i = 0;
	j = 0;
	if (dot_vec3f(&ray->dir, &p.nhit) > 0)
		p.nhit = scale_vec3f(&p.nhit, -1);
	scolor = new_color(0, 0, 0);
	while (i < spheres->top)
	{
		if (spheres->store[i].ecolor.x > 0)
		{
			trans = (t_vec3f)new_uni_color(1);
			light_dir = sub_vec3f(&spheres->store[i].pos, &p.phit);
			light_dir = normal_vec3f(&light_dir);
			j = 0;
			while (j < spheres->top)
			{
				if (j != i)
				{
					temp = dup_ray(ray);
					temp.origin = scale_vec3f(&p.nhit, bias);
					temp.origin = add_vec3f(&temp.origin, &p.phit);
					temp.dir = light_dir;
					if (cylinder_intersection(&temp, &spheres->store[j],
								&t0, &t1))
					{
						trans = (t_vec3f)new_uni_color(0);
						break;
					}
				}
				j++;
			}
			tmp = mat_vec3f(&sphere->scolor, &trans);
			tmp = scale_vec3f(&tmp, ftmax2(0.0f, dot_vec3f(&p.nhit, &light_dir)));
			tmp = mat_vec3f(&tmp, &spheres->store[i].ecolor);
            scolor = add_vec3f(&scolor, &tmp);
		}
		i++;
	}
	return (add_vec3f(&scolor, &sphere->ecolor));
}

t_vec3f	trace_ray_2(t_ray *ray, t_spheres *sp, float depth)
{
	int			i;
	float		t0;
	float		t1;
	t_vec3f		phit;
	t_vec3f		nhit;
	t_sphere	*sphere;
	t_params	param;

	sphere = NULL;
	i = 0;
	param.tnear = INFINITY;
	while (i < sp->top)
	{
		t0 = INFINITY;
		t1 = INFINITY;
		if (cylinder_intersection(ray, &sp->store[i], &t0, &t1))
		{
			if (t0 < 0)
				t0 = t1;
			if (t0 < param.tnear)
			{
				param.tnear = t0;
				sphere = &(sp->store[i]);
			}
		}
		i++;
	}
	if (sphere == NULL)
		return (new_vec3f(.7, .7, .7));
	param.phit = scale_vec3f(&ray->dir, param.tnear);
	param.phit = add_vec3f(&ray->origin, &param.phit);
	param.nhit = sub_vec3f(&param.phit, &sphere->pos);
	param.nhit.y = 0;
	param.nhit = normal_vec3f(&param.nhit);
	return (trace_back_2(param, ray, sp, sphere));
}
