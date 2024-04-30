# include "wireframe.h"

void draw_plane(t_mlx *mlx, int color)
{
	draw_line(mlx, (t_line){(t_point){100, 100, 0,}, (t_point){700, 100, 0}, 0, 0}, color);
	draw_line(mlx, (t_line){(t_point){100, 100, 0,}, (t_point){100, 500, 0}, 0, 0}, color);
	draw_line(mlx, (t_line){(t_point){700, 100, 0,}, (t_point){700, 500, 0}, 0, 0}, color);
	draw_line(mlx, (t_line){(t_point){100, 500, 0,}, (t_point){700, 500, 0}, 0, 0}, color);

	draw_line(mlx, (t_line){(t_point){100, 100, 0}, (t_point){700, 500, 0}, 0, 0}, color);
}

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
