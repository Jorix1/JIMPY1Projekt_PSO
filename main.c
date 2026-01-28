#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "pso.h"
#include "Logger.h"
#include "utils.h"

int main(int argc, char *argv[]){
    if (argc < 2) {
        printf("Sposob wywołania: %s <plik_mapy> [-p liczba_dronow] [-i iteracje] [-c plik_config] [-n logowanie]\n", argv[0]);
        return 1;
    }

    char *plik_mapy = argv[1];   
    int liczba_dronow = 30;    
    int liczba_iteracji = 100;   
    char *plik_config = NULL;    
    int log_co_ile = 0;
    
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-p") == 0 && i + 1 < argc) {
            liczba_dronow = atoi(argv[i + 1]);
            i++;
        } 
        else if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
            liczba_iteracji = atoi(argv[i + 1]);
            i++;
        }
        else if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
            plik_config = argv[i + 1];
            i++;
        }
        else if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
            log_co_ile = atoi(argv[i + 1]);
            i++;
        }
    }

    mapa teren;
    if (wczytaj_mape(&teren, plik_mapy) == EXIT_FAILURE) {
        printf("nie udało się wczytać mapy");
        return 1;
    }

    grupa grupa;
    wczytaj_konfiguracje(plik_config, &grupa);

    init_grupa(&grupa, liczba_dronow, &teren);

    char *nazwa_logu = "wyniki.csv";
    if (log_co_ile > 0) {
        wyczysc_plik_logu(nazwa_logu);
        zapisz_pozycje(nazwa_logu, &grupa, 0);
    }

    for (int t = 1; t <= liczba_iteracji; t++) {
        for(int i = 0; i < grupa.liczbaDronow; i++){
            update_grupa(&grupa, &teren, i);
        }

        if (log_co_ile > 0 && (t % log_co_ile == 0)) {
            zapisz_pozycje(nazwa_logu, &grupa, t);
        }
    }
    
    printf("\n--- WYNIK ---\n");
    printf("Najlepszy znaleziony sygnał: %lf\n", grupa.gBestVal);
    printf("Współrzędne celu: X = %lf, Y = %lf\n", grupa.gBestX, grupa.gBestY);

    free_grupa(&grupa);
    zwolnij_mape(&teren);
    return 0;
}