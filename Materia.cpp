#include "Materia.h"

// ---------- CONSTRUTORES -------------------

Materia::Materia( void )
: massaInverso( 1.0 ), forca( 0.0, GRAVIDADETERRA*(1/massaInverso), 0.0 ), 
  tempoInicial( 0 ), tempoFinal( 1 ) {

    Vetor3 a( 0, GRAVIDADETERRA, 0 );
    aceleracao = a;
}


Materia::Materia( float massa ) {

    if ( massa <= 0.0 ) {
        massaInverso = 1.0; 
    } else {
        massaInverso = 1/massa;
    }
    
    Vetor3 a( 0, GRAVIDADETERRA, 0 );
    aceleracao = a;

    forca.setY( GRAVIDADETERRA*(1/massaInverso) );
}


Materia::Materia( Vetor3 posInicial, Vetor3 velInicial, float massa )
: posicao( posInicial ), velocidade( velInicial ) {

    if ( massa <= 0.0 ) {
        massaInverso = 1.0; 
    } else{
        massaInverso = 1/massa;
    }
    
    Vetor3 a( 0.0, GRAVIDADETERRA, 0.0 );
    aceleracao = a;

    Vetor3 forcaAplicada( 0.0, GRAVIDADETERRA*(1/massaInverso), 0.0 );
    forca = forcaAplicada;
}

Materia::Materia( const Materia &mOther ) {
    this->posicao = mOther.posicao;
    this->velocidade = mOther.velocidade;
    this->aceleracao = mOther.aceleracao;
    this->massaInverso = mOther.massaInverso;
}

Materia::~Materia( ) {

}


// --------------- METODOS ------------------

void Materia::updateMateria( ) {
/*
* Equações de Newton-Euler para dinâmica de um corpo rígido
*/
    posicao = posicao + ( velocidade * ( tempoFinal - tempoInicial ) );
    aceleracao = aceleracao + (forca * massaInverso);
    velocidade = velocidade + aceleracao * ( tempoFinal - tempoInicial );

    tempoInicial = tempoFinal;
    tempoFinal += 1;

/*
position.addScaledVector(velocity, duration);
// Work out the acceleration from the force.
Vector3 resultingAcc = acceleration;
resultingAcc.addScaledVector(forceAccum, inverseMass);
// Update linear velocity from the acceleration.
velocity.addScaledVector(resultingAcc, duration);
// Impose drag.
velocity *= real_pow(damping, duration);
// good damping is around 1 -- like 0.995
*/

// Reseta força para o peso apenas, pois a força aplicada é momentanea
    Vetor3 forcaAplicada( 0, GRAVIDADETERRA*(1/massaInverso), 0 );
    forca = forcaAplicada;
}


void Materia::aplicarForca( const Vetor3 &forcaAplicada ) {
    cout << "\n\nFoi aplicado uma forca " << forcaAplicada << " no objeto";

    this->forca = this->forca + forcaAplicada;
}


void Materia::somarMassa( float massa ){
    this->massaInverso = 1/(1/this->massaInverso + massa);
}


Vetor3 Materia::getForca( ) const {
    return forca;
}

Vetor3 Materia::getPosicao( ) const {
    return posicao;
}

void Materia::resetarVetores( ) {
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
    forca.setY( GRAVIDADETERRA*(1/massaInverso) );
    forca.setZ( 0.0 );
}

void Materia::displayMateria( ) const {
    cout << "\nMassa Total: " << 1/(massaInverso) << "kg"
       << "\nPosicao: " << posicao
       << "\nVelocidade: " << velocidade
       << "\nAceleracao: " << aceleracao
       << "\nTempo Total: " << tempoInicial;
}


// // ---------- SOBRECARGA DE OPERADORES -----------

// ostream& operator<<( ostream& os, const Materia &mOther ) {
//     os << "\nMassa Total: " << 1/(mOther.massaInverso) << "kg"
//        << "\nPosicao: " << mOther.posicao
//        << "\nVelocidade: " << mOther.velocidade
//        << "\nAceleracao: " << mOther.aceleracao
//        << "\nForca resultante: " << mOther.forca
//        << "\nTempo Total: " << mOther.tempoInicial;
//     return os;
// }


// bool Materia::operator==( const Materia &mOther ) {
//     if ( this->velocidade == mOther.velocidade && this->aceleracao == mOther.aceleracao
//          && this->posicao == mOther.posicao && this->forca == mOther.forca
//          && this->massaInverso == mOther.massaInverso ) {
//             return true;
//         }
//     return false;
// }

// bool Materia::operator!=( const Materia &mOther ) {
//     return !( *this == mOther );
// }

// Materia Materia::operator=( const Materia &mOther ) {
//     this->velocidade = mOther.velocidade;
//     this->aceleracao = mOther.aceleracao;
//     this->posicao = mOther.posicao;
//     this->forca = mOther.forca;

//     this->massaInverso = mOther.massaInverso;

//     return *this;
// }

// Materia Materia::operator!( ) {
//     this->velocidade = !this->velocidade;
//     this->aceleracao = !this->aceleracao;
//     this->posicao = !this->posicao;
//     this->forca = !this->forca;

//     return *this;
// }