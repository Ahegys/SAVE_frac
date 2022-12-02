#include "../includes/fractal.h"

int		render(t_data *mlx)
{
	draw(mlx);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img.img, 0, 0);
	return (0);
}

double    map_re(int x, t_data *mlx)
{
    double    range;

    range = mlx->frac.max_re - mlx->frac.min_re;
    return (mlx->frac.min_re + (x * range) / WIDTH);
}

double    map_im(int y, t_data *mlx)
{
    double    range;

    range = mlx->frac.max_im - mlx->frac.min_im;
    return (mlx->frac.min_im + (y * range) / HEIGHT);
}

void    init_m(t_data *mlx)
{
    mlx->frac.min_re = -2.2;
    mlx->frac.max_re = 3.0;
    mlx->frac.min_im = -1.8;
    mlx->frac.max_im = (mlx->frac.max_re - mlx->frac.min_re) * HEIGHT / WIDTH + mlx->frac.min_im;
    mlx->frac.max_inter = 100;
}

