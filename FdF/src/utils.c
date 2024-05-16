/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:10:14 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/16 17:05:22 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void	debug(char *str)
{
	static int	i;

	if (str == NULL)
		ft_printf("Debug %d\n", i++);
	else
		ft_printf("Debug %d: %s\n", i++, str);
}

void	update_center(t_wireframe *w, t_line *edges, int edges_count)
{
	int	i;

	w->center = (t_point){0, 0, 0, 0};
	i = -1;
	while (++i < edges_count)
	{
		w->center.x += edges[i].start.x;
		w->center.y += edges[i].start.y;
	}
	w->center.x /= edges_count;
	w->center.y /= edges_count;
}

int	upscale(int vertices_count)
{
	int	scale;

	scale = 1;
	while (vertices_count * scale * scale < 1000000)
		++scale;
	return (scale);
}
