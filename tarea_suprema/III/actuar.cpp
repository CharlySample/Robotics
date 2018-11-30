#include <iostream>
#include <armadillo>
#include <unistd.h>
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"
#include <libplayerc++/playerc++.h>//cabezeras player

using namespace std;
using namespace arma;
using namespace PlayerCc; //LIbreria para player

////////////////////////////////////////////////////////Robot 1 (CONFIGURACION) /////////////////////////////////////////////////////////////////
PlayerClient reybot1("localhost",6665); // forma de declarar conexion al bot y su name.
//RangerProxy rp1(&reybot1,0); //usar ranger
Position2dProxy pp1(&reybot1,0); //usar position2d

class actuador
{
private:
  mat x;
public:
void avanzar(mat y)
{
       x << 0.8 << -0.8 << 0 << endr;

        ////////////////////////////////////////////////////////// Robot 1 (Actuacion) ////////////////////////////////////////////////////////////////////
        pp1.SetSpeed(0.3,dot(trans(x),y));

}
};

int main()
{
        actuador act;
        mat y(3,1);

        while(1)
        {
                usleep(23456);

                y.load("actuar.txt",arma_ascii);

                act.avanzar(y);
        }

        return 0;
}
