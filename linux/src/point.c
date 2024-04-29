# include "struct.h"

// Rotate around the x-axis
// `angle` is in radians
void rotateX(t_point2D *point, t_point2D center, double angle)
{
	double y = point->y;
	double z = point->z;
	y -= center.y;
	z -= center.z;

	double y1 = y * cos(angle) + z * sin(angle);
	double z1 = -y * sin(angle) + z * cos(angle);
	y += center.y;
	z1 += center.z;
	printf("y: %f, z1: %f, angle: %f\n", y, z1, angle / M_PI * 180); // debug
	point->y = y;
	point->z = z1;
}

// Rotate around y-axis
void rotateY(t_point2D *point, t_point2D center, double angle) {
    double x = point->x;
    double z = point->z;
	x -= center.x;
	z -= center.z;
    point->x = x * cos(angle) + z * sin(angle);
    point->z = -x * sin(angle) + z * cos(angle);
	x += center.x;
	z += center.z;
	point->x = x;
	point->z = z;
}

// Rotate around z-axis
void rotateZ(t_point2D *point, t_point2D center, double angle) {
    double x = point->x;
    double y = point->y;
	x -= center.x;
	y -= center.y;
    point->x = x * cos(angle) - y * sin(angle);
    point->y = x * sin(angle) + y * cos(angle);
	x += center.x;
	y += center.y;
	point->x = x;
	point->y = y;
}
