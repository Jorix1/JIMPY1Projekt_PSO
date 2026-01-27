#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int wczytaj_mape(mapa *Teren, char *nazwa_pliku){
    FILE *f = fopen(nazwa_pliku, "r");
    if (f == NULL) {
        printf("Nie udało się otworzyć pliku do wczytywnia mapy\n");
        return EXIT_FAILURE;
    }

    if (fscanf(f, "%d %d", &Teren->W, &Teren->H) != 2) {
        printf("Zly format naglowka mapy.\n");
        fclose(f);
        return EXIT_FAILURE;
    }

    Teren->Tablica = malloc(sizeof(double*) * Teren->H);
    for(int i = 0; i < Teren->H; i++) {
        Teren->Tablica[i] = malloc(sizeof(double) * Teren->W);
    }

    for(int i = 0; i < Teren->H; i++) {
        for(int j = 0; j < Teren->W; j++) {
            fscanf(f, "%lf", &Teren->Tablica[i][j]);
        }
    }

    fclose(f);
    return EXIT_SUCCESS;
}

void zwolnij_mape(mapa *Teren){
    if (Teren->Tablica != NULL) {
        for(int i = 0; i < Teren->H; i++) {
            free(Teren->Tablica[i]);
        }

        free(Teren->Tablica);
        Teren->Tablica = NULL;
    }
}

double pobierz_wartosc(mapa *Teren, double x, double y){
    int kolumna = (int)x;
    int wiersz = (int)y;

    //jeśli dron chcę odzyskać wartośc poza mapą to zwracam niegtywny sygnał(spowoduje e dron wroci na mape)
    if (kolumna < 0 || kolumna >= Teren->W || wiersz < 0 || wiersz >= Teren->H) {
        return -1000000.0; 
    }

    return Teren->Tablica[wiersz][kolumna];
}

