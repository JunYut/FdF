# include <stdio.h>
# include <OpenGL/gl.h>
# include "c_libft.h"
# include "mlx.h"
# include "struct.h"

int main (void)
{

	void *mlx;
	void *win;
	t_image img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_loop(mlx);

	return (0);
}
