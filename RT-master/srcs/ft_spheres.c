/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spheres.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 13:20:22 by smamba            #+#    #+#             */
/*   Updated: 2016/07/17 17:26:54 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/tracer.h"

t_spheres	*new_spheres(int size)
{
	t_spheres	*cap;

	cap = (t_spheres*)malloc(sizeof(t_spheres));
	if (cap == NULL)
		return (NULL);
	cap->store = (t_sphere*)malloc(sizeof(t_sphere) * size);
	if (cap->store == NULL)
	{
		free(cap);
		return (NULL);
	}
	cap->top = 0;
	cap->size = size;
	return (cap);
}

t_spheres	*push_sphere(t_spheres *sps, t_sphere *s)
{
	if (sps == NULL)
		return (NULL);
	if (!(sps->top < sps->size))
		return (NULL);
	sps->store[sps->top] = *s;
	sps->top += 1;
	return (sps);
}

t_sphere	get_sphere(t_spheres *s, int idx)
{
	return (s->store[idx]);
}

void		kill_spheres(t_spheres *sp)
{
	if (sp != NULL)
		free(sp);
}
