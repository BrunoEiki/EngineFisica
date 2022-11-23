#include <iostream>
using std::cout;
using std::cin;

#include <locale>
using std::setlocale;

#include "Vetor3.h"
#include "Vetor3.cpp"

#include "Materia.h"
#include "Materia.cpp"

#include "Canhao.h"
#include "Canhao.cpp"

#include "Foguete.h"
#include "Foguete.cpp"

void setForca( );

int main( ) {
    setlocale(LC_ALL, "portuguese");
    
    cout << "\n======================================";
    cout << "\n======= Simulador de Canhao ==========";
    cout << "\n=====================================";
    
    int vida;
    cout << "\nDisparos do Canhao: ";
    cin >> vida;

    Vetor3 forca;
    float temp;

    Canhao canhao ( vida, Vetor3( 0, 0, 0 ) );
    cout << canhao;
    while ( canhao.getVida( ) > 0 ) {
        vida--;
        cout << "\nForca em X: ";
        cin >> temp;
        forca.setX(temp);
        
        cout << "\nForca em Y: ";
        cin >> temp;
        forca.setY(temp);
        
        cout << "\nForca em Z: ";
        cin >> temp;
        forca.setZ(temp);

        canhao.disparar( forca );
        cout << canhao;
    }

    cout << "\n===================================";
    cout << "\n===== Simulador de Foguete ========";
    cout << "\n==================================";
    
    Foguete foguete;
    foguete.combustao();
    cout << foguete;
    foguete.combustao();
    cout << foguete;

    
}