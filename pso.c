// plik mózg obliczenia i algorytm pso cząstki i roju
#include <pso.h>
#include <map.h>



void pso(grupa *Drony,mapa *Teren,int iteracja,int nrDrona){
    
    

    
    Drony->vx[nrDrona][iteracja+1] = Drony->w[nrDrona]*Drony->vx[nrDrona][iteracja]+Drony->c[nrDrona][0]*Drony->r[nrDrona][0]*(Drony->pBest[nrDrona][0]-Drony->x[nrDrona][iteracja])+Drony->c[nrDrona][1]*Drony->r[nrDrona][1]*(Drony->gBest-Drony->x[nrDrona][iteracja]);
    Drony->x[nrDrona][iteracja+1] = Drony->x[nrDrona][iteracja]+Drony->vx[nrDrona][iteracja];// obliczanie miejsca i prędkośći porusania się drona do g best dla wsp. X

    Drony->vy[nrDrona][iteracja+1] = Drony->w[nrDrona]*Drony->vy[nrDrona][iteracja]+Drony->c[nrDrona][0]*Drony->r[nrDrona][0]*(Drony->pBest[nrDrona][0]-Drony->x[nrDrona][iteracja])+Drony->c[nrDrona][1]*Drony->r[nrDrona][1]*(Drony->gBest-Drony->x[nrDrona][iteracja]);
    Drony->y[nrDrona][iteracja+1] = Drony->y[nrDrona][iteracja]+Drony->vy[nrDrona][iteracja];;// obliczanie miejsca i prędkośći porusania się drona do g best dla wsp. Y

    if(Drony->pBest[nrDrona]<Teren->Tablica[Drony->x[nrDrona][iteracja+1]]) Drony->pBest[nrDrona] = Teren->Tablica[Drony->x[nrDrona][iteracja+1]];// jeśli obecne położenie dorna jest lepsze od najlepszego to zmieniamy pbest
    if(Drony->pBest[nrDrona]<Drony->gBest) Drony->gBest = Drony->pBest[nrDrona];// sprawdzamy czy pbest jest lepsze od gbest


}
void Iterowanie(grupa *Drony,mapa *Teren,int iteracja){
    for(int i=0;i<Drony->LDron;i++){
        pso(Drony,Teren,iteracja,i);// przechodzimy po wszystkich dronach dla iteracji 
    }
}