# include "struct.h"

int main (void)
{

	t_mlx mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");

	mlx_loop_hook(mlx.mlx, render_new_frame, &mlx);
	mlx_hook(mlx.win, 17, 0, quit, &mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);

	mlx.img.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	mlx.img.offset = (WIN_HEIGHT * mlx.img.line_length + WIN_WIDTH * (mlx.img.bits_per_pixel / 8));


	mlx_loop(mlx.mlx);

	return (0);
}
