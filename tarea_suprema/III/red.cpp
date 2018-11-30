#include <iostream>
#include <armadillo>
#include <string>
#include "perceptron_multidimension.hpp" //Cabecera personal para el perceptron.
#include <unistd.h>


using namespace std;
using namespace arma;

int main() {
        mat x(1,3),w;
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
                w << 0.543903 << -0.759926 << 0.414679 << endr;
                y(0,0) = neuroput(dot(trans(w),x));
                 }

                if(i==2)
                {
                w <<  -0.520628 << 1.07445 << -1.70968 << endr;
                  y(1,0) = neuroput(dot(trans(w),x));
              }

                if(i==3)
                {
                w << -0.569658 << 1.05896 << 0.0493002 << endr;
                  y(2,0) = neuroput(dot(trans(w),x));



                  cout << "Compensar derecha: " << y(0,0) << " Compensar izquierda: " << y(1,0) << " No compensar: " << y(2,0) << endl;
                  y.save("actuar.txt",arma_ascii);

              }
/////////////////////////////////////////////// Mandar matriz tabla a funcion perceptron ///////////////////////////////////////////////////////////////////////////////////

}


}

        return 0;
}
