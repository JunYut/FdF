# include "wireframe.h"

void	draw_wireframe(t_mlx *mlx, t_wireframe *wireframe)
{
	// debug("Drawing wireframe...");
	int	i;

	i = -1;
	while (++i < wireframe->edges_count)
	{
		// debug(NULL);
		draw_line(mlx, wireframe->projection[i]);
	}
}

// TODO: find a way to draw a line with a gradient color
// also, remove the color parameter from this function
void draw_line(t_mlx *mlx, t_line line)
{
	int steps;
	float incX;
	float incY;
	float x;
	float y;
	int		i;

	x = line.start.x;
	y = line.start.y;
	line.dx = line.end.x - line.start.x;
	line.dy = line.end.y - line.start.y;
	steps = abs(line.dx) > abs(line.dy) ? abs(line.dx) : abs(line.dy);
	incX = line.dx / (float)steps;
	incY = line.dy / (float)steps;
	i = -1;
	while (++i < steps)
	{
		if (i <= steps / 2)
			renderPixel(&mlx->img, x, y, line.start.color);
		else
			renderPixel(&mlx->img, x, y, line.end.color);
		x += incX;
		y += incY;
	}
}
