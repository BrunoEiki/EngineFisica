#ifndef PROJETIL_H
#define PROJETIL_H

#include "Materia.h"

class Projetil : public Materia {

    friend ostream& operator<<( ostream& os, const Projetil & );

public:

// CONSTRUTORES
    Projetil( void );
    Projetil( float );
    Projetil( const Projetil & );

    ~Projetil( );


// SOBRECARGA DE OPERADORES
    bool operator==( const Projetil & );
    bool operator!=( const Projetil & );
    Projetil operator=( const Projetil & );
    Projetil operator!( );

// METODOS
    virtual void disparar( );
    virtual void carregar( );

private:
    float anguloDisparo;

};

#endif  // PROJETIL_H