#ifndef FOGUETE_H
#define FOGUETE_H

#include "Veiculo.h"

class Foguete : public Veiculo {
// Sobrecarga para saida
    // friend ostream& operator<<( ostream &, const Foguete & );

public:
// Construtores
    Foguete( string, string, int, int );
    Foguete( string, string, int, int, float );
    Foguete( const Foguete & );

// Destrutor
    ~Foguete( );

// Metodos
    void acelerar( );
    void frear( );

// Sobrecarga de Operadores
    // bool operator==( const Foguete & );
    // bool operator!=( const Foguete & );
    // Foguete operator=( const Foguete & );
    // Foguete operator!( );

    void teste( );
    // void atualizarStatus( );

private:
    const int PESOFOGUETE = 300;
    int distancia;
    string statusAltura = "Troposfera";
    // Troposfera [0 - 18km)
    // Estratosfera [18 - 50km]
    // Mesosfera [50 - 90]
    // Termosfera [90 - 800]
    // Exosfera [800 - 3000]
    // Espaco 

};


#endif