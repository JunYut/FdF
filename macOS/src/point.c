# include "struct.h"

// `angle` is in radians
void rotatePoint(t_point *point, t_point center, double angle)
{
	double x = point->x;
	double y = point->y;
	x -= center.x;
	y -= center.y;

	double x1 = x * cos(angle) + y * sin(angle);
	double y1 = -x * sin(angle) + y * cos(angle);
	x1 += center.x;
	y1 += center.y;
	printf("x1: %f, y1: %f, angle: %f\n", x1, y1, angle / M_PI * 180); // debug
	point->x = x1;
	point->y = y1;
}
