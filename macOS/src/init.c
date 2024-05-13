# include "wireframe.h"

t_wireframe	*init_wireframe(t_list *map)
{
	t_wireframe *w;
	t_map		*m;

	w = (t_wireframe *)ft_calloc(1, sizeof(t_wireframe));
	m = (t_map *)map->content;
	w->vertices_count = m->columns * m->rows;
	w->edges_count = (m->rows - 1) * m->columns + (m->columns - 1) * m->rows;
	w->scale = 1;
	w->translate = (t_point){0, 0, 0, 0};
	w->rotate = (t_point){100, 0, 20, 0};
	w->vertices = (t_point *)ft_calloc(w->vertices_count, sizeof(t_point));
	w->edges = (t_line *)ft_calloc(w->edges_count, sizeof(t_line));
	w->rotated = (t_line *)ft_calloc(w->edges_count, sizeof(t_line));

	// printf("Vertices count: %d\n", w->vertices_count);	// Debug
	// printf("Edges count: %d\n", w->edges_count);	// Debug

	init_vertices(w->vertices, map);
	// print_vertices(w->vertices, w->vertices_count);	// Debug
	init_center(w, w->vertices);
	init_edges(w, m->rows, m->columns);
	// print_edges(w->edges, w->edges_count);	// Debug

	return (w);
}

void	init_edges(t_wireframe *w, int rows, int columns)
{
	int	e_index;
	int	v_index;
	int	i;
	int	j;

	// Initialize rows
	e_index = -1;
	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < columns - 1)
		{
			v_index = i * columns + j;
			// if ((v_index + 1) % rows == 0)
			// 	++v_index;
			// printf("v_index: %d\n", v_index);	// Debug
			w->edges[++e_index].start = w->vertices[v_index];
			w->edges[e_index].end = w->vertices[v_index + 1];
			// w->edges[e_index].start.color = 0;
			// w->edges[e_index].end.color = 0;
			// printf("start[%d]: %d %d\n", e_index, w->edges[e_index].start.x,
			// w->edges[e_index].start.y);	// Debug
			// printf("end[%d]: %d %d\n", e_index, w->edges[e_index].end.x,
			// w->edges[e_index].end.y);
			// printf("%d ", w->edges[e_index].start.z);
			// if (j == columns - 2)
				// printf("%d\n", w->edges[e_index].end.z);
		}
	}
	// printf("\n");	// Debug
	// Initialize columns
	i = -1;
	while (++i < columns)
	{
		j = -1;
		while(++j < rows - 1)
		{
			v_index = j * columns + i;
			// if ((v_index + 1) % columns == 0)
			// 	++v_index;
			// printf("v_index: %d\n", v_index);	// Debug
			w->edges[++e_index].start = w->vertices[v_index];
			w->edges[e_index].end = w->vertices[v_index + columns];
			// w->edges[e_index].start.color = 0;
			// w->edges[e_index].end.color = 0;
			// printf("start[%d]: %d %d\n", e_index, w->edges[e_index].start.x,
			// w->edges[e_index].start.y);	// Debug
			// printf("end[%d]: %d %d\n\n", e_index, w->edges[e_index].end.x,
			// w->edges[e_index].end.y);
			// printf("%d ", w->edges[e_index].start.z);
			// if (j == rows - 2)
				// printf("%d\n", w->edges[e_index].end.z);
		}
	}
	// printf("\n");	// Debug
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

void	init_vertices(t_point *vertices, t_list *map)
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
			// printf("Color: %s\n", m->split_comma[j][1]);	// Debug
			vertices[++index] = (t_point){j*10, i*10, ft_atoi(m->split_comma[j][0]) * 10, WHITE};
			if (m->split_comma[j][1])
				vertices[index].color = ft_atoi_base(m->split_comma[j][1], 16);
			// printf("%d ", vertices[index].color);
		}
		// printf("\n");
		current = current->next;
	}
}
