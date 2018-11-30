// La compilacion esta dada por g++ sensado.cpp -o sensado -larmadillo -lreflapack -lrefblas `pkg-config --cflags playerc++` `pkg-config --libs playerc++`

#include <iostream>
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"
#include <libplayerc++/playerc++.h>//cabezeras player
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <armadillo>
#include <fstream>

using namespace std;
using namespace arma;
using namespace PlayerCc; //LIbreria para player

////////////////////////////////////////////////////////Robot 1 (CONFIGURACION) /////////////////////////////////////////////////////////////////
PlayerClient reybot1("localhost",6665); // forma de declarar conexion al bot y su name.
RangerProxy rp1(&reybot1,0); //usar ranger
//RangerProxy rp2(&reybot1,1);
Position2dProxy pp1(&reybot1,0); //usar position2d

ofstream fp("mapeo.txt");

class sensado
{
private:
   // double s[11];
public:
/////////////////////////////////////////////////// Variables utilizadas para ajustar sensores izq,derecha y frontal para cada robot /////////////////////////////////////////////////////////////
static double objx[11],s[11],objy[11],sx[11],sy[11];
static double x, y,xx;
static mat B,C,D;
static mat A;
void obstaculo()
{
   double pos[] = {8,37,70,110,147,172,188,213,250,290,323,352};
   double posi[] = {0,0,0,0,0,0,0,0,0,0,0,0};         
        //////////////////////////////////////////////////////Lectura de sensores ///////////////////////////////////////////////////////////////////////////////

        for(int i=0;i<=11;i++)
            {
                s[i] = rp1[i];
            }



/////////////////////////////////////////////////////////////////////// Robot 1 (asignacion de sensores) //////////////////////////////////////////////////////////////////


/*
                   S4 ---------- S3        
                  S5 -           -
               S6  -              -S2
               S7 -                -S1
                  -                - S2
                 S8 -             - S11
                    S9 ---------- S10

sensor pos(grados)
S1     8
S2     37
S3     70
S4     110
S5     147
S6     172
S7     -172
S8     -147
S9     -110
S10    -70
S11    -37
S12    -8

*/

        xx = pp1.GetXPos();
        y = pp1.GetYPos();

        A.zeros(),B.zeros(),C.zeros(),D.zeros();

        B << cos(90 )<< sin(90) << endr
          << -sin(90) << cos(90) << endr;

        D << 3 + xx << endr
          << 3 + y  << endr;

        for(int i=0;i<=11;i++)
        {
            if(s[i] < 10)
            {
                objx[i] = s[i] * cos(pos[i]);
                objy[i] = s[i] * sin(pos[i]);
                sx[i] = 2 * cos(pos[i]+posi[i]);
                sy[i] = 2 * sin(pos[i]+posi[i]); 
            }
            else
            {
                objx[i] = 0;
                objy[i] = 0;
                sx[i] = 0;
                sy[i] = 0; 
            }       
            C << 0.2*cos(pos[i])+ objx[i] << endr
              << 0.2*sin(pos[i])+ objy[i] << endr;

            A = B*C+D;
            if(objx[i] != 0 and objy[i != 0])
                fp << trans(A) << endl;
        }

        
}
};

double sensado::s[11], sensado::sx[11],sensado::sy[11],sensado::objx[11],sensado::objy[11],sensado::x,sensado::y,sensado::xx;
mat sensado::D,sensado::B,sensado::C,sensado::A;
int main()
{
        double yaw;
        double deltax[12]={0}, deltay[12]={0};
        double xm = 9.0, ym=-20;
       // ofstream fp("mapeo.txt");
        int p;
        sensado angulo;

        //   ftok to generate unique key
      //  key_t key = ftok("shmfile",66);

        //      shmget returns an identifier in shmid
    // int shmid = shmget(key,1024,0666|IPC_CREAT);

        for(int i=1;i<=100;i++)
        {
                reybot1.Read();
                usleep(150);
            //  double *str = (double*) shmat(shmid,(void*)0,0);
                angulo.obstaculo();

                yaw = pp1.GetYaw()*(180/3.14159);

                cout << trans(sensado::A) << endl;

                pp1.SetSpeed(0.3,0);


////////////////////////////////////////////////////////////// Ciclo para obtener deltas //////////////////////////////////////////////////////////////
                /*for(int i=0;i<=11;i++)
                {
                    if(sensado::s[i] < 10)
                    {
                    deltax[i] = sensado::objx[i] - sensado::xx;
                    deltay[i] = sensado::objy[i] - sensado::y;
                    }
                    else
                    {
                        deltax[i] = 0;
                        deltay[i] = 0;
                    }
                }

              deltax[12] = xm - sensado::xx;
              deltay[12] = ym - sensado::y;

                for(int i=0;i<=11;i++)
                    str[i] = deltax[i];
                
                p = 13;
                str[12] = deltax[12];

                for(int i=0;i<=11;i++)
                {
                    str[p] = deltay[i];
                    p++;
                }
                str[24] = deltay[12];*/

               // cout << "Posicion X: "<< sensado::xx << ", Posicion Y: " << sensado::y << ", Angulo: " << yaw << endl;
               // shmdt(str);
        }
        fp.close();

        return 0;
}