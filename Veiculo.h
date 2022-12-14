#ifndef VEICULO_H
#define VEICULO_H

#include "Materia.h"

// ==== CLASSE ABSTRATA ====
class Veiculo : public Materia {
public:

// CONSTRUTORES
    Veiculo( string, string, int, int );
    Veiculo( string, string, int, int, float );
    Veiculo( const Veiculo & );

    virtual ~Veiculo( void );

// // SOBRECARGA DE OPERADORES
    // bool operator==( const Veiculo & );
    // bool operator!=( const Veiculo & );
    // Veiculo operator=( const Veiculo & );
    // Veiculo operator!( );

// METODO CLONE
// virtual Veiculo* clone() const;

// METODO
    void emitirSom( void );
    int getPropelente( void );

// METODOS VIRTUAIS
    virtual void acelerar( void ) = 0;
    virtual void frear( void ) = 0;
    

protected:
    string modelo;
    string som;
    int anoCriacao;                  
    // float velocidadeLimite;
    float propelente;
    float preco;
};

#endif    // VEICULO_H