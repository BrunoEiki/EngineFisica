#include <iostream>
using std::cout;

#include <locale>
using std::setlocale;

#include "Vetor3.h"
#include "Vetor3.cpp"

#include "Materia.h"
#include "Materia.cpp"

int main(){
    setlocale(LC_ALL, "portuguese");

    Vetor3 speed( 0, 100, 0 );
    Vetor3 position( 0, 0, 0 );
    Vetor3 force(5, 0, 0);

    Materia caixa( position, speed, 1 );
    Materia caixa2 = caixa;

    cout << caixa;

    caixa.aplicarForca( force );
    caixa.updateMateria();
    cout << caixa;

    if (caixa == caixa2) cout << "Igual\n";
    else cout << "Diferente";
}