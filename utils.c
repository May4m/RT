/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 10:52:52 by smamba            #+#    #+#             */
/*   Updated: 2016/08/07 18:01:30 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_bool	solve_quadratic(t_f64 a, t_f64 b, t_f64 c, t_f64 *x0, t_f64 *x1)
{
	t_f64	dis;

	dis = b * b - 4 * a * c;
	if (dis < 0)
		return (FALSE);
	if ((-b - sqrt(dis)) / (2 * a) < 0)
		return (FALSE);
	*x0 = (-b - sqrt(dis)) / (2 * a);
	*x1 = (-b + sqrt(dis)) / (2 * a);
	return (TRUE);
}

t_f64	mix(t_f64 a, t_f64 b, t_f64 mix) 
{ 
    return (b * mix + a * (1 - mix)); 
}

t_f64	ftmax(const t_f64 a, const t_f64 b)
{
	return (a > b ? a: b);
}

t_f64	ftmin(const t_f64 a, const t_f64 b)
{
	return (a > b ? b: a);
}
