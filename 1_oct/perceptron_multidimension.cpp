#include <iostream>
#include <armadillo>
#include <string>
#include "perceptron_multidimension.hpp" //Cabecera personal para el perceptron.

using namespace std;
using namespace arma;

int main() {
        mat tabla,w,tabla1,tabla2;
        int capa;
        double a,b,c;
        string datos;
/////////////////////////////////////////////////////////// Capas a calcular /////////////////////////////////////////////////////////////////////////////////////////
        //cout << "Introduce cantidad de capas del perceptron:  ";
        //cin >> capa;
        capa = 2;
////////////////////////////////////////////////////////// Ciclo for para mandar tablas distintas a la funcion perceptron ///////////////////////////////////////////////////
        for(int i=1; i<=capa; i++)
        {
                neurona neuro;
                tabla.zeros();
///////////////////////////////////////////////////////// Carga de las distintas tablas a utilizar ////////////////////////////////////////////////////////////////////////////////
                //datos = "capa";
                //datos += to_string(i);
                //datos += ".txt";

                tabla1.load("ya.txt");
                tabla2.load("yb.txt");
                tabla.load("yayb.txt");
                //w << -0.712082 << 1.05915 << endr;
/////////////////////////////////////////////// Mandar matriz tabla a funcion perceptron //////////////////////////////////////////////////////////////////////////////////////
              //  neuro.perceptron(tabla);
              if(capa == 1)
                a = neuro.perceptron(tabla1);
                if(capa == 2)
                b = neuro.perceptron(tabla2);

          //      cout << a << endl << b << endl;

        //        neuro.percep(tabla,w);

                cout << "\n\n";

        }

  cout << a << endl << b << endl;

        return 0;
}
