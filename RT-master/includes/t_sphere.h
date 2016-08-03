#ifndef T_SPHERE_H
# define T_SPHERE_H
# include "tracer.h"

struct			s_sphere
{
	t_vec3f		plane_normal;
	t_vec3f		pos;
	t_vec3f		size;
	t_color		scolor;
	t_color		ecolor;
	t_f64		transparency;
	t_f64		reflection;
	t_f64		radius;
	t_vec3f		(*normal)(t_vec3f*, t_vec3f*);
	t_bool		(*intersect)(t_ray*, struct s_sphere*, t_f64*, t_f64*);
	int			type;
}			t_sphere;

t_sphere		get_sphere(t_spheres *s, int idx);
t_sphere		new_cylinder(t_vec3f p, t_color s, t_color e, t_f64 rf, t_f64 r);
t_sphere		new_light(t_vec3f p, t_color s, t_f64 rf);
t_sphere		new_plane(t_vec3f p, t_color s, t_color e, t_f64 ref);
t_sphere		new_sphere(t_vec3f pos, t_color s, t_color e,
				t_f64 rd, t_f64 r);
#endif
