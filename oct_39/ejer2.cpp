#include <iostream>
#include <armadillo>
#define pi 3.14159

using namespace arma;
using namespace std;

int main()
{
	mat A,B,C;

	double d=0.0;
	double phi = 0.0;
	double x=0.0,y=0.0;

	for(double i=0.0;i<=2*pi;i+=0.1)
	{
		cout << i << endl;
		for(double p=0.35;p<=0.50;p+=0.01)
		{
				x = p*cos(i);
				y = p*sin(i);  
				
				A << x << y << endr;

				B = join_cols(B,A);
			
		}
	}


	B.print("");
	B.save("ejer2.txt",raw_ascii);


	return 0;
}