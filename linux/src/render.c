# include "wireframe.h"

int render_new_frame(t_frame *frame)
{
	static int i;

	if (i != 12)
	{
		// Clear the image
		ft_memset(frame->mlx.img.addr, 0, WIN_HEIGHT * frame->mlx.img.line_length + WIN_WIDTH * (frame->mlx.img.bits_per_pixel / 8));

		if (i == 0)
			print_wireframe(frame->wireframe);	// Debug
		// Project the wireframe
		projector(frame->wireframe);
		if (i == 0)
			print_projection(frame->wireframe);	// Debug
		offset_projection(frame->wireframe);
		if (i == 0)
			print_projection(frame->wireframe);	// Debug
		// if (i == 0)
		// 	print_center(frame->wireframe);	// Debug

		// Draw the wireframe
		draw_wireframe(&frame->mlx, frame->wireframe);

		// Draw the image
		mlx_put_image_to_window(frame->mlx.mlx, frame->mlx.win, frame->mlx.img.img, 0, 0);

		++i;
	}

	return (0);
}

int render_resize(t_frame *frame)
{
	int	width;
	int	height;

	mlx_get_screen_size(frame->mlx.mlx, &width, &height);

	mlx_destroy_image(frame->mlx.mlx, frame->mlx.img.img);

	// Create a new image with the new size
	frame->mlx.img.img = mlx_new_image(frame->mlx.mlx, width, height);
	frame->mlx.img.addr = mlx_get_data_addr(frame->mlx.img.img, &frame->mlx.img.bits_per_pixel, &frame->mlx.img.line_length, &frame->mlx.img.endian);

	// Clear the image
	ft_memset(frame->mlx.img.addr, 0, height * frame->mlx.img.line_length + width * (frame->mlx.img.bits_per_pixel / 8));

	// Project the wireframe
	projector(frame->wireframe);
	// print_projection(frame->wireframe);	// Debug
	offset_projection(frame->wireframe);
	// print_projection(frame->wireframe);	// Debug

	// Draw the wireframe
	draw_wireframe(&frame->mlx, frame->wireframe);

	// Draw the image
	mlx_put_image_to_window(frame->mlx.mlx, frame->mlx.win, frame->mlx.img.img, 0, 0);

	return (0);
}


void renderPixel(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
