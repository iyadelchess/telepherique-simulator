#include "Cabine.h"
#include <iostream>
#include <string>
using namespace std;

Cabine::Cabine(string modele) : modele(modele) {
    
    position = 0.0;
    vitesse = 0;
    estPropre = true;
    
}
void Cabine::accelerer() {
    position += vitesse;
    if (vitesse == 0){
        vitesse+= 1;
    } 
    if (vitesse<seuilAcceleration){   
    vitesse += vitesse * 0.18 ;
        }
}

void Cabine::ralentir(){
    vitesse *= 0.95;
    position+=vitesse; 
}

void Cabine::freiner(){
    if (vitesse>10){
    vitesse *= 0.70;
    position+=vitesse; 
    }
    else if (vitesse>4){
        vitesse *= 0.35;
        position+=vitesse; 
    }
    else{
        vitesse *= 0.05;
        position+=vitesse; 
    }
}

double Cabine::getPosition()const{
    return this->position; 
}

void Cabine::arreter(){
    freiner();
    if (vitesse<0.1){
    vitesse = 0;
    etat=ARRET;
               }
}

void Cabine::fermerPortes(){
    portes = FERMES;
    dureeDeViePortes-=1;
}
