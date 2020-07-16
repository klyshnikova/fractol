/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:42:40 by jemendy           #+#    #+#             */
/*   Updated: 2020/03/04 15:42:42 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	randoms_calc(t_f *f)
{
	f->moveY = f->x / f->zoom + f->x1;
	f->moveY2 = f->y / f->zoom + f->y1;
	f->it = 0;
	while (f->moveY * f->moveY + f->moveY2
			* f->moveY2 < 4 && f->it < f->it_max)
	{
		f->tmp = f->moveY;
		f->moveY = f->moveY * f->moveY -
				f->moveY2 * f->moveY2 - 0.8 + (f->moveX / WIDTH);
		f->moveY2 = j0(2 * f->moveY2 * f->tmp + f->moveX1 / WIDTH);
		f->it++;
	}
	if (f->it == f->it_max)
		put_pxl_to_img(f, f->x, f->y, 0x000000);
	else
		put_pxl_to_img(f, f->x, f->y, (f->color * f->it));
}

void	julia_calc(t_f *f)
{
	f->moveY = f->x / f->zoom + f->x1;
	f->moveY2 = f->y / f->zoom + f->y1;
	f->it = 0;
	while (f->moveY * f->moveY + f->moveY2
			* f->moveY2 < 4 && f->it < f->it_max)
	{
		f->tmp = f->moveY;
		f->moveY = f->moveY * f->moveY -
				f->moveY2 * f->moveY2 - 0.8 + (f->moveX / WIDTH);
		f->moveY2 = 2 * f->moveY2 * f->tmp + f->moveX1 / WIDTH;
		f->it++;
	}
	if (f->it == f->it_max)
		put_pxl_to_img(f, f->x, f->y, 0x000000);
	else
		put_pxl_to_img(f, f->x, f->y, (f->color * f->it));
}

void	mandelbrot_calc(t_f *f)
{
	f->moveX = f->x / f->zoom + f->x1;
	f->moveX1 = f->y / f->zoom + f->y1;
	f->moveY = 0;
	f->moveY2 = 0;
	f->it = 0;
	while (f->moveY * f->moveY + f->moveY2 *
			f->moveY2 < 4 && f->it < f->it_max)
	{
		f->tmp = f->moveY;
		f->moveY = f->moveY * f->moveY -
				f->moveY2 * f->moveY2 + f->moveX;
		f->moveY2 = 2 * f->moveY2 * f->tmp + f->moveX1;
		f->it++;
	}
	if (f->it == f->it_max)
		put_pxl_to_img(f, f->x, f->y, 0x000000);
	else
		put_pxl_to_img(f, f->x, f->y, (f->color * f->it));
}
