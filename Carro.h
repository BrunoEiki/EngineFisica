#ifndef CARRO_H
#define CARRO_H

#include "Veiculo.h"

// ---- CLASSE CONCRETA -----
class Carro : public Veiculo{

friend ostream& operator<<( ostream& os, const Carro & );

public:
// CONSTRUTORES
    Carro( string, string, int, int );
    Carro( string, string, int, int, float );
    Carro( const Carro & );

    ~Carro( );

// // SOBRECARGA DE OPERADORES
    bool operator==( const Carro & );
    bool operator!=( const Carro & );
    Carro operator=( const Carro & );
    Carro operator!( );

// DECLARAR METODOS VIRTUAIS HERDADOS
    void acelerar( );
    void frear( );
    void teste( );

// METODOS
    void trocarRoda( );
    void reporPropelente( );

    float getDistancia( );
    int getTempo( );


private:
    int rodaSaude;
    int distancia;
};

#endif  //CARRO_H