#include <iostream>
#include <armadillo>
#include <cmath>

using namespace std;
using namespace arma;

class regresion
{
public:

	int n,x,y;

	double Ex=0.0,Ey=0.0,Exy=0.0,Ex2y=0.0,Ex3y=0.0,Ex2=0.0,Ex3=0.0,Ex4=0.0,Ex5=0.0,Ex6=0.0;
    double Ex7=0.0,Ex8=0.0,Ex4y=0.0;

	mat A,at,xt,yt;

	void tabla()
	{
		for(int i=0;i<=n;i++)
		{
			Ex+=A(i,x);
			Ey+=A(i,y);
			Exy+=A(i,x)*A(i,y);
			Ex2+=pow(A(i,x),2);
			Ex3+=pow(A(i,x),3);
			Ex4+=pow(A(i,x),4);
			Ex5+=pow(A(i,x),5);
			Ex6+=pow(A(i,x),6);
			Ex7+=pow(A(i,x),7);
			Ex8+=pow(A(i,x),8);
			Ex2y+=pow(A(i,x),2)*A(i,y);
			Ex3y+=pow(A(i,x),3)*A(i,y);
			Ex4y+=pow(A(i,x),4)*A(i,y);

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
	
	void regresion_cuarta()
	{
		xt << n+1 << Ex << Ex2 << Ex3 << Ex4 << endr
		   << Ex << Ex2 << Ex3 << Ex4 << Ex5 << endr
		   << Ex2 << Ex3 << Ex4 << Ex5 << Ex6 << endr
		   << Ex3 << Ex4 << Ex5 << Ex6 << Ex7 << endr
		   << Ex4 << Ex5 << Ex6 << Ex7 << Ex8 << endr;

		yt << Ey << endr
		   << Exy << endr
		   << Ex2y << endr
		   << Ex3y << endr
		   << Ex4y << endr;

		at = inv(xt)*yt;


	}
};

int main()
{
	regresion valores;
	mat A;
	int n;
	string datos;

	/*A << 10 << 1 << endr
	  << 12 << 2 << endr
	  << 15 << 8 << endr
	  << 30 << 20 << endr
	  << 45 << 70 << endr;*/

	cout << "\nNombre del archivo de datos a leer: ";
	getline(cin,datos);

   A.load(datos, arma_ascii);

    cout << "\nIntroduce Numero n: ";
    cin >> valores.n;
    cout << "\nIntroduce columna de x: ";
    cin >> valores.x;
    cout << "\nIntroduce columna de y: ";
    cin >> valores.y;
    valores.A = A;

    valores.tabla();

    cout << "\nlista de grados de regresion:\n1.- Lineal\n2.-Cuadrada\n3.-Cubica\n4.-Cuarta\n";
    cout << "Que grado de regresion desea?: ";
    cin >> n;

    if(n==1)
    	valores.regresion_lineal();
    else if (n==2)
    	valores.regresion_cuadrada();
    else if (n==3)
    	valores.regresion_cubica();
    else
    	valores.regresion_cuarta();

    cout << "\n\n" <<valores.Ex << "\t" << valores.Ex2 << "\t" << valores.Ex3 << "\t" << valores.Ex4 << "\t" << valores.Ex5 << " " << valores.Ex6 << endl;
    cout << valores.Ey << "\t" << valores.Exy << "\t" << valores.Ex2y << "\t" << valores.Ex3y << "\t" << endl;

    //valores.regresion_cuarta();

    valores.xt.print("\n matriz xt: ");

    valores.yt.print("\n matriz yt: ");

    valores.at.print("\n matriz at: ");

    //valores.at.save("regresion.txt", arma_ascii);

	return 0;
}