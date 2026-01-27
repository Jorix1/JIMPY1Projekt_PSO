#ifndef MAP_H
#define MAP_H

typedef struct
{
    int H;
    int W;
    double **Tablica;
}mapa;

int wczytaj_mape(mapa *Teren, char *nazwa_pliku);

void zwolnij_mape(mapa *Teren);

double pobierz_wartosc(mapa *Teren, double x, double y);

#endif