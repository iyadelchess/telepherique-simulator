#ifndef CABINE_H
#define CABINE_H

class Cabine{
    private:
       double position;
       double vitesse;
    public:
       bool  estPropre;
       const int capacité ; 
       bool  estEnMarche;
       bool  estEnPanne;
       Cabine();

       void getPosition()const;
       void accelerer();
       void arreter();
       void ralentir();
       

};


















#endif
