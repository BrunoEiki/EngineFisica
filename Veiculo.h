#ifndef VEICULO_H
#define VEICULO_H

#include "Materia.h"

// ==== CLASSE ABSTRATA ====
class Veiculo : public Materia {
public:

// CONSTRUTORES
    Veiculo( string, string, int );
    Veiculo( string, string, int, float );
    Veiculo( const Veiculo & );

// METODO
    void emitirSom( );

// METODOS VIRTUAIS
    virtual void acelerar( ) = 0;
    virtual void frear( ) = 0;


private:
    string modelo;
    string som;
    int anoCriacao;

protected:
    float velocidadeLimite;
    float propelente;
    float preco;
};

#endif    // Veiculo_h