#ifndef CORPOCELESTE_H
#define CORPOCELESTE_H

#include "Materia.h"

class CorpoCeleste : public Materia 
{
    friend ostream& operator<<( ostream& os, const CorpoCeleste & );

public:

// CONSTRUTORES
    CorpoCeleste( string, float );
    CorpoCeleste( string, float, float );
    CorpoCeleste( const CorpoCeleste & );

    ~CorpoCeleste( );

// SOBRECARGA DE OPERADORES
    bool operator==( const CorpoCeleste & );
    bool operator!=( const CorpoCeleste & );
    CorpoCeleste operator=( const CorpoCeleste & );
    CorpoCeleste operator!( );

// METODOS
    void aplicarGravidade( Materia & );
    void aplicarGravidade( CorpoCeleste & );

// GETTERS
    string getNome ( ) const { return nome; };
    float getRaio ( ) const { return raio; };


// DECLARAR METODO VIRTUAL PURO DE MATERIA_H
    bool checarLimite ( );

private:
    string nome;
    float raio;
    const float CONSTANTEGRAVITACIONAL = 6.674e-11;  

};

#endif  // CORPOCELESTE_H