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
*  OK. Merge branches
*  2. Mudar setters e getters triviais para setXYZ e getXYZ;
*  3. Display posicao da bala no cout do canhao
*  4. Implementar tempo
*  5. Resetar força apos updateMateria()
*  6. Força do Disparo tem que ser Vetor3
*  7. Joguinho de acertar o alvo
*  8. Criar classe Pistola
*  9. +++ Implementar uma interface grafica
*/
