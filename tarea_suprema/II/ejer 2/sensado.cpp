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
RangerProxy rp1(&reybot1,0); //usar ranger
Position2dProxy pp1(&reybot1,0); //usar position2d


class sensado
{
public:

/////////////////////////////////////////////////// Variables utilizadas para ajustar sensores izq,derecha y frontal para cada robot /////////////////////////////////////////////////////////////
static double sxi,syi,sxd,syd,ob1x,ob1y,ob2x,ob2y;
static double dd,di;

void obstaculo()
{
        //////////////////////////////////////////////////////Lectura de sensores ///////////////////////////////////////////////////////////////////////////////
        //  reybot1.Read();

        sxi = 0.0, syi = 0.0,sxd = 0.0,syd =0.0, dd = 0.0, di=0.0,ob1x=0.0,ob1y=0.0,ob2x=0.0,ob2y=0.0;

/////////////////////////////////////////////////////////////////////// Robot 1 (asignacion de sensores) //////////////////////////////////////////////////////////////////

        di = rp1[0]+rp1[1]+rp1[2];
        dd = rp1[3]+rp1[4]+rp1[5];
        dd = dd/3;
        di = di/3;

        if(di < 2)
        {
                sxi = di*cos(90);
                syi = di*sin(90);
                ob1x = 2*cos(90);
                ob1y = 2*sin(90);
        }
        else
        {
                sxi = 0;
                syi =0;
                ob1x = 0;
                ob1y = 0;
        }
        if(dd < 2)
        {
                sxd = dd*cos(-90);
                syd = dd*sin(-90);
                ob2x = 2*cos(-90);
                ob2y = 2*sin(-90);
        }
        else
        {
                sxd = 0;
                syd =0;
                ob2x = 0;
                ob2y = 0;
        }
}
};

double sensado::di,sensado::dd,sensado::sxi, sensado::syi, sensado::sxd,sensado::syd,sensado::ob1x,sensado::ob1y,sensado::ob2x,sensado::ob2y;

int main()
{
        mat x(1,3);
        double yaw;
        double deltax1=0.0,deltay1=0.0,deltax2=0.0,deltay2=0.0;
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

                yaw = pp1.GetYaw()*(180/3.14159);

//////////////////////////////////////////////////////////////Obstaculo derecha //////////////////////////////////////////////////////////////
                deltax1 = sensado::ob1x - sensado::sxi;
                deltay1 = sensado::ob1y - sensado::syi;

//////////////////////////////////////////////////////////////Obstaculo izquierda ////////////////////////////////////////////////////////////
                deltax2 = sensado::ob2x - sensado::sxd;
                deltay2 = sensado::ob2y - sensado::syd;

               str[0] = deltax1;
                str[1] =deltay1;
                str[2] = deltax2;
                str[3] = deltay2;

                cout << "Sensor derecha: "<< sensado::dd << ", Sensor izquierda: " << sensado::di << ", Angulo: " << yaw << endl;
                shmdt(str);
        }

        return 0;
}
