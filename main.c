//wywyływanie funkcja która zkleja wszystko w całość

#include <stdio.h>
#include <stdlib.h>

#include "pso.h"
#include "map.h"
#include "utils.h"
#include "Logger.h"


int main(int argc, char **argv){

    struct mapa * Teren = malloc(sizeof(mapa));
    struct grupa *Grupa = malloc(sizeof(grupa)); // maloc na gurpę i teren

    // faza inicjalizacji wczytanie mapy i grupy

    int liczbaDr = atoi(argv[]);
    int liczbaIter = atoi(argv[]);
    int CoIleZapis = atoi (argv[]); // wartości liczba dronow liczba iteracji etc. dla wygody
    int i = 0, j = 0;

    char *nazwaPlikuZapisu = argv[]; // tu plik zapisywania
    char *nazwaMapa = argv[];       // tu plik mapa
    char *nazwaPlikKonfi = argv[]; // tu plik konfiguracyjny z c1 c2 i w
    


    wczytaj_mape(Teren, nazwaMapa);           
    init_grupa(Grupa, liczbaDr, Teren);         
    plikKonfi(nazwaPlikKonfi, Grupa);
    wyczysc_plik_logu(nazwaPlikuZapisu); //wczytywanie mapy zapisywanie wartośći losowych dla dronów etc.


   for(i=0;i<liczbaIter;i++){

        for(j=0; j<liczbaDr; j++){
            update_grupa(Grupa,Teren,j);
        }

        
        if((i+1)%CoIleZapis==0) zapisz_pozycje(nazwaPlikuZapisu,Grupa,i); // warunek dla zapisywania pozycji co ile 
   }

   free_grupa(Grupa); // funkcje które zwalniają pamięć
   zwolnij_mape(Teren);

   free(Grupa);
   free(Teren);

   return 0;

}
