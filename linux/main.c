# include <stdio.h>
# include "c_libft.h"
# include "mlx_int.h"
# include "mlx.h"

int main (void)
{

	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "mlx 42");
	mlx_loop(mlx);

	return (0);
}
