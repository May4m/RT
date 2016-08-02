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

void	mat4_1(t_vec4 **columns)
{
	t_vec4	*vec4;
	t_vec3f	vec3;
	float	w;
	int		i;

	i = -1;
	if (!(vec4 = (t_vec4 *)malloc((sizeof(vec4) * 4) + 1)))
		return ;
	while (++i < 4)
		vec4[i].constructor2 = &vec4_2;
	w = 0;
	vec4[0].values = vec4[0].constructor2((t_vec3f){1, 0, 0}, w);
	vec4[1].values = vec4[1].constructor2((t_vec3f){0, 1, 0}, w);
	vec4[2].values = vec4[2].constructor2((t_vec3f){0, 0, 1}, w);
	vec4[3].values = vec4[3].constructor2((t_vec3f){0, 0, 0}, (w = 1));
}

void	mat4_2(t_vec4 **columns, t_vec4 *vec4)
{
	if (!columns || !vec4)
		return ;
	columns[0] = &vec4[0];
	columns[1] = &vec4[1];
	columns[2] = &vec4[2];
	columns[3] = &vec4[3];
}

float	to_radians(float degrees)
{
	return ((degrees * M_PI) / 180);
}

t_mat4	rh_view_cam(t_vec3f eye, float pitch, float yaw)
{
	float	cos_pitch;
	float	sin_pitch;
	float	cos_yaw;
	float	sin_yaw;
	t_vec3f	xaxis;
	t_vec3f yaxis;
	t_vec3f zaxis;
	t_mat4	view_matrix;
	t_vec3f vec3f;

	cos_pitch = to_radians(cos(pitch));
	sin_pitch = to_radians(sin(pitch));
	cos_yaw = to_radians(cos(yaw));
	sin_yaw = to_radians(sin(yaw));
	xaxis = (t_vec3f){cos_yaw, 0, -sin_yaw};
	yaxis = (t_vec3f){sin_yaw * sin_pitch, cos_pitch, cos_yaw * sin_pitch};
	zaxis = (t_vec3f){sin_yaw * cos_pitch, -sin_pitch, cos_pitch * cos_yaw};
	//TODO
	//Set up the entire matrix from the computed values above and return the view_matrix.
	return (view_matrix);
}