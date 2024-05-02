# include "wireframe.h"

// Initializes a simple cube
t_wireframe	*init_wireframe(void)
{
	t_wireframe *wireframe;

	wireframe = (t_wireframe *)ft_calloc(1, sizeof(t_wireframe));
	wireframe->vertices = (t_point *)ft_calloc(8, sizeof(t_point));
	wireframe->edges = (t_line *)ft_calloc(12, sizeof(t_line));
	wireframe->vertices_count = 8;
	wireframe->edges_count = 12;

 	// Back square
    wireframe->vertices[0] = (t_point){0, 0, 0};
    wireframe->vertices[1] = (t_point){100, 0, 0};
    wireframe->vertices[2] = (t_point){0, 100, 0};
    wireframe->vertices[3] = (t_point){100, 100, 0};

    // Front square
    wireframe->vertices[4] = (t_point){0, 0, 100};
    wireframe->vertices[6] = (t_point){100, 0, 100};
    wireframe->vertices[5] = (t_point){0, 100, 100};
    wireframe->vertices[7] = (t_point){100, 100, 100};

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

	// Connecting edges
	wireframe->edges[8] = (t_line){wireframe->vertices[0], wireframe->vertices[4], 0, 0};
	wireframe->edges[9] = (t_line){wireframe->vertices[1], wireframe->vertices[6], 0, 0};
	wireframe->edges[10] = (t_line){wireframe->vertices[2], wireframe->vertices[5], 0, 0};
	wireframe->edges[11] = (t_line){wireframe->vertices[3], wireframe->vertices[7], 0, 0};

	// print_vertices(wireframe);	// Debug

	return (wireframe);
}

void	offset_projection(t_wireframe *wireframe)
{
	int i;

	i = -1;
	while (++i < wireframe->edges_count)
	{
		wireframe->projection[i].start.x += WIN_WIDTH / 2;
		wireframe->projection[i].start.y += WIN_HEIGHT / 2;
		wireframe->projection[i].end.x += WIN_WIDTH / 2;
		wireframe->projection[i].end.y += WIN_HEIGHT / 2;
	}
}
