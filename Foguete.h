#include "Materia.h"

#ifndef FOGUETE_H
#define FOGUETE_H

class Foguete : public Materia {
private:
    
public:
    
}

#ifndef CANHAO_H
#define CANHAO_H

#include "Materia.h"

class Foguete : public Materia{
// Sobrecarga para saida
    friend ostream& operator<<( ostream &, const Foguete & );

private:
    float gasolina;           // Limita a distancia que pode percorrer
    float forcaPropulsao;     // Forca gerado pelo foguete
    Materia foguete( 300 );   // massa do foguete eh de 300 kg

public:
// Construtores
    Foguete( );
    Foguete( int, float );
    Foguete( const Foguete & );

// Destrutor
    ~Foguete( );

// Metodos
    void disparar( );

// Sobrecarga de Operadores
    bool operator==( const Foguete & );
    bool operator!=( const Foguete & );
    Foguete operator=( const Foguete & );
    Foguete operator!( );
};


#endif