#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

void drawLine(void *mlx, void *win, int x1, int y1, int x2, int y2, int color);
void drawGrid(void *mlx, void *win, int x, int y, int color);
int	key_hook(int keycode);
int quit();

int main (void)
{
	void *mlx = mlx_init();
	void *window = mlx_new_window(mlx, 500, 500, "test");

	drawGrid(mlx, window, 500, 500, 0xFFFFFF);

	drawLine(mlx, window, 0, 0, 100, 200, 0xFF0000);

	mlx_key_hook(window, key_hook, &mlx);
	mlx_hook(window, 17, 0, quit, mlx);
	mlx_loop(mlx);

	return (0);
}

void drawLine(void *mlx, void * win, int x1, int y1, int x2, int y2, int color)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;
	float X = x1;
	float Y = y1;

	printf("dx: %d, dy: %d, steps: %d, Xinc: %f, Yinc: %f\n", dx, dy, steps, Xinc, Yinc);
	for (int i = 0; i <= steps; i += 1)
	{
		mlx_pixel_put(mlx, win, X, Y, color);
		X += Xinc;
		Y += Yinc;
	}
}

void drawGrid(void *mlx, void *win, int x, int y, int color)
{
	for (int i = 0; i <= x; i += 1)
		for (int j = 0; j <= y; j += 1)
			if (i % 10 == 0 || j % 10 == 0)
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
