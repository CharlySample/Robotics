#include <iostream>
#include <armadillo>
#include <cmath>

using namespace std;
using namespace arma;

class fann
{
private:
  mat datos;
public:

  void data(mat tabla,int capas)
  {
      int neuro_salidas=0;
      int dimensiones=0;

      neuro_salidas = sqrt(capas);
      dimensiones = tabla.n_cols - neuro_salidas;
      cout << dimensiones << endl;

  }
};
