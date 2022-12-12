#include "Vetor3.h"

#ifndef MATERIA_H
#define MATERIA_H

// ==== CLASSE ABSTRATA ====
class Materia {

public:
// CONSTRUTORES
    Materia( );
    Materia( float , int );
    Materia( Vetor3, Vetor3, float, int );
    Materia( const Materia & );

    ~Materia( );

// // SOBRECARGA DE OPERADORES
//     bool operator==( const Materia & );
//     bool operator!=( const Materia & );
//     Materia operator=( const Materia & );
//     Materia operator!( );

// MÉTODOS
    void updateMateria( );
    void getMassa( ) const;
    void somarMassa( float );
    Vetor3 getForca ( ) const;

    void displayMateria ( ) const;

// METODOS VIRTUAIS
    virtual void aplicarForca( const Vetor3 & ) = 0;


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
    int tempoInicial;
    int tempoFinal; 
};


#endif  // MATERIA_H