#pragma once

#ifndef CARRO_H
#define CARRO_H

#include "Veiculo.h"
#include "Vetor3.h"

// ---- CLASSE CONCRETA -----
class Carro : public Veiculo
{
friend ostream& operator<<( ostream& os, const Carro & );

public:
// CONSTRUTORES
    Carro( string, string, int, int );
    Carro( string, string, int, int, float );
    Carro( const Carro & );

    ~Carro( );

// SOBRECARGA DE OPERADORES
    bool operator==( const Carro & );
    bool operator!=( const Carro & );
    Carro operator=( const Carro & );
    Carro operator!( );

// METODOS
    void trocarRoda( );
    void reporPropelente( );

// DECLARAR METODOS VIRTUAIS HERDADOS
    void acelerar( );
    void frear( );
    bool checarLimite( );

// GETTERS
    int getTempo( )     const { return tempoFinal; };
    int getSaudeRoda( ) const { return rodaSaude; };


private:
    int rodaSaude;
};

#endif  //CARRO_H