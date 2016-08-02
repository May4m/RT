#ifndef VIEW_MATRIX_H
#define VIEW_MATRIX_H
#include "tracer.h"

typedef struct 	s_vec4
{
	float	values[4];
	s_vec4	*(*vec4_nparam)(float **values);
	s_vec4	*(*vec4_param)(t_vec3f xyz, float w, float **values);
}				t_vec4;

typedef struct 	s_mat4
{
	t_vec4	columns[4];
	t_vec4	*(*mat4_nparam)(t_vec4 **columns);
	t_vec4	*(*mat4_param)(t_vec4 *vec4, t_vec4 **columns);
}				t_mat4;

float			**vec4_constr_np(float **values);
t_vec3f			**vec4_constr_p(t_vec3f xyz, float w, t_vec4 **values);
t_vec4			*mat4(t_vec4 vec4, t_vec4 **columns);
t_vec4			**mat4(t_vec4 *vec4, t_vec4 **columns);
t_mat4			rh_fps_view()

#endif