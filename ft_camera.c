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

t_camera new_camera(t_vec3f eye, t_vec3f target, t_vec3f up, t_f64 fov)
{
	t_camera	cam;

	cam.pos = eye;
	cam.target = target;
	cam.up = up;
	cam.fov = fov;
	cam.angle = tan(M_PI * 0.5 * fov / 180);
	return (cam);
}
