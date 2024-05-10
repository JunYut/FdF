# include "wireframe.h"

t_wireframe	*init_wireframe(t_list *map)
{
	t_wireframe *wireframe;
	t_map		*m;

	m = (t_map *)map->content;
	wireframe = (t_wireframe *)ft_calloc(1, sizeof(t_wireframe));
	wireframe->vertices_count = m->columns * m->rows;
	wireframe->edges_count = (m->rows - 1) * m->columns + (m->columns - 1) * m->rows;
	wireframe->vertices = (t_point *)ft_calloc(wireframe->vertices_count, sizeof(t_point));
	wireframe->edges = (t_line *)ft_calloc(wireframe->edges_count, sizeof(t_line));
	wireframe->rotated = (t_line *)ft_calloc(wireframe->edges_count, sizeof(t_line));
	wireframe->scale = 1;
	wireframe->translate = (t_point){0, 0, 0, 0};
	wireframe->rotate = (t_point){0, 0, 0, 0};

	printf("Vertices count: %d\n", wireframe->vertices_count);	// Debug
	printf("Edges count: %d\n", wireframe->edges_count);	// Debug

	init_vertices(wireframe->vertices, map);
	print_vertices(wireframe->vertices, wireframe->vertices_count);	// Debug
	// init_edges(wireframe);

	return (wireframe);
}

void	init_edges(t_wireframe *wireframe)
{
	// Back square edges
	wireframe->edges[0] = (t_line){wireframe->vertices[0], wireframe->vertices[1], 0, 0};
	wireframe->edges[1] = (t_line){wireframe->vertices[0], wireframe->vertices[2], 0, 0};
	wireframe->edges[2] = (t_line){wireframe->vertices[1], wireframe->vertices[3], 0, 0};
	wireframe->edges[3] = (t_line){wireframe->vertices[2], wireframe->vertices[3], 0, 0};

	// Front square edges
	wireframe->edges[4] = (t_line){wireframe->vertices[4], wireframe->vertices[5], 0, 0};
	wireframe->edges[5] = (t_line){wireframe->vertices[4], wireframe->vertices[6], 0, 0};
	wireframe->edges[6] = (t_line){wireframe->vertices[5], wireframe->vertices[7], 0, 0};
	wireframe->edges[7] = (t_line){wireframe->vertices[6], wireframe->vertices[7], 0, 0};

	// Connecting front & back squares
	wireframe->edges[8] = (t_line){wireframe->vertices[0], wireframe->vertices[4], 0, 0};
	wireframe->edges[9] = (t_line){wireframe->vertices[1], wireframe->vertices[6], 0, 0};
	wireframe->edges[10] = (t_line){wireframe->vertices[2], wireframe->vertices[5], 0, 0};
	wireframe->edges[11] = (t_line){wireframe->vertices[3], wireframe->vertices[7], 0, 0};
}

// Initializes a simple cube
void	init_vertices(t_point *vertices, t_list *map)
{
	(void)vertices;
	t_list	*current;
	t_map	*m;
 	int		i;
	int		j;

	current = map;
	i = -1;
	while (current)
	{
		m = (t_map *)current->content;
		j = -1;
		while (++j < m->columns)
		{
			// printf("Color: %s\n", m->split_comma[j][1]);	// Debug
			vertices[++i] = (t_point){j, i, ft_atoi(m->split_comma[j][0]), 0};
			if (m->split_comma[j][1])
				vertices[i].color = ft_atoi_base(m->split_comma[j][1], 16);
		}
		current = current->next;
	}
}
