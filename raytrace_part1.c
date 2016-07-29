#include "tracer.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	
	/* Our ray and a sphere */
	t_sphere s;
	t_ray r;
	
	/* x, y for screen 'resolution' */
	int x, y;

	s.pos.x = 20;
	s.pos.y = 20;
	s.pos.z = 20;
	s.radius = 10;
    
	s.scolor = new_vec3f(0, 0, 0);
    s.ecolor = new_vec3f(3, 2, 3);

	r.dir.x = 0;
	r.dir.y = 0;
	r.dir.z = 1;
	r.origin.z = 0;
	for(y = 0; y < 40; y++){
		r.origin.y = y;
		for(x = 0; x < 40; x++){
			r.origin.x = x;
            float t1, t2;
			t_bool hit = sphere_intersection(&r, &s, &t1, &t2);
			if (hit)
				printf("**");
			else
				printf("..");
		}
		printf("\n");
	}

}
