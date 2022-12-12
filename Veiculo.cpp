#include "Veiculo.h"

// --- CONSTRUTORES ---

// Massa 1kg
Veiculo::Veiculo( string model, string sound, int anoCriacao )
: Materia( ), modelo( model ), som( sound ) {
    if ( anoCriacao < 1800 ){
        cout << "\nAno invalido! Ano de criacao estimado para 2000.";
        this->anoCriacao = 2000;
    }
}

// Massa por parametro
Veiculo::Veiculo ( string model, string sound, int anoCriacao, float massa )
: Materia( massa ), modelo( model ), som( sound ) {
    if ( anoCriacao < 1800 ){
        cout << "\nAno invalido! Ano de criacao estimado para 2000.";
        this->anoCriacao = 2000;
    }
}

Veiculo::Veiculo ( const Veiculo &other )
: Materia( other ) {
    this->modelo = other.modelo;
    this->som = other.som;
    this->anoCriacao = other.anoCriacao;

    this->velocidadeLimite = other.velocidadeLimite;
    this->propelente = other.propelente;
    this->preco = other.preco;
}

void Veiculo::emitirSom( ){
    cout << som;
}