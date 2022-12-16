// -----------------------------------------
// Uma vez que existe uma relação de composição entre Vetor3 
// e Materia, as classes que herdarem MAteria vão
// poder utilizar Vetor3 também. OBS: mas cuidado para não 
// incluir nenhum arquivo .cpp duas vezes na hierarquia/main
// -------------------------------------------
#pragma once

#ifndef MATERIA_H
#define MATERIA_H

#include "Vetor3.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;

#include <vector>
using std::vector;

// ==== CLASSE ABSTRATA ====
class Materia
{
public:

// CONSTRUTORES
    Materia( void );
    Materia( float );
    Materia( Vetor3, Vetor3, float );
    Materia( const Materia & );

    virtual ~Materia( );

// MÉTODOS
    void updateMateria( );
    void somarMassa( float );
    void displayMateria ( ) const;

    void aplicarForca( const Vetor3 & );
    void resetarVetores( );

// GETTERS
    Vetor3 getForca      ( ) const { return forca; };
    Vetor3 getAceleracao ( ) const { return aceleracao; };
    Vetor3 getVelocidade ( ) const { return velocidade; };
    Vetor3 getPosicao    ( ) const { return posicao; };
    Vetor3 getDirecao    ( ) const { return direcao; };
    float getMassaInv    ( ) const { return massaInverso; };
    int getTempo         ( ) const { return tempoFinal; };


// METODO VIRTUAL
    virtual bool checarLimite ( ) = 0;

private:
// eh mais facil lidar com massa infinita (objeto imovel) do que massa zero (objeto c\ aceleracao inf)
    float massaInverso;

// Devo modificar o nome para ficar mais fácil diferenciar vetor de variáveis normais?
// velocidade + velocidade pode ser confundido com uma soma normal, do tipo 1+1, ao invés de (1, 2, 3) + (3, 2, 1)
    Vetor3 velocidade;
    Vetor3 aceleracao;
    Vetor3 posicao;
    Vetor3 direcao;
    Vetor3 forca;

    const float GRAVIDADETERRA = -10.0;

protected:
// tempo discreto em segundos
    int tempoInicial = 0;
    int tempoFinal = 1; 
};


#endif  // MATERIA_H