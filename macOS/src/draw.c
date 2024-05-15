/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:11:33 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/15 10:29:10 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	draw_wireframe(t_mlx *mlx, t_wireframe *wireframe)
{
	int	i;

	i = -1;
	while (++i < wireframe->edges_count)
	{
		draw_line(mlx, wireframe->projection[i]);
	}
}

void	draw_line(t_mlx *mlx, t_line line)
{
	int		steps;
	float	x;
	float	y;
	int		i;

	x = line.start.x;
	y = line.start.y;
	line.dx = line.end.x - line.start.x;
	line.dy = line.end.y - line.start.y;
	if (abs(line.dx) > abs(line.dy))
		steps = abs(line.dx);
	else
		steps = abs(line.dy);
	i = -1;
	while (++i < steps)
	{
		if (i <= steps / 2)
			render_pixel(&mlx->img, x, y, line.start.color);
		else
			render_pixel(&mlx->img, x, y, line.end.color);
		x += line.dx / (float)steps;
		y += line.dy / (float)steps;
	}
}
