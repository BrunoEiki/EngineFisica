#include "Veiculo.h"

// --- CONSTRUTORES ---

// Massa 1000kg
Veiculo::Veiculo( string model, string sound, int anoCriacao, int propelente )
: Materia( 1000 ), modelo( model ), som( sound ) {

    if ( anoCriacao < 1800 || anoCriacao >= 2023 ){
        cout << "\nAno invalido! Ano de criacao estimado para 2000.";
        this->anoCriacao = 2000;
    }

    if ( anoCriacao >= 1800 && anoCriacao < 1900 ){
        this->preco = 5000;

    } else if ( anoCriacao >= 1900 && anoCriacao < 1950 ){
        this->preco = 10000;
    
    } else if ( anoCriacao >= 1950 && anoCriacao < 2000 ){
        this->preco = 30000;
    
    } else {
        this->preco = 70000;
    } 

    if ( propelente < 5 ){
        cout << "\nPropelente insuficiente! Valor setado para 5.";
        this->propelente = 5;
    } else {
        this->propelente = propelente;
    }
}

// Massa por parametro
Veiculo::Veiculo ( string model, string sound, int anoCriacao, int propelente, float massa )
: Materia( massa ), modelo( model ), som( sound ) {

    if ( anoCriacao < 1800 || anoCriacao >= 2023 ){
        cout << "\nAno invalido! Ano de criacao estimado para 2000.";
        this->anoCriacao = 2000;
    }

    if ( anoCriacao >= 1800 && anoCriacao < 1900 ){
        this->preco = 5000;

    } else if ( anoCriacao >= 1900 && anoCriacao < 1950 ){
        this->preco = 10000;
    
    } else if ( anoCriacao >= 1950 && anoCriacao < 2000 ){
        this->preco = 30000;
    
    } else {
        this->preco = 70000;
    } 

    if ( propelente < 5 ){
        cout << "\nPropelente insuficiente! Valor setado para 5.";
        this->propelente = 5;
    } else {
        this->propelente = propelente;
    }
}


Veiculo::Veiculo ( const Veiculo &other )
: Materia( other ) {
    this->modelo = other.modelo;
    this->som = other.som;
    this->anoCriacao = other.anoCriacao;

    // this->velocidadeLimite = other.velocidadeLimite;
    this->propelente = other.propelente;
    this->preco = other.preco;
}


Veiculo::~Veiculo ( void ) {

}

// ------ METODO CLONE ------
// virtual Veiculo* clone() const {
//     return new Veiculo( *this );
// }


// // -------- SOBRECARGA DE OPERADORES --------

// bool Carro::operator==( const Carro &other ){
//     // PROBLEMA
//     return ( Veiculo::operator==( other ) );
// }

// bool Veiculo::operator!=( const Veiculo &other ){
//     return !( *this == other );
// }

// Veiculo Veiculo::operator=( const Veiculo &other ){
//     // *this = other;

//     // Materia::operator=( other );
//     // Não posso usar a sobrecarga de = pq precisaria instanciar um objeto
//     //do tipo Materia, e Matereia eh abstrata

//     this->modelo == other.modelo;
//     this->som == other.som;
//     this->anoCriacao == other.anoCriacao;
//     this->propelente == other.propelente;
//     this->preco == other.preco;

//     return *this;
// }

// Veiculo Veiculo::operator!( ){
//     /*
//     * Reseta os atributos para um valor padrao
//     */
//     // Materia::operator!( );
    
//     this->modelo == "UFPA";
//     this->som == "VRUM!";
//     this->anoCriacao == 2020;
//     this->propelente == 100;
//     this->preco == 70000;

//     return *this;
// }


void Veiculo::emitirSom( void ) {
    cout << som;
}

int Veiculo::getPropelente( void ) {
    return propelente;
}

/* ADICIONAR ALGUM METODO MAIS UTIL DPS */