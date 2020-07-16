/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:13:49 by jemendy           #+#    #+#             */
/*   Updated: 2020/03/03 15:13:49 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	start(t_f *f)
{
	if (f->name == 0)
		mandelbrot_init(f);
	else if (f->name == 1)
		julia_init(f);
	else if (f->name == 2)
		randoms_init(f);
	f_calc(f);
}

void	f_calc(t_f *f)
{
	if (f->it_max < 0)
		f->it_max = 0;
	if (f->name == 0)
		mandelbrot_flow(f);
	else if (f->name == 1)
		julia_flow(f);
	else if (f->name == 2)
		randoms_flow(f);
}

void	mlx_win_init(t_f *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, WIDTH, "Fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, WIDTH);
	f->img_ptr = mlx_get_data_addr(f->img,
			&f->bpp, &f->sl, &f->endian);
}

int		f_str(char **av, t_f *f)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		f->name = 0;
	else if (ft_strcmp(av[1], "julia") == 0)
		f->name = 1;
	else if (ft_strcmp(av[1], "randoms") == 0)
		f->name = 2;
	else
	{
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\", \"randoms\"");
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_f	*f;

	if (!(f = (t_f *)malloc(sizeof(t_f))))
		return (-1);
	if (ac == 2)
	{
		mlx_win_init(f);
		if ((f_str(av, f)) == 0)
			return (0);
		start(f);
		mlx_hook(f->win, 6, 1L < 6, mouse_julia, f);
		mlx_hook(f->win, 17, 0L, ft_close, f);
		mlx_key_hook(f->win, key_hook, f);
		mlx_mouse_hook(f->win, mouse_hook, f);
		draw_menu(f);
		mlx_loop(f->mlx);
	}
	else
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\", \"randoms\"");
	return (0);
}
