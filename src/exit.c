/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:14:02 by jemendy           #+#    #+#             */
/*   Updated: 2020/03/03 15:14:03 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		draw_menu(t_f *f)
{
	mlx_string_put(f->mlx, f->win, 30, 30, 0x8b,
			"MENU: ");
	mlx_string_put(f->mlx, f->win, 30, 50, 0x8b0000,
			"Click on the arrows and change the location");
	mlx_string_put(f->mlx, f->win, 30, 70, 0xf54242,
			"Space will put everything back in place");
	mlx_string_put(f->mlx, f->win, 30, 90, 0x6400,
			"Change color 1 - 2");
	mlx_string_put(f->mlx, f->win, 30, 110, 0xcd6600,
			"Change iteration + -");
	mlx_string_put(f->mlx, f->win, 30, 130, 0xa9a9a9,
			"Change the zoom with the mouse");
	mlx_string_put(f->mlx, f->win, 30, 150, 0x056565,
			"Stop/start mouse in Julia");
}

int			ft_close(void)
{
	exit(1);
	return (0);
}

void		put_pxl_to_img(t_f *f, int x, int y, int color)
{
	if (f->x < WIDTH && f->y < WIDTH)
	{
		color = mlx_get_color_value(f->mlx, color);
		ft_memcpy(f->img_ptr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}
