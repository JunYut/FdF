# include "wireframe.h"

int render_new_frame(t_frame *frame)
{
	// Clear the image
	ft_memset(frame->mlx.img.addr, 0, WIN_HEIGHT * frame->mlx.img.line_length + WIN_WIDTH * (frame->mlx.img.bits_per_pixel / 8));

	// Draw the wireframe
	for (int i = 0; i < frame->wireframe->edges_count; i++)
		draw_line(&frame->mlx, frame->wireframe->edges[i], 0xFFFFFF);

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
