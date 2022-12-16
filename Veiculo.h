#pragma once

#ifndef VEICULO_H
#define VEICULO_H

#include "Materia.h"

// ==== CLASSE ABSTRATA ====
class Veiculo : public Materia 
{
public:

// CONSTRUTORES
    Veiculo( string, string, int, int );
    Veiculo( string, string, int, int, float );
    Veiculo( const Veiculo & );

    virtual ~Veiculo( );


// METODO
    void emitirSom ( void );

// GETTERS
    string getModelo     ( void ) const  { return modelo; };
    string getSom        ( void ) const  { return som; };
    int    getAnoCriacao ( void ) const  { return anoCriacao; };
    int    getPropelente ( void ) const  { return propelente; };
    float  getPreco      ( void ) const  { return preco; }


// METODOS VIRTUAIS
    virtual void acelerar( void ) = 0;
    virtual void frear( void ) = 0;
    // checarLimite( ) : de Materia.h

protected:
    string modelo;
    string som;
    int anoCriacao;                  
    int propelente;
    float preco;
};

#endif    // VEICULO_H