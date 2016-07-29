/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 13:58:05 by smamba            #+#    #+#             */
/*   Updated: 2016/07/13 14:14:26 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_gui	new_gui(int w, int h, char *title)
{
	t_gui	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, w, h, title);
	env.width = w;
	env.height = h;
	env.title = title;
	env.image = mlx_new_image(env.mlx, w, h);
	env.pixel = mlx_get_data_addr(env.image, &env.bpp, &env.sl, &env.endian);
	return (env);	
}
