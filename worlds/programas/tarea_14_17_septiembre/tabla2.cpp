#include <iostream>
#include <armadillo>
#include <cmath>
#define pi 3.14159

using namespace std;
using namespace arma;

int main()
{
	mat A,B,C,D,E,F;
	double yx=0.0,s=0.0,th=0.0,x=3.0,y=0.0,raiz=0.0,sumth=2.094;
	double yi=0.0;
  double smraiz=0.0,tiempo=3.8;
	int i=0;

  y=-.53*pow(x,2)+5.46*x-6.6;
  //yi=100.3506-24.36601*(x+0.14)+1.999574*pow((x+0.14),2)-0.062194*pow((x+0.14),3)+0.00065461*pow((x+0.14),4);

 //gnu cout << yx << endl;


  A << 0 << 1.763965007956 << 0 << 0 << endr;
  B = join_cols(B,A);

   for(float xi=3.1;xi<=8.0;xi+=0.1)
    {
      yi=-.53*pow(xi,2)+5.46*xi-6.6;
    	s = (pow((xi-x),2.0))+(pow((yi-y),2.0));
    	raiz = sqrt(s);
      //smraiz = raiz;

      //rad = ((yi-y)/(xi-x))*(pi/180);
    	th = (atan(((yi-y)/(xi-x))))-sumth;
      sumth = th;
      y=yi;
      //yi=100.3506-24.36601*(xi)+1.999574*pow((xi),2)-0.062194*pow((xi),3)+0.00065461*pow((xi),4);

    	i+=1;

    	cout << raiz << ", " << th << " ," << i << " ," << tiempo << endl;
    	A << raiz << th << i << tiempo << endr;
      //F << th << i << tiempo <<endr;
      //C << x + 0.1<< y << th << i << endr; 

    	B = join_cols(B,A);
      //D = join_cols(D,C);
      //E = join_cols(E,F);
      //sumth = th;
  		x +=0.1;
  		//y +=0.28; 
  		//yi +=0.28;
      tiempo+=.20;

  		//cout << xi << endl;


    }

    //B.print("Matriz Salida: ");
    B.save("tabla2.txt", arma_ascii); // desplazamiento.
   // E.save("angulo.txt", arma_ascii);
 //   D.save("xy.txt", arma_ascii); //x y theta i

	return 0;
} 
