/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:13:41 by jemendy           #+#    #+#             */
/*   Updated: 2020/03/03 15:13:42 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	julia_init(t_f *f)
{
	f->it_max = 50;
	f->zoom = 200;
	f->x1 = -2.0;
	f->y1 = -1.9;
	f->color = 0x9932cc;
	f->moveX = 0.285;
	f->moveX1 = 0.01;
	f->j_m = 1;
}

int		mouse_julia(int x, int y, t_f *f)
{
	if (f->name == 1 && f->j_m == 1)
	{
		f->moveX = x * 2;
		f->moveX1 = y * 2 - 800;
		f_calc(f);
	}
	return (0);
}

void	*julia(void *param)
{
	int		tmp;
	t_f		*f;

	f = (t_f *)param;
	f->x = 0;
	tmp = f->y;
	while (f->x < WIDTH)
	{
		f->y = tmp;
		while (f->y < f->y_max)
		{
			julia_calc(f);
			f->y++;
		}
		f->x++;
	}
	return (param);
}
