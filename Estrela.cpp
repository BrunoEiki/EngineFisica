#include "Estrela.h"

// CONSTRUTORES
Estrela::Estrela( string nome, float temperatura )
: CorpoCeleste( nome, 100000 ), temperatura( temperatura ) 
{
    if ( temperatura < 1000 )
        this->temperatura = 2700;
}


Estrela::Estrela( string nome, float temperatura, float massa, float raio )
: CorpoCeleste( nome, massa ), temperatura( temperatura )
{
    if ( temperatura < 1000 )
        this->temperatura = 2700;
}


Estrela::Estrela( const Estrela &eOther )
: CorpoCeleste( eOther ) 
{
    this->temperatura = eOther.temperatura;
}


Estrela::~Estrela( )
{

}

// METODOS

void Estrela::classificarEstrela( )
{
    if ( temperatura < 2400 )
    {
        cout << "\nIndefinido!";
    
    } else if ( temperatura >= 2400 && temperatura < 3700 )
    {
        cout << "\nClasse: M -> Cromaticidade vermelho alaranjado";
    
    } else if ( temperatura >= 3700 && temperatura < 5200 )
    {
        cout << "\nClasse: K -> Cromaticidade laranja claro";

    } else if ( temperatura >= 5200 && temperatura < 6000 )
    {
        cout << "\nClasse: G -> Cromaticidade amarelo";
    
    } else if ( temperatura >= 6000 && temperatura < 7500 )
    {
        cout << "\nClasse: F -> Cromaticidade amarelo-branco";
    
    } else if ( temperatura >= 7500 && temperatura < 10000 )
    {
        cout << "\nClasse: A -> Cromaticidade branco";
    
    } else if ( temperatura >=10000 && temperatura < 30000 )
    {
        cout << "\nClasse: B -> Cromaticidade azul-branco";
    
    } else
    {
        cout << "\nClasse: O -> Cromaticidade azul";
    }
}


// SOBRECARGA DE OPERADORES

ostream& operator<<( ostream& os, const Estrela &eOther ) 
{
    os << "\nTemperatura: " << eOther.getTemperatura( ) << "K";

    return os;
}


bool Estrela::operator==( const Estrela &eOther )
{
    return ( this->temperatura == eOther.temperatura && 
            CorpoCeleste::operator==( eOther ));    
}


bool Estrela::operator!=( const Estrela &eOther )
{
    return !( *this == eOther );
}


Estrela Estrela::operator=( const Estrela &eOther )
{
     CorpoCeleste::operator=( eOther );    
    this->temperatura = eOther.getTemperatura( ); 

    return *this;
}

Estrela Estrela::operator!( )
{
    this->temperatura = 5780;  // temperatura efetiva do sol
    return *this;
}