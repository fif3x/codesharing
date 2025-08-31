#ifndef VARS
#define VARS

static float r;
static float y;
static float V;
static float areaX;
static float areaZ;
static float base;
static float area;
static float baseline;

#define PI 3.141592

#endif

#ifndef SHAPES
#define SHAPES


static float area_circle(float tr);
static float vol_cone(float tr, float ty);
static float vol_cube(float tbaseline);
static float vol_cylinder(float tr, float ty);
static float vol_pyramid(float tsideX, float tsideZ, float ty);
static float vol_sphere(float tr);
static float area_triangle(float tbase, float ty);


#endif