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
Position2dProxy pp1(&reybot1,0); //usar position2d

class actuador
{
private:
  mat x;
public:
void avanzar()
{
    usleep(33);
    x.load("vel.txt",arma_ascii);

        ////////////////////////////////////////////////////////// Robot 1 (Actuacion) ////////////////////////////////////////////////////////////////////
        pp1.SetSpeed(0.3,x(0,0));
        cout << "Velocidad tangencial: 0.3" << " Velocidad angular: " << x(0,0) << endl;

}
};

int main()
{
        actuador act;

        while(1)
        {
          usleep(63456);
                act.avanzar();
        }

        return 0;
}
