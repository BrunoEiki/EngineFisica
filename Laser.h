#ifndef LASER_H
#define LASER_H

#include "Projetil.h"

class Laser : public Projetil {

    friend ostream& operator<<( ostream& os, const Laser & );


public:
// CONSTRUTORES
    Laser( string, string, int, int );
    Laser( string, string, int, int, float );
    Laser( const Laser & );

    ~Laser( );

// SOBRECARGA DE OPERADORES
    bool operator==( const Laser & );
    bool operator!=( const Laser & );
    Laser operator=( const Laser & );
    Laser operator!( );

// METODOS

private:

};

#endif // LASER_H