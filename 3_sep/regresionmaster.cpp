#include <iostream>
#include <armadillo>
#include <cmath>

using namespace std;
using namespace arma;

class regresion
{
public:

	int n;

	double Ex=0.0,Ey=0.0,Exy=0.0,Ex2y=0.0,Ex3y=0.0,Ex2=0.0,Ex3=0.0,Ex4=0.0,Ex5=0.0,Ex6=0.0;

	mat A,at,xt,yt;

	void tabla()
	{
		for(int i=0;i<=n;i++)
		{
			Ex+=A(i,0);
			Ey+=A(i,1);
			Exy+=A(i,0)*A(i,1);
			Ex2+=pow(A(i,0),2);
			Ex3+=pow(A(i,0),3);
			Ex4+=pow(A(i,0),4);
			Ex5+=pow(A(i,0),5);
			Ex6+=pow(A(i,0),6);
			Ex2y+=pow(A(i,0),2)*A(i,1);
			Ex3y+=pow(A(i,0),3)*A(i,1);

		}
	}

		void regresion_lineal()
	{
		xt << n+1 << Ex << endr
		   << Ex << Ex2 << endr;

		yt << Ey << endr
		   << Exy << endr;

		at = inv(xt)*yt;


	}

	void regresion_cuadrada()
	{
		xt << n+1 << Ex << Ex2 << endr
		   << Ex << Ex2 << Ex3 << endr
		   << Ex2 << Ex3 << Ex4 << endr;

		yt << Ey << endr
		   << Exy << endr
		   << Ex2y << endr;

		at = inv(xt)*yt;


	}

	void regresion_cubica()
	{
		xt << n+1 << Ex << Ex2 << Ex3 << endr
		   << Ex << Ex2 << Ex3 << Ex4 << endr
		   << Ex2 << Ex3 << Ex4 << Ex5 << endr
		   << Ex3 << Ex4 << Ex5 << Ex6 <<endr;

		yt << Ey << endr
		   << Exy << endr
		   << Ex2y << endr
		   << Ex3y << endr;

		at = inv(xt)*yt;


	}
	
};

int main()
{
	regresion valores;
	mat A;
	int n;
    //A.load("test.txt", arma_ascii);

	A << 10 << 1 <<endr
	  << 12 << 2 <<endr
	  << 15 << 8 <<endr
	  << 30 << 20 <<endr
	  << 45 << 70 <<endr;

    cout << "Introduce Numero n: " << endl;
    cin >> valores.n;
    valores.A = A;

    valores.tabla();

    cout << "\n" <<valores.Ex << "\t" << valores.Ex2 << "\t" << valores.Ex3 << "\t" << valores.Ex4 << "\t" << valores.Ex5 << " " << valores.Ex6 << endl;
    cout << valores.Ey << "\t" << valores.Exy << "\t" << valores.Ex2y << "\t" << valores.Ex3y << "\t" << endl;

    valores.regresion_lineal();

    valores.xt.print("\n matriz: ");

    valores.yt.print("\n matriz is: ");

    valores.at.print("\n resultado: ");

	return 0;
}