# include "struct.h"

void rotatePoint(t_point *point, double angle)
{
	double x = point->x;
	double y = point->y;
	printf("x: %f, y: %f\n", x, y);	// debug
	double x1 = x * cos(angle) - y * sin(angle);
	double y1 = x * sin(angle) + y * cos(angle);
	printf("x1: %f, y1: %f\n", x1, y1); // debug
	point->x = x1;
	point->y = y1;
}
