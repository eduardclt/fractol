/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 12:16:31 by ecloete           #+#    #+#             */
/*   Updated: 2017/10/19 11:55:30 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_values *v)
{
	if (v->zoom <= 0.9 && v->zoom > 0.2)
		v->zoom *= 3;
	v->zoom *= 1.8;
	if (v->max_iter < 300)
		v->max_iter += 30;
}

void	zoom_out(t_values *v)
{
	if (v->zoom <= 1 && v->zoom > 0.2)
		v->zoom -= 0.2;
	else
		v->zoom /= 1.8;
	if (v->max_iter > 180)
		v->max_iter -= 30;
}
