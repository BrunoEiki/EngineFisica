#include "Foguete.h"

// ---------- CONSTRUTORES -------------------

Foguete::Foguete( )
:gasolina( 200 ), foguete( PESOFOGUETE + gasolina ) {

}

Foguete::Foguete( int gasolina )
:foguete( PESOFOGUETE ) {
    /*
    * PARAMETROS
    *   gasolina: necessario para propulsao
    * 
    * ATRIBUTOS
    *   massa: massa do foguete + massa da gasolina
    *   forcaPropulsao: força que aumenta aceleração para cima
    */
    if ( gasolina < 0 ) {
        this->gasolina = 200;
    } else {
        this->gasolina = gasolina;
    }
    
    foguete.somarMassa( gasolina );

}

Foguete::Foguete( const Foguete &cOther )
:foguete( PESOFOGUETE ) {
    this->gasolina = cOther.gasolina;
    this->foguete = cOther.foguete;
}

Foguete::~Foguete( ) {
    
}


// --------------- METODOS ------------------

void Foguete::combustao( ) {
    if ( gasolina >= 10 ) {
        gasolina -= 10;
        foguete.somarMassa( -10.0 );

        Vetor3 f( 0.0, 10000.0, 0.0 ); 
        foguete.aplicarForca( f );
    
    } else {
        cout << "\nNao ha mais gasolina para propulsao.";
    }
    foguete.updateMateria( );
}


// ---------- SOBRECARGA DE OPERADORES -----------

ostream& operator<<( ostream& os, const Foguete &cOther ) {
    os << "\n--------STATUS----------"
       << "\nGasolina: " << cOther.gasolina << "Kg"
       << cOther.foguete
       << "\n-----------------------";

    return os;
}

bool Foguete::operator==( const Foguete &cOther ) {
    if ( this->gasolina == cOther.gasolina ) {
        return true;
       }
    return false;
}

bool Foguete::operator!=( const Foguete &cOther ) {
    return !( *this == cOther );
}

Foguete Foguete::operator=( const Foguete &cOther ) {
    this->gasolina = cOther.gasolina;
    this->foguete = cOther.foguete;

    return *this;
}

Foguete Foguete::operator!( ) {
    /*
    * Reseta Foguete para estado inicial
    */
    this->gasolina = 200;
    this->foguete.resetarVetores( );

    return *this;
}