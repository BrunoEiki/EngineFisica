#include "Vetor3.h"

#include <iostream>
using std::cout;


// UPDATE 13/12/2022
// Direcao Y nao pode ficar abaixo de 0.0


// ---------- CONSTRUTORES -------------------

Vetor3::Vetor3( )
:x( 0.0 ), y( 0.0 ), z( 0.0 ){

}

Vetor3::Vetor3( const float xin, const float yin, const float zin )
:x( xin ), z( zin ) {
    if ( this->y <= 0.001 ){
        this->y = 0.0;
    }
}

Vetor3::Vetor3( const Vetor3 &vOther ){
    this->x = vOther.x;
    this->y = vOther.y;
    this->z = vOther.z;
}

Vetor3::~Vetor3( ){

}



// --------------- METODOS ------------------

float Vetor3::getMagnitude( ) const {
    return std::sqrt( x*x + y*y + z*z );
}

float Vetor3::getX( ) const {
    return x;
}

float Vetor3::getY( ) const {
    return y;
}

float Vetor3::getZ( ) const {
    return z;
}

void Vetor3::setX( const float x ) {
    this->x = x;    
}
void Vetor3::setY( const float y ) {
    if ( this->y <= 0.001 ){
        this->y = 0.001;
    }
}
void Vetor3::setZ( const float z ) {
    this->z = z;    
}



// ---------- SOBRECARGA DE OPERADORES -----------


bool Vetor3::operator==( const Vetor3 &vOther ){
    if ( this->x == vOther.x && this->y == vOther.y && this->z == vOther.z ) {
        return true;
    }
    return false;
}

ostream& operator<<( ostream& os, const Vetor3 &vOther ) {
    os << "x:" << vOther.x << " y:" << vOther.y << " z:" << vOther.z;
    return os;
}


bool Vetor3::operator!=( const Vetor3 &vOther ) {
    return !( *this == vOther );
}

Vetor3 Vetor3::operator=( const Vetor3 &vOther ) {
    this->x = vOther.x;
    this->y = vOther.y;
    this->z = vOther.z;

    return *this;
}

Vetor3 Vetor3::operator=( const float escalar ) {
    /*
    * Atribui o mesmo escalar a todos os eixos: x, y e z.
    */
    this->x = escalar;
    this->y = escalar;
    this->z = escalar;

    return *this;
}

Vetor3 Vetor3::operator!( ) {
    /*
    * Valos negativo de x e z, mas valor zero para y
    */
    this->x *= -1;
    this->y = 0;
    this->z *= -1;

    return *this;
}

Vetor3 Vetor3::operator+( const Vetor3 &vOther ) {
    this->x = this->x + vOther.x;
    this->y = this->y + vOther.y;
    if ( this->y <= 0.001 ){
        this->y = 0.0;
    }
    this->z = this->z + vOther.z;

    return *this;
}

Vetor3 Vetor3::operator-( const Vetor3 &vOther ) {
    this->x = this->x - vOther.x;
    this->y = this->y - vOther.y;
    if ( this->y <= 0.0 ){
        this->y = 0.0;
    }
    this->z = this->z - vOther.z;

    return *this;
}

Vetor3 Vetor3::operator*( const float escalar ) {
    this->x *= escalar;
    this->y *= escalar;
    if ( this->y <= 0.001 ){
        this->y = 0.0;
    }
    this->z *= escalar;

    return *this;
}
    // Subtração

