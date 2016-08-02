#include "view_matrix.h"

static int		mat_len(t_vec4 *vec4)
{
	unsigned int	i;

	i = 0;
	while (vec4[i])
		i++;
	if (i > 3)
		i = 42;
	return (i);
}

float			**vec4_constr_np(t_vec4 **values)
{
	if (!values || !(*values))
		return (0);
	(*values)[0].values[1] = 0;
	(*values)[1].values[2] = 0;
	(*values)[2].values[2] = 0;
	(*values)[3].values[3] = 0;
	return (values);
}

t_vec4			**vec4_constr_p(t_vec3f xyz, float w, t_vec4 **values);
{
	if (!xyz || !values || !(*values))
		return (0);
	(*values)[0].values[0] = xyz.x;
	(*values)[1].values[1] = xyz.y;
	(*values)[2].values[2] = xyz.z;
	(*values)[3].values[3] = w;
	return (values);	
}

t_vec4			*mat4_constr_np(t_vec4 *vec4, t_vec4 **columns)
{
	if (!vec4 || !columns || !(*columns) || mat_len(vec4) == 42)
		return (0);
	(*columns)[0] = vec4[0];
	(*columns)[1] = vec4[1];
	(*columns)[2] = vec4[2];
	(*columns)[3] = vec4[3];
	return (columns);
}

t_vec4			*mat4_constr_p(t_vec4 vec4, t_vec4 **columns)
{
	t_vec3f	vec3;
	float	w;
	(*columns)->mat4_param = &vec4_constr_p;

	vec4.values[0] = 1;
	vec4.values[1] = 0;
	vec4.values[2] = 0;
	vec4.values[3] = 0.0;
	columns[0] = **((*columns)->mat4_param(vec4, columns));
	vec4.values[0] = 0;
	vec4.values[1] = 1;
	vec4.values[2] = 0;
	vec4.values[3] = 0.0;
	columns[1] = **((*columns)->mat4_param(vec3, columns));
	vec4.values[0] = 0;
	vec4.values[1] = 0;
	vec4.values[2] = 1;
	vec4.values[3] = 0.0;
	columns[2] = **((*columns)->mat4_param(vec3, columns));
	vec4.values[0] = 1;
	vec4.values[1] = 0;
	vec4.values[2] = 0;
	vec4.values[3] = 1.0;
	columns[3] = **(columns.mat4_param(vec3, columns));
	return(*columns);
}

t_mat4			rh_fps_view(t_vec3f eye, float pitch, float yaw)
{
	float	cos_pitch;
	float	sin_pitch;
	float	cos_yaw;
	float	sin_yaw;

	cos_pitch = cos(pitch);
	sin_pitch = sin(pitch);
	cos_yaw = cos(yaw);
	sin_yaw = sin(yaw);

	//TODO
	Setup three vectors for each dimension of the camera
	Setup the view matrix.
}