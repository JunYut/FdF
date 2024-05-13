# include "wireframe.h"

int render_new_frame(t_frame *frame)
{
	t_wireframe *w;
	t_mlx		*m;

	w = frame->wireframe;
	m = &frame->mlx;
	if (frame->redraw_flag == 1)
	{
		// debug("Redrawing...");
		// Clear the image
		mlx_clear_window(m->mlx, m->win);
		// printf("Start addr: %p\n", (void *)m->img.addr);	// Debug
		// printf("Memory size: %d\n", m->img.offset);	// Debug
		// printf("End addr: %p\n\n", (void *)(m->img.addr + m->img.offset));	// Debug
		ft_bzero(m->img.addr, m->img.offset);

		offset_origin(w);
		rotate(w, w->rotate.x, w->rotate.y, w->rotate.z);
		// debug("Done rotating...");
		c_projector(w, m);
		// debug("Done projecting...");
		scale(w, w->scale);
		// debug("Done scaling...");
		offset_center(w);
		// debug("Done offsetting...");
		translate(w, w->translate.x, w->translate.y);
		// debug("Done translating...");

		// print_transform(w);	// Debug

		draw_wireframe(m, w);
		// debug("Done drawing...\n");

		mlx_put_image_to_window(m->mlx, m->win, m->img.img, 0, 0);
		// debug("Done putting image to window...\n");

		frame->redraw_flag = 0;
	}
	return (0);
}

void renderPixel(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		byte_offset;

	// debug(NULL);
	byte_offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = img->addr + byte_offset;
		*(unsigned int*)dst = color;
	}
}
