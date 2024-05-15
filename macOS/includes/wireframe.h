/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:50:48 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/15 09:54:42 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIREFRAME_H
# define WIREFRAME_H

# ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include "macOS_keys.h"
# elif __linux__
#  include "linux_keys.h"
# endif

# include "FdF.h"

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

typedef struct s_frame	t_frame;

// Initialization functions

t_wireframe	*init_wireframe(t_list *map);
void		init_edges(t_wireframe *w, int rows, int columns);
void		update_center(t_wireframe *w, t_line *edges, int edges_count);
void		init_center(t_wireframe *w, t_point *vertices);
void		init_vertices(t_point *vertices, t_list *map);

// Offset functions

void		offset_center(t_wireframe *w);
void		offset_origin(t_wireframe *w);

// Projection functions

void		c_projector(t_wireframe *w);
t_point		isometric_projection(t_point p);

// Geometric Transformations

void		scale(t_wireframe *wireframe, float factor);
void		translate(t_wireframe *wireframe, int x, int y);
void		rotate(t_wireframe *wireframe, float x, float y, float z);

// Debug functions

void		print_projection(t_line *projection, int edges_count);
void		print_edges(t_line *edges, int edges_count);
void		print_vertices(t_point *vertices, int vertices_count);
void		print_transform(t_wireframe *wireframe);
void		print_center(t_point center);
void		debug(char *msg);

#endif
