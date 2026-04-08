#ifndef CABINE_H
#define CABINE_H
#include <string>
using namespace std;

enum EtatCabine {
    ARRET,
    EN_MOUVEMENT,
    EN_PANNE
};
enum Portes{
   OUVERTES,
   FERMES,
   ENDOMMAGE
};
class Cabine{

    private:
       string modele;
       double position;
       double vitesse;
    public:
       bool  estPropre;
       const int capacité ; 
       bool  porteOuverte;
       Cabine();

       double getPosition()const;
       void accelerer();
       void arreter();
       void ralentir();
       void nettoyer();
       void declarerEnPanne();
       void fermerPortes();
       void ouvrirPortes();

};


















#endif
