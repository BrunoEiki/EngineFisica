#include "Materia.h"

// ---------- CONSTRUTORES -------------------

Materia::Materia( void )
: massaInverso( 1.0 ), forca( 0.0, GRAVIDADETERRA*(1/massaInverso), 0.0 ), 
  tempoInicial( 0 ), tempoFinal( 1 ) 
{
    Vetor3 a( 0, GRAVIDADETERRA, 0 );
    aceleracao = a;
}


Materia::Materia( float massa ) 
{
    if ( massa <= 0.0 )
        massaInverso = 1.0; 
    else
        massaInverso = 1/massa;
    
    Vetor3 a( 0, GRAVIDADETERRA, 0 );
    aceleracao = a;

    forca.setY( GRAVIDADETERRA*( 1/massaInverso ) );
}


Materia::Materia( Vetor3 posInicial, Vetor3 velInicial, float massa )
: posicao( posInicial ), velocidade( velInicial ) 
{
    if ( massa <= 0.0 ) 
        massaInverso = 1.0; 
    else
        massaInverso = 1/massa;
    
    Vetor3 a( 0.0, GRAVIDADETERRA, 0.0 );
    aceleracao = a;

    Vetor3 forcaAplicada( 0.0, GRAVIDADETERRA*( 1/massaInverso ), 0.0 );
    forca = forcaAplicada;
}

Materia::Materia( const Materia &mOther ) 
{
    this->forca = mOther.forca;
    this->posicao = mOther.posicao;
    this->velocidade = mOther.velocidade;
    this->aceleracao = mOther.aceleracao;
    this->massaInverso = mOther.massaInverso;
}

Materia::~Materia( ) 
{

}


// --------------- METODOS ------------------

void Materia::updateMateria( ) 
{
/*
* Equações de Newton-Euler para dinâmica de um corpo rígido
*/
    posicao = posicao + ( velocidade * ( tempoFinal - tempoInicial ) );
    if ( posicao.getY( ) <= 0.1 ) 
    {
        posicao.setY( 0.0 );
    }

    aceleracao = aceleracao + (forca * massaInverso);
    
    velocidade = velocidade + aceleracao * ( tempoFinal - tempoInicial );
    if ( velocidade.getY( ) <= 0.1 ) 
    {
        velocidade.setY( 0.0 );
    }

    tempoInicial = tempoFinal;
    tempoFinal += 1;

// Reseta força para o peso apenas, pois a força aplicada é momentanea
    Vetor3 forcaAplicada( 0, GRAVIDADETERRA*( 1/massaInverso ), 0 );
    forca = forcaAplicada;
}


void Materia::aplicarForca( const Vetor3 &forcaAplicada ) 
{
    // cout << "\n\nFoi aplicado uma forca " << forcaAplicada << " no objeto";
    this->forca = this->forca + forcaAplicada;
}

void Materia::somarMassa( float massa )
{
    this->massaInverso = 1 / ( 1/this->massaInverso + massa );
}


void Materia::resetarVetores( ) 
{
    aceleracao.setX( 0.0 );
    aceleracao.setY( GRAVIDADETERRA );
    aceleracao.setZ( 0.0 );

    velocidade.setX( 0.0 );
    velocidade.setY( 0.0 );
    velocidade.setZ( 0.0 );

    posicao.setX( 0.0 );
    posicao.setY( 0.0 );
    posicao.setZ( 0.0 );

    forca.setX( 0.0 );
    forca.setY( GRAVIDADETERRA*( 1/massaInverso ) );
    forca.setZ( 0.0 );
}

void Materia::displayMateria( ) const 
{
    cout << "\nMassa Total: " << 1/(massaInverso) << "kg"
       << "\nPosicao: " << posicao
       << "\nVelocidade: " << velocidade
       << "\nAceleracao: " << aceleracao
       << "\nTempo Total: " << tempoInicial << "s";
}

