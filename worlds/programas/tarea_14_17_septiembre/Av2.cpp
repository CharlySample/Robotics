#include <iostream>
#include <cmath>
#include <armadillo>
#include <sstream>
#include <string>
#include <unistd.h>
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"
#include <libplayerc++/playerc++.h>//cabezeras player
//#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"
#define pi 3.14159


using namespace std;
using namespace arma;
using namespace PlayerCc; //LIbreria para player

PlayerClient reybot("localhost"); // forma de declarar conexion al bot y su name.
RangerProxy rp(&reybot,0); //usar ranger
Position2dProxy pp(&reybot,0); //usar position2d


class sensa
{
public:

	void sensar()
	{
		reybot.Read();
     	long double x = pp.GetXPos();
     	long double y = pp.GetYPos();
	    long double a = pp.GetYaw();
	    cout.precision(4);
   		cout << fixed << " (" << x << " , " << y << ")\tyaw: " << a << "\t" << endl;
   		
	    // cout << "hola" << endl;
	}
};

class planea
{
private:
	mat at,h,xt,yt,bt;
	int n=0,xs=0,ys=0,grado=0,pot=0,tama=0;
	//string polinomio;
	//actua oa;
public:

	 mat A,B,C,D,E;
	 static mat F;
	// mat at,yt,xt,desp;
	int i=0;
	//int n=1,grado=0,pot=0,tama=0;
	static mat u1,w1,u2,w2,u3,w3;

	void planear()
	{
		A.zeros();
		B.zeros();
		C.zeros();
		D.zeros();

		A.load("tabla1.txt", arma_ascii);
		B.load("tabla2.txt", arma_ascii);
		C.load("tabla3.txt", arma_ascii);


		for(i=0;i<=2;i++)
		{
			if(i==0)
			{
				D=A;
				n=19;
				xs=3;
				ys=0;
				grado=2;
				u1 = regresion();
				ys=1;
				w1 = regresion();
			}

			if(i==1)
			{
				D=B;
				n=49;
				xs=3;
				ys=0;
				grado=4;
				u2 = regresion();
				ys=1;
				w2 = regresion();
			}

			if(i==2)
			{
				D=C;
				n=69;
				xs=3;
				ys=0;
				grado=7;
				u3 = regresion();
				ys=1;
				w3 = regresion();
			}

		}


	

	//regresion();

	//yeah = regresion();

	//imprimir();
//usleep(50000);
}

	//n=0,xs=0,ys=0,grado=0,pot=0,tama=0;

	//mat at,yt,xt;

mat regresion()
{
	//int n=1,x=0,y=0,grado=0,pot=0,tama=0;
	//string polinomio;

	//mat A,at,yt,xt,desp;

	 //mat at(2,2);
	 //mat yt(2,1);
//mat xt(2,1);


	 //xs=3;
	 //ys=0;
	 //n=19;
	// grado=1;

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

		/*for(int i=0;i<grado+1;i++)
    	{
    		if(i>=1 and bt(i,0) >= 0)
    			polinomio += "+";

			polinomio += to_string(bt(i,0));
			polinomio += "*pow(i,";
			polinomio += to_string(i);
			polinomio += ")";
		}*/


		//for(int i=0;i<tama;i++)
			//desp(i,0) = (at(i,0))*i;

		//for(int i=0;i<=grado+1;i++)
			//polinomio += to_string(at(i,0));
return bt;
}

//mat h(1,1);

 //planea() // Constructor
 //   : h(2, 2),xt(2,2),yt(2,1),at(2,1) { // Default matrix member variable initialization
//    }

};

//int planea::a = 0;

 //mat planea::C=0;

class actua
{
		//sensa os;
	//planea op;
	//actua oa;

	//op.planear();
//	mat W1,	W2,	W3;
private:
//	float i=0.0;
//	long double u=0.0,w=0.0;

public:
//int a;
//static int b;

