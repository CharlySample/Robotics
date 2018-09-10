#include <iostream>
#include <cmath>
#include <armadillo>
#include <libplayerc++/playerc++.h>//cabezeras player
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"
#define pi 3.14159


using namespace std;
using namespace arma;
using namespace PlayerCc; //LIbreria para player

PlayerClient reybot("localhost"); // forma de declarar conexion al bot y su name.
RangerProxy rp(&reybot,0); //usar ranger
Position2dProxy pp(&reybot,0); //usar position2d

/*class sensado
{
public:

	long double x = pp.GetXPos();
	long double y = pp.GetYPos();
	long double a = pp.GetYaw();
};*/

/*class actuado
{
public:

	long double u,w;
	 
	 void avanzar()
	 {

	 	pp.SetSpeed(u,w);
	 }
	
};*/

int main()
{
	//double i = 0.0;
	int n=0;
	
		//reybot.Read();
		//sensado senso;
		//actuado act;
		//long double sen = senso.a ;//* (180/3.141615);
		long double u=0.0,w=0.0;

		cout << "Grado polinomio?: " << endl;
		cin >> n;

		mat A,B,C,D;

		A.load("angulo.txt",arma_ascii);
		B.load("desplazamiento.txt",arma_ascii);

		//for(int m=0;m<=n;m++)
		//	C(0,m) = pow(i,m); 

		//C(0,0)= 3; 

		//for(int m=0;m<=nlm++)
		//	D(0,m) = pow(i,m);

		//int s;

		/*for(float i=0.0; i<=37.5; i+=0.15)
		{	
			if(s==0)
			D << 0 << endr;
			else
			D << pow(i,s) << endr;

			C = join_cols(C,D);
		}*/

 		
 		for(float i=0.0; i<=50; i+=0.10)
 		{
 			reybot.Read();
 			//for(int m=0;m<=n;m++)
				//C(0,m)= pow(i,m); 

			//for(int m=0;m<=n;m++)
				//D(0,m)= pow(i,m);
			//m+=1;

			C << 0 << endr
			  << pow(i,0) << endr
			  << pow(i,1) << endr
			  << pow(i,2) << endr
			  << pow(i,3) << endr
			  << pow(i,4) << endr
			  << pow(i,5) << endr
			  << pow(i,6) << endr
			  << pow(i,7) << endr
			  << pow(i,8) << endr
			  << pow(i,9) << endr
			  << pow(i,10) << endr
			  << pow(i,11) << endr
			  << pow(i,12) << endr
			 << pow(i,13) << endr
			  << pow(i,14) << endr;
			 // << pow(i,15) << endr
			  //<< pow(i,16) << endr
			 // << pow(i,17) << endr
			 // << pow(i,18) << endr
			 // << pow(i,19) << endr
			  //<< pow(i,20) << endr
			  //<< pow(i,21) << endr
			  //<< pow(i,22) << endr
			  //<< pow(i,23) << endr
			  //<< pow(i,24) << endr
			  //<< pow(i,25) << endr
			  //<< pow(i,26) << endr
			  //<< pow(i,27) << endr
			  //<< pow(i,28) << endr
			 // << pow(i,29) << endr;


 			//reybot.Read();

  			u += dot(trans(B),C);
 			w = dot(trans(A),C);
 			pp.SetSpeed((u),w);
 			//u=0.0;
 			//w=0.0;
			//act.avanzar();
 		

 // writes the the robot the desired position and velocity

		cout.precision(4);
   		cout << fixed << " (" << pp.GetXPos() << " , " << pp.GetYPos() << ")\tyaw: " << pp.GetYaw() << "\t" << i << endl;
   		//cout << fixed << "\tSonar left : " << s << "\tSonar right : " << s1 << "\tSonar Front : " << sf << endl;
	}
	return 0;
}
