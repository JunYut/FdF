# include "wireframe.h"

int render_new_frame(t_frame *frame)
{
	if (frame->redraw_flag == 1)
	{
		debug("Redrawing...");
		// Clear the image
		ft_memset(frame->mlx.img.addr, 0, WIN_HEIGHT * frame->mlx.img.line_length + WIN_WIDTH * (frame->mlx.img.bits_per_pixel / 8));

		rotate(frame->wireframe, frame->wireframe->rotate.x, frame->wireframe->rotate.y, frame->wireframe->rotate.z);
		projector(frame->wireframe);
		scale(frame->wireframe, frame->wireframe->scale);
		offset_projection(frame->wireframe);
		translate(frame->wireframe, frame->wireframe->translate.x, frame->wireframe->translate.y);
		print_transform(frame->wireframe);	// Debug
		// print_projection(frame->wireframe);	// Debug

		draw_wireframe(&frame->mlx, frame->wireframe);

		mlx_put_image_to_window(frame->mlx.mlx, frame->mlx.win, frame->mlx.img.img, 0, 0);

		frame->redraw_flag = 0;
	}
	return (0);
}

void renderPixel(t_img *img, int x, int y, int color)
{
	char *dst;

	// debug(NULL);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
