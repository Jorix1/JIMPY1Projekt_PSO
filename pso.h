#ifndef PSO_H
#define PSO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{   

    
    double **vx;
    double **vy;
    double *w;
    double **c;
    double **r;
    int **x;
    int **y;
    int **pBest;
    int gBest;
    int LDron;
    
}grupa;

void pso(grupa *Drony,mapa *Teren,int iteracja,int nrDrona);

void Iterowanie(grupa *Drony,mapa *Teren,int iteracja);

#endif