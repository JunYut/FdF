# include <stdio.h>
# include "c_libft.h"
# include "mlx_int.h"
# include "mlx.h"

int main (void)
{

	void *mlx;
	void *win;
	void *img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "mlx 42");
	img = mlx_new_image(mlx, 800, 600);
	mlx_loop(mlx);

	return (0);
}
