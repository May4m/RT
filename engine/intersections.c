/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 16:21:06 by smamba            #+#    #+#             */
/*   Updated: 2016/08/07 18:18:59 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"
#include <math.h>

t_bool	plane_intersection(t_ray *r, t_object *s, t_f64 *t0, t_f64 *t1)
{
	t_f64	denom;
	t_vec3f	v_n;
	t_vec3f	c;
	t_vec3f	f;

	v_n = s->pos;
	denom = dot_vec3f(&v_n, &r->dir);
	if (denom > 1e-6)
	{
		f = sub_vec3f(&s->pos, &r->origin);
		*t1 = dot_vec3f(&f, &v_n) / denom;
		
		
		*t0 = *t1;
		c = scale_vec3f(&r->dir, *t0);
		c = add_vec3f(&c, &r->origin);
		if (!((c.y > s->pos.y) && (c.y < (s->pos.y + s->size.y))))
			return (FALSE);
		/*
		if (!((c.z > s->pos.z) && (c.z < (s->pos.z + s->size.z))))
			return (FALSE);*/
		return (*t0 >= 0);
	}
	return (FALSE);
}

t_bool	cylinder_intersection(t_ray *r, t_object *s, double *t0, double *t1)
{
	t_vec3f	diff;
	t_vec3f	dir;
	t_f64	b;
	t_f64	c;
	t_f64	y0;
	t_f64	y1;

	dir = r->dir;
	diff = sub_vec3f(&r->origin, &s->pos);
	diff.y = 0;
	dir.y = 0;
	b = 2 * (dot_vec3f(&diff, &dir));
	c = dot_vec3f(&diff, &diff) - pow(s->radius, 2);
	if (!solve_quadratic(dot_vec3f(&dir, &dir), b, c, t0, t1))
		return (FALSE);
	return (TRUE);
}

t_bool	sphere_intersection(t_ray *r, t_object *s, double *t0, double *t1)
{
	t_vec3f	diff;
	float	tca;
	float	thc;
	float	d2;

	diff = sub_vec3f(&s->pos, &r->origin);
	tca = dot_vec3f(&diff, &r->dir);
	if (tca < 0)
		return (FALSE);
	d2 = dot_vec3f(&diff, &diff) - tca * tca;
	if (d2 > (s->radius * s->radius))
		return (FALSE);
	thc = sqrt(s->radius * s->radius - d2);
	*t0 = tca - thc;
	*t1 = tca + thc;
	return (TRUE);
}

t_bool	cone_intersections(t_ray *r, t_object *s, double *t0, double *t1)
{
	t_f64	a;
	t_f64	b;
	t_f64	c;
	t_f64	z;
	t_f64	radicant;

	z = 0.5 * r->dir.z;
	a = pow(r->dir.x, 2) + pow(r->dir.y, 2) - pow(z, 2);
	b = 2 * (s->pos.x * r->dir.x + s->pos.y * r->dir.y - s->pos.z * z);
	c = pow(s->pos.x, 2) + pow(s->pos.y, 2) - pow(s->pos.z, 2);
	radicant = pow(b, 2) - 4 * a * c;
	if (radicant < 0)
	{
		*t0 = -1;
		*t1 = -1;
		return (FALSE);
	}
	*t0 = (-b + sqrt(radicant)) / (2 * a);
	*t1 = (-b - sqrt(radicant)) / (2 * a);
	return (TRUE);
}
