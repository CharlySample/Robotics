#include <iostream>
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"
#include <libplayerc++/playerc++.h>//cabezeras player
#include <unistd.h>
#include <armadillo>

using namespace std;
using namespace arma;
using namespace PlayerCc; //LIbreria para player

////////////////////////////////////////////////////////Robot 1 (CONFIGURACION) /////////////////////////////////////////////////////////////////
PlayerClient reybot1("localhost",6665); // forma de declarar conexion al bot y su name.
RangerProxy rp1(&reybot1,0); //usar ranger

class sensado
{
public:

/////////////////////////////////////////////////// Variables utilizadas para ajustar sensores izq,derecha y frontal para cada robot /////////////////////////////////////////////////////////////
static double sr,sl,sf;

void obstaculo()
{
  //////////////////////////////////////////////////////Lectura de sensores para cada robot ///////////////////////////////////////////////////////////////////////////////
        reybot1.Read();

        sl = 0;
        sr = 0;
        sf = 0;

/////////////////////////////////////////////////////////////////////// Robot 1 (asignacion de sensores) //////////////////////////////////////////////////////////////////
for(int i=120; i<=180; i++)
       sl += rp1[i];
sl = sl/60;
for(int i=0; i<=60; i++)
       sr += rp1[i];
sr = sr/60;
for(int i = 60; i<=120; i++)
       sf += rp1[i];
sf = sf/60;

}

};

double sensado::sl, sensado::sr, sensado::sf;

int main()
{
        mat x(1,3);
        sensado angulo;

        while(1)
        {

                angulo.obstaculo();

                usleep(100000);
                cout << "Right: "<<sensado::sr << ", Left: " << sensado::sl << ", Front: " << sensado::sf << endl;
                x <<sensado::sr << sensado::sl << sensado::sf << endr;
                x.save("x.txt",arma_ascii);

        }

        return 0;
}
