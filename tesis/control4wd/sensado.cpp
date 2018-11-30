// La compilacion esta dada por g++ sensado.cpp -o sensado -larmadillo -lreflapack -lrefblas `pkg-config --cflags playerc++` `pkg-config --libs playerc++`

#include <iostream>
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"
#include <libplayerc++/playerc++.h>//cabezeras player
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <armadillo>

using namespace std;
using namespace arma;
using namespace PlayerCc; //LIbreria para player

////////////////////////////////////////////////////////Robot 1 (CONFIGURACION) /////////////////////////////////////////////////////////////////
PlayerClient reybot1("localhost",6665); // forma de declarar conexion al bot y su name.
Position2dProxy pp1(&reybot1,0); //usar position2d


class sensado
{
private:
public:
static double x, y,xx;
void obstaculo()
{
        //////////////////////////////////////////////////////Lectura de odometros ///////////////////////////////////////////////////////////////////////////////

        xx = pp1.GetXPos();
        y = pp1.GetYPos();
}
};

double sensado::y,sensado::xx;

int main()
{
        double yaw;
        sensado angulo;

        while(1)
        {
                reybot1.Read();
                usleep(150);

                angulo.obstaculo();

                yaw = pp1.GetYaw()*(180/3.14159);

                cout << "Posicion X: "<< sensado::xx << ", Posicion Y: " << sensado::y << ", Angulo: " << yaw << endl;
        }

        return 0;
}