# include <stdio.h>
# include "wireframe.h"

// Draw a plane that has a width of 300, a height of 100 and a depth of 30

int main (void)
{

	t_mlx mlx;

	// Initialize the mlx and create a window
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");

	// Set the loop hook and the key hook
	mlx_loop_hook(mlx.mlx, render_new_frame, &mlx);
	mlx_hook(mlx.win, 17, 0, quit, &mlx);

	// Create an image
	mlx.img.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	mlx.img.offset = (WIN_HEIGHT * mlx.img.line_length + WIN_WIDTH * (mlx.img.bits_per_pixel / 8));

	// Loop
	mlx_loop(mlx.mlx);

	return (0);
}




