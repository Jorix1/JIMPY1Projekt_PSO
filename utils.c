#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pso.h"

void plikKonfi(char *nazwaPliku,grupa *grupa){
    srand(time(NULL));
    FILE *f = fopen(nazwaPliku,"w");
    
    double w  = (double) rand() / RAND_MAX; // generowanie wspolczynnika bezwladnosci
    double c1 = (double) rand() / RAND_MAX;// generowanie wspolczynnika przyciagania do najlepszego rozwiazania czasteczki
    double c2 = (double) rand() / RAND_MAX;
    fprintf(f,"%lf %lf %lf\n",w,c1,c2);

    grupa->c1 = c1;// zapisanie do grupy parametrów losowych waga i jak bardzo ufa sobie i grupie jednostka
    grupa->c2 = c2;
    grupa->w = w;
}
