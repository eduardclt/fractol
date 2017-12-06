/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 11:17:31 by ecloete           #+#    #+#             */
/*   Updated: 2017/10/19 12:20:32 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_iter(t_values *val)
{
	val->oldR = val->newR;
	val->oldI = val->newI;
	val->newR = val->oldR * val->oldR - val->oldI * val->oldI + val->cR;
	val->newI = 2 * val->oldR * val->oldI + val->cI;
}

int		julia(t_values *val)
{
	int i;

	i = 0;
	val->newR = 1.5 * (val->x - val->w / 2) /
		(0.5 * val->zoom * val->w) + val->moveX;
	val->newI = (val->y - val->h / 2) / (0.5 * val->zoom * val->h) + val->moveY;
	i = 0;
	while (i < val->max_iter)
	{
		julia_iter(val);
		if ((val->newR * val->newR + val->newI * val->newI) > 4)
			break ;
		i++;
	}
	return (i + 250 * 240 * (i % 30));
}
