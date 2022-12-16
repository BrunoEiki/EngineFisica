#include <iostream>
using std::cout;
using std::cin;

#include "Carro.h"
#include "Carro.cpp"

#include "Foguete.h"
#include "Foguete.cpp"

#include "CorpoCeleste.h"
#include "CorpoCeleste.cpp"

#include "Estrela.h"
#include "Estrela.cpp"

#include "Planeta.h"
#include "Planeta.cpp"

int main( ) 
{
    int numVeiculo;

    int op = 0;
    vector< Veiculo* > veiculos ( 5 );
    vector< CorpoCeleste* > corposCelestes ( 5 );

    while ( op != 4 ) 
    {
        cout << "\n===================================="
             << "\n======= Simulador de Fisica ========"
             << "\n===================================="
             << "\n|                                  |"
             << "\n| 1. TESTE DE VELOCIDADE DO CARRO  |"
             << "\n| 2. TESTE DE ALTURA DO FOGUETE    |"
             << "\n| 3. CLASSIFICAR ESTRELAS          |"
             << "\n|__________________________________|"
             << "\n\n";

        cout << "\nDigite sua escolha: ";
        cin >> op;

        switch( op )
        {
            case 1:
            {
                // ----------------- EXEMPLO DE ENTRADAS ------------------ 
                veiculos[ 0 ] = new Carro( "Fiat", "SOM_CARRO!!", 2022, 50 );
                veiculos[ 1 ] = new Carro( "Honda", "SOM_CARRO", 2006, 20 );
                veiculos[ 2 ] = new Carro( "UFPA", "SOM_CARRO", 2007, 50 );
                veiculos[ 3 ] = new Foguete( "NASA", "SOM_FOGUETE!!", 2022, 2000 );
                veiculos[ 4 ] = new Foguete( "Fiat", "SOM_FOGUETE!!", 2022, 8000 );
                // ------------------------------------------------------------
                
                cout << "\n===================================";
                cout << "\n====== Teste de Velocidade ========";
                cout << "\n==================================";
                
                for ( size_t i = 0; i < veiculos.size( ); i++ ) 
                {
                    Carro *derivedPtr = dynamic_cast< Carro * >( veiculos[ i ] );

                    if ( derivedPtr != nullptr ) 
                    {
                        cout << "\n\n========= CARRO " << veiculos[ i ]->getModelo( ) << " ==========\n";

                        // Repete metodo ACELERAR() ate que o veiculo ultrapasse dada posicao
                        while ( derivedPtr->getPosicao( ).getX( ) < 30 && derivedPtr->getPropelente( ) > 1 )
                        {
                            derivedPtr->acelerar( );
                            cout << "\nPosicao atual: " << derivedPtr->getPosicao( ).getX( ); 
                        }
                        
                        cout << "\n\nTempo Final: " << derivedPtr->getTempo( );
                        
                        if ( derivedPtr->getPropelente( ) < 1 ) 
                            cout << "\n\nO propelente do carro terminou!";
                        
                        if ( derivedPtr->getPosicao( ).getX( ) < 30 )
                            cout << "\n\nO Carro nao foi rapido o suficiente! Tempo esgotado.";
                        else
                            cout << "\n\nParabens! O Carro completou o teste antes do tempo limite.";
                    }
                }
                cout << "\n\n--------------------------------";
                for ( size_t j = 0; j < veiculos.size(); j++ ) 
                {
                    cout << "\n\nDeletando objeto de classe "
                        << typeid( *veiculos[ j ] ).name( ) << "...";

                    delete veiculos[ j ];
                }
                break;
            } 

            case 2:
            {
                // ----------------- EXEMPLO DE ENTRADAS ------------------ 
                veiculos[ 0 ] = new Carro( "Fiat", "SOM_CARRO!!", 2022, 50 );
                veiculos[ 1 ] = new Carro( "Honda", "SOM_CARRO", 2006, 20 );
                veiculos[ 2 ] = new Carro( "UFPA", "SOM_CARRO", 2007, 50 );
                veiculos[ 3 ] = new Foguete( "NASA", "SOM_FOGUETE!!", 2022, 2000 );
                veiculos[ 4 ] = new Foguete( "Voyager", "SOM_FOGUETE!!", 2022, 8000 );
                // ------------------------------------------------------------

                cout << "\n===================================";
                cout << "\n======== Teste de Altura ==========";
                cout << "\n===================================";

                for ( size_t i = 0; i < veiculos.size( ); i++ )
                {
                    Foguete *derivedPtr = dynamic_cast< Foguete * >( veiculos[ i ] );

                    if ( derivedPtr != nullptr ) 
                    {
                        cout << "\n\n======= FOGUETE " << derivedPtr->getModelo( ) << " =========";
                        
                        // Repete metodo ACELERAR() ate que o veiculo ultrapasse dada posicao
                        while ( derivedPtr->getPropelente( ) > 500 )
                        {
                            derivedPtr->acelerar( );
                            cout << "\nPosicao: " << derivedPtr->getPosicao( ).getY( ) << "km";
                        }
                        cout << "\n\nTempo Final: " << derivedPtr->getTempo( );
                        cout << "\n[Status -> " << derivedPtr->getAlturaStatus( ) << "]";
                    }
                }

                cout << "\n\n--------------------------------";
                for ( size_t j = 0; j < veiculos.size(); j++ ) 
                {
                    cout << "\n\nDeletando objeto de classe "
                        << typeid( *veiculos[ j ] ).name( ) << "...";

                    delete veiculos[ j ];
                }
                break;
            }
            case 3:
            {
                // ----------------- EXEMPLO DE ENTRADAS ------------------ 
                corposCelestes[ 0 ] = new Planeta( "Terra", 24, 1 );
                corposCelestes[ 1 ] = new Planeta( "Jupiter", 10, 12 );
                corposCelestes[ 2 ] = new Planeta( "Netuno", 16, 165 );
                corposCelestes[ 3 ] = new Estrela( "Sol", 5780, 1.9e30, 6.9e5 );
                corposCelestes[ 4 ] = new Estrela( "Vega", 9602, 4.2e30, 1.6e6 );
                // --------------------------------------------------------


                cout << "\n===================================";
                cout << "\n====== Classificar Estrelas =======";
                cout << "\n===================================";
                
                for ( size_t i = 0; i < corposCelestes.size( ); i++ )
                {
                    Estrela *derivedPtr = dynamic_cast< Estrela * >( corposCelestes[ i ] );

                    if ( derivedPtr != nullptr ) 
                    {
                        cout << "\n\n======= ESTRELA " << derivedPtr->getNome( ) << " =========";
                        derivedPtr->classificarEstrela( );
                    }
                }

                cout << "\n\n--------------------------------";
                for ( size_t j = 0; j < corposCelestes.size(); j++ ) 
                {
                    cout << "\n\nDeletando objeto de classe "
                        << typeid( *corposCelestes[ j ] ).name( ) << "...";

                    delete corposCelestes[ j ];
                }
                break;
            }
        }
        cin.get();
        cin.get();
    }
}