#include "Materia.h"

Materia::Materia()
: posicao( ), velocidade( ), massaInverso( 1.0 ), tempoInicial( 0 ){
    Vetor3 a(0, GRAVIDADETERRA, 0);
    aceleracao = a;
}

Materia::Materia(Vetor3 posInicial, Vetor3 velInicial, float massa, int temp=0 )
: posicao( posInicial ), velocidade( velInicial ), forca( ){

    if ( massa <= 0.0 ) {
        massaInverso = 1.0; 
    } else{
        massaInverso = 1/massa;
    }
    
    Vetor3 a(0, GRAVIDADETERRA, 0);
    aceleracao = a;

    if (temp < tempoInicial){
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

    posicao = posicao + ( velocidade * ( tempoFinal - tempoInicial ) );

    Vetor3 auxForca = forca;
    auxForca.setX( auxForca.getX() * massaInverso );
    auxForca.setY( auxForca.getY() * massaInverso );
    auxForca.setZ( auxForca.getZ() * massaInverso );

// MODIFICAR ERRO CONSERTAR BLA BLA
    aceleracao = aceleracao + (auxForca * massaInverso);
 
    velocidade = velocidade + aceleracao * ( tempoFinal - tempoInicial );

    tempoInicial = tempoFinal;
    tempoFinal += 1;

}


void Materia::aplicarForca( const Vetor3 &fOther ){
    cout << "\nFoi aplicado uma forca " << fOther << " no objeto\n\n";
    this->forca = fOther;
}

// void Materia::displayMateria( ){
//     std::cout << "\nVelocidade: " << velocidade;
//     std::cout << "\nPosicao: " << posicao;
//     std::cout << "\nAceleracao: " << aceleracao;
//     std::cout << "\nTempo: " << tempoFinal << "\n";
// }

// float Materia::getVelocidade(){
//     return velocidade.getMagnitude();
// }

// const float Materia::getMagnitude( const Vetor3 &vOther ){
//     return (vOther.getX()*vOther.getX() + vOther.getY()*vOther.getY() + vOther.getZ()*vOther.getZ());
// }

ostream& operator<<( ostream& os, const Materia &mOther ){
    // POR QUE ISSO NN FUNCIONA??
    // Talvez porque estou acessando atributo não-const usando objeto const
    // Quando retirei const de "const Materia &mOther" no parametro
    // ele começou a funcionar.
    // [https://stackoverflow.com/questions/56980750/call-non-const-function-on-a-const-object]
    
    // Alternativa: usar getMagnitude( const Vetor3 & const )
    // os << mOther.getMagnitude( mOther.velocidade );
    
    os << "Massa: " << 1/mOther.massaInverso << "kg\n"
       << "Posicao: " << mOther.posicao << "\n"
       << "Velocidade: " << mOther.velocidade << "\n"
       << "Aceleracao: " << mOther.aceleracao << "\n"
       << "Forca resultante: " << mOther.forca << "\n\n";
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