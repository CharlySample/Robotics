#include <iostream>
#include <cmath>
// LIbreria para guardar en un file mis datos.
#include <fstream>

using namespace std;

//Clase por una funcion.
class interpolacion
{
	long double x;
	long double a = 0.0006546;
	long double b = 0.0621943;
	long double c = 1.9995743;
	long double d = 24.366017;
	long double e = 100.35064;

public:
	interpolacion(long double y) { x = y;}
	long double interp() 
	{

		return (a*pow(x,4)) - (b*pow(x,3)) + (c*pow(x,2)) - (d*x) + e;
	}
	
};

int main()
{
	int x[5] = {10,12,15,30,45}, y[5] = {1,2,8,20,70};

	cout << "i\t" << "xi\t" << "yi\t" << "y(x)" << endl;

	// Declarar objeto archivo y abrir para guardar.
	ofstream fp("/home/carlos/Documents/Universidad/Robotica/programas/tarea2_interpo/dat.txt");

	for (int i=0;i<5;i++)
	{
		interpolacion valor(x[i]);
		fp << i << ", \t" << x[i] << ", \t" << y[i] << ", \t"<< valor.interp() << endl;
		cout << i << ", \t" << x[i] << ", \t" << y[i] << ", \t"<< valor.interp() << endl;
	}

	fp.close();

	return 0;
}