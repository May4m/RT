#ifndef T_RAY_H
# define T_RAY_H
# include "tracer.h"
# include "t_vec3f.h"

typedef struct	s_ray
{
	t_vec3f	origin;
	t_vec3f	dir;
}		t_ray;

t_ray		dup_ray(t_ray *r);
t_ray		new_ray(t_vec3f origin, t_vec3f dir);
t_ray		*new_hray(t_vec3f o, t_vec3f dir);
#endif
