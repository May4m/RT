
#ifndef ENGINE_H
# define ENGINE_H
# include "tracer.h"
# define MAX_RAY_DEPTH 10

t_vec3f		get_reflection_dir(t_vec3f *nhit, t_vec3f *dir);
t_ray		reflected_ray(t_ray *r, t_vec3f *d, t_vec3f *n, t_vec3f *p);
t_ray		refracted_ray(t_ray *r, t_vec3f *d, t_vec3f *n, t_vec3f *p);
t_params	get_closest_primitive(t_ray *ray, t_objects *sp);
t_color		defualt_glossy_shading(t_color *r, t_color *f,
				t_f64 e, t_object *p);
t_vec3f		phong_shading(t_vec3f t, t_ray *r, t_params p,
				t_vec3f l, t_color e);
t_color		lambertian_shading(t_vec3f t, t_params p, t_vec3f l, t_color s);
t_color		compute_ideal_refractions(t_ray *r, t_bool inside, t_params p);
#endif
