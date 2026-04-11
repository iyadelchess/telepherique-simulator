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
       double niveauDeProprete;
       double conditionCabine;
       int dureeDeViePortes=50000;
       Portes portes;
       EtatCabine etat; 
       bool  estPropre;
       bool  lumiereEstAllume;
       const int capacité = 10 ; 
       const int seuilAcceleration = 12;
       
       Cabine(const string modele);

       double getPosition()const;
       void accelerer();
       void arreter();
       void ralentir();
       void freiner();
       void fermerPortes();
       void ouvrirPortes();
       void allumerLumieres();
};


















#endif
