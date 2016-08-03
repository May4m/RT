#ifndef T_SPHERES_H
# define T_SPHERES_H
# include "tracer.h"
# include "t_sphere.h"

typedef struct		s_spheres
{
	int		top;
	t_sphere	*store;
	int		size;
}			t_spheres;

t_spheres		*new_spheres(int size);
t_spheres		*push_sphere(t_spheres *sps, t_sphere *s);
t_spheres		*scene_one();
#endif
