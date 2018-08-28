#include <iostream>
#include <libplayerc++/playerc++.h>//cabezeras player
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"

using namespace std;
using namespace PlayerCc; //LIbreria para player

int main()
{
	PlayerClient reybot("localhost"); // forma de declarar conexion al bot y su name.
	RangerProxy rp(&reybot,0); //usar ranger
	Position2dProxy pp(&reybot,0); //usar position2d

	double x,y,a; //Variables para almacenar posicion.
	double s,s1,sf ;
	double ang;

	while(1)
	{
		s = 0;
		s1 = 0;
		sf = 0;
		reybot.Read(); // leer valores constantemente.
		x = pp.GetXPos();
		y = pp.GetYPos();
		a = pp.GetYaw();
		for(int i=0;i<=2;i++)
			s = rp[i] + s;
		for(int n=5;n<=7;n++)
			s1 = rp[n] + s1;
		for(int m=3;m<=4;m++)
			sf = rp[m] + sf;

		if(s < 3 and s1 > 3)
			ang = s<6 ? -0.80 : -0.20  ;
		else if(s1 < 3 and s > 3)
			ang = s1<6 ? 0.80 : 0.20  ;
		else if(sf < 3 and s > 4 and s1 > 4)
			ang = rp[3]<rp[4] ? -0.80 : 0.80;
		else if(sf < 4 and s < 4 and s1 < 4)
			ang = 0.90;
		else
			ang = 0.00;

		//para cuando tengas que usar coordenadas de un punto a otro podes utilizar el hack vector.

		/*for(int i=0; i<=3; i++)
		s = rp.GetRange(i);*/
		/*for(int n=0; n <=3; n++)
		s1 = rp.GetRange(n);*/
		//rp.RequestConfigure();
		//s = rp.GetMaxAngle();

		pp.SetSpeed(0.2,ang);
		cout.precision(4);
   		cout << fixed << " (" << x << " , " << y << ")\tyaw: " << a;
   		cout << fixed << "\tSonar left : " << s << "\tSonar right : " << s1 << "\tSonar Front : " << sf << endl;
	}
	return 0;
}