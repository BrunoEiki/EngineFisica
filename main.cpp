#include <iostream>
using std::cout;

#include "Vetor3.h"

const float G = 6.668e-11; // Constante gravitacional
const float ATRITO = 1.4e-2; // Constante de atrito (usou-se valor aleatorio)

int main(){
    Vetor3 vetor;
    cout << vetor.getMagnitude();
}

// class Fisica : public Vetor{
// public:
//     Fisica():Vetor(){}
//     void leiInercia(){
        
//     }
//     void leiAcaoReacao(){
        
//     }
//     void leiForca(){
        
//     }
// };


// class Objeto : public Fisica{
// public:
//     struct Corpo{
//         float massa;
//         Vetor posicao;
//     };
// };