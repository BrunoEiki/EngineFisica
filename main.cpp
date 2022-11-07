#include <iostream>
using std::cout;

#include <locale>
using std::setlocale;

#include "Vetor3.h"
#include "Vetor3.cpp"

#include "Materia.h"
#include "Materia.cpp"

#include "Canhao.h"
#include "Canhao.cpp"

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
    
    // cout << caixa;
    // caixa.displayMateria();

    Canhao canhao;
    Canhao canhao2 = canhao;

    if (canhao == canhao2) {
        cout << "TRUE";
    }

    canhao2 = !canhao2;
    cout << canhao2;

    cout << canhao;
    canhao.disparar( );
    cout << canhao;

}

// Mudanças;
/*
*  1. Merge branches
*  2. Mudar setters e getters triviais para setXYZ e getXYZ;
*  3. Display posicao da bala no cout do canhao
*  4. Implementar tempo
*  5. Resetar força apos updateMateria()
*  6. Força do Disparo tem que ser Vetor3
*  7. Joguinho de acertar o alvo
*  8. +++ Implementar uma interface grafica
*/
