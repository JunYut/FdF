# include "wireframe.h"

int render_new_frame(t_frame *frame)
{
	if (frame->redraw_flag == 1)
	{
		// debug("Redrawing...");
		// Clear the image
		mlx_clear_window(frame->mlx.mlx, frame->mlx.win);
		// printf("Start addr: %p\n", (void *)frame->mlx.img.addr);	// Debug
		// printf("Memory size: %d\n", frame->mlx.img.offset);	// Debug
		// printf("End addr: %p\n\n", (void *)(frame->mlx.img.addr + frame->mlx.img.offset));	// Debug
		ft_bzero(frame->mlx.img.addr, frame->mlx.img.offset);

		rotate(frame->wireframe, frame->wireframe->rotate.x, frame->wireframe->rotate.y, frame->wireframe->rotate.z);
		// debug("Done rotating...");
		c_projector(frame->wireframe);
		// debug("Done projecting...");
		scale(frame->wireframe, frame->wireframe->scale);
		// debug("Done scaling...");
		offset_projection(frame->wireframe);
		// debug("Done offsetting...");
		translate(frame->wireframe, frame->wireframe->translate.x, frame->wireframe->translate.y);
		// debug("Done translating...");

		// print_transform(frame->wireframe);	// Debug

		draw_wireframe(&frame->mlx, frame->wireframe);
		// debug("Done drawing...\n");

		mlx_put_image_to_window(frame->mlx.mlx, frame->mlx.win, frame->mlx.img.img, 0, 0);
		// debug("Done putting image to window...\n");

		frame->redraw_flag = 0;
	}
	return (0);
}

void renderPixel(t_img *img, int x, int y, int color)
{
	char *dst;

	// debug(NULL);
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}
