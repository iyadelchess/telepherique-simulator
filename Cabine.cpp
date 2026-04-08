#include "Cabine.h"
#include <iostream>
#include <string>
using namespace std;

Cabine::Cabine(string modele ) : modele(modele) {
    
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
    while (etat != ARRET)
    {
        vitesse *= 0.95;
        position+=vitesse;
        if (position<positionStation-0.05){
            arreter();
        }
    }
    
    
    
}

double Cabine::getPosition()const{
    return this->position; 
}


