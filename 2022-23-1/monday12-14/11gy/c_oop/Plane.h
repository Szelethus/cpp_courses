#ifndef __PLANE_H__
#define __PLANE_H__

struct Plane;

struct Plane *mallocPlane(int ID, int wingspan, char *brand);
void freePlane(struct Plane *plane);

int getWingSpan(const struct Plane *plane);
const char *getBrand(const struct Plane *plane);

#endif // __PLANE_H__
