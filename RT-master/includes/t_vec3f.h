#ifndef T_VEC3F_H
# define T_VEC3F_H
# include "tracer.h"

typedef struct	s_vec3f
{
	double	x;
	double	y;
	double	z;
}		t_vec3f;

typedef t_vec3f	t_color;

t_vec3f			cpy_vec3f(t_vec3f *dest, t_vec3f *src);
t_vec3f			dup_vec3f(t_vec3f *src);
t_vec3f			new_vec3f(double x, double y, double z);
t_vec3f			mat_vec3f(t_vec3f *v1, t_vec3f *t1);
t_vec3f			add_vec3f(t_vec3f *v1, t_vec3f *v2);
t_vec3f			sub_vec3f(t_vec3f *v1, t_vec3f *v2);
t_vec3f			normal_vec3f(t_vec3f *vec);
t_vec3f			scale_vec3f(t_vec3f *s, double scale);
t_vec3f			trace_ray(t_ray *ray, t_spheres *sp, int depth);
t_vec3f			trace_ray_2(t_ray *ray, t_spheres *sp, double depth);
t_vec3f			sphere_normal(t_vec3f *phit, t_vec3f *pos);
t_vec3f			cylinder_normal(t_vec3f *phit, t_vec3f *pos);
t_vec3f			plane_normal(t_vec3f *phit, t_vec3f *pos);
t_color			new_color(double r, double g, double b);
t_color			new_uni_color(double a);
t_color			phone_shading(t_vec3f t, t_params p, t_vec3f ld, t_color s);
t_color			lambertian_shading(t_vec3f t, t_params p, t_vec3f l, t_color s);
t_color			specular_shading(t_vec3f t, t_params p, t_vec3f l, t_color s);
#endif
