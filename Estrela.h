#ifndef ESTRELA_H
#define ESTRELA_H

#include "CorpoCeleste.h"

class Estrela : public CorpoCeleste
{

    friend ostream& operator<<( ostream& os, const Estrela & );

public:
// CONSTRUTORES
    Estrela( string, float );
    Estrela( string, float, float, float );
    Estrela( const Estrela & );

    ~Estrela( );

// SOBRECARGA DE OPERADORES
    bool operator==( const Estrela & );
    bool operator!=( const Estrela & );
    Estrela operator=( const Estrela & );
    Estrela operator!( );

// METODOS
    void classificarEstrela( );

// GETTERS
    float getTemperatura( ) const { return temperatura; };

private:
    float temperatura; // kelvin
};

#endif // ESTRELA_H