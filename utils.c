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
    fclose(f);
}

void wczytaj_konfiguracje(char *nazwa_pliku, grupa *grupa){
    grupa->w = 0.5;
    grupa->c1 = 1.0;
    grupa->c2 = 1.0;

    if (nazwa_pliku == NULL) return; 

    FILE *f = fopen(nazwa_pliku, "r");
    if (!f) {
        perror("Błąd otwarcia pliku");
        printf("Nie udalo sie o.xtworzyc pliku config");
        return;
    }

    if (fscanf(f, "%lf %lf %lf", &grupa->w, &grupa->c1, &grupa->c2) != 3) {
        
        printf("Blad formatu pliku config. Uzywam domyslnych.\n");
        grupa->w = 0.5;
        grupa->c1 = 1.0;
        grupa->c2 = 1.0;
    }
    
    fclose(f);
}
