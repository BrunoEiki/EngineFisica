#include "Foguete.h"

// ---------- CONSTRUTORES -------------------


// OK Gasolina tem massa
//    Conforme o tempo passa, a massa diminui
//    1Kg de gasolina equivale a 1000N de Força
// OK Força apenas na vertical
//    Para sair da atmosfera, é preciso gastar pelo menos 7000 Kg
//    No entanto, se tiver mais de 9000kg, o peso do foguete fica maior que a força de propulsão

// STATIC_CAST
// VIRTUAL FUNCTION UPDATE_MATERIA()

Foguete::Foguete( )
:gasolina( 8000 ), forcaPropulsao( 2.0 ){

}

Foguete::Foguete( int gasolina ) {
    if ( gasolina < 0 ) {
        this->gasolina = 8000;
    } else {
        this->gasolina = gasolina;
    }
    
    foguete.somarMassa( gasolina );

    if (forca.getMagnitude() < 0.0) {
        forcaPropulsao = 2.0;
    } else {
        forcaPropulsao = forca;
    }
}

Foguete::Foguete( const Foguete &cOther ) {
    this->bala = cOther.bala;
    this->gasolina = cOther.gasolina;
    this->forcaPropulsao = cOther.forcaPropulsao;
}

Foguete::~Foguete( ){
    
}


// --------------- METODOS ------------------

void Foguete::lancarFoguete( ){

    Vetor3 f( 0.0, forcaPropulsao, 0.0 ); 
    foguete.aplicarForca( f );

    foguete.updateMateria( );
}


void Foguete::combustao( ){
    // 1segundo ---gasta--- 20kg gasolina 
    // 20kg gasolina ---faz---  100

    
}

// ---------- SOBRECARGA DE OPERADORES -----------

ostream& operator<<( ostream& os, const Foguete &cOther ) {
    os << "\ngasolina: " << cOther.gasolina << " disparos restantes"
       << "\nForca aplicada: " << cOther.forcaPropulsao << "N"
       << "\nBala";
    
    foguete.updateMateria( );
    return os;
}

bool Foguete::operator==( const Foguete &cOther ) {
    if ( this-> gasolina == cOther.gasolina && this->forcaPropulsao == cOther.forcaPropulsao
       && this->bala == cOther.bala){
        return true;
       }
    return false;
}

bool Foguete::operator!=( const Foguete &cOther ) {
    return !( *this == cOther );
}

Foguete Foguete::operator=( const Foguete &cOther ) {
    this->gasolina = cOther.gasolina;
    this->forcaPropulsao = cOther.forcaPropulsao;
    this->bala = cOther.bala;

    return *this;
}

Foguete Foguete::operator!( ) {
    this->gasolina = 0;
    this->forcaPropulsao = 0;

// Possivel erro
    this->bala.resetarVetores( );

    return *this;
}