#include "CorpoCeleste.h"
#include "Vetor3.h"

// CONSTRUTORES
CorpoCeleste::CorpoCeleste( string nome, float massa )
: Materia( massa ), nome( nome ), raio( 5000.0 )
{

}


CorpoCeleste::CorpoCeleste( string nome, float massa, float raio  )
: Materia( massa ), nome( nome )
{
    if ( !checarLimite( ) )
    {
        this->raio = 5000.0;
    
    } else 
    {
        this->raio = raio;
    }
}


CorpoCeleste::CorpoCeleste( const CorpoCeleste & cOther )
: Materia( cOther ) 
{
    this->raio = cOther.raio;
    // Reseta massa para zero e depois recebe massa do parametro
    this->somarMassa( -this->getMassaInv( ) );
    this->somarMassa( cOther.getMassaInv( ) );
}


CorpoCeleste::~CorpoCeleste( ) 
{

}


// // SOBRECARGA DE OPERADORES

ostream& operator<<( ostream& os, const CorpoCeleste &cOther ) 
{
    os << "\nNome: " << cOther.getNome( )
       << "\nRaio: " << cOther.getRaio( );

    return os;
}

bool CorpoCeleste::operator==( const CorpoCeleste &cOther ) 
{
    return ( this->raio == cOther.raio
             && this->getMassaInv( ) == cOther.getMassaInv( ) );
}


bool CorpoCeleste::operator!=( const CorpoCeleste &cOther ) 
{
    return !( *this == cOther );
}


CorpoCeleste CorpoCeleste::operator=( const CorpoCeleste &cOther ) 
{
    this->raio = cOther.raio;
    // Reseta massa para zero e depois recebe massa do parametro
    this->somarMassa( -this->getMassaInv( ) );
    this->somarMassa( cOther.getMassaInv( ) );
    return *this;
}


CorpoCeleste CorpoCeleste::operator!( ) 
{
    this->raio = 0;
    this->somarMassa( -this->getMassaInv( ) );
    this->somarMassa( 10000 );

    return *this;
}


// // METODOS
void CorpoCeleste::aplicarGravidade( Materia &mOther )
{
    Vetor3 distancia = mOther.getPosicao( ) - this->getPosicao( );
    float distQuadrada = distancia.getX( ) * distancia.getX( ) +
                         distancia.getY( ) * distancia.getY( ) +
                         distancia.getZ( ) * distancia.getZ( );


    float forcaGravitacional = CONSTANTEGRAVITACIONAL * 
                              (  ( 1/this->getMassaInv( ) + 1/mOther.getMassaInv( ) ) / 
                              ( distQuadrada ) );
    Vetor3 velocidade = mOther.getVelocidade( );
    Vetor3 direcao = distancia.calcularDirecao( velocidade );
    Vetor3 forca = distancia * forcaGravitacional;

    mOther.aplicarForca( forca );
}


void CorpoCeleste::aplicarGravidade( CorpoCeleste &cOther )
{
    Vetor3 distancia = cOther.getPosicao( ) - this->getPosicao( );
    float distQuadrada = distancia.getX( ) * distancia.getX( ) +
                         distancia.getY( ) * distancia.getY( ) +
                         distancia.getZ( ) * distancia.getZ( );
    
    float forcaGravitacional = CONSTANTEGRAVITACIONAL * 
                            ( ( 1/this->getMassaInv( ) + 1/cOther.getMassaInv( ) ) /
                            ( distQuadrada ) );
    
    Vetor3 velocidade = cOther.getVelocidade( );
    Vetor3 direcao = distancia.calcularDirecao( velocidade );
    Vetor3 forca = distancia * forcaGravitacional;

    cOther.aplicarForca( forca );
}


bool CorpoCeleste::checarLimite( ) 
{
    if ( raio < 1 || raio > 100000000 ) 
    {
        cout << "Erro no Comprimento do Raio!";
        return false;
    }
    return true;
}
