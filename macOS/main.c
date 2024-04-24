# include <stdio.h>
# include <OpenGL/gl.h>
# include "struct.h"

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
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);

	// Create an image
	mlx.img.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	mlx.img.offset = (WIN_HEIGHT * mlx.img.line_length + WIN_WIDTH * (mlx.img.bits_per_pixel / 8));

	// Draw a plane from top-down view
	// drawLine(&mlx.img, 0, 	0, 	 300, 0,   0xFFFFFF);
	// drawLine(&mlx.img, 0, 	0, 	 0,   100, 0xFFFFFF);
	// drawLine(&mlx.img, 0, 	100, 300, 100, 0xFFFFFF);
	// drawLine(&mlx.img, 300, 100, 300, 0,   0xFFFFFF);

	// Draw a plane from profile view
	// drawLine(&mlx.img, 0, 	150,	  300, 150, 	 0xFFFFFF);
	// drawLine(&mlx.img, 0, 	150, 	  0,   150 + 30, 0xFFFFFF);
	// drawLine(&mlx.img, 0, 	150 + 30, 300, 150 + 30, 0xFFFFFF);
	// drawLine(&mlx.img, 300, 150 + 30, 300, 150, 	 0xFFFFFF);

	t_line line = {0, {0, 0}, {100, 0}, 0};
	drawLine(&mlx.img, line.start.x, line.start.y, line.end.x, line.end.y, 0xFFFFFF);
	rotateLine(&line, 45);
	drawLine(&mlx.img, line.start.x, line.start.y, line.end.x, line.end.y, 0xFFFFFF);

	// A simple 3D cube
	// Draw the front face
	// drawLine(&mlx.img, 0,   0,   100, 0,   0xFFFFFF);
	// drawLine(&mlx.img, 0,   0,   0,   100, 0xFFFFFF);
	// drawLine(&mlx.img, 0,   100, 100, 100, 0xFFFFFF);
	// drawLine(&mlx.img, 100, 100, 100, 0,   0xFFFFFF);

	// // Draw the back face
	// drawLine(&mlx.img, 30,  30,  130, 30,  0xFFFFFF);
	// drawLine(&mlx.img, 30,  30,  30,  130, 0xFFFFFF);
	// drawLine(&mlx.img, 30,  130, 130, 130, 0xFFFFFF);
	// drawLine(&mlx.img, 130, 130, 130, 30,  0xFFFFFF);

	// // Connect the corners
	// drawLine(&mlx.img, 0,   0,   30,  30,  0xFFFFFF);
	// drawLine(&mlx.img, 0,   100, 30,  130, 0xFFFFFF);
	// drawLine(&mlx.img, 100, 100, 130, 130, 0xFFFFFF);
	// drawLine(&mlx.img, 100, 0,   130, 30,  0xFFFFFF);

	// Put the image to the window
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);

	// Loop
	mlx_loop(mlx.mlx);

	return (0);
}




