#ifndef PSO_H
#define PSO_H

#include "map.h"

typedef struct 
{      
    double x;
    double y; 
    double vx;
    double vy;

    double pBestVal;
    double pBestX;
    double pBestY;
}dron;

typedef struct
{
    dron *drony;
    int liczbaDronow;

    double gBestVal;
    double gBestX;
    double gBestY;

    double w;
    double c1;
    double c2;
}grupa;

void init_grupa(grupa *grupa, int liczbaDronow, mapa *mapa);

void update_grupa(grupa *grupa, mapa *mapa,int i);

void free_grupa(grupa *grupa);

#endif