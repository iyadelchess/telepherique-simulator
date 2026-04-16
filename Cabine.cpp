#include "Cabine.h"
#include <iostream>
#include <string>
using namespace std;

Cabine::Cabine(string numero) : numero(numero) {
    
    position = 0;
    vitesse = 0;
    estPropre = true;
    
}
void Cabine::accelerer() {
    etat=EN_MOUVEMENT;
    if (vitesse == 0){
        vitesse+= 1;
    } 
    if (vitesse>=seuilAcceleration){   
    vitesse += vitesse * 0.18 ;
        }
    position += vitesse;
}

void Cabine::ralentir(){
    if (position==0){
        throw invalid_argument("La machine n'est pas en mouvement");
    }
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

int Cabine::getNbPassagers()const{
    return this->nombreDepassagers;
}

void Cabine::arreter(){
    freiner();
    if (vitesse<0.1){
    vitesse = 0;
    etat=ARRET;
               }
}

void Cabine::fermerPortes(){
    if(etat!=ARRET){
    portes = FERMES;
    etatPortes-=0.1;
    }
    else{
        throw invalid_argument("Les passagers sont entrain de monter dans la cabine");
    }
}

void Cabine::ouvrirPortes(){
    if (etat!=EN_MOUVEMENT){
    portes = OUVERTES;
    etatPortes-=0.1;
    }
    else{
        throw invalid_argument("La cabine est en mouvement risque d'accident pour les passagers!");
    }
}

void Cabine::allumerLumieres(){
    lumiereEstAllume=true;
    etatLumieres-=1;
}

void Cabine::ajouterPassagers(int passagers){
    if(portes==OUVERTES){
        nombreDepassagers+=passagers;}
    else{
        throw invalid_argument("impossible pour les passagers de rentrer à bord");
    }
}

void Cabine::descendrePassagers(int passagers){
    if(portes==OUVERTES){
    nombreDepassagers-=passagers;}
    else{
        throw invalid_argument("impossible pour les passagers de sortir");
    }
}

double Cabine::getConditionCabine()const{
   return (etatPortes + etatLumieres + niveauDeProprete + etatDesPlaces) / 4;
}
double Cabine::getVitesse()const{
    return this->vitesse;
}
