#include <iostream>
#include <armadillo>
#include <cmath>
#include <fstream>

using namespace std;
using namespace arma;

class fann
{
private:
mat datos;
public:

void data(mat tabla,int capas)
{
        int neuro_salidas=0,muestras=0,dimensiones=0;
        ofstream fp("carlos.data");

        neuro_salidas = sqrt(capas); // -1 para matricez
        dimensiones = tabla.n_cols - neuro_salidas; // -1 para matricez
        muestras = tabla.n_rows; // -1 para matricez
        mat y(muestras,neuro_salidas);

        for(int i=0; i<=neuro_salidas-1; i++)
        {
                for(int p=0; p<=muestras-1; p++)
                {
                        y(p,i) = tabla(p,dimensiones+i);
                }
        }

        fp << muestras <<" " << dimensiones << " " << neuro_salidas << endl;

        for(int i=0; i<=muestras-1; i++)
        {
                for(int p=0; p<=dimensiones-1; p++)
                        fp << tabla(i,p) << " ";
                fp << endl;
                for(int w=0; w<=neuro_salidas-1; w++)
                        fp << y(i,w) << " ";
                fp << endl;
        }

        fp.close();

}
};
