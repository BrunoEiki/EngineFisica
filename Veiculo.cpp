#include "Veiculo.h"

// --- CONSTRUTORES ---

// Massa 1000kg
Veiculo::Veiculo( string model, string sound, int anoCriacao, int propelente )
: Materia( 1000 ), modelo( model ), som( sound ), propelente( propelente )
{
    if ( propelente < 5 )
    {
        this->propelente = 10;
    }

    if ( anoCriacao < 1800 || anoCriacao >= 2023 )
    {
        cout << "\nAno invalido! Ano de criacao estimado para 2000.";
        this->anoCriacao = 2000;
    }

    if ( anoCriacao >= 1800 && anoCriacao < 1900 )
    {
        this->preco = 5000;
    
    } else if ( anoCriacao >= 1900 && anoCriacao < 1950 )
    {
        this->preco = 10000;
    
    } else if ( anoCriacao >= 1950 && anoCriacao < 2000 )
    {
        this->preco = 30000;

    } else 
    {
        this->preco = 70000;
    } 
}

// Massa por parametro
Veiculo::Veiculo ( string model, string sound, int anoCriacao, int propelente, float massa )
: Materia( massa ), modelo( model ), som( sound ), propelente( propelente )
{
    if ( propelente < 5 )
    {
        this->propelente = 10;
    }

    if ( anoCriacao >= 1800 && anoCriacao < 1900 )
    {
        this->preco = 5000;

    } else if ( anoCriacao >= 1900 && anoCriacao < 1950 )
    { 
        this->preco = 10000;
    
    } else if ( anoCriacao >= 1950 && anoCriacao < 2000 )
    {
        this->preco = 30000;
    
    } else 
    {
        this->preco = 70000;
    } 
}


Veiculo::Veiculo ( const Veiculo &other )
: Materia( other ) 
{
    this->modelo = other.modelo;
    this->som = other.som;
    this->anoCriacao = other.anoCriacao;
    this->propelente = other.propelente;
    this->preco = other.preco;
}


Veiculo::~Veiculo ( void ) 
{

}


void Veiculo::emitirSom( void )
{
    cout << som;
}