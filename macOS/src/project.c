# include "wireframe.h"

void	offset_projection(t_wireframe *wireframe)
{
	debug("Offsetting wireframe...");
	int i;

	wireframe->center = (t_point){0, 0, 0, 0};
	i = -1;
	while (++i < wireframe->vertices_count)
	{
		wireframe->center.x += wireframe->vertices[i].x;
		wireframe->center.y += wireframe->vertices[i].y;
	}
	wireframe->center.x /= wireframe->vertices_count;
	wireframe->center.y /= wireframe->vertices_count;

	i = -1;
	while (++i < wireframe->edges_count)
	{
		wireframe->projection[i].start.x += WIN_WIDTH / 2 - wireframe->center.x;
		wireframe->projection[i].start.y += WIN_HEIGHT / 2 - wireframe->center.y;
		wireframe->projection[i].end.x += WIN_WIDTH / 2 - wireframe->center.x;
		wireframe->projection[i].end.y += WIN_HEIGHT / 2 - wireframe->center.y;
	}
}

void  projector(t_wireframe *wireframe)
{
	debug("Projecting wireframe...");
	int i;

	wireframe->projection = (t_line *)ft_calloc(wireframe->edges_count, sizeof(t_line));

	i = -1;
	while (++i < wireframe->edges_count)
	{
		debug(NULL);
		wireframe->projection[i].start = isometric_projection(wireframe->rotated[i].start);
		wireframe->projection[i].end = isometric_projection(wireframe->rotated[i].end);
	}
}

t_point isometric_projection(t_point p)
{
	debug("Projecting point...");
	// Isometric factor (adjust based on your needs)
	int isometric_factor = 1;

	// Isometric projection formulas (assumes isometric angle of 30 degrees)
	int new_x = (isometric_factor * p.x + isometric_factor * p.z) / 2;
	int new_y = (isometric_factor * p.y - (isometric_factor * p.x - isometric_factor * p.z)) / 2;

	t_point projected_point = {new_x, new_y, 0, 0}; // Set z to 0 for 2D representation
	return (projected_point);
}
