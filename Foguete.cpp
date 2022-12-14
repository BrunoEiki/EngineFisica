#include "Foguete.h"

// ---------- CONSTRUTORES -------------------

Foguete::Foguete( string model, string sound, int anoCriacao, int propelente )
: Veiculo( model, sound, anoCriacao, propelente, 2000000 ), distancia( 0 ) {
    /*
    * PARAMETROS
    *   propelente: necessario para propulsao
    * 
    * ATRIBUTOS
    *   massa: massa do foguete + massa da gasolina
    *   forcaPropulsao: força que aumenta aceleração para cima
    */
    if ( propelente < 0 ) {
        this->propelente = 1000;
    } else {
        this->propelente = propelente;
    }
    
    somarMassa( this->propelente );
    
}


Foguete::Foguete( string model, string sound, int anoCriacao, int propelente, float massa )
: Veiculo( model, sound, anoCriacao, propelente, massa ), distancia( 0 ) {
    
    if ( propelente < 0 ) {
        this->propelente = 1000;
    } else {
        this->propelente = propelente;
    }
    
    somarMassa( this->propelente );
}


Foguete::Foguete( const Foguete &cOther )
: Veiculo ( cOther ) {

}

Foguete::~Foguete( ) {
    
}


// --------------- METODOS ------------------


// ---- INICIALIZAR METODOS VIRTUAIS HERDADOS ----

void Foguete::acelerar( ) {

    if ( propelente < 500 ){
        cout << "\nO propelente acabou! Nao tem como encher de novo.";
        return;
    }

    propelente -= 500;
    Vetor3 f( 3000000.0, 0.0, 0.0 ); 

    // cout << "G: " << getPosicao();

    aplicarForca( f );
    updateMateria( );
    displayMateria( );
}

void Foguete::frear( ) {
    if ( propelente <= 0 ){
        cout << "\nO propelente acabou! Nao tem como encher de novo.";
        return;
    }

    propelente -= 500;
    Vetor3 f( 0.0, -3000000.0, 0.0 ); 

    aplicarForca( f );
    updateMateria( );
    displayMateria( );
}

void Foguete::teste( ) {
    cout << "\nSIMMMM!";
}

// ---------- SOBRECARGA DE OPERADORES -----------

// ostream& operator<<( ostream& os, const Foguete &fOther ) {
//     os << "\nModelo: " << fOther.modelo
//        << "\nSom: " << fOther.som
//        << "\nAno de Criacao: " << fOther.anoCriacao
//        << "\nPropelente Restante: " << fOther.propelente
//        << "\nPreco Estimado: " << fOther.preco
//        << "\nStatus de Altura: " << fOther.statusAltura;
//     return os;
// }

// bool Carro::operator==( const Foguete &cOther ){
//     // PROBLEMA
//     return ( this->modelo == cOther.modelo
//             && this->som == cOther.som
//             && this->anoCriacao == cOther.anoCriacao
//             && this->propelente == cOther.propelente 
//             && this->preco == cOther.preco
//             && this->statusAltura == cOther.statusAltura );
// }


// bool Foguete::operator!=( const Foguete &cOther ) {
//     return !( *this == cOther );
// }

// Foguete Foguete::operator=( const Foguete &cOther ) {
//     *this = cOther;

//     return *this;
// }

// Foguete Foguete::operator!( ) {
//     /*
//     * Reseta Foguete para estado inicial
//     */
//     *this = !( *this );

//     return *this;
// }

// void Foguete::atualizarStatus( ) {
//     if (  )
// }