	//long double u,w;
	float i=0.0;
	long double u=0.0,w=0.0;
	 void actuar()
	 {
	 	mat W1(3,1),W2(5,1),W3(8,1);
	 	W1.zeros(),W2.zeros(),W3.zeros();
	 	//planea op;
	 	//op.planear();
		// planea op;
	 	
	 	if(i<3.8)
	 	{
		for(  i==0.0;i<=3.8;i+=0.1)
		{
			W1 << 0 << endr
			  << pow(i,0) << endr
			  << pow(i,1) << endr;
			  //<< pow(i,2) << endr
			  //<< pow(i,3) << endr
			  //<< pow(i,4) << endr
			  //<< pow(i,5) << endr
			  //<< pow(i,6) << endr
			  //<< pow(i,7) << endr
			  //<< pow(i,8) << endr
			  //<< pow(i,9) << endr
			  //<< pow(i,10) << endr
			  //<< pow(i,11) << endr
			  //<< pow(i,12) << endr
			 //<< pow(i,13) << endr
			  //<< pow(i,14) << endr;
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

			u = (dot(trans(planea::u1),W1))+0.8;
 			w = dot(trans(planea::w1),W1);
 			pp.SetSpeed(u,w);
 			cout << i << "\t" << w << endl;
 			usleep(180000);

		} 
		}

		pp.SetSpeed(0,0);

				if(i<13.6)
				{
				for(i==3.8;i<=13.6;i+=0.1)
		{
			W2 << 0 << endr
			  << pow(i,0) << endr
			  << pow(i,1) << endr
			  << pow(i,2) << endr
			  << pow(i,3) << endr;
			  //<< pow(i,4) << endr;
			  //<< pow(i,5) << endr
			  //<< pow(i,6) << endr
			  //<< pow(i,7) << endr
			  //<< pow(i,8) << endr
			  //<< pow(i,9) << endr
			  //<< pow(i,10) << endr
			  //<< pow(i,11) << endr
			  //<< pow(i,12) << endr
			 //<< pow(i,13) << endr
			  //<< pow(i,14) << endr;
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

			u += (dot(trans(planea::u2),W2));
 			w = (dot(trans(planea::w2),W2))-.3;
 			pp.SetSpeed(u,w);
 			cout << i << "\t" << u << endl;
 			usleep(80000);

		} 
	}

			if(i<27.4)
			{
			for(i==13.6;i<=27.4;i+=0.1)
		{
			W3 << 0 << endr
			  << pow(i,0) << endr
			  << pow(i,1) << endr
			  << pow(i,2) << endr
			  << pow(i,3) << endr
			  << pow(i,4) << endr
			  << pow(i,5) << endr
			  << pow(i,6) << endr;
			  //<< pow(i,7) << endr;
			  //<< pow(i,8) << endr
			  //<< pow(i,9) << endr
			  //<< pow(i,10) << endr
			  //<< pow(i,11) << endr
			  //<< pow(i,12) << endr
			 //<< pow(i,13) << endr
			  //<< pow(i,14) << endr;
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

			u += (dot(trans(planea::u3),W3))*-1;
 			w = (dot(trans(planea::w3),W3))-.15;
 			pp.SetSpeed(u,w);
 			cout << i << "\t" << u << endl;
 			usleep(80000);

		} 

	}

		if(i>=27.4)
			i=0;
	 	//a = planea::a;
	 	//cout << planea::u1 << endl;
	 	//cout << planea::w1 << endl;
	 	//cout << planea::u2 << endl;
	 	//cout << planea::w2 << endl;
	 	//cout << planea::u3 << endl;
	 	//cout << planea::w3 << endl;


	 //	cout << op.C << endl;
	 	//cout << op.E << endl;
	 	//if(planea::a = 5)
	 	//	b=2;

	 	
	 }
	// void avanzar()
	// {

	 //	pp.SetSpeed(u,w);
	// }
	
};

mat planea::F;
mat planea::u1,planea::w1,planea::u2,planea::w2,planea::u3,planea::w3;

int main()
{
	sensa os;
	planea op;
	actua oa;

	for(;;)
	{
		os.sensar();
		op.planear();
		oa.actuar();


	}
		//reybot.Read();
		//sensado senso;
		//actuado act;
		//long double sen = senso.a ;//* (180/3.141615);

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

 		
 	
	return 0;
}
