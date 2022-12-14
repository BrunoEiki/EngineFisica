// -----------------------------------------
// Uma vez que existe uma relação de 
// composição entre Vetor3 e Materia,
// as classes que herdarem MAteria vão
// poder utilizar Vetor3 também.
// OBS: mas cuidado para não incluir nenhum
// arquivo .cpp duas vezes na hierarquia/main
// -------------------------------------------
#ifndef MATERIA_H
#define MATERIA_H

#include "Vetor3.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;

// ==== CLASSE ABSTRATA ====
class Materia {

// friend ostream& operator<<( ostream& os, const Materia & );

public:
// CONSTRUTORES
    Materia( void );
    Materia( float );
    Materia( Vetor3, Vetor3, float );
    Materia( const Materia & );

    virtual ~Materia( );

// // SOBRECARGA DE OPERADORES
    // bool operator==( const Materia & );
    // bool operator!=( const Materia & );
    // Materia operator=( const Materia & );
    // Materia operator!( );

// MÉTODOS
    void updateMateria( );
    void somarMassa( float );
    void displayMateria ( ) const;
    
    void getMassa( ) const;
    Vetor3 getForca ( ) const;
    Vetor3 getPosicao( ) const;


// METODOS VIRTUAIS
    void aplicarForca( const Vetor3 & );

    virtual void teste( ) = 0;

// PROCESSO DE TRIAGEM
    void resetarVetores( );
    

private:
// eh mais facil lidar com massa infinita (objeto imovel) do que massa zero (objeto c\ aceleracao inf)
    float massaInverso;

// Devo modificar o nome para ficar mais fácil diferenciar vetor de variáveis normais?
// velocidade + velocidade pode ser confundido com uma soma normal, do tipo 1+1, ao invés de (1, 2, 3) + (3, 2, 1)
    Vetor3 velocidade;
    Vetor3 aceleracao;
    Vetor3 posicao;
    Vetor3 forca;

    const float GRAVIDADETERRA = -10.0;

protected:
// tempo discreto em segundos
    int tempoInicial = 0;
    int tempoFinal = 1; 
};


#endif  // MATERIA_H