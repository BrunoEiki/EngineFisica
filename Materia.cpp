#include "Materia.h"


// ---------- CONSTRUTORES -------------------

Materia::Materia()
: massaInverso( 1.0 ), forca( 0, GRAVIDADETERRA*(1/massaInverso) ), tempoInicial( 0 ){
    Vetor3 a( 0, GRAVIDADETERRA, 0 );
    aceleracao = a;
}

Materia::Materia( float massa, int temp = 0 ) {

    if ( massa <= 0.0 ) {
        massaInverso = 1.0; 
    } else {
        massaInverso = 1/massa;
    }
    
    Vetor3 a( 0, GRAVIDADETERRA, 0 );
    aceleracao = a;

    Vetor3 forcaAplicada(0, GRAVIDADETERRA*(1/massaInverso), 0);
    forca = forcaAplicada;

    if (temp < 0){
        tempoInicial = 0;
    } else{
        tempoInicial = temp;
    }

    tempoFinal = tempoInicial + 1;
}

Materia::Materia(Vetor3 posInicial, Vetor3 velInicial, float massa, int temp = 0 )
: posicao( posInicial ), velocidade( velInicial ) {

    if ( massa <= 0.0 ) {
        massaInverso = 1.0; 
    } else{
        massaInverso = 1/massa;
    }
    
    Vetor3 a( 0, GRAVIDADETERRA, 0 );
    aceleracao = a;

    Vetor3 forcaAplicada(0, GRAVIDADETERRA*(1/massaInverso), 0);
    forca = forcaAplicada;

    if (temp < 0){
        tempoInicial = 0;
    } else{
        tempoInicial = temp;
    }

    tempoFinal = tempoInicial + 1;
}

Materia::Materia( const Materia &mOther ){
    this->posicao = mOther.posicao;
    this->velocidade = mOther.velocidade;
    this->aceleracao = mOther.aceleracao;
    this->massaInverso = mOther.massaInverso;
}

Materia::~Materia( ){

}


// --------------- METODOS ------------------

void Materia::updateMateria( ){
'''
Equações de Newton-Euler para dinâmica de um corpo rígido
'''
    posicao = posicao + ( velocidade * ( tempoFinal - tempoInicial ) );
    aceleracao = aceleracao + (forca * massaInverso);
    velocidade = velocidade + aceleracao * ( tempoFinal - tempoInicial );

    tempoInicial = tempoFinal;
    tempoFinal += 1;

// Reseta força para o peso apenas, pois a força aplicada é momentanea
    Vetor3 forcaAplicada(0, GRAVIDADETERRA*(1/massaInverso), 0);
    forca = forcaAplicada;
}


void Materia::aplicarForca( const Vetor3 &forcaAplicada ) {
    cout << "\nFoi aplicado uma forca " << forcaAplicada << " no objeto\n\n";

    this->forca += forcaAplicada;
}

void Materia::somarMassa( float massa ){
    this->massaInverso += 1/massa;
}

float Materia::getForca( ){
    return forca;
}

// void Materia::resetarAceleracao( ) {
//     aceleracao.setX( 0.0 );
//     aceleracao.setY( GRAVIDADETERRA );
//     aceleracao.setZ( 0.0 );
// }


// ---------- SOBRECARGA DE OPERADORES -----------

ostream& operator<<( ostream& os, const Materia &mOther ) {
    os << "Massa: " << 1/(mOther.massaInverso) << "kg\n"
       << "Posicao: " << mOther.posicao << "\n"
       << "Velocidade: " << mOther.velocidade << "\n"
       << "Aceleracao: " << mOther.aceleracao << "\n"
       << "Forca resultante: " << mOther.forca << "\n\n";
    return os;
}


bool Materia::operator==( const Materia &mOther){
    if (this->velocidade == mOther.velocidade && this->aceleracao == mOther.aceleracao
        && this->posicao == mOther.posicao && this->forca == mOther.forca
        && this->massaInverso == mOther.massaInverso){
            return true;
        }
    return false;
}

bool Materia::operator!=( const Materia &mOther ){
    return !(*this == mOther);
}

Materia Materia::operator=( const Materia &mOther ){
    this->velocidade = mOther.velocidade;
    this->aceleracao = mOther.aceleracao;
    this->posicao = mOther.posicao;
    this->forca = mOther.forca;

    this->massaInverso = mOther.massaInverso;

    return *this;
}

Materia Materia::operator!( ){
    this->velocidade = !this->velocidade;
    this->aceleracao = !this->aceleracao;
    this->posicao = !this->posicao;
    this->forca = !this->forca;

    return *this;
}