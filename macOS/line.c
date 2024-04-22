#include "struct.h"

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
