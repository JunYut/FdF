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
		// printf("%d ", wireframe->projection[i].start.x);
		// if (i % 3 == 0 && i != 0)
		// 	printf("\n");
	}
}

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
	// printf("start color: %d\n", line.start.color);	// Debug
	// printf("end color: %d\n", line.end.color);	// Debug
	// printf("start x: %d, y: %d\n", line.start.x, line.start.y);	// Debug
	// printf("end x: %d, y: %d\n", line.end.x, line.end.y); // Debug
	// printf("dx: %d, dy: %d\n", line.dx, line.dy); // Debug
	// printf("incX: %.2f, incY: %.2f\n", incX, incY); // Debug
	// printf("point: %.2f, %.2f\n\n", x, y);	// Debug
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
