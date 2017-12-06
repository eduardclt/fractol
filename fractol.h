/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 10:25:19 by ecloete           #+#    #+#             */
/*   Updated: 2017/10/12 10:25:21 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"

typedef struct		s_mlx
{
	void	*mlx;
    void	*win;
    void	*image;
	unsigned int	*data;
}					t_mlx;

typedef struct  s_values
{
    char        *name;
    double      cR;
    double      cI;
    double      newR;
    double      newI; 
    double      oldR;
    double      oldI;
    double      moveX;
    double      moveY;
    double      zoom;
    int         colour;
    int         max_iter;
    int         h;
    int         w;
    int         x;
    int         y;
    int         bpp;
    int         endian;
    int         lines;
    t_mlx		m;

}               t_values;

int		julia(t_values *val);
int		mandel(t_values *val);
int		chameleon(t_values *v);
int		zoom_m(int button, int x, int y, t_values  *param);
int     motion_hook(int x, int y, t_values *v);
void	putpixel(t_values *v);
void	zoom_in(t_values *v);
void	draw(t_values *val);
void	zoom_out(t_values *v);

#endif