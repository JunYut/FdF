/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:34:49 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/16 15:40:39 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "FdF.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

typedef struct s_wireframe	t_wireframe;
typedef struct s_line		t_line;

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

typedef struct s_frame
{
	t_list		*map;
	t_mlx		mlx;
	t_wireframe	*wireframe;
	int			redraw_flag;
}				t_frame;

// Drawing functions

void	draw_wireframe(t_mlx *mlx, t_wireframe *wireframe);
void	draw_line(t_mlx *mlx, t_line l);
float	lerp(int start, int end, float t);

// Rendering functions

int		render_new_frame(t_frame *frame);
void	render_pixel(t_img *img, int x, int y, int color);

// Event functions

int		quit(t_frame *frame);
int		key_hook(int keycode, t_frame *frame);

#endif
