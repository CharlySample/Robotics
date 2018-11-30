#include <iostream>
#include <armadillo>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
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
  //double x;
  double xi;
public:
  static double x;
void avanzar()
{


        ////////////////////////////////////////////////////////// Robot 1 (Actuacion) ////////////////////////////////////////////////////////////////////
        if(x!=xi)
        pp1.SetSpeed(0.3,x);
        xi = x;
        cout << "Velocidad tangencial: 0.3" << " Velocidad angular: " << x << endl;

}
};

double actuador::x;

int main()
{
        actuador act;

        // ftok to generate unique key
        key_t key = ftok("shmfile",65);

        // shmget returns an identifier in shmid
        int shmid = shmget(key,1024,0666|IPC_CREAT);

        while(1)
        {

            double *str = (double*) shmat(shmid,(void*)0,0);


           actuador::x = *str;
        //   cout << actuador::x << endl;

                act.avanzar();
                shmdt(str);
        }
//shmctl(shmid,IPC_RMID,NULL);
        return 0;
}
