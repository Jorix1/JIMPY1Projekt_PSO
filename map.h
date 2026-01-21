#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int H;
    int W;
    double **Tablica;
}mapa;

void wczytywanie (mapa *Teren,FILE *F );

#endif