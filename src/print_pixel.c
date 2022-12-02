#include "../includes/fractal.h"

void	my_mlx_pixel_put(t_data *mlx, int x, int y, int color)
{
	char	*dest;

	dest = mlx->img.addr + (y * mlx->img.line_len + x * (mlx->img.bpp / 8));
	*(unsigned int *)dest = color;
}

int	background(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
			my_mlx_pixel_put(mlx, j++, i, 0xFFFFFF);
		i++;
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img.img, 0, 0);
	return (0);
}
