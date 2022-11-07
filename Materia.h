#ifndef MATERIA_H
#define MATERIA_H

#include "Vetor3.h"

class Materia : public Vetor3{

    friend ostream& operator<<( ostream& os, const Materia & );

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

public:
// CONSTRUTORES
    Materia( );
    Materia( Vetor3, Vetor3, float, int );
    Materia( const Materia & );

    ~Materia( );

// SOBRECARGA DE OPERADORES
    bool operator==( const Materia & );
    bool operator!=( const Materia & );
    Materia operator=( const Materia & );
    Materia operator!( );

// MÉTODOS
    void updateMateria( );
    void aplicarForca( const Vetor3 & );
    void displayMateria( );
    void resetarVetores( );

    float getVelocidade();
    void getPosicao();
    void getAceleracao();

    float getMagnitude( const Vetor3 & );


protected:
// tempo discreto em segundos
    int tempoInicial = 0;
    int tempoFinal; 
};

#endif