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
//RangerProxy rp1(&reybot1,0); //usar ranger
Position2dProxy pp1(&reybot1,0); //usar position2d


class sensado
{
public:

/////////////////////////////////////////////////// Variables utilizadas para ajustar sensores izq,derecha y frontal para cada robot /////////////////////////////////////////////////////////////
static double sr,sl,sf;

void obstaculo()
{
        //////////////////////////////////////////////////////Lectura de sensores para cada robot ///////////////////////////////////////////////////////////////////////////////
        //  reybot1.Read();

        sl = 0;
        sr = 0;
        sf = 0;

/////////////////////////////////////////////////////////////////////// Robot 1 (asignacion de sensores) //////////////////////////////////////////////////////////////////

        sl = pp1.GetXPos();
        sr = pp1.GetYPos();
        sf = pp1.GetYaw();

}

};

double sensado::sl, sensado::sr, sensado::sf;

int main()
{
        mat x(1,3);
        double yaw;
        double xm=5.0,ym=7.0;
        double deltax=0.0,deltay=0.0;
        sensado angulo;

        //   ftok to generate unique key
        key_t key = ftok("shmfile",65);

        //      shmget returns an identifier in shmid
        int shmid = shmget(key,1024,0666|IPC_CREAT);

        while(1)
        {
                reybot1.Read();
                usleep(150);
                double *str = (double*) shmat(shmid,(void*)0,0);
                angulo.obstaculo();
///////////////////////////////////////////Convertir radianes a grados para mejor visualizacion del angulo///////////////////////////////////////////////////////
                yaw = sensado::sf*(180/3.14159);
/////////////////////////////////////////////////// Sacar las diferenciales de x y y.////////////////////////////////////////////////////////////////////////////////////////
                deltax = xm - sensado::sl;
                deltay = ym - sensado::sr;
////////////////////////////////////////////////// Asignacion del arreglo a mandar por memoria compartida ///////////////////////////////////////////////////////
                str[0] = deltax;
                str[1] =deltay;

                cout << "Posicion X: "<< sensado::sl << ", Posicion Y: " << sensado::sr << ", Angulo: " << yaw << endl;
                shmdt(str);
        }

        return 0;
}
