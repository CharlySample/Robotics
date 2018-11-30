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

int main()
{
while(1)
{
	int n=0; 
	float i=0.0, p=0.0;
 			reybot.Read();
i+=0.1;
p+=0.1;
 			pp.SetSpeed((-0.5*cos(i)+0.5),(0.2*sin(p))+0.2);

 // writes the the robot the desired position and velocity

		cout.precision(4);
   		cout << fixed << " (" << pp.GetXPos() << " , " << pp.GetYPos() << ")\tyaw: " << pp.GetYaw() << endl;
   		//cout << fixed << "\tSonar left : " << s << "\tSonar right : " << s1 << "\tSonar Front : " << sf << endl;
}
	return 0;
}
