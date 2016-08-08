/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 16:37:19 by smamba            #+#    #+#             */
/*   Updated: 2016/08/08 13:09:30 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_object	new_object(t_vec3f pos, t_color s, t_color e, t_f64 rd, t_f64 r, int t)
{
	t_object	sp;

	sp.pos.x = pos.x;
	sp.pos.y = pos.y;
	sp.pos.z = pos.z;
	sp.scolor = s;
	sp.ecolor = e;
	sp.radius = rd;
	sp.transparency = 0;
	sp.reflection = r;
	sp.type = t;
	sp.mirror = FALSE;
	return (sp);
}

t_object	new_sphere(t_vec3f pos, t_color s, t_color e, t_f64 rad, t_f64 r)
{
	t_object	sp;

	sp = new_object(pos, s, e, rad, r, SPHERE);
	sp.intersect  = sphere_intersection;
	sp.normal = sphere_normal;
	return (sp);
}

t_object	new_cone(t_vec3f pos, t_color s, t_color e, t_f64 rad, t_f64 r)
{
	t_object	cone;

	cone = new_object(pos, s, e, rad, r, CONE);
	cone.intersect = cone_intersection;
	cone.normal = cone_normal;
	return (cone);
}

t_object	new_plane(t_vec3f pos, t_vec3f size, t_color s, t_f64 ref)
{
	t_object	plane;

	plane = new_object(pos, s, new_color(0, 0, 0), 10, ref, PLANE);
	plane.size = size;
	plane.intersect = plane_intersection;
	plane.normal = plane_normal;
	return (plane);
}

t_object	new_cylinder(t_vec3f pos, t_color s, t_color e, t_f64 rad, t_f64 r)
{
	t_object	sp;

	sp = new_object(pos, s, e, rad, r, CYLINDER);
	sp.intersect = cylinder_intersection;
	sp.normal = cylinder_normal;
	return (sp);
}

t_object	new_light(t_vec3f pos, t_color s, t_f64 rad)
{
	t_object	light;

	light = new_sphere(pos, new_uni_color(0), s, rad, 0);
	light.type = LIGHT;
	return (light);
}
