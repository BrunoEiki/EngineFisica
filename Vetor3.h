#include <cmath>

#include <ostream>
using std::ostream;

#ifndef VETOR3_H
#define VETOR3_H

class Vetor3{

    /*
    * VETOR3 representa os vetores como definidos na física. Têm 3 dimensões, x, y e z, 
    * que podem ser manipulados pelos operadores via sobrecarga. É classe base de FISICA
    * e CORPORIGIDO.  
    */

// SOBRECARGA DE OPERADOR
    friend ostream& operator<<( ostream& os, const Vetor3 & );

private:
    float x;
    float y;
    float z;

public:
// CONSTRUTORES
    Vetor3( );
    Vetor3( const float, const float, const float );
    Vetor3( const Vetor3 &vOther );

// DESTRUTOR
    ~Vetor3( );

// SOBRECARGA DE OPERADORES ()
    bool operator==( const Vetor3 & );
    bool operator!=( const Vetor3 & );
    Vetor3 operator=(const Vetor3 & );
    Vetor3 operator!( );

    Vetor3 operator=( const float escalar );
    Vetor3 operator+( const Vetor3 & );
    Vetor3 operator-( const Vetor3 & );
    Vetor3 operator*( const float );

// OPCIONAL
    // Vetor3 operator*( const float & ); // produto escalar -> isso limita comutatividade? -> [1,1,1]*2 != 2*[1,1,1] ?
    // Vetor3 operator*( const Vetor3 & ); // produto vetorial


// MÉTODOS
    float getMagnitude( ) const;
    float getX( ) const;
    float getY( ) const;
    float getZ( ) const;

    void setX( const float );
    void setY( const float );
    void setZ( const float );


// FAZER?
    float scalarProduct( );
    void vectorProduct( );
};

#endif