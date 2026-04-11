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

int main(){
    testAccelerer();
    testRalentir();
    testRalentirCasSiCabineEnArret();
}