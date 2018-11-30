#include <iostream>
#include <libplayerc++/playerc++.h>//cabezeras player
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"

using namespace std;
using namespace PlayerCc; //LIbreria para player

PlayerClient reybot("localhost",6666); // forma de declarar conexion al bot y su name.
RangerProxy rp(&reybot,0); //usar ranger
Position2dProxy pp(&reybot,0); //usar position2d

class sensado
{
public:

	double x = pp.GetXPos();
	double y = pp.GetYPos();
	double a = pp.GetYaw();
};

class actuado
{
public:

	double px,py,pa;
	 
	 void avanzar()
	 {

	 	player_pose2d_t pos;
 		pos.px = px; //x position in meters
 		pos.py = py; //y position in meters
 		pos.pa = pa; // angle of the robot in radians
 		// the desired velocity in x, y and the angle of the robot
 		player_pose2d_t vel;
 		vel.px = 0.0; //x desired position in meters
 		vel.py = 0.0; //y desired position in meters
 		vel.pa = 0.0; //angle desired in radians

	 	pp.GoTo(pos, vel);
	 }
	
};

int main()
{
	int i = 0;
	while(1)
	{
		reybot.Read();
		sensado senso;
		actuado act;
		double sen = senso.a * (180/3.141615);

 		act.avanzar();

 		if(i==0)
 		{
 			act.px = 3.0;
 			act.py = 0.0;
 			//act.pa = 0.0 * (3.141615/180); // conversion grados a radianes
 			if(senso.x>2.98 and senso.x < 3.0001)
 			i++;
 		}

 		if(i==1)
 		{
 			act.px = 3.0;
 			act.py = 3.0;
 			//act.pa = 90.0 * (3.141615/180); // conversion grados a radianes
 			if(senso.y > 2.98 and senso.y < 3.0001)
 			i++;
 		}

 		if(i==2)
 		{
 			act.px = 0.0;
 			act.py = 3.0;
 			//act.pa = 180.0 * (3.141615/180); // conversion grados a radianes
 			if(senso.x > -0.9999 and senso.x < 0.2000)
 			i++;
 		}

 		if(i==3)
 		{
 			act.px = 0.0;
 			act.py = 0.0; 
 			//act.pa = 270.0 * (3.141615/180); // conversion grados a radianes
 			if(senso.y > -0.9999 and senso.y < 0.2000)
 			i=0;
 		}

 // writes the the robot the desired position and velocity

		cout.precision(4);
   		cout << fixed << " (" << senso.x << " , " << senso.y << ")\tyaw: " << sen << "\t" << i << endl;
   		//cout << fixed << "\tSonar left : " << s << "\tSonar right : " << s1 << "\tSonar Front : " << sf << endl;
	}
	return 0;
}
