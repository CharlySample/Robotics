#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main(int argc, char const *argv[])
{
	mat A;

	A << 8 << 3 <<endr
          << 6 << 2 <<endr
          << 5 << 1 <<endr
	  << 3 << 1 <<endr
	  << 2 << 2 <<endr
	  << 1 << 1 <<endr;

	A.save("prueba.txt", arma_ascii);


	return 0;
}
