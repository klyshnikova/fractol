/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:13:28 by jemendy           #+#    #+#             */
/*   Updated: 2020/03/03 15:13:29 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	randoms_init(t_f *f)
{
	f->it_max = 50;
	f->zoom = 220;
	f->x1 = -2.2;
	f->y1 = -2.5;
	f->color = 0xb2ee;
}

void	*randoms(void *param)
{
	int		i;
	t_f		*f;

	f = (t_f *)param;
	f->x = 0;
	i = f->y;
	while (f->x < WIDTH)
	{
		f->y = i;
		while (f->y < f->y_max)
		{
			randoms_calc(f);
			f->y++;
		}
		f->x++;
	}
	return (param);
}
