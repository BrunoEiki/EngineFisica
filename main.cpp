// #include <stdlib.h>
// using std::system;

#include <iostream>
using std::cout;
using std::cin;

#include <vector>
using std::vector;

#include <locale>
using std::setlocale;

// #include "Vetor3.h"
// #include "Vetor3.cpp"

// #include "Materia.h"
// #include "Materia.cpp"

// #include "Veiculo.h"
// #include "Veiculo.cpp"

#include "Carro.h"
#include "Carro.cpp"

#include "Foguete.h"
#include "Foguete.cpp"

int main( ) {
    setlocale(LC_ALL, "portuguese");

    vector< Veiculo* > veiculos;
    
    int numVeiculo;
    bool carroOuFoguete = true;

    string modelo;
    string som;
    int ano;
    int propelente;

    int op = 0;

    while ( op != 4){
        // system("CLS");        
        cout << "\n===================================";
        cout << "\n====== Simulador de Fisica ========";
        cout << "\n==================================";

        cout << "\n\n1. Teste de Velocidade do Veiculo";
        cout << "\n2. Alguma coisa";
        cout << "\n3. Lorem Ipsum Socorro";
        cout << "\n4. Sair";
        cout << "\n";

        cout << "Digite sua escolha: ";
        cin >> op;

        switch( op ){
            case 1:
            {
                cout << "\nNumero de Veiculos: ";
                cin >> numVeiculo;
                if ( numVeiculo < 0 ) {
                    numVeiculo = 2;
                }

                // ---------- EXEMPLO DE ENTRADAS ----------- 
                veiculos[ 0 ] = new Carro( "Fiat", "Vruuummmmm!!", 2022, 50 );
                veiculos[ 1 ] = new Carro( "Honda", "Vruuuuuuum", 2006, 50 );
                veiculos[ 2 ] = new Carro( "UFPA", "Vrum", 2007, 50 );
                // veiculos[ 3 ] = new Foguete( "NASA", "BUMMMMMM!!", 2022, 1000 );
                // veiculos[ 4 ] = new Foguete( "Fiat", "FUSSHHHHH!!", 2022, 8000 );

                for ( size_t i = 0; i < veiculos.size( ); i++ ) {
                    Carro *derivedPtr = dynamic_cast< Carro * >( veiculos[ 0 ] );
                    derivedPtr->acelerar( );
                }

                    // cout << "\nCarro[0] ou Foguete[1]: ";
                    // cin >> carroOuFoguete;

                    // cout << "Nome do Modelo: ";
                    // cin >> modelo;

                    // cout << "Som do Veiculo: ";
                    // cin >> som;

                    // cout << "Ano de Fabricacao: ";
                    // cin >> ano;

                    // cout << "Quantidade de Propelente: ";
                    // cin >> propelente;

                    // veiculos.push_back( veiculo );

                    // if ( carroOuFoguete ) {
                    //     Veiculo *veiculo = new Carro( modelo, som, ano, propelente );
                    //     veiculos.push_back( veiculo );            
                    // }     
                    
                    // } else{
                    //     Veiculo *veiculo = new Foguete( modelo, som, ano, propelente );
                    //     veiculos.push_back( veiculo );
                    // }

                // }
                
                // for ( size_t i = 0; i < veiculos.size( ); i++ ) {
                //     // veiculos[ i ]->mostrar( );
                //     Carro *derivedPtr = dynamic_cast< Carro * >( veiculos[ i ] );
                    
                //     if ( derivedPtr != nullptr ){
                        
                    //     cout << " entrou";
                    //     // derivedPtr->emitirSom( );
                    //     // while ( derivedPtr->getDistancia( ) <= 80 && derivedPtr->getTempo( ) < 11 ){
                    //     // while ( derivedPtr->getTempo( ) < 11 ){
                    //     //     derivedPtr->acelerar( );
                    //     // }

                    //     // if ( derivedPtr->getTempo( ) == 11 ){
                    //     //     cout << "\nTempo estourado! Velocidade do veiculo insuficiente.";
                    //     // }

                    //     // }
                //     }
                // }

                for ( size_t j = 0; j < veiculos.size(); j++ )
                {

                    cout << "\nDeletando objeto de classe "
                        << typeid( *veiculos[ j ] ).name( ) << "...";

                    delete veiculos[ j ];
                }
                veiculos.clear(); // precisa?
                break;
            } 

            case 2:
            {

                // Carro fiat2022( "Fiat", "Vruuummmmm!!", 2022, 50 );
                // fiat2022.acelerar( );
                // fiat2022.acelerar( );
                // fiat2022.acelerar( );
                // fiat2022.frear( );
                // fiat2022.frear( );
                // fiat2022.reporPropelente( );
                // fiat2022.frear( );
                // fiat2022.frear( );
                // fiat2022.frear( );
                // fiat2022.frear( );
                // fiat2022.frear( );
                // fiat2022.frear( );
                // fiat2022.frear( );

                break;
            }
        }
        cin.get();
        cin.get();
    }

    // cout << "\n===================================";
    // cout << "\n===== Simulador de Foguete ========";
    // cout << "\n==================================";
    
    // Foguete foguete;
    // foguete.combustao();
    // cout << foguete;
    // foguete.combustao();
    // cout << foguete;



    // cout << "\n======================================";
    // cout << "\n======= Simulador de Canhao ==========";
    // cout << "\n=====================================";
    
    // int vida;
    // cout << "\nDisparos do Canhao: ";
    // cin >> vida;

    // Vetor3 forca;
    // float temp;

    // Canhao canhao ( vida, Vetor3( 0, 0, 0 ) );
    // cout << canhao;
    // while ( canhao.getVida( ) > 0 ) {
    //     vida--;
    //     cout << "\nForca em X: ";
    //     cin >> temp;
    //     forca.setX(temp);
        
    //     cout << "\nForca em Y: ";
    //     cin >> temp;
    //     forca.setY(temp);
        
    //     cout << "\nForca em Z: ";
    //     cin >> temp;
    //     forca.setZ(temp);

    //     canhao.disparar( forca );
    //     cout << canhao;
    // }
    
}