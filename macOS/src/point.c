# include "struct.h"

// `vector` is a unit vector, should be 1 or 0
void rotatePoint3D(t_point3D *point, t_point3D center, t_point3D vector, double angle)
{
    double x = point->x;
    double y = point->y;
    double z = point->z;

    // Translate the point so that the point of rotation is at the origin
    x -= center.x;
    y -= center.y;
    z -= center.z;

    // Rotate the point around the arbitrary vector
    double x1 = vector.x*(vector.x*x + vector.y*y + vector.z*z)*(1 - cos(angle)) + x*cos(angle) + (-vector.z*y + vector.y*z)*sin(angle);
    double y1 = vector.y*(vector.x*x + vector.y*y + vector.z*z)*(1 - cos(angle)) + y*cos(angle) + (vector.z*x - vector.x*z)*sin(angle);
    double z1 = vector.z*(vector.x*x + vector.y*y + vector.z*z)*(1 - cos(angle)) + z*cos(angle) + (-vector.y*x + vector.x*y)*sin(angle);

    // Translate the point back
    x1 += center.x;
    y1 += center.y;
    z1 += center.z;

    point->x = x1;
    point->y = y1;
    point->z = z1;
}

// `angle` is in radians
void rotatePoint2D(t_point2D *point, t_point2D center, double angle)
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
