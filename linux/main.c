# include <stdio.h>
# include "wireframe.h"

// Draw a plane that has a width of 300, a height of 100 and a depth of 30

int main (void)
{
	t_frame frame;

	// Initialize the mlx and create a window
	frame.mlx.mlx = mlx_init();
	frame.mlx.win = mlx_new_window(frame.mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	frame.wireframe = init_wireframe();
	frame.redraw_flag = 1;

	// Set the loop hook and the key hook
	mlx_loop_hook(frame.mlx.mlx, render_new_frame, &frame);
	mlx_hook(frame.mlx.win, 17, 0, quit, &frame.mlx);
	mlx_key_hook(frame.mlx.win, key_hook, &frame);

	// Create an image
	frame.mlx.img.img = mlx_new_image(frame.mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	frame.mlx.img.addr = mlx_get_data_addr(frame.mlx.img.img, &frame.mlx.img.bits_per_pixel, &frame.mlx.img.line_length, &frame.mlx.img.endian);
	frame.mlx.img.offset = (WIN_HEIGHT * frame.mlx.img.line_length + WIN_WIDTH * (frame.mlx.img.bits_per_pixel / 8));

	// Loop
	mlx_loop(frame.mlx.mlx);

	return (0);
}
