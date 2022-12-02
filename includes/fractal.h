#ifndef FRACTOL_H
# define FRACTOL_H

#include "../minilibx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

# define WIDTH 700
# define HEIGHT 700

// ===================== MACROS

# define ESC 65307

typedef struct l_img
{
	void	*img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
	int	color;
} t_img;

typedef struct l_frac
{
        double  min_re;
        double  max_re;
        double  min_im;
		double  max_im;
        int  	max_inter;
        int 	min_inter;
} t_frac;

typedef	struct l_data
{
	void	*init;
	void	*win;
	t_img	img;
	t_frac frac;
} t_data;

int	new_window();
int     close_window(int keysym, t_data *mlx);
int	event_caller(t_data *mlx, t_img *img);
//int	background(t_data *mlx, t_img *img);
void	my_mlx_pixel_put(t_data *mlx, int x, int y, int color);
//int	square(t_data *mlx, t_img *img, int pointX, int pointY);
int	render(t_data *mlx);
int	background(t_data *mlx);
double    map_re(int x, t_data *mlx);
double    map_im(int y, t_data *mlx);
void    init_m(t_data *mlx);
int	draw(t_data *mlx);
int	set_fractal(int x, int y, int i, t_data *mlx);
double		mandelbrot(double num_r, double num_i, t_data *mlx);
#endif // FRACTOL_H

