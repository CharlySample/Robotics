#include <iostream>
#include <armadillo>
#include <fstream>
//#define ARMA_USE_LAPACK
//#define ARMA_USE_BLAS
//#define ARMA_DONT_USE_WRAPPER

using namespace std;
using namespace arma;
using namespace lapack;

int main ()
{

	mat A,B,C; //declaracion de la matriz A 2x3

	A << -10 << 4 << -5  << endr
	  << 18 << -2 << -5 << endr;

	for(int i = 63 ; i<= 1500 ; i+=2)
	{
	B << 70 << endr
	  << 70 << endr
	  << i  << endr;

	C = A * B;

	C.print("");
    

    }
	  //A.print("\nMatriz 2x3 original: ");

	//Procedimiento para la transpuesta manual por (izq)

	//mat At = trans(A);
	//mat Amanual = inv((At * A))*At;

	//C = Amanual*B;

	//C.print("Temperaturas manual: ");

	//C = pinv(A)*B;

	//C.print("Temperaturas auto: ");
	
return 0;
}
