/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 14:30:48 by smamba            #+#    #+#             */
/*   Updated: 2016/07/31 15:36:44 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_spheres	*scene_one()
{
	t_spheres   *vector = new_spheres(4);

	t_sphere	sp1	= new_sphere(new_vec3f(0, -10004, -20),
									 new_vec3f(.2, .2, .2),
									 new_vec3f(0, .0, .0),
									 10000, 0);
	t_sphere    sp2 = new_sphere(new_vec3f(0, -1, -40),
                                 new_color(.8, .8, .8),
                                 new_color(0., 0., 0.),
                                 3, .5);
	t_sphere	sp3 = new_plane(new_vec3f(0, -4, -40),
								new_vec3f(10, 10, 10),
								new_color(.6, .35, .35),
								0);
	t_sphere    sp5 = new_light(new_vec3f(0, 20.0, -30),
                                 new_color(2.5, 2.5, 2.5), 3);
	push_sphere(vector, &sp1);
	push_sphere(vector, &sp2);
	push_sphere(vector, &sp3);
	push_sphere(vector, &sp5);
	return (vector);
}
