/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 13:52:43 by simzam            #+#    #+#             */
/*   Updated: 2016/08/02 13:53:00 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view_matrix.h"

void	vec4_1(float **values)
{
	(*values)[0] = 0;
	(*values)[1] = 0;
	(*values)[2] = 0;
	(*values)[3] = 0;
}

float	*vec4_2(t_vec3f vec3, float w)
{
	float	*values;

	if (!(values = (float *)malloc((sizeof(float) * 4) + 1)))
		return (0);
	values[0] = vec3.x;
	values[1] = vec3.y;
	values[2] = vec3.z;
	values[3] = w;
	return (values);
}

t_vec4	**mat4_1(t_vec4 **columns)
{
	t_vec3f	vec3;
	float	w;
	int		i;

	i = -1; ;
	while (++i < 4)
		(*columns)[i].constructor2 = &vec4_2;
	w = 0;
	(*columns)[0].values = (*columns)[0].
	constructor2((t_vec3f){1, 0, 0}, w);
	(*columns)[1].values = (*columns)[1].
	constructor2((t_vec3f){0, 1, 0}, w);
	(*columns)[2].values = (*columns)[2].
	constructor2((t_vec3f){0, 0, 1}, w);
	(*columns)[3].values = (*columns)[3].
	constructor2((t_vec3f){0, 0, 0}, (w = 1));
	return (columns);
}

t_vec4	**mat4_2(t_vec4 **columns, t_vec4 *vec4)
{
	if (!columns || !vec4)
		return (0);
	columns[0] = &vec4[0];
	columns[1] = &vec4[1];
	columns[2] = &vec4[2];
	columns[3] = &vec4[3];
	return (columns);
}

float	to_radians(float degrees)
{
	return ((degrees * M_PI) / 180);
}

t_mat4	rh_view_cam(t_vec3f eye, float pitch, float yaw)
{
	t_cam_params	cam;

	cam.vmat.columns->constructor2 = &vec4_2;
	cam.cos_pitch = to_radians(cos(pitch));
	cam.sin_pitch = to_radians(sin(pitch));
	cam.cos_yaw = to_radians(cos(yaw));
	cam.sin_yaw = to_radians(sin(yaw));
	cam.xaxis = (t_vec3f){cam.cos_yaw, 0, -cam.sin_yaw};
	cam.yaxis = (t_vec3f){cam.sin_yaw * cam.sin_pitch,
		cam.cos_pitch, cam.cos_yaw * cam.sin_pitch};
	cam.zaxis = (t_vec3f){cam.sin_yaw * cam.cos_pitch,
		-cam.sin_pitch, cam.cos_pitch * cam.cos_yaw};
	cam.vmat.columns[0].values =  cam.vmat.columns
		->constructor2((t_vec3f){cam.xaxis.x, cam.yaxis.x, cam.zaxis.x}, 0);
	cam.vmat.columns[1].values = cam.vmat.columns
		->constructor2((t_vec3f){cam.xaxis.y, cam.yaxis.y, cam.zaxis.y}, 0);
	cam.vmat.columns[2].values = cam.vmat.columns
		->constructor2((t_vec3f){cam.xaxis.z, cam.yaxis.z, cam.zaxis.z}, 0);
	cam.vmat.columns[3].values = cam.vmat.columns
		->constructor2((t_vec3f){-dot_vec3f(&cam.xaxis, &eye),
			-dot_vec3f(&cam.yaxis, &eye), -dot_vec3f(&cam.zaxis, &eye)}, 1);
	return (cam.vmat);
}