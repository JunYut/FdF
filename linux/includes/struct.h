# pragma once

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "mlx.h"
# include "c_libft.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

enum colors
{
	BLACK = 0x000000,
	WHITE = 0xFFFFFF,
	RED = 0xFF0000,
	GREEN = 0x00FF00,
	BLUE = 0x0000FF,
	YELLOW = 0xFFFF00,
	CYAN = 0x00FFFF,
	MAGENTA = 0xFF00FF
};

enum keys
{
	ESC = 53,
	SPACE = 49,
	LEFT = 123,
	RIGHT = 124,
	UP = 126,
	DOWN = 125,
	W = 13,
	A = 0,
	S = 1,
	D = 2
};

enum mouse
{
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	MIDDLE_CLICK = 3,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5

};

typedef struct	s_image
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
	int	offset;
}				t_image;

typedef struct	s_mlx
{
	void *mlx;
	void *win;
	t_image img;
}				t_mlx;

typedef struct	s_point
{
	int x;
	int y;
	int z;
}				t_point2D;

typedef struct	s_line
{
	int pixels;
	t_point2D start;
	t_point2D end;
	double gradient;
}				t_line;

int render_new_frame(t_mlx *mlx);

void rotateLine(t_line *line, double angleX, double angleY, double angleZ);
void drawLine(t_image *img, int x1, int y1, int x2, int y2, int color);
void drawPixel(t_image *img, int x, int y, int color);
void drawGrid(void *mlx, void *win, int x, int y, int color);

void rotateX(t_point2D *point, t_point2D center, double angle);
void rotateY(t_point2D *point, t_point2D center, double angle);
void rotateZ(t_point2D *point, t_point2D center, double angle);

int	key_hook(int keycode, t_mlx *mlx);
int quit(t_mlx *mlx);
int up(void);
int down(void);
int left(void);
int right(void);
int mouse_hook(int button, int x, int y, t_mlx *mlx);
