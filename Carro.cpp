#include "Carro.h"

Carro::Carro( string model, string sound, int anoCriacao, int propelente )
: Veiculo( model, sound, anoCriacao, propelente, 1000 )
{
    somarMassa( this->propelente );
    this->rodaSaude = 100;
}


Carro::Carro( string model, string sound, int anoCriacao, int propelente, float massa )
: Veiculo( model, sound, anoCriacao, propelente, massa )
{
    somarMassa( this->propelente );
    this->rodaSaude = 100;
}

Carro::Carro( const Carro &cOther ) 
: Veiculo( cOther )
{ 
    //usa o construtor de copia de Veiculo para pegar
    // os atributos do objeto cOther da classe acima   
    this->rodaSaude = cOther.rodaSaude; 
}


Carro::~Carro( )
{

}


// -------- SOBRECARGA DE OPERADORES --------

ostream& operator<<( ostream& os, const Carro &cOther ) 
{
    os << "\nModelo: " << cOther.getModelo()
       << "\nSom: " << cOther.getSom()
       << "\nAno de Criacao: " << cOther.getAnoCriacao()
       << "\nPropelente Restante: " << cOther.getPropelente()
       << "\nPreco Estimado: " << cOther.getPreco()
       << "\nSaude das Rodas: " << cOther.getSaudeRoda();
    return os;
}

bool Carro::operator==( const Carro &cOther )
{
    // PROBLEMA
    return ( this->modelo == cOther.getModelo()
            && this->som == cOther.getSom()
            && this->anoCriacao == cOther.getAnoCriacao()
            && this->propelente == cOther.getPropelente()
            && this->preco == cOther.getPreco()
            && this->rodaSaude == cOther.getSaudeRoda() );
}

bool Carro::operator!=( const Carro &cOther )
{
    return !( *this == cOther );
}

Carro Carro::operator=( const Carro &cOther )
{
    this->modelo == cOther.getModelo();
    this->som == cOther.getSom();
    this->anoCriacao == cOther.getAnoCriacao();
    this->propelente == cOther.getPropelente();
    this->rodaSaude == cOther.getPreco();
    this->preco == cOther.getSaudeRoda();

    return *this;
}

Carro Carro::operator!( )
{
    /*
    * Reseta os atributos para um valor padrao
    */
    // Materia::operator!( );
    
    this->modelo = "UFPA";
    this->som = "VRUM!";
    this->anoCriacao = 2020;
    this->propelente = 100;
    this->rodaSaude = 100;
    this->preco = 70000;

    return *this;
}


// ------------- METODOS -----------------
void Carro::trocarRoda( )
{
    rodaSaude = 100;
}

void Carro::reporPropelente( )
{
    propelente = 100;
}

// ---- INICIALIZAR METODOS VIRTUAIS HERDADOS ----
void Carro::acelerar( )
{
    if ( rodaSaude <= 0 )
    {
        cout << "\nA roda quebrou! Precisa trocar.";
        return;
    }
    if ( propelente <= 0 )
    {
        cout << "\nO propelente acabou! Precisa encher o tanque.";
        return;
    }

    rodaSaude -= 10;
    propelente -= 10;
    Vetor3 f( 2000.0, 0.0, 0.0 ); 

    aplicarForca( f );
    updateMateria( );
    // displayMateria( );
}


void Carro::frear( )
{
    if ( rodaSaude <= 0 )
    {
        cout << "\nA roda quebrou! Precisa trocar.";
        return;
    }
    if ( propelente <= 0 )
    {
        cout << "\nO propelente acabou! Precisa encher o tanque.";
        return;
    }

    rodaSaude -= 10;
    propelente -= 10;

    Vetor3 f( -4000.0, 0.0, 0.0 ); 
    aplicarForca( f );
    updateMateria( );
    // displayMateria( );
}

bool Carro::checarLimite( ) 
{
    float dist = static_cast<int>( getPosicao( ).getX( ) );
    if ( dist > 100000 || dist < -100000 ) 
    {
        cout << "Ultrapassou os limites da simulação!";
        return false;
    }
    return true;
}