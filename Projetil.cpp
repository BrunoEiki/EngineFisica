#include "Projetil.h"

// CONSTRUTORES
Projetil::Projetil( void )
: Materia( ) {

}

Projetil::Projetil( float massaProjetil )
: Materia( massaProjetil ) {

}

Projetil::Projetil( const Projetil & pOther )
: Materia( pOther ) {

}

Projetil::~Projetil( ) {

}


// // SOBRECARGA DE OPERADORES
// bool operator==( const Projetil & );
// bool operator!=( const Projetil & );
// Projetil operator=( const Projetil & );
// Projetil operator!( );

// // METODOS
void Projetil::disparar( float forca ) {
    
    updateMateria();
}

void Projetil::carregar( ) {
     
}
