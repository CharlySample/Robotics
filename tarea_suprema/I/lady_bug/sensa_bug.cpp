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
static double sr,sl,sf;

void obstaculo()
{
        //////////////////////////////////////////////////////Lectura de sensores para cada robot ///////////////////////////////////////////////////////////////////////////////
      //  reybot1.Read();

        sl = 0;
        sr = 0;
        sf = 0;

/////////////////////////////////////////////////////////////////////// Robot 1 (asignacion de sensores) //////////////////////////////////////////////////////////////////

        sl = rp1[0];
        sr = rp1[1];
        sf = rp1[2];

}

};

double sensado::sl, sensado::sr, sensado::sf;

int main()
{
        mat x(1,3);
        double yaw;
        double d=0.0;
        double alfa=0.0,th=0.0,q=0.0;
        double jerk=0.0;
        sensado angulo;

        // ftok to generate unique key
        key_t key = ftok("shmfile",65);

        // shmget returns an identifier in shmid
        int shmid = shmget(key,1024,0666|IPC_CREAT);

        while(1)
        {
                reybot1.Read();
            double *str = (double*) shmat(shmid,(void*)0,0);
                angulo.obstaculo();

                yaw = pp1.GetYaw()*(180/3.14159);
                d = (sensado::sl+sensado::sr+sensado::sf)/3;
                th = 0.5 - d;

                if(sensado::sr < 0.76)
                {

                        if(sensado::sl > sensado::sr and sensado::sl > sensado::sf and sensado::sr > .3)
                                alfa = 0.3;
                        else if (sensado::sl < sensado::sr and sensado::sl < sensado::sf and sensado::sr > .3)
                                alfa = -0.3;
                        else if (sensado::sr < .3)
                                alfa = -0.3;
                        else if (sensado::sl == 0.5 and sensado::sr == 0.5 and sensado::sf == 0.5 and th == 0)
                                alfa = 0;
                        else if (sensado::sl == sensado::sr and sensado::sl == sensado::sf and th != 0)
                                alfa = 0.2;
                        else if (sensado::sf < sensado::sl and sensado::sf < sensado::sr)
                                alfa = -0.6;
                }

                else if(sensado::sr > 0.76 and sensado::sr < 0.90 and (sensado::sl+.2 > sensado::sr and sensado::sl+.2 > sensado::sf))
                {
                        alfa = 0.3;
                }
                else
                        alfa=0;

                      *str = alfa;

                cout << "s1: "<<sensado::sl << ", s2: " << sensado::sr << ", s3: " << sensado::sf << " angulo: " << yaw << endl;
  shmdt(str);
        }

        return 0;
}
