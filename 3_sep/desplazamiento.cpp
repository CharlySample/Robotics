#include <iostream>
#include <armadillo>
#include <cmath>

using namespace std;
using namespace arma;

int main()
{
	mat A,B,C,D;
	double yx(0.0),s(0.0),th(0.0),x(10.0),y(0.0),raiz(0.0),sumth(0.0);
	double yi(0.0);
  double smraiz(0.0);
	int i=0;

  y=-1.3111+8.0031*x-7.3864*pow(x,2)+2.6028*pow(x,3)-.2819*pow(x,4);
  yi=-1.3111+8.0031*(x+14)-7.3864*pow(x+.14,2)+2.6028*pow(x+.14,3)-.2819*pow(x+.14,4);

  cout << yx << endl;

   for(float xi=10.14;xi<=45;xi+=0.14)
    {
    	s = (pow((xi-x),2.0))+(pow((yi-y),2.0));
    	raiz = sqrt(s);
      //smraiz = raiz;
    	th = atan((yi-y)/(xi-x))-sumth;
      sumth = th;
      y=yi;
      yi=-1.3111+8.0031*xi-7.3864*pow(xi,2)+2.6028*pow(xi,3)-.2819*pow(xi,4);

    	i+=1;

    	cout << raiz << ", " << th << " ," << i << endl;
    	A << raiz << th << i <<endr;
      C << x + 0.14<< y << th << i << endr; 

    	B = join_cols(B,A);
      D = join_cols(D,C);

  		x +=0.14;
  		//y +=0.28; 
  		//yi +=0.28;

  		//cout << xi << endl;


    }

    //B.print("Matriz Salida: ");
    B.save("testdesplazamiento.txt", arma_ascii); // desplazamiento angulo.
    D.save("xydesplazamiento.txt", arma_ascii); //x y theta i

	return 0;
} 