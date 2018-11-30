#include <iostream>
#include <armadillo>
#include <cmath>
//#include "carlos.hpp"
#include "perceptron.hpp"

using namespace std;
using namespace arma;

/*class neurona {
private:

float alfa=2;
double y=0.0,y0=0.0;
int n=0,p=1,a=0,b=0,iter=0;

public:
mat w;

  void perceptron (mat tabla)
  {
    n=tabla.n_rows;
    mat x(3,1),saly(n,1),saly0(n,1);

    while(alfa <= 0 or alfa > 1)
    {
            cout << "factor de aprendizaje: ";
            cin >> alfa;
    }
              system("clear");
              cout << "Please Wait ..." << endl;

    while(a==0)
    {
           iter++;
            b=0;
            w.zeros(),saly.zeros(),saly0.zeros();
            y=0.0;
            y0=0.0;

            w = randn(1,3);

            for(int h=0; h<n; h++)
            {
                    y0 = tabla(h,4);

                    for(int i=0; i<=2; i++)
                    {
                            x(i,0) = tabla(h,p);
                            p++;
                    }
                    p=1;

                    y = sign(dot(w,x));

                    w = w + ((alfa*(y0-y))*trans(x));

            }

            for(int h=0; h<n; h++)
            {
                    y0 = tabla(h,4);

                    for(int i=0; i<=2; i++)
                    {
                            x(i,0) = tabla(h,p);
                            p++;
                    }

                    p=1;

                    y = neuroput(dot(trans(w),x));
                    saly(h,0) = y;
                    saly0(h,0) = y0;

                    if(y0 != y)
                    {
                      b = 1;
                      h = n;
                    }

                    if(h+1 == n and b == 0)
                            a = 1;

            }

    }
system("clear");
    for(int i=0;i<n;i++)
    cout << "Referencia: " << saly0(i,0) << "\tEvaluacion: " << saly(i,0) <<endl;

    cout << endl << "Iteracciones realizadas para el aprendizaje: " <<iter << endl;

    cout << "\nVector de pesos resultante:\n" << "w0: " << w(0,0) << "\nw1: " << w(0,1) << "\nw2: " << w(0,2) << endl;



  }

};*/

int main() {
  mat tabla;
  neurona neuro;

        tabla.load("tabla.txt");

        neuro.perceptron(tabla);

        return 0;
}
