// wczytywanie danych z plików struktóra jest przesyłana poprzez plik logger tam jest zdefiniowana struktóra dla mapy 


#include <stdio.h>
#include <stdlib.h>
#include <map.h>


void wczytywanie (mapa *Teren,FILE *F ){ //zdefiniowanie funkcji wczytywanie x weilkość mapy x y wielkość mapy y struct to struktóra która ma mapę czyli 2 tablice dla wysokośc i sygnału
    int i ,j,k ;

    
    fscanf(F,"%d %d",&Teren->H,&Teren->W);
    
    int height = Teren->H;
    int width = Teren->W;
    Teren ->Tablica = malloc(sizeof(double*)*height);
    for(k=0;k<height;k++) Teren->Tablica[k] = malloc(sizeof(double)*width);
    
    
    
    for(i = 0;i<height;i++){
        for(j = 0;j<width;j++){
            fscanf(F,"%lf",&Teren->Tablica[i][j]);
            
        }
    }
    return;

}

