# pragma once

# ifdef __APPLE__
	# include <OpenGL/gl.h>
	# include "macOS_keys.h"
# elif __linux__
	# include "linux_keys.h"
# endif

# include "FdF.h"

// TODO: make this dynamic
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		offset;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct s_line
{
	t_point	start;
	t_point	end;
	int		dx;
	int		dy;
}				t_line;

typedef struct s_wireframe
{
	t_line	*projection;
	t_line	*rotated;
	t_line	*edges;
	t_point	*vertices;
	float	scale;
	t_point	translate;
	t_point	rotate;
	t_point	center;
	int		edges_count;
	int		vertices_count;
}				t_wireframe;

typedef struct s_frame
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

t_wireframe	*init_wireframe(t_list *map);
void		init_edges(t_wireframe *wireframe);
void		init_vertices(t_point *vertices, t_list *map);

// Projection functions

void		offset_projection(t_wireframe *wireframe);
void		c_projector(t_wireframe *wireframe);
t_point		isometric_projection(t_point p);

// Drawing functions

void		draw_wireframe(t_mlx *mlx, t_wireframe *wireframe);
void		draw_line(t_mlx *mlx, t_line line, int color);

// Render functions

int			render_new_frame(t_frame *frame);
void		renderPixel(t_img *img, int x, int y, int color);

// Event functions

int			quit(t_mlx *mlx);
int			key_hook(int keycode, t_frame *frame);

// Debug functions

void		print_wireframe(t_wireframe *wireframe);
void		print_projection(t_wireframe *wireframe);
void		print_vertices(t_point *vertices, int vertices_count);
void		print_transform(t_wireframe *wireframe);
void		print_center(t_wireframe *wireframe);
void		debug(char *msg);
