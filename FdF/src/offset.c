/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:16:05 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/16 17:11:41 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

// Use after scaling
void	offset_center(t_wireframe *w)
{
	int	i;

	update_center(w, w->rotated, w->edges_count);
	i = -1;
	while (++i < w->edges_count)
	{
		w->rotated[i].start.x += WIN_WIDTH / 2 - w->center.x;
		w->rotated[i].start.y += WIN_HEIGHT / 2 - w->center.y;
		w->rotated[i].end.x += WIN_WIDTH / 2 - w->center.x;
		w->rotated[i].end.y += WIN_HEIGHT / 2 - w->center.y;
	}
}

// Use before rotating
void	offset_origin(t_wireframe *w)
{
	int	i;

	update_center(w, w->edges, w->edges_count);
	i = -1;
	while (++i < w->edges_count)
	{
		w->edges[i].start.x -= w->center.x;
		w->edges[i].start.y -= w->center.y;
		w->edges[i].end.x -= w->center.x;
		w->edges[i].end.y -= w->center.y;
	}
}
