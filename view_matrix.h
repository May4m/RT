#ifndef VIEW_MATRIX_H
# define VIEW_MATRIX_H
# include "tracer.h"

typedef struct 	s_ve4
{
	float	*values;
	void	(*constructor1)(float **values);
	float	*(*constructor2)(t_vec3f vec3, float w);
}				t_vec4;

typedef struct 	s_mat4
{
	t_vec4		*columns;
	void		(*constructor1)(t_vec4 **columns);
	void		(*constructor2)(t_vec4 **columns, t_vec4 *vec4);	
}				t_mat4;

void	vec4_1(float **values);
float	*vec4_2(t_vec3f vec3, float w);
void	mat4_1(t_vec4 **columns);
void	mat4_2(t_vec4 **columns, t_vec4 *vec4);
t_mat4	rh_view_cam(t_vec3f eye, float pitch, float yaw);

#endif