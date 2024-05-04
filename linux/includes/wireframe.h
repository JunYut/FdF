# pragma once

# include <math.h>
# include "c_libft.h"
# include "mlx.h"

// TODO: make this dynamic
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

enum e_keycode
{
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_MINUS = 45,
	KEY_PLUS = 61,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363
};

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			offset;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
}				t_mlx;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct	s_line
{
	t_point		start;
	t_point		end;
	int			dx;
	int			dy;
}				t_line;

typedef struct	s_wireframe
{
	t_line	*projection;
	t_line	*edges;
	t_point	*vertices;
	t_point	center;
	float	scale;
	t_point	translate;
	t_point	rotate;
	int		edges_count;
	int		vertices_count;
}				t_wireframe;

typedef struct	s_frame
{
	t_mlx		mlx;
	t_wireframe	*wireframe;
	int			redraw_flag;
}				t_frame;

// Geometric Transformations

void		scale(t_wireframe *wireframe, float factor);
void		translate(t_wireframe *wireframe, int x, int y);
void		rotate(t_wireframe *wireframe, float x, float y, float z);

// Initialization functions

t_wireframe	*init_wireframe(void);
void		init_edges(t_wireframe *wireframe);
void		init_vertices(t_wireframe *wireframe); // Hardcoded for a cube


// Projection functions

void		offset_projection(t_wireframe *wireframe);
void		projector(t_wireframe *wireframe);
t_point 	isometric_projection(t_point p);


// Drawing functions

void		draw_wireframe(t_mlx *mlx, t_wireframe *wireframe);
void		draw_line(t_mlx *mlx, t_line line, int color);


// Render functions

int			render_new_frame(t_frame *frame);
int			render_resize(t_frame *frame);
void		renderPixel(t_img *img, int x, int y, int color);


// Event functions

int			quit(t_mlx *mlx);
int			key_hook(int keycode, t_frame *frame);


// Utility functions

void		clean_up(t_wireframe *wireframe);


// Debug functions

void		print_wireframe(t_wireframe *wireframe);
void		print_projection(t_wireframe *wireframe);
void		print_vertices(t_wireframe *wireframe);
void		print_center(t_wireframe *wireframe);
void		debug(char *msg);
