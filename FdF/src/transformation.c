/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:22:57 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/16 12:43:49 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"
#include "euler.h"

static void	init_euler(t_euler *e, t_line *edges, float x, float y);

// Use after projecting the wireframe, before offsetting the projection
void	scale(t_wireframe *wireframe, float factor)
{
	int	i;

	i = -1;
	while (++i < wireframe->edges_count)
	{
		wireframe->projection[i].start.x *= factor;
		wireframe->projection[i].start.y *= factor;
		wireframe->projection[i].end.x *= factor;
		wireframe->projection[i].end.y *= factor;
	}
}

// Use after offsetting the projection
void	translate(t_wireframe *wireframe, int x, int y)
{
	int	i;

	i = -1;
	while (++i < wireframe->edges_count)
	{
		wireframe->projection[i].start.x += x;
		wireframe->projection[i].start.y += y;
		wireframe->projection[i].end.x += x;
		wireframe->projection[i].end.y += y;
	}
}

// Use before projecting the wireframe
void	rotate(t_wireframe *w, float x, float y, float z)
{
	t_euler	e;
	int		i;

	x = x * M_PI / 180;
	y = y * M_PI / 180;
	z = z * M_PI / 180;
	i = -1;
	while (++i < w->edges_count)
	{
		init_euler(&e, &w->edges[i], x, y);
		w->rotated[i].start.x = e.xy[0] * cos(z) - e.yx[0] * sin(z);
		w->rotated[i].start.y = e.xy[0] * sin(z) + e.yx[0] * cos(z);
		w->rotated[i].start.z = e.zy[0];
		w->rotated[i].end.x = e.xy[1] * cos(z) - e.yx[1] * sin(z);
		w->rotated[i].end.y = e.xy[1] * sin(z) + e.yx[1] * cos(z);
		w->rotated[i].end.z = e.zy[1];
	}
}

static void	init_euler(t_euler *e, t_line *edges, float x, float y)
{
	e->x[0] = edges[0].start.x;
	e->y[0] = edges[0].start.y;
	e->z[0] = edges[0].start.z;
	e->x[1] = edges[0].end.x;
	e->y[1] = edges[0].end.y;
	e->z[1] = edges[0].end.z;
	e->yx[0] = e->y[0] * cos(x) - e->z[0] * sin(x);
	e->zx[0] = e->y[0] * sin(x) + e->z[0] * cos(x);
	e->yx[1] = e->y[1] * cos(x) - e->z[1] * sin(x);
	e->zx[1] = e->y[1] * sin(x) + e->z[1] * cos(x);
	e->xy[0] = e->x[0] * cos(y) + e->zx[0] * sin(y);
	e->zy[0] = -e->x[0] * sin(y) + e->zx[0] * cos(y);
	e->xy[1] = e->x[1] * cos(y) + e->zx[1] * sin(y);
	e->zy[1] = -e->x[1] * sin(y) + e->zx[1] * cos(y);
}
