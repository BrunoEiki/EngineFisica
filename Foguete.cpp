
#include "Foguete.h"


// ---------- CONSTRUTORES -------------------

Foguete::Foguete( string model, string sound, int anoCriacao, int propelente )
: Veiculo( model, sound, anoCriacao, propelente, 1000000 ) 
{
    if ( propelente < 500 ) 
        this->propelente = 1000;
    else 
        this->propelente = propelente;

    somarMassa( this->propelente );
}


Foguete::Foguete( string model, string sound, int anoCriacao, int propelente, float massa )
: Veiculo( model, sound, anoCriacao, propelente, massa ) 
{    
    if ( propelente < 0 )
        this->propelente = 1000;
    else
        this->propelente = propelente;
    
    somarMassa( this->propelente );
}


Foguete::Foguete( const Foguete &cOther )
: Veiculo ( cOther ) 
{

}

Foguete::~Foguete( ) 
{
    
}


// --------------- METODOS ------------------
void Foguete::atualizarStatus( ) 
{
    float altura = static_cast<int>( getPosicao( ).getY( ) );
    if ( altura >= 0 && altura <= 18 ) 
    {
        statusAltura = "Troposfera";
    
    } else if ( altura > 18 && altura <= 50 )
    {
        statusAltura = "Estratosfera";
    
    } else if ( altura > 50 && altura <= 90 )
    {
        statusAltura = "Mesosfera";
    
    } else if ( altura > 90 && altura <= 3000 )
    {
        statusAltura = "Termosfera";
    
    } else 
    {
        statusAltura = "Exosfera";
    }

}


// ---- INICIALIZAR METODOS VIRTUAIS HERDADOS ----
void Foguete::acelerar( ) 
{
    if ( propelente < 500 )
    {
        cout << "\nO propelente acabou! Nao tem como encher de novo.";
        return;
    }

    propelente -= 500;
    somarMassa( -500 );
    Vetor3 f( 0.0, 99000000.0, 0.0 );  // 15 milhões

    aplicarForca( f );
    updateMateria( );
    // displayMateria( );
    atualizarStatus( );
}

void Foguete::frear( ) 
{
    if ( propelente < 500 )
    {
        cout << "\nO propelente acabou! Nao tem como encher de novo.";
        return;
    }

    propelente -= 100;
    somarMassa( -100 );
    Vetor3 f( 0.0, -2160000.0, 0.0 );  // 1 milhao

    aplicarForca( f );
    updateMateria( );
    // displayMateria( );
    atualizarStatus( );
}


bool Foguete::checarLimite( ) 
{
    if ( static_cast<int>( getPosicao( ).getY( ) ) > 1000000 ) 
    {
        cout << "Ultrapassou os limites da simulação!";
        return false;
    }
    return true;
}


// ---------- SOBRECARGA DE OPERADORES -----------

ostream& operator<<( ostream& os, const Foguete &fOther ) 
{
    os << "\nModelo: " << fOther.getModelo( )
       << "\nSom: " << fOther.getSom( )
       << "\nAno de Criacao: " << fOther.getAnoCriacao( )
       << "\nPropelente Restante: " << fOther.getPropelente( )
       << "\nPreco Estimado: " << fOther.getPreco( )
       << "\nStatus de Altura: " << fOther.getAlturaStatus( );
    return os;
}

bool Foguete::operator==( const Foguete &cOther )
{
    return ( this->modelo == cOther.getModelo( )
            && this->som == cOther.getSom( )
            && this->anoCriacao == cOther.getAnoCriacao( )
            && this->propelente == cOther.getPropelente( ) 
            && this->preco == cOther.getPreco( )
            && this->statusAltura == cOther.getAlturaStatus( ) );
}


bool Foguete::operator!=( const Foguete &cOther ) 
{
    return !( *this == cOther );
}

Foguete Foguete::operator=( const Foguete &cOther ) 
{
    this->modelo == cOther.getModelo( );
    this->som == cOther.getSom( );
    this->anoCriacao == cOther.getAnoCriacao( );
    this->propelente == cOther.getPropelente( );
    this->preco == cOther.getPreco( );
    this->statusAltura == cOther.getAlturaStatus( );

    return *this;
}

Foguete Foguete::operator!( )
{
    this->modelo = "UFPA";
    this->som = "ZIUMM";
    this->anoCriacao = 1960;
    this->propelente = 10000;
    this->preco = 2000000;
    this->statusAltura = "Troposfrera";

    return *this;
}