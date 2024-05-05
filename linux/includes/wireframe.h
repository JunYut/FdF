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
	KEY_Q = 113,
	KEY_E = 101,
	KEY_MINUS = 45,
	KEY_PLUS = 61,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363
};

enum e_x11_events
{
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	BUTTON_PRESS = 4,
	BUTTON_RELEASE = 5,
	MOTION_NOTIFY = 6,
	ENTER_NOTIFY = 7,
	LEAVE_NOTIFY = 8,
	FOCUS_IN = 9,
	FOCUS_OUT = 10,
	KEYMAP_NOTIFY = 11,
	EXPOSE = 12,
	VISIBILITY_NOTIFY = 15,
	CREATE_NOTIFY = 16,
	DESTROY_NOTIFY = 17,
	UNMAP_NOTIFY = 18,
	MAP_NOTIFY = 19,
	MAP_REQUEST = 20,
	REPARENT_NOTIFY = 21,
	CONFIGURE_NOTIFY = 22,
	CONFIGURE_REQUEST = 23,
	GRAVITY_NOTIFY = 24,
	RESIZE_REQUEST = 25,
	CIRCULATE_NOTIFY = 26,
	CIRCULATE_REQUEST = 27,
	PROPERTY_NOTIFY = 28,
	SELECTION_CLEAR = 29,
	SELECTION_REQUEST = 30,
	SELECTION_NOTIFY = 31,
	COLORMAP_NOTIFY = 32,
	CLIENT_MESSAGE = 33,
	MAPPING_NOTIFY = 34,
	GENERIC_EVENT = 35,
	LAST_EVENT = 36
};

enum e_x11_masks
{
	NO_EVENT_MASK = 0,
	KEY_PRESS_MASK = 1 << 0,
	KEY_RELEASE_MASK = 1 << 1,
	BUTTON_PRESS_MASK = 1 << 2,
	BUTTON_RELEASE_MASK = 1 << 3,
	ENTER_WINDOW_MASK = 1 << 4,
	LEAVE_WINDOW_MASK = 1 << 5,
	POINTER_MOTION_MASK = 1 << 6,
	POINTER_MOTION_HINT_MASK = 1 << 7,
	BUTTON1_MOTION_MASK = 1 << 8,
	BUTTON2_MOTION_MASK = 1 << 9,
	BUTTON3_MOTION_MASK = 1 << 10,
	BUTTON4_MOTION_MASK = 1 << 11,
	BUTTON5_MOTION_MASK = 1 << 12,
	BUTTON_MOTION_MASK = 1 << 13,
	KEYMAP_STATE_MASK = 1 << 14,
	EXPOSURE_MASK = 1 << 15,
	VISIBILITY_CHANGE_MASK = 1 << 16,
	STRUCTURE_NOTIFY_MASK = 1 << 17,
	RESIZE_REDIRECT_MASK = 1 << 18,
	SUBSTRUCTURE_NOTIFY_MASK = 1 << 19,
	SUBSTRUCTURE_REDIRECT_MASK = 1 << 20,
	FOCUS_CHANGE_MASK = 1 << 21,
	PROPERTY_CHANGE_MASK = 1 << 22,
	COLORMAP_CHANGE_MASK = 1 << 23,
	OWNER_GRAB_BUTTON_MASK = 1 << 24

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
	t_line	*rotated;
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
	int			rotate_flag;
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
void		print_transform(t_wireframe *wireframe);
void		print_center(t_wireframe *wireframe);
void		debug(char *msg);
