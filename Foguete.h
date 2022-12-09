#include "Materia.h"


#ifndef FOGUETE_H
#define FOGUETE_H


class Foguete : public Materia {
// Sobrecarga para saida
    friend ostream& operator<<( ostream &, const Foguete & );

public:
// Construtores
    Foguete( );
    Foguete( int );
    Foguete( const Foguete & );

// Destrutor
    ~Foguete( );

// Metodos
    void combustao( );

// Sobrecarga de Operadores
    bool operator==( const Foguete & );
    bool operator!=( const Foguete & );
    Foguete operator=( const Foguete & );
    Foguete operator!( );

private:
    const int PESOFOGUETE = 300;
    float gasolina;           // Limita a distancia que pode percorrer
    Materia foguete;   // massa do foguete eh de 300 kg

};


#endif