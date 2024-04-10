#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

void drawGrid(void *mlx, void *win, int x, int y, int color);
int	key_hook(int keycode);
int quit();

int main (void)
{
	void *mlx = mlx_init();
	void *window = mlx_new_window(mlx, 500, 500, "test");

	mlx_pixel_put(mlx, window, 500/2, 500/2, 0xFFFFFF);

	drawGrid(mlx, window, 500, 500, 0xFFFFFF);

	mlx_key_hook(window, key_hook, &mlx);
	mlx_hook(window, 17, 0, quit, mlx);
	mlx_loop(mlx);

	return (0);
}

void drawGrid(void *mlx, void *win, int x, int y, int color)
{
	for (int i = 0; i <= x; i += 1)
		for (int j = 0; j <= y; j += 1)
			if (i % 25 == 0 || j % 25 == 0)
				mlx_pixel_put(mlx, win, i, j, color);
}


int key_hook(int keycode)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return 0;
}

int quit()
{
	exit(EXIT_SUCCESS);
	return (0);
}
