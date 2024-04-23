# include "struct.h"

int render_new_frame(void)
{

	return (0);
}

void drawPixel(t_image *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
