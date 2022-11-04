#include "Materia.h"

#include <iostream>

Materia::Materia()
: posicao( ), velocidade( ), aceleracao( 0, -10, 0 ), massaInverso( 1.0 ), tempoInicial( 0 ){
    
}

Materia::Materia(Vetor3 posInicial, Vetor3 velInicial, float massaInv, int temp=0 )
: posicao( posInicial ), velocidade( velInicial ), aceleracao( 0, GRAVIDADETERRA, 0 ), forca( ){
    if ( massaInv < 0.0 ) {
        massaInverso = 1.0; 
    }

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

void Materia::updateMateria( ){

    // CONSERTAR

    posicao = posicao + ( velocidade * ( tempoFinal - tempoInicial ) );
    
    Vetor3 auxForca = forca;
    auxForca.setX( auxForca.getX() * massaInverso );
    auxForca.setY( auxForca.getY() * massaInverso );
    auxForca.setZ( auxForca.getZ() * massaInverso );

    aceleracao = aceleracao + auxForca;
 
    velocidade = velocidade + aceleracao * ( tempoFinal - tempoInicial );

    tempoInicial = tempoFinal;
    tempoFinal += 1;
}


void Materia::aplicarForca( const Vetor3 &fOther ){
    this->forca = fOther;
}

void Materia::displayMateria( ){
    std::cout << "\nVelocidade: " << velocidade;
    std::cout << "\nPosicao: " << posicao;
    std::cout << "\nAceleracao: " << aceleracao;
    std::cout << "\nTempo: " << tempoFinal;
}


ostream& operator<<( ostream& os, const Materia &mOther ){
    // POR QUE ISSO NN FUNCIONA??
    // os << mOther.velocidade.getMagnitude();

    os << "AAAAAAAAAAAAA";
    return os;
}


bool Materia::operator==( const Materia &mOther){
    if (this->velocidade == mOther.velocidade && this->aceleracao == mOther.aceleracao &&
        this->posicao == mOther.posicao && this->forca == mOther.forca &&
        this->massaInverso == mOther.massaInverso){
            return true;
        }
    return false;
}

bool Materia::operator!=( const Materia &mOther ){
    if (*this != mOther) return true;
    return false;
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