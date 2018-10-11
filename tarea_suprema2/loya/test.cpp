#include <iostream>
#include <armadillo>
#include "datafann.h"

using namespace std;
using namespace arma;

int main() {
        fann generar;
        mat dummy,tabla,y1,y2,muerta(800,1);
        int uno[] ={-1,1},muestras,capas,k;
        string gen[]={"21","22","23","24","91","92","93","94","a1","a2","a3","a4","u1","u2","u3","u4"};

        muestras = sizeof(gen)/sizeof(gen[0])-1;

        for(int i=0; i<=muestras; i++)
        {
                dummy.zeros();
                muerta.zeros();
                dummy.load(gen[i]);

               
               
                        for(int h=0; h<=799; h++)
                                muerta(h,0) = dummy((h*3),0)*1/255;
               

                tabla = join_cols(tabla,trans(muerta));
                gen[i]+=".txt";
                muerta.save(gen[i],raw_ascii);
        }

        for(int p=0; p<=1; p++)
        {
                for (int i=1; i<=8; i++)
                {
                        dummy << uno[p] << endr;
                        y1 = join_cols(y1,dummy);
                }
        }

        for(int pp=1; pp<=2; pp++)
        {
                for(int p=0; p<=1; p++)
                {
                        for (int i=1; i<=4; i++)
                        {
                                dummy << uno[p] << endr;
                                y2 = join_cols(y2,dummy);
                        }
                }
        }

        tabla = join_rows(tabla,y1);
        tabla = join_rows(tabla,y2);

        cout << "\nIntroduce numero de capas: ";
        cin >> capas;

        generar.data(tabla, capas);


        return 0;
}
