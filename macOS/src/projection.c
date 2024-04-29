# include "struct.h"

t_point2D perspectiveProjection(t_point3D point, double focalLength) {
	t_point2D projectedPoint;
	projectedPoint.x = (point.x * focalLength) / point.z;
	projectedPoint.y = (point.y * focalLength) / point.z;
	return projectedPoint;
}
