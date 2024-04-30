# include "wireframe.h"

int quit(t_mlx *mlx)
{
	ft_printf("Exiting...\n");
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}
