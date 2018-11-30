#include <iostream>
#include <armadillo>
#include <string>
#include "perceptron_multidimension.hpp" //Cabecera personal para el perceptron.
#include <unistd.h>


using namespace std;
using namespace arma;

int main() {
        mat x(1,5),w;
        mat y(3,1);
        int capa;
        string datos;
/////////////////////////////////////////////////////////// Capas a calcular /////////////////////////////////////////////////////////////////////////////////////////
capa = 3;
////////////////////////////////////////////////////////// Ciclo for para mandar tablas distintas a la funcion perceptron ///////////////////////////////////////////////////
        while(1)
        {
        for(int i=1; i<=capa; i++)
        {
            //    neurona neuro;
                x.zeros();
///////////////////////////////////////////////////////// Carga de las distintas tablas a utilizar ////////////////////////////////////////////////////////////////////////////////

              //  datos = "x.txt";
            //    datos += to_string(i);
          //      datos += ".txt";
          usleep(50000);
            x.load("x.txt",arma_ascii);
            w.zeros();
                //usleep(400000);
                //x.load("x.txt");

                if (i==1)
                {
                w << 1.00111 <<  0.000608056 << -0.000712082 << -0.00171895 << 0.9996 << -0.00227172 << endr;
                y(0,0) = neuroput(dot(trans(w),x));
                 }

                if(i==2)
                {
                w << 0.000866331 << 0.998967 << -0.000358203 << 0.998886 << 0.0000474476 << 0.000844847 << endr;
                  y(1,0) = neuroput(dot(trans(w),x));
              }

                if(i==3)
                {
                w << 0.00222414 << -0.00000641742 << 0.99925 << 0.000154229 << -0.000227977 << 0.998672 << endr;
                  y(2,0) = neuroput(dot(trans(w),x));



                  cout << "Compensar derecha: " << y(0,0) << " Compensar izquierda: " << y(1,0) << " No compensar: " << y(2,0) << endl;
                  y.save("actuar.txt",arma_ascii);

              }
/////////////////////////////////////////////// Mandar matriz tabla a funcion perceptron ///////////////////////////////////////////////////////////////////////////////////

}


}

        return 0;
}
