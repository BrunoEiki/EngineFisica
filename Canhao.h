#ifndef CANHAO_H
#define CANHAO_H

#include "Materia.h"

class Canhao : public Materia{
// Sobrecarga para saida
    friend ostream& operator<<( ostream &, const Canhao & );

private:
    int vida;                // quantidade de disparos que pode fazer
    float forcaDisparo;      // Forcao aplicado na bala
    Materia bala( 5.5 );     // objeto a ser disparado (com massa 5.5kg)

public:
// Construtores
    Canhao( );
    Canhao( int, float );
    Canhao( const Canhao & );

// Destrutor
    ~Canhao( );

// Metodos
    void disparar( );

// Sobrecarga de Operadores
    bool operator==( const Canhao & );
    bool operator!=( const Canhao & );
    Canhao operator=( const Canhao & );
    Canhao operator!( );
};

#endif