#include "Vetor3.h"

#include <iostream>
using std::cout;

Vetor3::Vetor3( )
:x( 0.0 ), y( 0.0 ), z( 0.0 ){

}

Vetor3::Vetor3( const float xin, const float yin, const float zin )
:x( xin ), y( yin ), z( zin ){

}

Vetor3::Vetor3( const Vetor3 &vOther ){
    this->x = vOther.x;
    this->y = vOther.y;
    this->z = vOther.z;
}

Vetor3::~Vetor3( ){

}

float Vetor3::getMagnitude( ){
    return std::sqrt( x*x + y*y + z*z );
}

const float Vetor3::getX( ){
    return x;
}

const float Vetor3::getY( ){
    return y;
}

const float Vetor3::getZ( ){
    return z;
}

void Vetor3::setX( const float x ){
    this->x = x;    
}
void Vetor3::setY( const float y ){
    this->y = y;    
}
void Vetor3::setZ( const float z ){
    this->z = z;    
}

bool Vetor3::operator==( const Vetor3 &vOther ){
    if ( this->x == vOther.x && this->y == vOther.y && this->z == vOther.z ){
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const Vetor3 &vOther){
    os << "x:" << vOther.x << " y:" << vOther.y << " z:" << vOther.z;
    return os;
}


bool Vetor3::operator!=( const Vetor3 &vOther ){
    return !( *this == vOther );
}

Vetor3 Vetor3::operator=( const Vetor3 &vOther ){
    this->x = vOther.x;
    this->y = vOther.y;
    this->z = vOther.z;

    return *this;
}

Vetor3 Vetor3::operator=( const float escalar ){
    /*
    * Atribui o mesmo escalar a todos os eixos: x, y e z.
    */
    this->x = escalar;
    this->y = escalar;
    this->z = escalar;

    return *this;
}

Vetor3 Vetor3::operator!( ){
    this->x *= -1;
    this->y *= -1;
    this->z *= -1;

    return *this;
}

Vetor3 Vetor3::operator+( const Vetor3 &vOther ){
    this->x = this->x + vOther.x;
    this->y = this->y + vOther.y;
    this->z = this->z + vOther.z;

    return *this;
}

Vetor3 Vetor3::operator-( const Vetor3 &vOther ){
    this->x = this->x - vOther.x;
    this->y = this->y - vOther.y;
    this->z = this->z - vOther.z;

    return *this;
}

Vetor3 Vetor3::operator*( const float escalar ){
    this->x *= escalar;
    this->y *= escalar;
    this->z *= escalar;

    return *this;
}
    // Subtração

