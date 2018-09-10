#include <iostream>
#include <armadillo>
#include <cmath>

using namespace std;
using namespace arma;

class regresion
{
public:

	int n=249,x=0,y=0,grado=0,pot=0,tama=0;

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

		for(int i=0;i<tama;i++)
			desp(i,0) = (at(i,0))*i;


		}
	
};

int main()
{
	regresion valores;
	mat A;
	int n,grado,opcion;
	string datos;

	//cout << "\nNombre del archivo de datos a leer: ";
	//getline(cin,datos);

   A.load("test.txt", arma_ascii);

    //cout << "\nIntroduce Numero n: ";
    //cin >> valores.n;
    cout << "\nIntroduce columna de x: ";
    cin >> valores.x;
    cout << "\nIntroduce columna de y: ";
    cin >> valores.y;
    valores.A = A;
    cout << "\nQue grado de regresion desea?: ";
    cin >> grado;
    cout << "\nQue coeficientes desea obtener?: \n 1.- desplazamiento\n 2.- angulo\n";
    cin >> opcion;

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

    if(opcion==1)
    {
    	valores.desp.print("\n coeficientes de desplazamiento: ");
    	valores.desp.save("/home/carlos/Documents/Universidad/Robotica/programas/worlds/desplazamiento.txt", arma_ascii);
	}

	else
	{
		valores.desp.print("\n coeficientes del angulo: ");
		valores.desp.save("/home/carlos/Documents/Universidad/Robotica/programas/worlds/angulo.txt", arma_ascii);
	}


	return 0;
}