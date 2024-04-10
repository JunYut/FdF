# pragma once

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
