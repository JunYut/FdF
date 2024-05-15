/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:21:05 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/15 11:21:55 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

// Cant name it projector cuz floating point exception
void	c_projector(t_wireframe *w)
{
	int	i;

	i = -1;
	while (++i < w->edges_count)
	{
		w->projection[i].start = w->rotated[i].start;
		w->projection[i].end = w->rotated[i].end;
		w->projection[i].start.color = w->edges[i].start.color;
		w->projection[i].end.color = w->edges[i].end.color;
	}
}

t_point	isometric_projection(t_point p)
{
	int		iso_factor;
	int		new_x;
	int		new_y;
	t_point	projected_point;

	iso_factor = 1;
	new_x = (iso_factor * p.x + iso_factor * p.z) / 2;
	new_y = (iso_factor * p.y - (iso_factor * p.x - iso_factor * p.z)) / 2;
	projected_point = (t_point){new_x, new_y, 0, 0};
	return (projected_point);
}
