# include <stdio.h>
# include <OpenGL/gl.h>
# include "c_libft.h"
# include "mlx.h"
# include "struct.h"

int main (void)
{

	t_mlx mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	mlx.img.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	mlx.img.offset = (WIN_HEIGHT * mlx.img.line_length + WIN_WIDTH * (mlx.img.bits_per_pixel / 8));
	drawPixel(&mlx.img, 100, 100, 0xFFFFFF);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_key_hook(mlx.win, key_hook, &mlx);

	mlx_loop(mlx.mlx);

	return (0);
}




