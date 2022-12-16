#pragma once

#ifndef FOGUETE_H
#define FOGUETE_H

#include "Veiculo.h"

class Foguete : public Veiculo 
{
    friend ostream& operator<<( ostream &, const Foguete & );

public:
// CONSTRUTORES
    Foguete( string, string, int, int );
    Foguete( string, string, int, int, float );
    Foguete( const Foguete & );

// DESTRUTOR
    ~Foguete( );

// METODOS
    void atualizarStatus( );

// DECLARAR METODOS VIRTUAIS HERDADOS
    void acelerar( );
    void frear( );
    bool checarLimite( );

// GETTER
    string getAlturaStatus ( ) const { return statusAltura; };


// SOBRECARGA DE OPERADORES
    bool operator==( const Foguete & );
    bool operator!=( const Foguete & );
    Foguete operator=( const Foguete & );
    Foguete operator!( );

private:
    string statusAltura = "Troposfera";

    // ******* possiveis status *******
      //  Troposfera   [0   -  18   km ]
      // Estratosfera  (18  -  50   km ]
      //   Mesosfera   (50  -  90   km ]
      //  Termosfera   (90  -  800  km ]
      //   Exosfera    (800 -  3000 km ]
};


#endif   // FOGUETE_H