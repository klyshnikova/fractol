/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:13:35 by jemendy           #+#    #+#             */
/*   Updated: 2020/03/03 15:13:35 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		key_hooks(int key, t_f *f)
{
	if (key == 83)
		f->color = 4567;
	else if (key == 82)
		f->j_m = !f->j_m;
	return (0);
}

int		key_hook(int key, t_f *f)
{
	if (key == 53)
		exit(1);
	else if (key == 69)
		f->it_max += 50;
	else if (key == 78)
		f->it_max -= 50;
	else if (key == 123)
		f->x1 += 30 / f->zoom;
	else if (key == 124)
		f->x1 -= 30 / f->zoom;
	else if (key == 125)
		f->y1 -= 30 / f->zoom;
	else if (key == 126)
		f->y1 += 30 / f->zoom;
	else if (key == 49)
		start(f);
	else if (key == 84)
		f->color = 1677216;
	key_hooks(key, f);
	f_calc(f);
	return (0);
}

void	ft_zoom(int x, int y, t_f *f)
{
	f->x1 = (x / f->zoom + f->x1) - (x / (f->zoom * 1.3));
	f->y1 = (y / f->zoom + f->y1) - (y / (f->zoom * 1.3));
	f->zoom *= 1.3;
	f->it_max++;
}

void	ft_zooms(int x, int y, t_f *f)
{
	f->x1 = (x / f->zoom + f->x1) - (x / (f->zoom / 1.3));
	f->y1 = (y / f->zoom + f->y1) - (y / (f->zoom / 1.3));
	f->zoom /= 1.3;
	f->it_max--;
}

int		mouse_hook(int mousekey, int x, int y, t_f *f)
{
	if (mousekey == 4 || mousekey == 1)
		ft_zoom(x, y, f);
	else if (mousekey == 5 || mousekey == 2)
		ft_zooms(x, y, f);
	f_calc(f);
	return (0);
}
