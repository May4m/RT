/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 14:30:48 by smamba            #+#    #+#             */
/*   Updated: 2016/08/08 15:18:22 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_objects	*scene_one()
{
	t_objects   *vector = new_stack(9);

	t_object	sp1	= new_sphere(new_vec3f(0, -10004, -20),
								 new_color(.30, .31, .32),
								 new_color(0, .0, .0),
								 10000, 0);
	t_object    sp2 = new_sphere(new_vec3f(0 -2, 0, -20 - 5),
                                 new_color(1.00, .32, .36),
                                 new_color(0., 0., 0.),
                                 4, TRUE);

	t_object	sp3 = new_sphere(new_vec3f(5.0 - 2, -1, -15 - 5),
								 new_color(0.90, 0.76, 0.46),
								 new_color(0.0, 0.0, 0.0),
								 2, TRUE);
	t_object	sp4 = new_sphere(new_vec3f(5.0 - 2, 0, -25 - 3),
								 new_color(0.65, 0.77, 0.97),
								 new_color(0.0, 0.0, 0.0),
								 3, TRUE);
	t_object	sp6 =  new_plane(new_vec3f(0, 0, -35),
								new_vec3f(100, 7, 0),
								new_color(1, 1, 1),
								TRUE);
	sp6.mirror = TRUE;	
	t_object	sp5 = new_sphere(new_vec3f(-5.5 - 2, 0, -15 - 5),
								new_color(.99, .99, .99),
								new_color(0.0, 0.0, 0.0),
								3, TRUE);
	t_object	cyl = new_cylinder(new_vec3f(10, 0, -25),
									new_color(.3, .4, .3),
									new_color(0, 0, 0),
									3, TRUE);
	t_object    lig = new_light(new_vec3f(5, 15, -30),
                                new_color(3, 3, 3), 3);
	t_object	lig2 = new_light(new_vec3f(-5, 15, -20),
								 new_color(4, 4, 4), 3);
	push_object(vector, &sp1);
	push_object(vector, &sp2);
	push_object(vector, &sp3);
	push_object(vector, &sp4);
	push_object(vector, &sp5);
	push_object(vector, &sp6);
	push_object(vector, &lig);
	push_object(vector, &lig2);
	push_object(vector, &cyl);
	return (vector);
}
