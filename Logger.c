<<<<<<< HEAD
#include <stdlib.h>
#include <stdio.h>
#include "Logger.h"

void wyczysc_plik_logu(char *nazwa_pliku){
    FILE *f = fopen(nazwa_pliku, "w");
    if(f){
        fprintf(f, "iteracja, x, y, sygnał\n");
        fclose(f);
    }
}

void zapisz_pozycje(char *nazwa_pliku, grupa *grupa, int iteracja){
    FILE *f = fopen(nazwa_pliku, "a");
    if(!f){
        printf("Nie udało się otworzyć plik do zapisu");
    }

    for(int i = 0; i < grupa->liczbaDronow; i++){
        fprintf(f, "%d,%lf,%lf,%lf\n", iteracja, grupa->drony[i].x, grupa->drony[i].y, grupa->drony[i].pBestVal);
    }

    fclose(f);
=======
//funkcja ktora zapisuje do pliku stan dronow co n iteracji 


#include <stdio.h>
#include <stdlib.h>
#include "pso.h"

void zapisywanie (FILE *plik,grupa *grupa){
    for(int i=0;i<grupa->liczbaDronow;i++){
        fprintf(plik,"%d, %d,%lf,%lf \n",  grupa->drony[i].x,  grupa->drony[i].y,  grupa->drony[i].vx,  grupa->drony[i].vy);
    }
>>>>>>> main
}