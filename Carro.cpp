#include "Vetor3.cpp"
#include "Materia.cpp"
#include "Veiculo.cpp"
#include "Carro.h"

Carro::Carro( string model, string sound, int anoCriacao, int propelente )
: Veiculo( model, sound, anoCriacao, propelente, 1000 ), distancia( 0 ){

    somarMassa( this->propelente );

    this->rodaSaude = 100;
}


Carro::Carro( string model, string sound, int anoCriacao, int propelente, float massa )
: Veiculo( model, sound, anoCriacao, propelente, massa ), distancia( 0 ){

    somarMassa( this->propelente );
    this->rodaSaude = 100;
}

// como copiar os atributos protected sem dar erros?
Carro::Carro( const Carro &cOther ) 
: Veiculo( cOther )
{ //usa o construtor de copia de Veiculo para pegar
  // os atributos do objeto cOther da classe acima
    
}


Carro::~Carro( ){

}


// -------- SOBRECARGA DE OPERADORES --------

ostream& operator<<( ostream& os, const Carro &cOther ) {
    os << "\nModelo: " << cOther.modelo
       << "\nSom: " << cOther.som
       << "\nAno de Criacao: " << cOther.anoCriacao
       << "\nPropelente Restante: " << cOther.propelente
       << "\nPreco Estimado: " << cOther.preco
       << "\nSaude das Rodas: " << cOther.rodaSaude;
    return os;
}

bool Carro::operator==( const Carro &cOther ){
    // PROBLEMA
    return ( this->modelo == cOther.modelo
            && this->som == cOther.som
            && this->anoCriacao == cOther.anoCriacao
            && this->propelente == cOther.propelente 
            && this->preco == cOther.preco
            && this->rodaSaude == cOther.rodaSaude );
}

bool Carro::operator!=( const Carro &cOther ){
    return !( *this == cOther );
}

Carro Carro::operator=( const Carro &cOther ){
    // *this = other;

    // Materia::operator=( other );
    // Não posso usar a sobrecarga de = pq precisaria instanciar um objeto
    //do tipo Materia, e Matereia eh abstrata

    this->modelo == cOther.modelo;
    this->som == cOther.som;
    this->anoCriacao == cOther.anoCriacao;
    this->propelente == cOther.propelente;
    this->rodaSaude == cOther.rodaSaude;
    this->preco == cOther.preco;

    return *this;
}

Carro Carro::operator!( ){
    /*
    * Reseta os atributos para um valor padrao
    */
    // Materia::operator!( );
    
    this->modelo == "UFPA";
    this->som == "VRUM!";
    this->anoCriacao == 2020;
    this->propelente == 100;
    this->rodaSaude == 100;
    this->preco == 70000;

    return *this;
}


void Carro::acelerar( ){

    if ( rodaSaude <= 0 ){
        cout << "\nA roda quebrou! Precisa trocar.";
        return;
    }
    if ( propelente <= 0.001 ){
        cout << "\nO propelente acabou! Precisa encher o tanque.";
        return;
    }

    rodaSaude -= 10;
    propelente -= 10;
    Vetor3 f( 2000.0, 0.0, 0.0 ); 

    // cout << "G: " << getPosicao();

    aplicarForca( f );
    updateMateria( );
    displayMateria( );
}


void Carro::frear( ){

    if ( rodaSaude <= 0 ){
        cout << "\nA roda quebrou! Precisa trocar.";
        return;
    }
    if ( propelente <= 0 ){
        cout << "\nO propelente acabou! Precisa encher o tanque.";
        return;
    }

    rodaSaude -= 10;
    propelente -= 10;
    Vetor3 f( -4000.0, 0.0, 0.0 ); 

    aplicarForca( f );
    updateMateria( );
    displayMateria( );
}


void Carro::trocarRoda( ){
    rodaSaude = 100;
}

void Carro::reporPropelente( ){
    propelente = 100;
}

// LEMBRETE: Funciona essa merda?
float Carro::getDistancia( ){
    return distancia;
}

int Carro::getTempo( ){
    return tempoFinal;
}


// LEMBRETE: metodo abstrato para classe MATERIA_H
void Carro::teste( ){
    cout << "OK";
} 