/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <ecloete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 10:42:29 by ecloete           #+#    #+#             */
/*   Updated: 2017/10/19 14:03:26 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		zoom_m(int keycode, int x, int y, t_values *v)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		zoom_in(v);
	if (keycode == 5)
		zoom_out(v);
	draw(v);
	mlx_put_image_to_window(v->m.mlx, v->m.win, v->m.image, 0, 0);
	return (0);
}

int		motion_hook(int x, int y, t_values *v)
{
    static int old_y = 0;

    (void)x;
    if (old_y < y)
    {
        v->cR += 0.01;
        v->cI += 0.01;
    }
    else
    {
        v->cR -= 0.01;
        v->cI -= 0.01;
    }
    old_y = y;
	draw(v);
	mlx_put_image_to_window(v->m.mlx, v->m.win, v->m.image, 0, 0);
	return (0);
}
