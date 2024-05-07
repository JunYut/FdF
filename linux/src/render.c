# include "wireframe.h"

int render_new_frame(t_frame *frame)
{
	if (frame->redraw_flag == 1)
	{
		debug("Redrawing...");
		// Clear the image
		ft_memset(frame->mlx.img.addr, 0, WIN_HEIGHT * frame->mlx.img.line_length + WIN_WIDTH * (frame->mlx.img.bits_per_pixel / 8));

		rotate(frame->wireframe, frame->wireframe->rotate.x, frame->wireframe->rotate.y, frame->wireframe->rotate.z);
		c_projector(frame->wireframe);
		scale(frame->wireframe, frame->wireframe->scale);
		offset_projection(frame->wireframe);
		translate(frame->wireframe, frame->wireframe->translate.x, frame->wireframe->translate.y);
		print_transform(frame->wireframe);	// Debug
		print_projection(frame->wireframe);	// Debug

		draw_wireframe(&frame->mlx, frame->wireframe);

		mlx_put_image_to_window(frame->mlx.mlx, frame->mlx.win, frame->mlx.img.img, 0, 0);

		frame->redraw_flag = 0;
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
	c_projector(frame->wireframe);
	scale(frame->wireframe, 1);
	offset_projection(frame->wireframe);
	translate(frame->wireframe, 0, 0);

	// Draw the wireframe
	draw_wireframe(&frame->mlx, frame->wireframe);

	// Draw the image
	mlx_put_image_to_window(frame->mlx.mlx, frame->mlx.win, frame->mlx.img.img, 0, 0);

	return (0);
}


void renderPixel(t_img *img, int x, int y, int color)
{
	char *dst;

	// debug(NULL);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
