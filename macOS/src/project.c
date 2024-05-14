# include "wireframe.h"

// Cant name it projector cuz floating point exception
void  c_projector(t_wireframe *w, t_mlx *tmp)
{
	// debug("Projecting w...");
	(void)tmp;
	int i;

	i = -1;
	while (++i < w->edges_count)
	{
		w->projection[i].start = isometric_projection(w->rotated[i].start);
		w->projection[i].end = isometric_projection(w->rotated[i].end);
		w->projection[i].start.color = w->edges[i].start.color;
		w->projection[i].end.color = w->edges[i].end.color;
		// if (i > 6)
		// 	draw_line(tmp, w->edges[i]);
		// printf("%d ", w->edges[i].start.z);
		// if (i % 3 == 0 && i != 0)
		// 	printf("%d\n", w->edges[i].end.z);
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
