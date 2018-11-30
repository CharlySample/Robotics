// Compilacion dada por g++ actuar.cpp -o actuar -larmadillo -lreflapack -lrefblas `pkg-config --cflags playerc++` `pkg-config --libs playerc++`
#include <iostream>
#include <armadillo>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cmath>
#include <stdio.h>
#include <unistd.h>
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"
#include <libplayerc++/playerc++.h>//cabezeras player

using namespace std;
using namespace arma;
using namespace PlayerCc; //LIbreria para player
#define pi 3.14159

////////////////////////////////////////////////////////Robot 1 (CONFIGURACION) /////////////////////////////////////////////////////////////////
PlayerClient reybot1("localhost",6665); // forma de declarar conexion al bot y su name.
Position2dProxy pp1(&reybot1,0); //usar position2d

class actuador
{
private:
double v=0.0,w=0.0;
public:
void avanzar(float t)
{
        reybot1.Read();
        v = 0.0, w = 0.0;

            v = (1/4)+((1/2)*t)-((pow(t,2))/(-8));
            w = -((pow(t,2))/(8))+((pow(t,3))/(16));

        ////////////////////////////////////////////////////////// Robot 1 (Actuacion) ////////////////////////////////////////////////////////////////////

                usleep(5);
		if(t <=10)
                    pp1.SetSpeed(v,w);
		else
			pp1.SetSpeed(0,0);
                cout << "Velocidad tangencial: " << v << " Velocidad angular: " << w <<  endl;
}
};

int main()
{
        actuador act;
   
        for (float t=0;t<=10;t+=0.01)
        {                   
                act.avanzar(t);
        }
        return 0;
}
