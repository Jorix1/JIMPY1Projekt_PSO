#include <stdlib.h> 
#include "pso.h"
#include "map.h"
#include "map.h"



void init_grupa(grupa *grupa, int liczbaDronow, mapa *mapa){
    int maxH = mapa->H;
    int maxW = mapa->W;
    
    grupa->drony = malloc(liczbaDronow*sizeof(dron));// maloc na całe drony
    grupa->liczbaDronow = liczbaDronow;
    grupa->gBestVal = -100000;
    for(int i =0;i<liczbaDronow;i++){
        
        
        grupa->drony[i].x = rand()%maxW;// losowe x i y wsp na mapie
        grupa->drony[i].y = rand()%maxH;

        grupa->drony[i].vx = (((double)rand() / RAND_MAX) * maxW) - (maxW/2);// losowa prędokść x i y
        grupa->drony[i].vx = (((double)rand() / RAND_MAX) * maxH) - (maxH/2);

        grupa->drony[i].pBestX = grupa->drony[i].x;// nie ma innych p best więc to jest najlepsza
        grupa->drony[i].pBestY = grupa->drony[i].y;

        grupa->drony[i].pBestVal = mapa->Tablica[(int)grupa->drony[i].x][(int)grupa->drony[i].y];// wartość na mapie

        if(grupa->gBestVal<grupa->drony[i].pBestVal){// sprawdza czy  obecna pozycja jest najlepsza z grupy
            grupa->gBestVal = grupa->drony[i].pBestVal;
            grupa->gBestX = grupa->drony[i].pBestX;
            grupa->gBestY = grupa->drony[i].pBestY;

        }

    }    


}
void update_grupa(grupa *grupa, mapa *mapa,int i){

        
    
    
    
    //  losowanie liczb r1 i r2 z przedziału [0,1]
    double r1 = ((double) rand()) / RAND_MAX;
    double r2 = ((double) rand()) / RAND_MAX;
    
    // Pobieramy współrzędne z drona
    int x = grupa->drony[i].x;
    int y = grupa->drony[i].y;

    // --- OŚ X ---
    

    
    grupa->drony[i].vx = grupa->w *grupa->drony[i].vx  + grupa->c1 * r1 * (grupa->drony[i].pBestX - x) + grupa->c2 * r2 * (grupa->gBestX - x);
    
    
    grupa->drony[i].x = x + (int)grupa->drony[i].vx;
    

    // --- OŚ Y ---
    


    grupa->drony[i].vy = grupa->w * grupa->drony[i].vy + grupa->c1 * r1 *(grupa->drony[i].pBestY - y)  + grupa->c2 * r2 * (grupa->gBestY - y);

    
    grupa->drony[i].y = grupa->drony[i].y + (int)grupa->drony[i].vy;
    
    double aktualnaWartosc;
    // Zapewnienie, że dron nie wyjdzie poza mapę
    if(grupa->drony[i].x < 0||grupa->drony[i].x > mapa->H|| grupa->drony[i].y < 0|| grupa->drony[i].y > mapa->W)
         aktualnaWartosc = pobierz_wartosc(mapa,x,y);
    
    // if(d->x[1] >= Teren->szerokosc) ... itd.


    else 
        aktualnaWartosc = mapa->Tablica[(int)grupa->drony[i].y][(int)grupa->drony[i].x];
    

    
    if(aktualnaWartosc > grupa->drony[i].pBestVal) {
        grupa->drony[i].pBestVal = aktualnaWartosc; // Zapisz wartość
        grupa->drony[i].pBestX = x;           // Zapisz GDZIE to było (X)
        grupa->drony[i].pBestY = y;           // Zapisz GDZIE to było (Y)
    }
}

void free_grupa(grupa *grupa){// zwalnianie tablicy dronow
    
    free(grupa->drony);
    
}
