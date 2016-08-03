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

t_vec3f	specular_shading(t_vec3f trans, t_params p, t_vec3f ld, t_color s)
{
	t_vec3f	R;
	t_vec3f	tmp;
	t_f64	spec;

	tmp = mat_vec3f(&p.sphere->scolor, &trans);
	R = scale_vec3f(&p.nhit, 2 * dot_vec3f(&ld, &p.nhit));
	R = sub_vec3f(&ld, &R);
	spec = pow(dot_vec3f(&p.nhit, &R), 20);
	return (new_vec3f(0, 0, 0)); // dummy return to silence the compiler
}

t_vec3f	phong_shading(t_vec3f trans, t_params p, t_vec3f ld, t_color s)
{
	t_color	diff;

	diff = lambertian_shading(trans, p, ld, s);
	return (diff); // return to silence the compiler
}

t_vec3f	lambertian_shading(t_vec3f trans, t_params p, t_vec3f ld, t_color e)
{
	t_color	tmp;
	t_color	scolor;

	// (Sc * Tr * Max(0, N.D)) * E
	tmp = mat_vec3f(&p.sphere->scolor, &trans);
	tmp = scale_vec3f(&tmp, ftmax(0, dot_vec3f(&p.nhit, &ld)));
	tmp = mat_vec3f(&tmp, &e);
	return (tmp);
}
