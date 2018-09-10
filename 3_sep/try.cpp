#include <iostream>
#include <armadillo>
#include <cmath>

using namespace std;
using namespace arma;

int main()
{
	mat A,B,C,D,E,F;
	long double yx=0.0,s=0.0,th=0.0,x=10.0,y=0.0,raiz=0.0,sumth=0.0;
	long double yi=0.0;
  long double smraiz=0.0,tiempo=0.0;
	int i=0;

  y=.0006546*pow(x,4)-0.0621946*pow(x,3)+1.9995743*pow(x,2)-24.366017*x+100.35064;


  cout << y << endl;

	return 0;
} 