/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 09:35:56 by ecloete           #+#    #+#             */
/*   Updated: 2017/10/19 11:45:27 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		chameleon(t_values *v)
{
	int		i;

	v->cR = v->cR;
	v->cI = v->cI;
	v->newR = 1.5 * (v->x - v->w / 2) / (0.5 * v->zoom * v->w) + v->moveX;
	v->newI = (v->y - v->h / 2) / (0.5 * v->zoom * v->h) + v->moveY;
	i = 0;
	while (v->newR * v->newR + v->newI * v->newI < 4 && i < v->max_iter)
	{
		v->oldR = v->newR;
		v->newR = v->newR * v->newR - v->newI * v->newI + v->cR;
		v->newI = -2 * v->newI * v->oldR + v->cI;
		i++;
	}
	return (i + 250 * 240 * (i % 30));
}
