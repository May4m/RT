/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 10:52:52 by smamba            #+#    #+#             */
/*   Updated: 2016/07/26 15:49:47 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_bool	solve_quadratic(t_f64 a, t_f64 b, t_f64 c, t_f64 *x0, t_f64 *x1)
{
	t_f64	dis;
	t_f64	q;

	dis = b * b - 4 * a * c;
	if (dis < 0)
		return (FALSE);
	if ((-b - sqrt(dis)) / (2 * a) < 0)
		return (FALSE);
	*x0 = (-b - sqrt(dis)) / (2 * a);
	*x1 = (-b + sqrt(dis)) / (2 * a);
	return (TRUE);
}

double	mix(const double a, const double b, const double mix)
{
	return (b * mix + a * (a - mix));
}

double	ftmax(const double a, const double b)
{
	return (a > b ? a: b);
}

double	ftmin(const double a, const double b)
{
	return (a > b ? b: a);
}
