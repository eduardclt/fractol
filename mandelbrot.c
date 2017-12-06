/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 11:13:13 by ecloete           #+#    #+#             */
/*   Updated: 2017/10/19 11:53:57 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_m(t_values *val)
{
	val->newR = 0;
	val->newI = 0;
	val->oldR = 0;
	val->oldI = 0;
}

void	mandel_iter(t_values *val, double pr, double pi)
{
	val->oldR = val->newR;
	val->oldI = val->newI;
	val->newR = val->oldR * val->oldR - val->oldI * val->oldI + pr;
	val->newI = 2 * val->oldR * val->oldI + pi;
}

int		mandel(t_values *val)
{
	int		i;
	double	pr;
	double	pi;

	i = 0;
	pr = 1.5 * (val->x - val->w / 2) / (0.5 * val->zoom * val->w) + val->moveX;
	pi = (val->y - val->h / 2) / (0.5 * val->zoom * val->h) + val->moveY;
	init_m(val);
	val->newR = 1.5 * (val->x - val->w / 2) /
		(0.5 * val->zoom * val->w) + val->moveX;
	val->newI = (val->y - val->h / 2) / (0.5 * val->zoom * val->h) + val->moveY;
	i = 0;
	while (i < val->max_iter)
	{
		mandel_iter(val, pr, pi);
		if ((val->newR * val->newR + val->newI * val->newI) > 4)
			break ;
		i++;
	}
	return (i + 250 * 240 * (i % 30));
}
