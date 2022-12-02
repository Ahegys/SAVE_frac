#include "../includes/fractal.h"
#include <stdlib.h>

int	new_window()
{
	t_data  mlx;
	t_img	img;

	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, HEIGHT, WIDTH, "Fractal");
	event_caller(&mlx, &img);
	return(1);

}

int	event_caller(t_data *mlx, t_img *img)
{
	img->img = mlx_new_image(mlx->init, HEIGHT, WIDTH);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
	mlx->img = *img;
	init_m(mlx);
	mlx_loop_hook(mlx->init, &render, mlx);
	mlx_key_hook(mlx->win, &close_window, mlx);
	mlx_loop(mlx->init);
	return (0);
}
int	close_window(int keysym, t_data *mlx)
{
	if (keysym == ESC)
	{
		mlx_destroy_window(mlx->init, mlx->win);
		mlx_destroy_display(mlx->init);
		if (mlx->init)
			free(mlx->init);
		exit(0);
	}
	return (0);
}
