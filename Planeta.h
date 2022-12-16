#ifndef PLANETA_H
#define PLANETA_H

#include "CorpoCeleste.h"

class Planeta : public CorpoCeleste
{

    friend ostream& operator<<( ostream& os, const Planeta & );

public:
// CONSTRUTORES
    Planeta( string, int, int );
    Planeta( string, int, int, float, float );
    Planeta( const Planeta & );

    ~Planeta( );

// SOBRECARGA DE OPERADORES
    bool operator==( const Planeta & );
    bool operator!=( const Planeta & );
    Planeta operator=( const Planeta & );
    Planeta operator!( );

// METODOS
    int calcularHorasAno( ) const;

// GETTERs
    int getRotacao ( ) const { return periodoRotacao; };
    int getTranslacao ( ) const { return periodoTranslacao; };

private:
    int periodoRotacao;    // horas
    int periodoTranslacao; // anos
};

#endif // PLANETA_H