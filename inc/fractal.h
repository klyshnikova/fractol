#ifndef FRACTAL_FRACTAL_H
#define FRACTAL_FRACTAL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "pthread.h"
# define WIDTH 1100
# define THR_N 1000
# define THR_WIDTH 5

typedef struct	s_f
{
	int			endian;
	int			sl;
	int			bpp;
	int			name;
	int			color;
	int			j_m;
	int			x;
	int			y;
	int			y_max;
	int			it;
	int			it_max;
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	double		zoom;
	double		x1;
	double		y1;
	double		moveX;
	double		moveX1;
	double		moveY;
	double		moveY2;
	double		tmp;
}				t_f;

int		mouse_hook(int mousekey, int x, int y, t_f *f);
int		key_hook(int key, t_f *f);
void	mandelbrot_init(t_f *f);
void	*mandelbrot(void *param);
void	f_calc(t_f *f);
void	start(t_f *f);
int		main(int ac, char **av);
void	randoms_calc(t_f *f);
void	julia_calc(t_f *f);
void	mandelbrot_calc(t_f *f);
int		ft_close(void);
void	put_pxl_to_img(t_f *f, int x, int y, int color);
void	julia_init(t_f *f);
int		mouse_julia(int x, int y, t_f *f);
void	*julia(void *param);
void	mandelbrot_flow(t_f *f);
void	julia_flow(t_f *f);
void	randoms_flow(t_f *f);
void	randoms_init(t_f *f);
void	*randoms(void *param);
void	draw_menu(t_f *f);

#endif
