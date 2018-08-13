//Primer programa de clase Robotica 13/Agosto/2018

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main ()
{
  //intruccion
  cout << "Suma de numeros" << endl;
  // Funcion para realizar el resultados.
  for (int i=-10; i<10; i++)
      cout << i << endl;

  // Declarar archivo y abrir para guardar.
  ofstream fp("file.txt");

  // Funcion para la realizacion de operaciones matematicas con cmath.
  for (float  x=0.0; x<20.0; x+=0.005)
      {
        fp << x << ", " << sqrt(x) << ", " << pow(x,2.0) << ", " << exp(x) << endl;
      }
  // Guardar archivo.
  fp.close();

return 0;
}
