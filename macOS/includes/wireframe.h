# pragma once

# include <math.h>
# include <OpenGL/gl.h>
# include "c_libft.h"
# include "mlx.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

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
	t_line		*projection;
	t_line		*edges;
	t_point		*vertices;
	int			edges_count;
	int			vertices_count;
}				t_wireframe;

typedef struct	s_frame
{
	t_mlx		mlx;
	t_wireframe	*wireframe;
}				t_frame;

// Initialization functions

t_wireframe	*init_wireframe(void);	// This is hardcoded for now


// Projection functions

void	projector(t_wireframe *wireframe);
t_point isometric_projection(t_point p);


// Drawing functions

void	draw_plane(t_mlx *mlx, int color);
void	draw_line(t_mlx *mlx, t_line line, int color);


// Render functions

int		render_new_frame(t_frame *frame);
void	renderPixel(t_img *img, int x, int y, int color);


// Event functions

int		quit(t_mlx *mlx);


// Utility functions

void	clean_up(t_wireframe *wireframe);
