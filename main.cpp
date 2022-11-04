#include <iostream>
using std::cout;

#include "Vetor3.h"
#include "Vetor3.cpp"

#include "Materia.h"
#include "Materia.cpp"

int main(){
    Vetor3 speed( 0, 100, 0 );
    Vetor3 position( 0, 0, 0 );
    Vetor3 force(5, 0, 0);

    Materia caixa( position, speed, 1 );
    caixa.aplicarForca( force );
    caixa.updateMateria();
    
    cout << caixa;
    caixa.displayMateria();
}