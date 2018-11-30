#include <iostream>
#include <armadillo>
#include <string>
#include "perceptron_multidimension.hpp" //Cabecera personal para el perceptron.

using namespace std;
using namespace arma;

int main() {
        mat tabla;
        int capa;
        string datos;
/////////////////////////////////////////////////////////// Capas a calcular /////////////////////////////////////////////////////////////////////////////////////////
        cout << "Introduce cantidad de capas del perceptron:  ";
        cin >> capa;
////////////////////////////////////////////////////////// Ciclo for para mandar tablas distintas a la funcion perceptron ///////////////////////////////////////////////////
        for(int i=1; i<=capa; i++)
        {
                neurona neuro;
                tabla.zeros();
///////////////////////////////////////////////////////// Carga de las distintas tablas a utilizar ////////////////////////////////////////////////////////////////////////////////
                //datos = "capa";
                //datos += to_string(i);
                //datos += ".txt";

                tabla.load("ejer3.txt");
/////////////////////////////////////////////// Mandar matriz tabla a funcion perceptron //////////////////////////////////////////////////////////////////////////////////////
                neuro.perceptron(tabla);

                cout << "\n\n";

        }



        return 0;
}
