# include "wireframe.h"

void draw_line(t_mlx *mlx, t_line line, int color)
{
	int dx;
	int dy;
	int x;
	int y;
	int d;
	int d1;
	int d2;
	int ix;
	int iy;

	dx = line.end.x - line.start.x;
	dy = line.end.y - line.start.y;
	ix = (dx > 0) ? 1 : -1;
	iy = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	d = (dx > dy) ? dx : -dy;
	d1 = (dx > dy) ? dx : dy;
	d2 = (dx > dy) ? dy : dx;
	x = line.start.x;
	y = line.start.y;
	while (d1--)
	{
		renderPixel(&mlx->img, x, y, color);
		if (d > 0)
		{
			d += 2 * d2;
			x += ix;
		}
		else
			d += 2 * d1;
		y += iy;
	}
}
