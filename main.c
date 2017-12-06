/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <ecloete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 10:22:45 by ecloete           #+#    #+#             */
/*   Updated: 2017/10/19 14:15:19 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_p(t_values *v)
{
	mlx_destroy_window(v->m.mlx, v->m.win);
	exit(0);
}

void	draw(t_values *val)
{
	val->x = 0;
	val->y = 0;
	while (val->y < val->h)
	{
		val->x = 0;
		while (val->x < val->w)
		{
			if (ft_strcmp(val->name, "julia") == 0)
				val->colour = julia(val);
			if (ft_strcmp(val->name, "mandelbrot") == 0)
				val->colour = mandel(val);
			if (ft_strcmp(val->name, "chameleon") == 0)
				val->colour = chameleon(val);
			putpixel(val);
			val->x++;
		}
		val->y++;
	}
}

int		readkeys(int keycode, t_values *v)
{
	if (keycode == 69)
		zoom_in(v);
	if (keycode == 78)
		zoom_out(v);
	if (keycode == 12)
		v->max_iter *= 2;
	if (keycode == 0)
		if (v->max_iter > 2)
			v->max_iter /= 2;
	if (keycode == 126)
		v->moveY -= 0.4 / v->zoom;
	if (keycode == 125)
		v->moveY += 0.4 / v->zoom;
	if (keycode == 123)
		v->moveX -= 0.4 / v->zoom;
	if (keycode == 124)
		v->moveX += 0.4 / v->zoom;
	if (keycode == 53)
		exit_p(v);
	draw(v);
	mlx_put_image_to_window(v->m.mlx, v->m.win, v->m.image, 0, 0);
	return (0);
}

int		initval(t_values *val)
{
	val->max_iter = 180;
	val->cR = -0.7269;
	val->cI = 0.1889;
	val->zoom = 1;
	val->moveX = 0;
	val->moveY = 0;
	val->h = 500;
	val->w = 500;
	val->x = 0;
	val->y = 0;
	val->m.mlx = mlx_init();
	val->m.win = mlx_new_window(val->m.mlx, val->h, val->w, "Fract'ol");
	val->m.image = mlx_new_image(val->m.mlx, val->w, val->h);
	val->m.data = (unsigned int *)mlx_get_data_addr(val->m.image,
			&val->bpp, &val->lines, &val->endian);
	val->lines /= 4;
	return (0);
}

int		main(int argc, char **argv)
{
	t_values	v;

	if ((argc == 2) && (ft_strcmp(argv[1], "julia") == 0
				|| ft_strcmp(argv[1], "chameleon") == 0
				|| ft_strcmp(argv[1], "mandelbrot") == 0))
	{
		initval(&v);
		v.name = argv[1];
		draw(&v);
		mlx_put_image_to_window(v.m.mlx, v.m.win, v.m.image, 0, 0);
		mlx_key_hook(v.m.win, readkeys, &v);
		mlx_mouse_hook(v.m.win, zoom_m, &v);
		mlx_hook(v.m.win, 6, 0, motion_hook, &v);
		mlx_loop(v.m.mlx);
	}
	else
	{
		ft_putendl("Invalid argument.");
		ft_putendl("Available fractals:\njulia\nmandelbrot\nchameleon");
	}
	return (0);
}
