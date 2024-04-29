# include "wireframe.h"

void render_new_frame(t_mlx *mlx)
{
	// Clear the image
	ft_memset(mlx->img.addr, 0, WIN_HEIGHT * mlx->img.line_length + WIN_WIDTH * (mlx->img.bits_per_pixel / 8));

	// Draw a plane
	draw_plane(mlx, (t_point){WIN_WIDTH / 2, WIN_HEIGHT / 2, 0}, (t_point){300, 100, 30});

	// Draw the image
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

void renderPixel(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
