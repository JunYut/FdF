# include <stdio.h>
# include <OpenGL/gl.h>
# include "c_libft.h"
# include "mlx.h"
# include "struct.h"

int main (void)
{

	void *mlx;
	void *win;
	t_image img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.offset = (WIN_HEIGHT * img.line_length + WIN_WIDTH * (img.bits_per_pixel / 8));
	drawPixel(&img, 100, 100, 0xFFFFFF);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	printf("bits_per_pixel: %d\n", img.bits_per_pixel);
	printf("line_length: %d\n", img.line_length);
	printf("endian: %d\n", img.endian);
	printf("offset: %d\n", img.offset);

	mlx_loop(mlx);

	return (0);
}
