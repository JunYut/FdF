# include "wireframe.h"

void	offset_projection(t_wireframe *w)
{
	// debug("Offsetting w...");
	int i;

	w->center = (t_point){0, 0, 0, 0};
	i = -1;
	while (++i < w->vertices_count)
	{
		w->center.x += w->vertices[i].x;
		w->center.y += w->vertices[i].y;
	}
	w->center.x /= w->vertices_count;
	w->center.y /= w->vertices_count;

	i = -1;
	while (++i < w->edges_count)
	{
		w->projection[i].start.x += WIN_WIDTH / 2 - w->center.x;
		w->projection[i].start.y += WIN_HEIGHT / 2 - w->center.y;
		w->projection[i].end.x += WIN_WIDTH / 2 - w->center.x;
		w->projection[i].end.y += WIN_HEIGHT / 2 - w->center.y;
	}
}

// Cant name it projector cuz floating point exception
void  c_projector(t_wireframe *w)
{
	// debug("Projecting w...");
	int i;

	w->projection = (t_line *)ft_calloc(w->edges_count, sizeof(t_line));

	i = -1;
	while (++i < w->edges_count)
	{
		w->projection[i].start = isometric_projection(w->rotated[i].start);
		w->projection[i].end = isometric_projection(w->rotated[i].end);
		w->projection[i].start.color = w->edges[i].start.color;
		w->projection[i].end.color = w->edges[i].end.color;
	}
}

t_point isometric_projection(t_point p)
{
	// debug("Projecting point...");
	int iso_factor;
	int new_x;
	int new_y;
	t_point projected_point;

	iso_factor = 1;
	new_x = (iso_factor * p.x + iso_factor * p.z) / 2;
	new_y = (iso_factor * p.y - (iso_factor * p.x - iso_factor * p.z)) / 2;
	// Isometric projection formulas (assumes isometric angle of 30 degrees)
	projected_point = (t_point){new_x, new_y, 0, 0}; // Set z to 0 for 2D representation
	return (projected_point);
}