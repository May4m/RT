/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:38:48 by smamba            #+#    #+#             */
/*   Updated: 2016/08/07 18:07:21 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_camera new_look_camera(t_vec3f eye, t_vec3f target, t_vec3f up)
{
	t_vec3f		zaxis;
	t_vec3f		xaxis;
	t_vec3f		yaxis;
	t_matrix44	orientation;
	t_matrix44	translation;

	zaxis = normalize_vec3f(sub_vec3f(&eye, &target));
	xaxis = normalize_vec3f(cross_vec3f(&up, &zaxis));
	yaxis = cross_vec3f(&zaxis, &xaxis);
	orientation = new_mat44(1);
	translation = new_mat44(1);
	set_row(&orientation, (t_f64[4]){xaxis.x, xaxis.y, xaxis.z, 0});
	set_row(&orientation, (t_f64[4]){yaxis.x, yaxis.y, yaxis.z, 0});
	set_row(&orientation, (t_f64[4]){zaxis.x, zaxis.y, zaxis.y, 0});
	set_row(&orientation, (t_f64[4]){0, 0, 0, 1});
	set_row(&translation, (t_f64[4]){1, 0, 0, -eye.x});
	set_row(&translation, (t_f64[4]){0, 1, 0, -eye.y});
	set_row(&translation, (t_f64[4]){0, 0, 1, -eye.z});
	set_row(&translation, (t_f64[4]){0, 0, 0, 1});
	return (new_camera(multiply_mat44(&orientation, &translation), 30));
}

t_camera new_camera(t_matrix44 m, t_f64 fov)
{
	t_camera	cam;

	cam.fov = fov;
	cam.view = m;
	return (cam);
}

void	kill_camera(t_camera *cam)
{
	kill_matrix(&(cam->view));
}
