#include "../includes/fractal.h"

int	set_fractal(int x, int y, int i, t_data *mlx)
{
	int	color;

	if (i == mlx->frac.max_inter)
		color = 0xfefefe;
	else
		color = i * 265;
	my_mlx_pixel_put(mlx, x, y, color);
	return (1);
}

int	draw(t_data *mlx)
{
	double	x;
	double	y;
	int	inter;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y++ < HEIGHT)
		{
			inter = mandelbrot(map_re(x, mlx), map_im(y, mlx), mlx);
			set_fractal(x, y, inter,mlx);
			y++;
		}
		x++;
	}
	return (1);
}

double		mandelbrot(double num_r, double num_i, t_data *mlx)
{
	double	x;
	double	y;
	double	inters;
	double	cache;
	
	x = 0;
	y = 0;
	inters = 0;
	while (inters < mlx->frac.max_inter)
	{
		cache = x * x - y * y + num_r;
		y = 2 * x * y + num_i;
		x = cache;
		if (x * x + y * y > 4) 
				return (inters);
		inters++;
	};
	return (inters);
}
