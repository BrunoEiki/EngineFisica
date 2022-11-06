#include "Canhao.h"

// ---------- CONSTRUTORES -------------------

Canhao::Canhao( )
:vida( 5 ), forcaDisparo( 2.0 ){

}

Canhao::Canhao( int vida, float forca ) {
    if (vida < 0) {
        forcaDisparo = 5;
    } else {
        this->vida = vida;
    }

    if (forca < 0.0) {
        forcaDisparo = 2.0;
    } else {
        forcaDisparo = forca;
    }
}

Canhao::Canhao( const Canhao &cOther ) {
    this->bala = cOther.bala;
    this->vida = cOther.vida;
    this->forcaDisparo = cOther.forcaDisparo;
}

Canhao::~Canhao( ){
    
}


// --------------- METODOS ------------------

void Canhao::disparar( ){
    Vetor3 f( forcaDisparo, forcaDisparo, 0.0 );
    bala.aplicarForca( f );
    bala.updateMateria( );
}


// ---------- SOBRECARGA DE OPERADORES -----------

ostream& operator<<( ostream& os, const Canhao &cOther ) {
    os << "\nVida: " << cOther.vida << " disparos restantes"
       << "\nForca aplicada: " << cOther.forcaDisparo << "N"
       << "\nBala";
    return os;
}

bool Canhao::operator==( const Canhao &cOther ) {
    if ( this-> vida == cOther.vida && this->forcaDisparo == cOther.forcaDisparo
       && this->bala == cOther.bala){
        return true;
       }
    return false;
}

bool Canhao::operator!=( const Canhao &cOther ) {
    return !( *this == cOther );
}

Canhao Canhao::operator=( const Canhao &cOther ) {
    this->vida = cOther.vida;
    this->forcaDisparo = cOther.forcaDisparo;
    this->bala = cOther.bala;

    return *this;
}

Canhao Canhao::operator!( ) {
    this->vida = 0;
    this->forcaDisparo = 0;

// Possivel erro
    this->bala.resetarVetores( );

    return *this;
}