/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading_model.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 15:12:59 by smamba            #+#    #+#             */
/*   Updated: 2016/07/31 15:50:31 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_vec3f	defualt_glossy_shading(t_color *ref, t_color *frac,
	t_f64 feffect, t_object *p)
{
	t_color	tmp;
	t_color	scolor;

	tmp = scale_vec3f(frac, (1 - feffect) * p->transparency);
	scolor = scale_vec3f(ref, feffect);
	scolor = add_vec3f(&scolor, &tmp);
	scolor = mat_vec3f(&scolor, &p->scolor);
	return (add_vec3f(&scolor, &p->ecolor));
}

t_vec3f	specular_shading(t_vec3f trans, t_params p, t_vec3f ld, t_color s)
{
	t_color	rcolor;
	
	(void)rcolor;
	(void)trans;
	(void)p;
	(void)ld;
	(void)s;
	return (rcolor);
}

t_vec3f	phong_shading(t_vec3f trans, t_params p, t_vec3f ld, t_color s)
{
	t_color	rcolor;
	
	(void)rcolor;
	(void)trans;
	(void)p;
	(void)ld;
	(void)s;
	return (rcolor); // return to silence the compiler
}

t_vec3f	lambertian_shading(t_vec3f trans, t_params p, t_vec3f ld, t_color e)
{
	t_color	scolor;

	scolor = mat_vec3f(&p.sphere->scolor, &trans);
	scolor = scale_vec3f(&scolor, ftmax(0, dot_vec3f(&p.nhit, &ld)));
	scolor = mat_vec3f(&scolor, &e);
	return (scolor);
}
