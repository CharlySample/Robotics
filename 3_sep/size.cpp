#include <iostream>
#include <armadillo>
#include <cmath>

using namespace std;
using namespace arma;

int main()
{
	
	mat A(2,2);
	A(0,0)=22;
	
	for(int i=1;i<1+1;i++)
    A.print("\n matriz at: ");

    //valores.a.save("regresion.txt", arma_ascii);

	return 0;
}