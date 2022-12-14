#ifndef CANHAO_H
#define CANHAO_H

#include "Projetil.h"


class Canhao : public Projetil {
// Sobrecarga para saida
    friend ostream& operator<<( ostream &, const Canhao & );

public:
// Construtores
    Canhao( );
    Canhao( int, Vetor3 );
    Canhao( const Canhao & );

// Destrutor
    ~Canhao( );

// Metodos
    void disparar( );
    void disparar( Vetor3 );

// Sobrecarga de Operadores
    bool operator==( const Canhao & );
    bool operator!=( const Canhao & );
    Canhao operator=( const Canhao & );
    Canhao operator!( );


private:
    const float BALAPESO = 5.5;
    int balaDisponivel;
    Vetor3 forcaDisparo;      // Forcao aplicado na bala
    
};

#endif