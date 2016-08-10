/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_environ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:44:28 by smamba            #+#    #+#             */
/*   Updated: 2016/08/10 16:45:45 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_interface	init_tracer(void)
{
	t_interface	i;

	i.gui = new_gui(WIDTH, HEIGHT, "Ray Tracing");
	if ((i.objects = scene_one()) == NULL)
		exit(0);
	return (i);
}

void		cast_ray(int x, int y, t_vec3f *pixel, t_interface *env)
{
	t_vec3f	dir;
	t_ray	ray;
	t_f64	xx;
	t_f64	yy;

	xx = (2 * ((x + 0.5) * (1.0 / WIDTH)) - 1) * env->camera.angle * ARATIO;
	yy = (1 - 2 * ((y + 0.5) * (1.0 / HEIGHT))) * env->camera.angle;
	dir = new_vec3f(xx, yy, 0);
	dir = add_vec3f(&dir, &env->camera.up);
	ray = new_ray(env->camera.pos, normal_vec3f(&dir));
	*pixel = trace_ray(&ray, env->objects, 0);
}

void		render_scene(t_interface *env)
{
	int		x;
	int		y;
	t_vec3f	*image;
	t_vec3f	*pixel;

	y = 0;
	image = (t_vec3f*)malloc(sizeof(t_vec3f) * (WIDTH * HEIGHT));
	if ((pixel = image) == NULL)
		return ;
	while (y < HEIGHT && !(x = 0))
	{
		while (x < WIDTH)
		{
			cast_ray(x, y, pixel++, env);
			x++;
		}
		y++;
	}
	paint_mlx(image, env->gui);
	free(image);
}

void		run_application(t_interface *env)
{
	mlx_key_hook(env->gui.win, onkey_handler, env);
	mlx_expose_hook(env->gui.win, expose_handler, env);
	mlx_loop(env->gui.mlx);
	mlx_destroy_image(env->gui.mlx, env->gui.image);
	kill_stack(&env->objects);
	dispose_garbage();
}
