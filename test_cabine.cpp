#include <cassert>
#include "Cabine.h"
#include <stdexcept>
using namespace std;

void testAccelerer(){
    Cabine cabine("l14g1");
    cabine.accelerer();
    assert(cabine.getPosition()==1);
    cabine.accelerer();
    assert(cabine.getPosition()>1);
} 

void testRalentir(){
    Cabine cabine("l14g1");
    cabine.accelerer();
    cabine.accelerer();
    double vitesseActuelle = cabine.getVitesse();
    cabine.ralentir();
    assert(cabine.getVitesse()<vitesseActuelle);
}
void testRalentirCasSiCabineEnArret(){
    Cabine cabine("mgp14");
    bool erreur = false;
    try{
    cabine.ralentir();
    }
    catch (const invalid_argument& e){
         erreur = true; 
    }
    assert(erreur);
}

void testOuvrirPortesFermerPortes(){
     bool erreur=false;
     Cabine cabine("jp15-m1");
     cabine.arreter();
     cabine.ouvrirPortes();
     try
     {
        cabine.fermerPortes();

     }
     catch(const exception& e)
     {
        erreur=true;
     }
     assert(erreur);
     assert(cabine.portes==OUVERTES);
     cabine.accelerer();
     cabine.fermerPortes();
     assert(cabine.portes==FERMES);
     erreur=false;
     try
     {
        cabine.ouvrirPortes();

     }
     catch(const exception& e)
     {
        erreur=true;
     }
     assert(erreur);
    }
void testPassagers(){
    Cabine cabine("jmh8-14");
    bool erreur = false;
    try
    {   
        cabine.ajouterPassagers(4);
        cabine.descendrePassagers(2);
        
    }
    catch(const exception& e)
    {
        erreur=true;
    }
    assert(erreur);
    cabine.ouvrirPortes();
    cabine.ajouterPassagers(4);
    assert(cabine.getNbPassagers()==4);
    cabine.descendrePassagers(2);
    assert(cabine.getNbPassagers()==2);

}
     



int main(){
    testAccelerer();
    testRalentir();
    testRalentirCasSiCabineEnArret();
    testOuvrirPortesFermerPortes();
    testPassagers();
}

