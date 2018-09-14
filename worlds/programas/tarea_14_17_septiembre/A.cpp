#include <iostream>
#include <cmath>
#include <armadillo>
#include <sstream>
#include <string>
#include <unistd.h>
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"
#include <libplayerc++/playerc++.h>//cabezeras player
#define pi 3.14159


using namespace std;
using namespace arma;
using namespace PlayerCc; //LIbreria para player

PlayerClient reybot("localhost"); // forma de declarar conexion al bot y su name.
RangerProxy rp(&reybot,0); //usar ranger
Position2dProxy pp(&reybot,0); //usar position2d

////////////////////////////// Clase de sensado /////////////////////////////////////
class sensa
{
	public:

		void sensar()
		{	
//////////////////////////// Captura e impresion de odometros ////////////////////////
			reybot.Read();
     		long double x = pp.GetXPos();
     		long double y = pp.GetYPos();
	    	long double a = pp.GetYaw();
	    	cout.precision(4);
   			cout << fixed << " (" << x << " , " << y << ")\tyaw: " << a << "\t" << endl;
		}	
};

/////////////////////////// Clase de planeacion /////////////////////////////////////////
class planea
{
	private:
		mat at,h,xt,yt,bt;
		int n=0,xs=0,ys=0,grado=0,pot=0,tama=0,i=0;
	public:

		mat A,B,C,D,E;
	 	static mat F;
		static mat u1,w1,u2,w2,u3,w3;
///////////////////////// Funcion principal de planear dentro de clase planeacion ///////////////////////////
		void planear()
		{
			A.zeros();
			B.zeros();
			C.zeros();
			D.zeros();

			A.load("tabla1.txt", arma_ascii);
			B.load("tabla2.txt", arma_ascii);
			C.load("tabla3.txt", arma_ascii);

///////////////////////////////////// Ciclos for para el ajuste de curvas ///////////////////////////////////
				for(i=0;i<=2;i++)
				{
					if(i==0)
					{
						D=A;
						n=20;
						xs=3;
						ys=0;
						grado=1;
						u1 = regresion();
						ys=1;
						w1 = regresion();
					}

					if(i==1)
					{
						D=B;
						n=50;
						xs=3;
						ys=0;
						grado=2;
						u2 = regresion();
						ys=1;
						w2 = regresion();
					}

					if(i==2)
					{
						D=C;
						n=70;
						xs=3;
						ys=0;
						grado=7;
						u3 = regresion();
						ys=1;
						w3 = regresion();
					}

			}
			usleep(50000);
		}

///////////////////////////////// Funcion para realizar regresiones de cualquie grado.//////////////////////////////////
		mat regresion()
		{
			tama=grado+1;
			mat xt(tama,tama),yt(tama,1),at(tama,1),bt(tama,1);
			xt.zeros(),yt.zeros(),at.zeros(),bt.zeros();

			xt(0,0)=n+1;
//////////////////////////////// Acomodo de matriz A /////////////////////////////////
			for(int f=1;f<tama;f++)
			{
				pot+=1;
				for(int i=0;i<=n;i++)
				{
					xt(f,0)+=pow((D(i,xs)),pot);
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
						xt(f,c)+=pow(D(i,xs),pot);
					}
				}
			}
///////////////////////////////// Acomodo de matriz y ////////////////////////////////
			pot = 0;
			for(int i=0;i<=n;i++)
				yt(0,0)+=D(i,ys);

			for(int f=1;f<tama;f++)
			{
				pot=f;
				for(int i=0;i<=n;i++)
				{
					yt(f,0)+=pow(D(i,xs),pot)*D(i,ys);
				}
			}
/////////////////////////////// Obtencion de coeficientes /////////////////////////////
			at = inv(xt)*yt;

			for(int i=0;i<tama;i++)
				bt(i,0) = (at(i,0))*i;

return bt;
		}
};

//////////////////////////////////// Clase de actuado ////////////////////////////////////////////
class actua
{
	private:

	public:

		float i=0.0;
		long double u=0.0,w=0.0;
////////////////////////////////// Funcion principal de actuar dentro de la clase de actuado ////////////////////////////////////////
	 	void actuar()
	 	{
	 		mat W1(3,1),W2(5,1),W3(8,1);
	 		W1.zeros(),W2.zeros(),W3.zeros();
	 	
	 	///////////////////////////// Serie de Ifs para la seleccion de trayectoria /////////////////////////////////////
	 		if(i<3.8)
	 		{
				for(  i==0.0;i<=3.8;i+=0.2)
				{
					W1 << 0 << endr
			  	       << pow(i,0) << endr;
			  
					u += (dot(trans(planea::u1),W1));
 					w = dot(trans(planea::w1),W1);
 					pp.SetSpeed(u,w);
 					cout << i << "\t" << w << endl;
 					usleep(200000);

				} 
			}

			pp.SetSpeed(0,0);

			if(i<13.2)
			{
				for(i==3.8;i<=13.6;i+=0.1)
			{
				W2 << 0 << endr
			       << pow(i,0) << endr
       			   << pow(i,1) << endr;

				u += (dot(trans(planea::u2),W2));
 				w = (dot(trans(planea::w2),W2))-.31;
 				pp.SetSpeed(u,w);
 				cout << i << "\t" << u << endl;
 				usleep(100000);

		} 
	}

			if(i<27.4)
			{
				for(i==13.6;i<=25;i+=0.1)
				{
					W3 << 0 << endr
			       	   << pow(i,0) << endr
			           << pow(i,1) << endr
			           << pow(i,2) << endr
			           << pow(i,3) << endr
			           << pow(i,4) << endr
			           << pow(i,5) << endr
			           << pow(i,6) << endr;

						u += (dot(trans(planea::u3),W3));
 				        w = (dot(trans(planea::w3),W3));
 						pp.SetSpeed(u,w);
 						cout << i << "\t" << u << endl;
 					    usleep(50000);

				} 

			}

			if(i>=27.4)
			i=0;
	 	
	 }
	
};

mat planea::F;
mat planea::u1,planea::w1,planea::u2,planea::w2,planea::u3,planea::w3;

int main()
{
//////////////////////////////////Declaracion de objetos///////////////////////////////////////////
	sensa os;
	planea op;
	actua oa;

///////////////////////////////// Ciclo for infinito para ejecutar ciclo sin fin. ///////////////////////////////////////
	for(;;)
	{
		os.sensar();
		op.planear();
		oa.actuar();


	}
 	
	return 0;
}