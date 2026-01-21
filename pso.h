#ifndef PSO_H
#define PSO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{   

    
    double vx[2];
    double vy[2];
    double w;
    double c[2];
    
    int x[2];
    int y[2];
    double pBestVal;
    int pBestX;
    int pBestY;
    
    
}dron;

void pso(dron *Drony[], mapa *Teren, int i, int gBestX, int gBestY);

void Iterowanie(dron *Drony[], mapa *Teren, int iteracja, int liczbaDronow, double *gBestVal, int *gBestX, int *gBestY);

#endif