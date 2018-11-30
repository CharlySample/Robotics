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
mat xi;
int R=7;
public:
static mat x;
double veltt=0.0,velt=0.0,angt=0.0,norm=0.0,gan = 0.0,vely =0.1,velx =0.1,deltax=0.0,deltay=0.0;
void avanzar()
{
        deltax=x(0,0);
        deltay=x(1,0);
        norm = sqrt(pow(deltax,2) + pow(deltay,2));
/////////////////////////////////////////////////////////// Ganancia para cambiar el angulo //////////////////////////////////////////////////////////////////////
        if(deltax < 0 and deltay > 0)
                gan = 3;
        else if(deltax < 0 and deltay < 0  )
                gan = -3;
        else
                gan = 0.0;

        ////////////////////////////////////////////////////////// Robot 1 (Actuacion) ////////////////////////////////////////////////////////////////////
        mat vel(2,1);
  //////////////////////////////////////////////////////////////Obtencion del vector velocidad ////////////////////////////////////////////////////////////////
        vel= ( (-0.8*exp((norm)/(R)))/(R*norm) ) * x;

        reybot1.Read();
//////////////////////////////////////////////////////////////// Calculo de velocidad total y angulo//////////////////////////////////////////////////
        velt = sqrt(pow(vel(0,0),2)+pow(vel(1,0),2));
       angt =  (atan((vel(1,0))/(vel(0,0)))+gan)- pp1.GetYaw();

        usleep(150);
        pp1.SetSpeed(velt,angt);

        cout << "Velocidad tangencial: " << velt << " Velocidad angular: " << angt << " Deltax: " << deltax << " Deltay: " << deltay << endl;
}
};

mat actuador::x;

int main()
{
        actuador act;
        double ww;
        double ww1;

        // ftok to generate unique key
        key_t key = ftok("shmfile",65);

        // shmget returns an identifier in shmid
        int shmid = shmget(key,1024,0666|IPC_CREAT);

        while(1)
        {
                double *str = (double*) shmat(shmid,(void*)0,0);

                ww = str[0];
                ww1 = str[1];

                actuador::x << ww << endr << ww1 << endr;

                act.avanzar();
                shmdt(str);

        }
        return 0;
}
