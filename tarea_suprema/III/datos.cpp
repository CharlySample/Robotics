#include <iostream>
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"
#include <libplayerc++/playerc++.h>//cabezeras player
#include <unistd.h>
#include <armadillo>
#define pi 3.14159


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
static double sl,sr,yaw;

void obstaculo()
{
  //////////////////////////////////////////////////////Lectura de sensores para cada robot ///////////////////////////////////////////////////////////////////////////////
        reybot1.Read();

        sl = 0;
        sr = 0;
        yaw = pp1.GetYaw();
      //  s3 = 0;
      //  s4 =0;
      //  s5 = 0;
    //    s6 =0;

/////////////////////////////////////////////////////////////////////// Robot 1 (asignacion de sensores) //////////////////////////////////////////////////////////////////
        for(int i=0; i<=2; i++)
                sl += rp1[i];
        sl = sl/3;
        for(int i=3; i<=5; i++)
                sr += rp1[i];
        sr = sr/3;

//s1 = rp1[0];
//s2 = rp1[1];
//s3 = rp1[2];
//s4 = rp1[3];
//s5 = rp1[4];
//s6 = rp1[5];


        //cout << sl << ", " << sr << endl;
}

};

double sensado::sl,sensado::sr,sensado::yaw;

int main()
{
        mat x(1,3);
        sensado angulo;

        while(1)
        {

                angulo.obstaculo();

                usleep(500000);
              //   if(pp1.GetYaw() != sensado::yaw)
                cout  << sensado::sl  << sensado::sr << sensado::yaw*(180/pi) << endl;
                //x <<  sensado::sr << sensado::sl << sensado::yaw*(180/pi) << endr;
                //x.save("centro.txt",arma_ascii);

        }

        return 0;
}
