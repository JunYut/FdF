/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:42:16 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/16 17:15:44 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

static void	init_columns(t_wireframe *w, int rows, int columns, int e_index);

t_wireframe	*init_wireframe(t_list *map)
{
	t_wireframe	*w;
	t_map		*m;

	w = (t_wireframe *)c_malloc(1 * sizeof(t_wireframe));
	m = (t_map *)map->content;
	w->vertices_count = m->columns * m->rows;
	w->edges_count = (m->rows - 1) * m->columns + (m->columns - 1) * m->rows;
	w->scale = 0.5;
	w->translate = (t_point){0, 0, 0, 0};
	w->rotate = (t_point){45, 40, -30, 0};
	w->vertices = (t_point *)c_malloc(w->vertices_count * sizeof(t_point));
	w->edges = (t_line *)c_malloc(w->edges_count * sizeof(t_line));
	w->rotated = (t_line *)c_malloc(w->edges_count * sizeof(t_line));
	init_vertices(w->vertices, map, w->vertices_count);
	init_center(w, w->vertices);
	init_edges(w, m->rows, m->columns);
	return (w);
}

void	init_edges(t_wireframe *w, int rows, int columns)
{
	int	e_index;
	int	v_index;
	int	i;
	int	j;

	e_index = -1;
	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < columns - 1)
		{
			v_index = i * columns + j;
			w->edges[++e_index].start = w->vertices[v_index];
			w->edges[e_index].end = w->vertices[v_index + 1];
		}
	}
	init_columns(w, rows, columns, e_index);
}

void	init_center(t_wireframe *wireframe, t_point *vertices)
{
	int	i;

	wireframe->center = (t_point){0, 0, 0, 0};
	i = -1;
	while (++i < wireframe->vertices_count)
	{
		wireframe->center.x += vertices[i].x;
		wireframe->center.y += vertices[i].y;
	}
	wireframe->center.x /= wireframe->vertices_count;
	wireframe->center.y /= wireframe->vertices_count;
}

void	init_vertices(t_point *v, t_list *map, int count)
{
	t_list	*current;
	t_map	*m;
	int		index;
	int		i;
	int		j;

	current = map;
	index = -1;
	i = -1;
	while (current)
	{
		m = (t_map *)current->content;
		++i;
		j = -1;
		while (++j < m->columns)
		{
			v[++index] = (t_point){j * upscale(count), i * upscale(count),
				ft_atoi(m->split_comma[j][0]) * upscale(count), WHITE};
			if (m->split_comma[j][1])
				v[index].color = ft_atoi_base(m->split_comma[j][1], 16);
		}
		current = current->next;
	}
}

static void	init_columns(t_wireframe *w, int rows, int columns, int e_index)
{
	int	v_index;
	int	i;
	int	j;

	i = -1;
	while (++i < columns)
	{
		j = -1;
		while (++j < rows - 1)
		{
			v_index = j * columns + i;
			w->edges[++e_index].start = w->vertices[v_index];
			w->edges[e_index].end = w->vertices[v_index + columns];
		}
	}
}
