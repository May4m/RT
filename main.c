/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 16:18:56 by smamba            #+#    #+#             */
/*   Updated: 2016/07/31 15:46:33 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

void	expose(t_vec3f *a, t_gui *gui)
{
	int	x;
	int	y;
	int	i;
	int	pos;

	x = 0;
	y = 0;
	i = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pos = (x * gui->bpp / 8) + (y * gui->sl);
			gui->pixel[pos] = (unsigned char)(ftmin((t_f64)1.0, a[i].z) * 255);
			gui->pixel[pos + 1] = (unsigned char)(ftmin((t_f64)1.0, a[i].y) * 255);
			gui->pixel[pos + 2] = (unsigned char)(ftmin((t_f64)1.0, a[i].x) * 255);
			i++;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(gui->mlx, gui->win, gui->image, 0, 0);
}

void	render(t_objects *s, t_gui *env)
{
	int		x;
	int		y;
	double	xx;
	double	yy;
	double	angle;
	t_ray	ray;
	t_vec3f	*image;
	t_vec3f	dir;
	t_vec3f	*pixel;

	image = (t_vec3f*)malloc(sizeof(t_vec3f) * (WIDTH * HEIGHT));
	pixel = image;
	y = 0;
	angle = tan(M_PI * 0.5 * FOV / 180);
	while (y < HEIGHT && !(x = 0))
	{
		while (x < WIDTH)
		{
			xx = (2 * ((x++ + 0.5) * (1.0 / WIDTH)) - 1) * angle * ARATIO;
			yy = (1 - 2 * ((y + 0.5) * (1.0 / HEIGHT))) * angle;
			dir = new_vec3f(xx, yy, -1);
			ray = new_ray(new_vec3f(0, 0, 0), normal_vec3f(&dir));
			*pixel++ = trace_ray(&ray, s, 0);
		}
		y++;
	}
	expose(image, env);
	free(image);
}

int		main(void)
{
	t_gui		gui;
	t_objects	*vector;

	vector = scene_one();
	gui = new_gui(WIDTH, HEIGHT, "Ray tracer");
	render(vector, &gui);
	mlx_loop(gui.mlx);
	
	free(vector->store);
	free(vector);
	return (0);
}
