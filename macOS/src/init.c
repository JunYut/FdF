# include "wireframe.h"

t_wireframe	*init_wireframe(void)
{
	t_wireframe *wireframe;

	wireframe = (t_wireframe *)ft_calloc(1, sizeof(t_wireframe));
	wireframe->vertices = (t_point *)ft_calloc(8, sizeof(t_point));
	wireframe->edges = (t_line *)ft_calloc(12, sizeof(t_line));
	wireframe->rotated = (t_line *)ft_calloc(12, sizeof(t_line));
	wireframe->scale = 1;
	wireframe->translate = (t_point){0, 0, 0, 0};
	wireframe->rotate = (t_point){0, 0, 0, 0};
	wireframe->vertices_count = 8;
	wireframe->edges_count = 12;

	init_vertices(wireframe);
	init_edges(wireframe);

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
void	init_vertices(t_wireframe *wireframe)
{
 	// Back square
    wireframe->vertices[0] = (t_point){0, 0, 0, 0};
    wireframe->vertices[1] = (t_point){100, 0, 0, 0};
    wireframe->vertices[2] = (t_point){0, 100, 0, 0};
    wireframe->vertices[3] = (t_point){100, 100, 0, 0};

    // Front square
    wireframe->vertices[4] = (t_point){0, 0, 100, 0};
    wireframe->vertices[6] = (t_point){100, 0, 100, 0};
    wireframe->vertices[5] = (t_point){0, 100, 100, 0};
    wireframe->vertices[7] = (t_point){100, 100, 100, 0};
}

void	update_extremes(t_wireframe *wireframe)
{
	// debug("Updating wireframe extremes...");
	int	i;

	wireframe->extremes[0] = wireframe->projection[0].start.y;
	wireframe->extremes[1] = wireframe->extremes[0];
	wireframe->extremes[2] = wireframe->projection[0].start.x;
	wireframe->extremes[3] = wireframe->extremes[2];
	i = -1;
	while (++i < wireframe->edges_count)
	{
		// y-min
		if (wireframe->projection[i].start.y < wireframe->extremes[0])
			wireframe->extremes[0] = wireframe->projection[i].start.y;
		if (wireframe->projection[i].end.y < wireframe->extremes[0])
			wireframe->extremes[0] = wireframe->projection[i].end.y;
		// y-max
		if (wireframe->projection[i].start.y > wireframe->extremes[1])
			wireframe->extremes[1] = wireframe->projection[i].start.y;
		if (wireframe->projection[i].end.y > wireframe->extremes[1])
			wireframe->extremes[1] = wireframe->projection[i].end.y;
		// x-min
		if (wireframe->projection[i].start.x < wireframe->extremes[2])
			wireframe->extremes[2] = wireframe->projection[i].start.x;
		if (wireframe->projection[i].end.x < wireframe->extremes[2])
			wireframe->extremes[2] = wireframe->projection[i].end.x;
		// x-max
		if (wireframe->projection[i].start.x > wireframe->extremes[3])
			wireframe->extremes[3] = wireframe->projection[i].start.x;
		if (wireframe->projection[i].end.x > wireframe->extremes[3])
			wireframe->extremes[3] = wireframe->projection[i].end.x;
	}
	// print_extremes(wireframe);
}
