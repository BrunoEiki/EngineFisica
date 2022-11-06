#ifndef MATERIA_H
#define MATERIA_H

#include "Vetor3.h"


class Materia : public Vetor3{

    friend ostream& operator<<( ostream& os, const Materia & );

private:
// eh mais facil lidar com massa infinita (objeto imovel) do que massa zero (objeto c\ aceleracao inf)
    float massaInverso;

    Vetor3 velocidade;
    Vetor3 aceleracao;
    Vetor3 posicao;
    Vetor3 forca;

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


protected:
// tempo discreto em segundos
    int tempoInicial = 0;
    int tempoFinal; 

    const float GRAVIDADETERRA = -10.0;
    const float ATRITO = 1.4e-2;    // Constante de atrito (usou-se valor aleatorio)

    // const float GRAVIDADETERRA = 6.668e-11;      // Constante gravitacional

};

#endif