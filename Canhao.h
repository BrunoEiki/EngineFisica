#include "Materia.h"


#ifndef CANHAO_H
#define CANHAO_H



class Canhao : public Materia {
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
    int getVida( );


// Sobrecarga de Operadores
    bool operator==( const Canhao & );
    bool operator!=( const Canhao & );
    Canhao operator=( const Canhao & );
    Canhao operator!( );


private:
    const float BALAPESO = 5.5;
    int vida;                // quantidade de disparos que pode fazer
    Vetor3 forcaDisparo;      // Forcao aplicado na bala
    Materia bala;     // objeto a ser disparado (com massa 5.5kg)

};

#endif