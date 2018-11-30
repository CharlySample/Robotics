#include <iostream>
#include <armadillo>
#include <cmath>
#include <unistd.h>
#include "carlos.hpp"

using namespace std;
using namespace arma;

int main() {
        mat tabla,w,x(3,1);
        float alfa=2;
        double y=0.0,y0=0.0;
        int n=0,p=1,a=0,b=0,iter=0;

        while(alfa <= 0 or alfa > 1)
        {
                cout << "factor de aprendizaje: ";
                cin >> alfa;
        }

        tabla.load("tabla.txt");
        n = tabla.n_rows;

        while(a==0)
        {
               iter++;
                b=0;
                w.zeros();
                y=0.0;
                y0=0.0;

                w = randn(1,3);
                //tabla.load("tabla.txt");
                //n = tabla.n_rows;

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

                system("clear");

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

                        if(y0 != y)
                        {
                          b = 1;
                          h = n;
                        }
                                //b = 1;

                        cout << "Referencia: " << y0 << "\tEvaluacion: " << y <<endl;
                        //usleep(500000);

                        if(h+1 == n and b == 0)
                                a = 1;

                }

        }

        cout << endl << "Iteracciones realizadas para el aprendizaje: " <<iter << endl;

        cout << "\nVector de pesos resultante:\n" << "w0: " << w(0,0) << "\nw1: " << w(0,1) << "\nw2: " << w(0,2) << endl;

        return 0;
}
