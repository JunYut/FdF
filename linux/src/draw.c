# include "wireframe.h"

// TODO: remove the color parameter from this function
void	draw_wireframe(t_mlx *mlx, t_wireframe *wireframe, int color)
{
	for (int i = 0; i < wireframe->edges_count; i++)
		draw_line(mlx, wireframe->projection[i], color);
}

// TODO: find a way to draw a line with a gradient color
// also, remove the color parameter from this function
void draw_line(t_mlx *mlx, t_line line, int color)
{
	int steps;
	float incX;
	float incY;
	float x;
	float y;

	x = line.start.x;
	y = line.start.y;
	line.dx = line.end.x - line.start.x;
	line.dy = line.end.y - line.start.y;
	steps = abs(line.dx) > abs(line.dy) ? abs(line.dx) : abs(line.dy);
	incX = line.dx / (float)steps;
	incY = line.dy / (float)steps;
	while (steps)
	{
		renderPixel(&mlx->img, x, y, color);
		x += incX;
		y += incY;
		steps--;
	}

}
