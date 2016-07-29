#include "tracer.h"

t_spheres	*scene_one()
{
	t_spheres   *vector = new_spheres(4);

	t_sphere	sp1	= new_sphere(new_vec3f(0, -10004, -20),
									 new_vec3f(.3, .3, .3),
									 new_vec3f(.1, .1, .1),
									 100000, 1);
	t_sphere    sp2 = new_sphere(new_vec3f(-4.0, 0, -50),
                                 new_color(.8, .8, .8),
                                 new_color(0., 0., 0.),
                                 4, 0);
	t_sphere    sp5 = new_light(new_vec3f(0, 20.0, -30),
                                 new_color(1.5, 1.5, 1.5), 3);
	push_sphere(vector, &sp1);
	push_sphere(vector, &sp2);
	push_sphere(vector, &sp5);
	return (vector);
}
