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

// This isn't drawing vertical edges properly
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
	printf("x: %.2f, y: %.2f\n", x, y);
	printf("dx: %d, dy: %d\n", line.dx, line.dy);
	printf("incX: %.2f, incY: %.2f\n\n", incX, incY);
	i = -1;
	while (++i < steps)
	{
		// printf("point: %.2f, %.2f\n", x, y);	// Debug
		if (i <= steps / 2)
			renderPixel(&mlx->img, x, y, line.start.color);
		else
			renderPixel(&mlx->img, x, y, line.end.color);
		x += incX;
		y += incY;
	}
}
