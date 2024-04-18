# pragma once

# include <stdio.h>
# include <stdlib.h>

# include "math.h"
# include "mlx.h"

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_line
{
	int pixels;
	t_point start;
	t_point end;
	double gradient;
}				t_line;

void drawLine(void *mlx, void *win, int x1, int y1, int x2, int y2, int color);
void drawGrid(void *mlx, void *win, int x, int y, int color);
int	key_hook(int keycode);
int quit();
