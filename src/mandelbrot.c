/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:13:56 by jemendy           #+#    #+#             */
/*   Updated: 2020/03/03 15:13:57 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mandelbrot_init(t_f *f)
{
	f->it_max = 1000;
	f->zoom = 300;
	f->x1 = -2.05;
	f->y1 = -1.3;
	f->color = 265;
}

void	*mandelbrot(void *param)
{
	t_f		*f;
	int		tmp;

	f = (t_f *)param;
	f->x = 0;
	tmp = f->y;
	while (f->x < WIDTH)
	{
		f->y = tmp;
		while (f->y < f->y_max)
		{
			mandelbrot_calc(f);
			f->y++;
		}
		f->x++;
	}
	return (param);
}
