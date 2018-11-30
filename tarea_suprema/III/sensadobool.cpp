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
        int z,zz,zzz,zzzz,zzzzz,zzzzzz;

        while(1)
        {

                angulo.obstaculo();

                usleep(100000);

                z=0;
                zz=0;
                zzz=0;
                zzzz=0;
                zzzzz=0;
                zzzzzz=0;

		if(sensado::sr<sensado::sl)
                 z=1;
                else if(sensado::sr>sensado::sl)
                 zz=1;
                else if(sensado::sr==sensado::sl)
                 zzz=1;

                 if(sensado::yaw*(180/pi)>0)
                 zzzz=1;
                else if(sensado::yaw*(180/pi)<0)
                 zzzzz=1;
                else if(sensado::yaw*(180/pi)==0)
                 zzzzzz=1;

                cout << "Left: " << sensado::sl << " Right: " << sensado::sr << " Yaw: " << sensado::yaw*(180/pi)<< " " << zzzz << " " << zzzzz << " " << zzzzzz << endl;
                x <<  z << zz << zzz << zzzz << zzzzz << zzzzzz << endr;
                x.save("x.txt",arma_ascii);

        }

        return 0;
}
