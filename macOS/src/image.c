# include "struct.h"

// This function will be called repeatedly by mlx_loop_hook
int render_new_frame(t_mlx *mlx)
{
	static int angle = 0; // This variable retains its value between calls

	// Clear the image buffer
	ft_memset(mlx->img.addr, 0, mlx->img.offset);

	// Draw and rotate the line
	t_line line = {0, {300, 300}, {300, 200}, 0};
	rotateLine(&line, angle);
	drawLine(&mlx->img, line.start.x, line.start.y, line.end.x, line.end.y, 0xFFFFFF);

	// Display the image in the window
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);

	// Increase the angle for the next frame
	angle += 10;
	if (angle >= 360) angle = 0; // Reset the angle after a full rotation

	 // Sleep for 0.5 second
	usleep(500000);

	return (0);
}

void drawPixel(t_image *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
