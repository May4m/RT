/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:14:28 by smamba            #+#    #+#             */
/*   Updated: 2016/07/31 15:24:31 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACER_H
# define TRACER_H
# define TRUE 1
# define FALSE 0
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# define WIDTH 1200
# define HEIGHT 900
# define ARATIO WIDTH / (float)HEIGHT
# define FOV 30
# define BIAS 1e-4

enum			e_objects
{
	SPHERE = 1,
	CONE = 2,
	CYLINDER = 3,
	PLANE = 4,
	BOX = 4
};

typedef int		t_bool;
typedef double	t_f64;
typedef float	t_f32;

typedef struct	s_gui
{
	void	*mlx;
	void	*win;
	char	*title;
	int		width;
	int		height;
	int		bpp;
	int		endian;
	int		sl;
	void	*image;
	char	*pixel;
}				t_gui;

typedef struct	s_vec3f
{
	double	x;
	double	y;
	double	z;
}				t_vec3f;

typedef t_vec3f	t_color;

typedef struct	s_ray
{
	t_vec3f	origin;
	t_vec3f	dir;
}				t_ray;

typedef struct	s_sphere
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
}				t_sphere;

typedef struct	s_spheres
{
	int			top;
	t_sphere	*store;
	int			size;
}				t_spheres;

typedef struct	s_camera
{
	t_vec3f	pos;
	t_vec3f	dir;
	double	fov;
}				t_camera;

typedef struct	s_light
{
	t_sphere	light;
}				t_light;

typedef struct	s_params
{
	t_ray		*ray;
	t_vec3f		nhit;
	t_vec3f		phit;
	int			depth;
	double		tnear;
	t_sphere	*sphere;
}				t_params;

double			mix(const double a, const double b, const double mix);
double			ftmin(const double a, const double b);
double			ftmax(const double a, const double b);
t_gui			new_gui(int w, int h, char *title);
t_spheres		*new_spheres(int size);
t_spheres		*push_sphere(t_spheres *sps, t_sphere *s);
t_spheres		*scene_one();
t_sphere		get_sphere(t_spheres *s, int idx);
t_sphere		new_cylinder(t_vec3f p, t_color s, t_color e, t_f64 rf, t_f64 r);
t_sphere		new_light(t_vec3f p, t_color s, t_f64 rf);
t_sphere		new_plane(t_vec3f p, t_color s, t_color e, t_f64 ref);
void			kill_spheres(t_spheres *sp);
t_color			new_color(double r, double g, double b);
t_color			new_uni_color(double a);
t_ray			dup_ray(t_ray *r);
t_ray			new_ray(t_vec3f origin, t_vec3f dir);
t_ray			*new_hray(t_vec3f o, t_vec3f dir);
t_sphere		new_sphere(t_vec3f pos, t_color s, t_color e,
		t_f64 rd, t_f64 r);
t_vec3f			cpy_vec3f(t_vec3f *dest, t_vec3f *src);
t_vec3f			dup_vec3f(t_vec3f *src);
t_vec3f			new_vec3f(double x, double y, double z);
t_vec3f			mat_vec3f(t_vec3f *v1, t_vec3f *t1);
t_vec3f			add_vec3f(t_vec3f *v1, t_vec3f *v2);
t_vec3f			sub_vec3f(t_vec3f *v1, t_vec3f *v2);
t_vec3f			normal_vec3f(t_vec3f *vec);
t_vec3f			scale_vec3f(t_vec3f *s, double scale);
t_vec3f			trace_ray(t_ray *ray, t_spheres *sp, int depth);
double			length_vec3f(t_vec3f *vec);
double			dot_vec3f(t_vec3f *v1, t_vec3f *v2);
t_bool			sphere_intersection(t_ray *r, t_sphere *s, t_f64 *t, t_f64 *a);
t_bool			intersect_ray(t_ray *r, t_sphere *s);
t_vec3f			trace_ray_2(t_ray *ray, t_spheres *sp, double depth);
t_vec3f			sphere_normal(t_vec3f *phit, t_vec3f *pos);
t_vec3f			cylinder_normal(t_vec3f *phit, t_vec3f *pos);
t_vec3f			plane_normal(t_vec3f *phit, t_vec3f *pos);
t_color			phone_shading(t_vec3f t, t_params p, t_vec3f ld, t_color s);
t_color			lambertian_shading(t_vec3f t, t_params p, t_vec3f l, t_color s);
t_color			specular_shading(t_vec3f t, t_params p, t_vec3f l, t_color s);
t_bool			solve_quadratic(t_f64 a, t_f64 b, t_f64 c, t_f64 *t0, t_f64 *t1);
t_bool			cylinder_intersection(t_ray *r, t_sphere *s, t_f64 *t0, t_f64 *t1);
t_bool			plane_intersection(t_ray *r, t_sphere *s, t_f64 *t0, t_f64 *t1);
#endif
