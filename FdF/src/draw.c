/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:11:33 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/16 17:11:20 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	draw_wireframe(t_mlx *mlx, t_wireframe *wireframe)
{
	int	i;

	i = -1;
	while (++i < wireframe->edges_count)
	{
		draw_line(mlx, wireframe->rotated[i]);
	}
}

void	draw_line(t_mlx *mlx, t_line l)
{
	int		steps;
	float	x;
	float	y;
	float	t;
	int		i;

	x = l.start.x;
	y = l.start.y;
	l.dx = l.end.x - l.start.x;
	l.dy = l.end.y - l.start.y;
	if (abs(l.dx) > abs(l.dy))
		steps = abs(l.dx);
	else
		steps = abs(l.dy);
	i = -1;
	while (++i < steps)
	{
		t = (float)i / (float)steps;
		render_pixel(&mlx->img, x, y, lerp(l.start.color, l.end.color, t));
		x += l.dx / (float)steps;
		y += l.dy / (float)steps;
	}
}

float	lerp(int start, int end, float t)
{
	int	start_color[3];
	int	end_color[3];
	int	color[3];

	start_color[0] = (start >> 16) & 0xFF;
	start_color[1] = (start >> 8) & 0xFF;
	start_color[2] = start & 0xFF;
	end_color[0] = (end >> 16) & 0xFF;
	end_color[1] = (end >> 8) & 0xFF;
	end_color[2] = end & 0xFF;
	color[0] = (int)(start_color[0] + t * (end_color[0] - start_color[0]));
	color[1] = (int)(start_color[1] + t * (end_color[1] - start_color[1]));
	color[2] = (int)(start_color[2] + t * (end_color[2] - start_color[2]));
	return (color[0] << 16 | color[1] << 8 | color[2]);
}
