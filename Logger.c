//funkcja ktora zapisuje do pliku stan dronow co n iteracji 


#include <stdio.h>
#include <stdlib.h>
#include "pso.h"

void zapisywanie (FILE *plik,grupa *grupa){
    for(int i=0;i<grupa->liczbaDronow;i++){
        fprintf(plik,"%d, %d,%lf,%lf \n",  grupa->drony[i].x,  grupa->drony[i].y,  grupa->drony[i].vx,  grupa->drony[i].vy);
    }
}