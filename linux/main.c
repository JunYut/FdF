# include <stdio.h>
# include "c_libft.h"
# include "mlx_int.h"
# include "mlx.h"
# include "struct.h"

int main (void)
{

	void *mlx;
	void *win;
	t_data img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "mlx 42");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
								&img.size_line, &img.endian);

	printf("bits_per_pixel: %d\n", img.bits_per_pixel);	// debug
	printf("size_line: %d\n", img.size_line);	// debug

	mlx_loop(mlx);

	return (0);
}
