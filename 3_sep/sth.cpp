#include <iostream>
#include <armadillo>
#include <cmath>

using namespace std;
using namespace arma;

int main()
{
	mat A,B;
	double s(0.0),th(0.0),x(10.0),y(1.0),raiz(0.0);
	double yi(1.28);
	int i=0;

   for(float xi=10.14;xi<=45;xi+=0.14)
    {
    	s = (pow((xi-x),2.0))+(pow((yi-y),2.0));
    	raiz = sqrt(s);
    	th = atan((yi-y)/(xi-x));

    	i+=1;

    	cout << raiz << ", " << th << " ," << i << endl;
    	A << raiz << th << i <<endr;

    	B = join_cols(B,A);

  		x +=0.14;
  		y +=0.28; 
  		yi +=0.28;

  		//cout << xi << endl;


    }

    //B.print("Matriz Salida: ");
    B.save("test.txt", arma_ascii);

	return 0;
} 
