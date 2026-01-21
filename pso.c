#include <pso.h>
#include <map.h>
#include <stdlib.h>


void pso(dron *Drony[], mapa *Teren, int i, int gBestX, int gBestY) {

    dron *d = Drony[i];
    
    double w = d->w;
    double *c = d->c;
    
    //  losowanie liczb r1 i r2 z przedziału [0,1]
    double r1 = ((double) rand()) / RAND_MAX;
    double r2 = ((double) rand()) / RAND_MAX;
    
    // Pobieramy współrzędne z drona
    int *x = d->x;
    int *y = d->y;

    // --- OŚ X ---
    double tempVx = d->vx[1];
    int tempX = d->x[1];

    
    d->vx[1] = w * d->vx[0] + c[0] * r1 * (d->pBestX - x[1]) + c[1] * r2 * (gBestX - x[1]);
    
    d->vx[0] = tempVx; 
    d->x[1] = x[1] + (int)d->vx[1];
    d->x[0] = tempX;

    // --- OŚ Y ---
    double tempVy = d->vy[1];
    int tempY = d->y[1];


    d->vy[1] = w * d->vy[0] + c[0] * r1 * (d->pBestY - y[1]) + c[1] * r2 * (gBestY - y[1]);

    d->vy[0] = tempVy;
    d->y[1] = y[1] + (int)d->vy[1];
    d->y[0] = tempY;

    // Zapewnienie, że dron nie wyjdzie poza mapę
    if(d->x[1] < 0) d->x[1] = 0;
    if(d->y[1] < 0) d->y[1] = 0;
    // if(d->x[1] >= Teren->szerokosc) ... itd.


    
    double aktualnaWartosc = Teren->Tablica[d->y[1]][d->x[1]];
    
    
    if(aktualnaWartosc > d->pBestVal) {
        d->pBestVal = aktualnaWartosc; // Zapisz wartość
        d->pBestX = d->x[1];           // Zapisz GDZIE to było (X)
        d->pBestY = d->y[1];           // Zapisz GDZIE to było (Y)
    }
}


void Iterowanie(dron *Drony[], mapa *Teren, int iteracja, int liczbaDronow, double *gBestVal, int *gBestX, int *gBestY) {
    
    for(int i = 0; i < liczbaDronow; i++) {
        
        pso(Drony, Teren, i, *gBestX, *gBestY);

        
        if(Drony[i]->pBestVal > *gBestVal) {
            *gBestVal = Drony[i]->pBestVal; // Nowy rekord wartości
            *gBestX = Drony[i]->pBestX;     // Nowe miejsce rekordu X
            *gBestY = Drony[i]->pBestY;     // Nowe miejsce rekordu Y
        }
    }
}