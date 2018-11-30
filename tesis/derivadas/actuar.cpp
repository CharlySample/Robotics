// Compilacion dada por g++ actuar.cpp -o actuar -larmadillo -lreflapack -lrefblas `pkg-config --cflags playerc++` `pkg-config --libs playerc++`
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
int R=10,Rm=100;
double normx=0.0, v=0.0,w=0.0;
public:
static mat objx,objy,x;
void avanzar()
{
        reybot1.Read();
        mat normo(12,1),velx(13,1),vely(13,1),velt(13,1),angt(13,1),gan(12,1);
        double vy, vx,gan3;
        v = 0.0, w = 0.0,vx =0.0, vy=0.0,gan3=0.0;
        velx.zeros(),vely.zeros(),normo.zeros(),velt.zeros(),angt.zeros(),gan.zeros();

        if(x(0,0) < 0 and x(1,0) > 0)
                gan3 = 3;
        else if(x(0,0) < 0 and x(1,0) < 0  )
                gan3 = -3;
        else
                gan3 = 0.0;

        for(int i=0;i<=12;i++)
        {
            if(i<=11)
            {
                normo(i,0) = sqrt(pow(objx(i,0),2) + pow(objy(i,0),2));
                if(normo(i,0)!=0)
                {
                    velx(i,0) = (((15*exp(-(normo(i,0))/(R)))/(R*-normo(i,0)) ) * objx(i,0));
                    vely(i,0) = (((15*exp(-(normo(i,0))/(R)))/(R*-normo(i,0)) ) * objy(i,0));

                    if(objx(i,0) < 0 and objy(i,0) > 0)
                    {   
                        if(i<=5)
                            gan(i,0) =-3;
                        else
                            gan(i,0) = 3;
                    }
                    else if(objx(i,0) < 0 and objy(i,0) < 0  )
                    {
                        if(i>=6)
                            gan(i,0) = 3;
                        else
                            gan(i,0) = -3;
                    }
                    else
                    {
                        gan(i,0) = 0.0;
                    }

                    angt(i,0) = 0.025*((atan((vely(i,0))/(velx(i,0))))+gan(i,0));
                    //angt(i,0) = 0.1*(-(vely(i,0)/(pow(velx(i,0),2)+pow(vely(i,0),2))) + (velx(i,0)/(pow(vely(i,0),2) + pow(velx(i,0),2))));
                }
                velt(i,0) = sqrt(pow(velx(i,0),2)+pow(vely(i,0),2));
            
            }
            else
            {
                normx = sqrt(pow(x(0,0),2) + pow(x(1,0),2));
                velx(i,0) = ((-5*exp((normx)/(Rm)))/(Rm*normx)) * x(0,0);
                vely(i,0) = ((-5*exp((normx)/(Rm)))/(Rm*normx)) * x(1,0);
                velt(i,0) = sqrt(pow(velx(i,0),2)+pow(vely(i,0),2));
                angt(i,0) = (((atan((vely(i,0))/(velx(i,0))))+gan3) - pp1.GetYaw())*0.8;
                //cout << objx << endl << objy << endl << endl << x << endl;
                //cin.get();
                //angt(i,0) = (-(vely(i,0)/(pow(velx(i,0),2)+pow(vely(i,0),2))) + (velx(i,0)/(pow(vely(i,0),2) + pow(velx(i,0),2))));
               //cout << angt(i,0) << endl;
            }

            v += velt(i,0);
            w += angt(i,0);
            vy += vely(i,0);
            vx += velx(i,0);

            //cout << angt << endl;
            

        }
            v *= 2;
            w *= 1;
            //cout << vy << endl << endl << vx << endl;
           // cin.get();
            //w = (- (vy/(pow(vy,2) + pow(vx,2)))*0.01)-pp1.GetYaw();
            //w = atan(vy/vx) - pp1.GetYaw();

        
       //reybot1.Read();

        ////////////////////////////////////////////////////////// Robot 1 (Actuacion) ////////////////////////////////////////////////////////////////////

                usleep(150);
                //cout << velx(0,0) << "\t"<< vely(0,0) << endl;
                if(normx <= 2)
                    pp1.SetSpeed(0,0);
                else
                    pp1.SetSpeed(v,w);
                cout << "Velocidad tangencial: " << v << " Velocidad angular: " << w <<  endl;
}
};

mat actuador::objx(12,1),actuador::objy(12,1),actuador::x(2,1);

int main()
{
        actuador act;
        int p;
        // ftok to generate unique key
        key_t key = ftok("shmfile",66);

        // shmget returns an identifier in shmid
        int shmid = shmget(key,1024,0666|IPC_CREAT);

        while(1)
        {
                double *str = (double*) shmat(shmid,(void*)0,0);
                for(int i=0;i<=11;i++)
                {
                    if(i<=11)
                    {
                        actuador::objx(i,0) = str[i];
                        //actuador::objy(i,0) = str1[i];
                    }
                }
                p=13;
                for(int i=0;i<=11;i++)
                {
                    actuador::objy(i,0) = str[p];
                    p++;
                }

                actuador::x(0,0) = str[12];
                actuador::x(1,0) = str[24];



                act.avanzar();
                shmdt(str);

        }
        return 0;
}
