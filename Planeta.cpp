#include "Planeta.h"

Planeta::Planeta( string nome, int rotacao, int translacao )
: CorpoCeleste( nome, 100000 ), periodoRotacao( rotacao ), periodoTranslacao( translacao ) 
{
    if ( rotacao < 1 )
        this->periodoRotacao = 1;

    if ( translacao < 1 )
        this->periodoTranslacao = 1;
}

Planeta::Planeta( string nome, int rotacao, int translacao, float massa, float raio )
: CorpoCeleste( nome, massa, raio ), periodoRotacao( rotacao ), periodoTranslacao( translacao )
{
    if ( rotacao < 1 )
        this->periodoRotacao = 1;

    if ( translacao < 1 )
        this->periodoTranslacao = 1;
}

Planeta::Planeta( const Planeta &pOther )
: CorpoCeleste( pOther ) 
{
    this->periodoRotacao = pOther.getRotacao( );
    this->periodoTranslacao = pOther.getTranslacao( );
}


Planeta::~Planeta( )
{

}

int Planeta::calcularHorasAno( ) const
{   
    return periodoRotacao * ( periodoTranslacao * 365 );
}


// SOBRECARGA DE OPERADORES

ostream& operator<<( ostream& os, const Planeta &pOther ) 
{
    os << "\nRotacao: " << pOther.getRotacao( ) << " dias terrestres"
       << "\nTranslacao: " << pOther.getTranslacao( ) << " anos terrestres"
       << "\nTotal de Horas no ano do planeta: " << pOther.calcularHorasAno( );

    return os;
}

bool Planeta::operator==( const Planeta &pOther )
{
    return ( this->periodoRotacao == pOther.getRotacao( ) &&
             this->periodoTranslacao == pOther.getTranslacao( ) &&
             CorpoCeleste::operator==( pOther ));
}


bool Planeta::operator!=( const Planeta &pOther )
{
    return !( *this == pOther );
}


Planeta Planeta::operator=( const Planeta &pOther )
{
    CorpoCeleste::operator=( pOther );
    this->periodoRotacao = pOther.getRotacao( );
    this->periodoTranslacao = pOther.getTranslacao( );

    return *this;
}

Planeta Planeta::operator!( )
{
    this->periodoRotacao = 1;
    this->periodoTranslacao = 1;

    return *this;
}