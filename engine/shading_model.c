/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading_model.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 15:12:59 by smamba            #+#    #+#             */
/*   Updated: 2016/08/04 16:43:13 by simzam           ###   ########.fr       */
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

/*t_vec3f	phong_shading(t_vec3f trans, t_params p, t_vec3f ld, t_color s)
{
	t_color	diff;

	diff = lambertian_shading(trans, p, ld, s);
	return (diff); // return to silence the compiler
}*/

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


//The following function assumes that the vectors passed to it are already
//normalised. It does not have to be that way but it just makes thing cleaner.
//We could normalise the vectors as  they come. Also, the dif_pl and dif_pv
//vectors are actually a difference between two vectors, which is something we
//can do as the activation is being prepared. Also got to move the defines to
//where they belong.

#define KD 0.5
#define KS 0.1

t_vec3f	phong_shading(t_vec3f *sn, t_vec3f *dif_pl, t_vec3 *dif_pv, t_vec3 *lvec)
{
	t_ve3f	diffuse;
	t_vec3f	phong_shadow;
	int		n;

	//Lambertian reflection
	diffuse = scale_vec3f(dot_vec3f(sn, dif_pl), KD);
	//Spectral reflectivity
	phong_shadow = diffuse + KS * pow(dot_vec3f(lvec, dif_pl), n);
	return (phong_shadow);
}
