#include <iostream>
#include <armadillo>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;
using namespace arma;

class regresion
{
public:

	int n=0,x=0,y=0,grado=0,pot=0,tama=0;
	string polinomio;

	mat A,at,yt,xt,desp;

	void regresiones()
	{
		tama=grado+1;
		xt(0,0)=n+1;
//////////////////////////////// Acomodo de matriz A /////////////////////////////////
		for(int f=1;f<tama;f++)
		{
			pot+=1;
			for(int i=0;i<=n;i++)
			{
				xt(f,0)+=pow((A(i,x)),pot);
			}
		}

		pot=0;

		for(int c=1;c<tama;c++)
		{
			pot=c-1;
			for(int f=0;f<tama;f++)
			{
				pot+=1;
				for(int i=0;i<=n;i++)
				{
					xt(f,c)+=pow(A(i,x),pot);
				}
			}
		}
///////////////////////////////// Acomodo de matriz y ////////////////////////////////
		pot = 0;

		for(int i=0;i<=n;i++)
				yt(0,0)+=A(i,y);

		for(int f=1;f<tama;f++)
		{
			pot=f;
			for(int i=0;i<=n;i++)
			{
				yt(f,0)+=pow(A(i,x),pot)*A(i,y);
			}
		}
/////////////////////////////// Obtencion de coeficientes /////////////////////////////
		at = inv(xt)*yt;

		//for(int i=0;i<tama;i++)
			//desp(i,0) = (at(i,0))*i;

		//for(int i=0;i<=grado+1;i++)
			//polinomio += to_string(at(i,0));


		}

};

int main()
{
	regresion valores;
	mat A;
	int n,grado,opcion;
	string datos;

  //  cout << "Introduzca nombre del arhivo a guardar asi como su extension: " << endl;
//    getline(cin,datos);

   A.load("servo3.txt");

 //   cout << "\nIntroduce Numero n: ";
//    cin >> valores.n;
    valores.n = A.n_rows-1;
    cout << "\nIntroduce columna de x: ";
    cin >> valores.x;
    cout << "\nIntroduce columna de y: ";
    cin >> valores.y;
    valores.A = A;
    cout << "\nQue grado de regresion desea?: ";
    cin >> grado;

    valores.grado=grado;
	mat pasar(grado+1,grado+1);
	mat ypasar(grado+1,1);
	mat despasar(grado+1,1);
	valores.desp = despasar;
	valores.yt = ypasar;
	valores.xt = pasar;

    valores.regresiones();

    valores.xt.print("\n matriz xt: ");

    valores.yt.print("\n matriz yt: ");

   valores.at.print("\n matriz at: ");


  // valores.at.save("test.txt", arma_ascii);

    cout << "\nPolinomio obtenido: ";

////////////////////////////// Ciclo for para imprimir polinomio a obtenido para ingresar en gnuplot /////////////////////////////////
 /*   for(int i=0;i<grado+1;i++)
    {
    		if(i>=1 and valores.at(i,0) >= 0)
    			valores.polinomio += "+";

			valores.polinomio += to_string(valores.at(i,0));
			valores.polinomio += "*x**";
			valores.polinomio += to_string(i);
	}*/

 for(int i=0;i<grado+1;i++)
    {
    		if(i>=1 and valores.at(i,0) > 0)
    			cout << "+" <<valores.at(i,0) << "*x**" << i << ""; 
                      else
			cout << valores.at(i,0) << "*x**" << i << "";
	}



    cout << valores.polinomio << endl;

	return 0;
}
