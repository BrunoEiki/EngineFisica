#include "Canhao.h"

// ---------- CONSTRUTORES -------------------

Canhao::Canhao( )
:vida( 5 ), bala( BALAPESO ), forcaDisparo( 80.0, 80.0, 0.0 ) {

}

Canhao::Canhao( int vida, Vetor3 forca )
:bala( BALAPESO ) {
    if (vida < 0) {
        forcaDisparo = 5;
    } else {
        this->vida = vida;
    }

    if (forca.getMagnitude() < 0.0) {
        Vetor3 f( 80.0, 80.0, 0.0 ); 
        bala.aplicarForca( f );
    } else {
        forcaDisparo = forca;
    }
}

Canhao::Canhao( const Canhao &cOther ) {
    this->bala = cOther.bala;
    this->vida = cOther.vida;
    this->forcaDisparo = cOther.forcaDisparo;
}

Canhao::~Canhao( ) {
    
}


// --------------- METODOS ------------------

void Canhao::disparar( ) {
    vida--;
    bala.resetarVetores( );
    
    Vetor3 f( forcaDisparo.getX(), forcaDisparo.getY(), 0.0 ); 
    bala.aplicarForca( f );
    bala.updateMateria( );
}


void Canhao::disparar( Vetor3 forca ) {
    vida--;
    bala.resetarVetores( );

    Vetor3 f( forca.getX( ), forca.getY( ), forca.getZ( ) ); 
    bala.aplicarForca( f );
    bala.updateMateria( );
}

int Canhao::getVida( ) {
    return vida;
}

// ---------- SOBRECARGA DE OPERADORES -----------

ostream& operator<<( ostream& os, const Canhao &cOther ) {
    os << "\n--------STATUS----------"
       << "\nVida: " << cOther.vida << " disparos restantes"
       << cOther.bala
       << "\n-----------------------";
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