#include "../../include/main/shapes.h"

static float r = 0.0f;
static float y = 0.0f;
static float V = 0.0f;
static float areaX = 0.0f;
static float areaZ = 0.0f;
static float base = 0.0f;
static float area = 0.0f;
static float baseline = 0.0f;

static float area_circle(float tr){
    r = tr;
    area = PI * (r * r);
    return area;
} 

static float vol_cone(float tr, float ty){
    r = tr;
    y = ty;
    V = (PI * (r * r) * y) / 3.0f;
    return V;
}

static float vol_cube(float tbaseline){
    baseline = tbaseline;
    V = baseline * baseline * baseline;
    return V;
}

static float vol_cylinder(float tr, float ty){
    r = tr;
    y = ty;
    V = (PI * (r * r)) * y;
    return V;
}

static float vol_pyramid(float tareaX, float tareaZ, float ty){
    areaX = tareaX;
    areaZ = tareaZ;
    y = ty;
    V = ((areaX * areaZ) * y) / 3.0f;
    return V;
}

static float vol_sphere(float tr){
    r = tr;
    V = (4.0f / 3.0f) * PI * (r * r * r);
    return V;
}

static float area_triangle(float tbase, float ty){
    base = tbase;
    y = ty;
    area = (base * y) / 2.0f;
    return area;
}