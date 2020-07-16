/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:40:03 by jemendy           #+#    #+#             */
/*   Updated: 2020/03/04 15:40:05 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

void	mandelbrot_flow(t_f *f)
{
	t_f			tab[THR_N];
	pthread_t	t[THR_N];
	int			y;

	y = 0;
	while (y < THR_N)
	{
		ft_memcpy((void*)&tab[y], (void*)f, sizeof(t_f));
		tab[y].y = THR_WIDTH * y;
		tab[y].y_max = THR_WIDTH * (y + 1);
		pthread_create(&t[y], NULL, mandelbrot, &tab[y]);
		y++;
	}
	while (y--)
		pthread_join(t[y], NULL);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	julia_flow(t_f *f)
{
	t_f			tab[THR_N];
	pthread_t	t[THR_N];
	int			c;

	c = 0;
	while (c < THR_N)
	{
		ft_memcpy((void*)&tab[c], (void*)f, sizeof(t_f));
		tab[c].y = THR_WIDTH * c;
		tab[c].y_max = THR_WIDTH * (c + 1);
		pthread_create(&t[c], NULL, julia, &tab[c]);
		c++;
	}
	while (c--)
		pthread_join(t[c], NULL);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	randoms_flow(t_f *f)
{
	t_f			tab[THR_N];
	pthread_t	t[THR_N];
	int			i;

	i = 0;
	while (i < THR_N)
	{
		ft_memcpy((void*)&tab[i], (void*)f, sizeof(t_f));
		tab[i].y = THR_WIDTH * i;
		tab[i].y_max = THR_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, randoms, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
