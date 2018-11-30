#include <iostream>
#include <armadillo>
#include <string>
#include "perceptron_multidimension.hpp" //Cabecera personal para el perceptron.
#include <unistd.h>

using namespace std;
using namespace arma;

int main() {
        mat x(1,3),w,ya,yb,yc,yeah(2,1);
        mat tabla,tabla1,tabla2;
        mat d;
        mat y(2,1);
        int capa;
        string datos;
/////////////////////////////////////////////////////////// Capas a calcular /////////////////////////////////////////////////////////////////////////////////////////
capa = 3;
////////////////////////////////////////////////////////// Ciclo for para mandar tablas distintas a la funcion perceptron ///////////////////////////////////////////////////
      //  while(1)

        for(int i=1; i<=capa; i++)
        {
                neurona neuro;
                tabla.zeros();
///////////////////////////////////////////////////////// Carga de las distintas tablas a utilizar ////////////////////////////////////////////////////////////////////////////////

              //  datos = "x.txt";
            //    datos += to_string(i);
          //      datos += ".txt";
          //usleep(50000);
            tabla.load("yayb.txt");
            tabla1.load("ya.txt");
            tabla2.load("yb.txt");

                //usleep(400000);
                //x.load("x.txt");

                if (i==1)
                {
                w << -0.712082 << 1.05915 << endr;
                ya = neuro.perceptron(tabla1);
                 }

                 if(i==2)
                 {
                   w << 1.01227 << -0.345324 << endr;
                   yb = neuro.perceptron(tabla2);
                 }

                 if(i==3)
                 {
                   w << 1.41395 << 1.11889 << endr;
                   yc = neuro.perceptron(tabla);
                 }

                // if(i==4)
                 //{
                  // w << 1.41395 << 1.11889 << endr;
                  // yeah << 1 << ya(i,0) << yb (i,0) << endr;
                  // cout << dot(w,yeah);
                // }





          //      if(i==2)
          //      {
          //      w << 1.01227 << -0.345324  << endr;
          //        y(1,0) = neuro.yf(tabla2,w);
          //    }

        //        if(i==3)
            //    {
              //    neuro.perceptron(tabla,y);

                  //cout << "Obstaculo derecha: " << y(0,0) << " Obstaculo izquierda: " << y(1,0) << " No obstaculo: " << y(2,0) << endl;
                  //y.save("actuar.txt",arma_ascii);

              //}
/////////////////////////////////////////////// Mandar matriz tabla a funcion perceptron ///////////////////////////////////////////////////////////////////////////////////

}
cout << "Vector Y0: " << endl;
for(int ll=0;ll<=3;ll++)
{

//for(int f=0;f<=3;f++)
//{
w << 1.41395 << 1.11889 << endr;
yeah << ya(ll,0) << yb (ll,0) << endr;
cout << neuroput(dot(w,trans(yeah))) << endl;
//}

}
//w << 1.41395 << 1.11889 << endr;
//cout << dot(w,yeah);

//}

        return 0;
}
