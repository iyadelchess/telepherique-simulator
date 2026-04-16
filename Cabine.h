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
       string numero;
       double position;
       double vitesse;
       int nombreDepassagers;
    public:
       double etatDesFreins=100;
       double etatDesPlaces=100;
       double niveauDeProprete=100;
       double conditionCabine;
       double etatPortes=100;
       double etatLumieres=100;
       Portes portes = FERMES;
       EtatCabine etat = ARRET; 
       bool  estPropre;
       bool  lumiereEstAllume;
       const int capacité = 15 ; 
       const int seuilAcceleration = 12;
       
       Cabine(const string numero);
       int getNbPassagers()const;
       double getPosition()const;
       double getVitesse()const;
       void accelerer();
       void arreter();
       void ralentir();
       void freiner();
       void fermerPortes();
       void ouvrirPortes();
       void allumerLumieres();
       void ajouterPassagers(int passagers);
       void descendrePassagers(int passagers);
       double getConditionCabine()const;
};


















#endif
