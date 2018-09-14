#include <iostream>
#include <cmath>
#include <armadillo>
//#include <libplayerc++/playerc++.h>//cabezeras player
//#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"
//#define pi 3.14159


using namespace std;
using namespace arma;
//using namespace PlayerCc; //LIbreria para player

//PlayerClient reybot("localhost"); // forma de declarar conexion al bot y su name.
//RangerProxy rp(&reybot,0); //usar ranger
//Position2dProxy pp(&reybot,0); //usar position2d


class sensa
{
public:

	void sensar()
	{
	//reybot.Read();
//	long double x = pp.GetXPos();
//	long double y = pp.GetYPos();
//	long double a = pp.GetYaw();
	//cout << ":hola" << endl;
	}
};

class planea
{
private:
	mat at,h,xt,yt;
	//actua oa;
public:

	 mat A,B,C,D,E;
	 static mat F;
	// mat at,yt,xt,desp;
	long double xi=0.0,xf=0.0,yx=0.0,s=0.0,th=0.0,x=1.0,raiz=0.0,sumth=0.0;
    long double smraiz=0.0,tiempo=5.0,y=0.0,yi=0.0;
	int i=0;
	//int n=1,grado=0,pot=0,tama=0;
	string polinomio;

	void planear()
	{

	for (int p=0;p<=2;p++)
	{

		if(p==0)
		{
			xi=3;
			x=1;
			y = -1+2*x;
			yi = -1+2*xi;
		}

		if(p==1)
		{
			xi=8;
			x=3;
			yi = (6.95)-(.74375)*xi+(.03125)*pow(xi,2);
			y = (6.95)-(.74375)*x+(.03125)*pow(x,2);
		}

		if(p==2)
		{
			xi=1;
			x=8;
			yi = 1.214988-(0.188919*xi)-(0.023642*pow(xi,2))-(0.002849*pow(xi,3))+(0.000369*pow(xi,4))+(0.000046*pow(xi,5))+(0.000006*pow(xi,6))+(0.000001*pow(xi,7));
			y = 1.214988-(0.188919*x)-(0.023642*pow(x,2))-(0.002849*pow(x,3))+(0.000369*pow(x,4))+(0.000046*pow(x,5))+(0.000006*pow(x,6))+(0.000001*pow(x,7));
		}

    		s = (pow((xi-x),2.0))+(pow((yi-y),2.0));
    		raiz = sqrt(s);

    		th = (atan(((yi-y)/(xi-x))))-sumth;
      		sumth = th;
      		//y=yi;

	    	i+=1;

    		//cout << raiz << ", " << th << " ," << i << " ," << tiempo << endl;
    		A << raiz << th << i << tiempo << endr;
   		    //F << th << i << tiempo <<endr;
      		//C << xi << y << th << i << endr; 
      		C = join_cols(C,A);
      
  			x +=1;
  
      		tiempo+=5;

    if(p==0)
    	B = A;
  

    if(p==1)
    	D = A;

    if(p==2)
    	E = A;

	

	//regresion();

	F = regresion();

	//imprimir();

}

	int n=0,xs=1,ys=0,grado=2,pot=0,tama=0;

	//mat at,yt,xt;

mat regresion()
{
	//int n=1,x=0,y=0,grado=0,pot=0,tama=0;
	//string polinomio;

	//mat A,at,yt,xt,desp;

	 //mat at(2,2);
	 //mat yt(2,1);
//mat xt(2,1);

	 //xs=1;
	 //ys=0;
	 //n=0;
	// grado=1;

	tama=grado+1;
		xt(0,0)=n+1;
//////////////////////////////// Acomodo de matriz A /////////////////////////////////
		for(int f=1;f<tama;f++)
		{
			pot+=1;
			for(int i=0;i<=n;i++)
			{
				xt(f,0)+=pow((B(i,xs)),pot);
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
					xt(f,c)+=pow(B(i,xs),pot);
				}
			}
		}
///////////////////////////////// Acomodo de matriz y ////////////////////////////////
		pot = 0;

		for(int i=0;i<=n;i++)
				yt(0,0)+=B(i,ys);

		for(int f=1;f<tama;f++)
		{
			pot=f;
			for(int i=0;i<=n;i++)
			{
				yt(f,0)+=pow(B(i,xs),pot)*B(i,ys);
			}
		}
/////////////////////////////// Obtencion de coeficientes /////////////////////////////
		at = inv(xt)*yt;

		//for(int i=0;i<tama;i++)
			//desp(i,0) = (at(i,0))*i;

		//for(int i=0;i<=grado+1;i++)
			//polinomio += to_string(at(i,0));
return at;
}

//mat h(1,1);

 planea() // Constructor
    : h(2, 2),xt(5,5),yt(5,1),at(5,1) { // Default matrix member variable initialization
    }



void imprimir()
{

	h(0,0)=2;
	cout << h;
}

};

//int planea::a = 0;

 //mat planea::C=0;

class actua
{
		//sensa os;
	//planea op;
	//actua oa;

	//op.planear();

public:
//int a;
//static int b;

	//long double u,w;
	 void actuar()
	 {
	 	//planea op;
	 	//op.planear();
		// planea op;
	 	
	 	
	
	 	//a = planea::a;
	 	cout << planea::F << endl;
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

int main()
{
	sensa os;
	planea op;
	actua oa;

	//for(;;)
//	{
		os.sensar();
		op.planear();
		oa.actuar();


	//}
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
