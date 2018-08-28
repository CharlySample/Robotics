#include <iostream>
#include <cmath>
// LIbreria para guardar en un file mis datos.
#include <fstream>

using namespace std;

//Clase por una funcion.
class interpolacion
{
	int x;
public:
	interpolacion(int y) { x = y;}
	int interp() {return pow(x,3) + 1;}
	
};

int main()
{
	int x[4] = {1,2,3,4}, y[4] = {2,9,28,65};

	cout << "i\t" << "xi\t" << "yi\t" << "y(x)" << endl;

	// Declarar objeto archivo y abrir para guardar.
	ofstream fp("/home/carlos/Documents/Universidad/Robotica/programas/programa3/dat.txt");

	for (int i=0;i<4;i++)
	{
		interpolacion valor(x[i]);
		fp << i << ", \t" << x[i] << ", \t" << y[i] << ", \t"<< valor.interp() << endl;
		cout << i << ", \t" << x[i] << ", \t" << y[i] << ", \t"<< valor.interp() << endl;
	}

	fp.close();

	return 0;
}
