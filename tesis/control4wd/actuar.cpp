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
    double desp=0.0, ang=0.0, v=0.0, w=0.0, r=0.15, b=1.0, alfa=0.25, beta=0.65, e=0.001, a=2.0, vmax=1.5;
    int p=0;
    mat u,uref,phi,phi1,u1,k,kinv,phi0,u0;
public:
    static double error;
void avanzar()
{
    reybot1.Read();

    if(p==0)
    {  
        k << r/4 << r/4 << r/4 << r/4 << endr
          << ((r*b)/2*(pow(a,2)+pow(b,2))) << ((r*b)/2*(pow(a,2)+pow(b,2))) << ((-r*b)/2*(pow(a,2)+pow(b,2))) << ((-r*b)/2*(pow(a,2)+pow(b,2))) << endr
          << (b*r)/(vmax) << (-b*r)/(vmax) << (-b*r)/(vmax) << (b*r)/(vmax) << endr
          << (-a*r)/(vmax) << (a*r)/(vmax) << (-a*r)/(vmax) << (a*r)/(vmax) << endr;

        kinv = inv(k);

        uref << 25 << endr << (3*pi)/(4) << endr << 1 << endr << 0.5 << endr;

        u << 0 << endr << 0 << endr << 0 << endr << 0 << endr;

        phi << 0 << endr << 0 << endr << 0 << endr << 0 << endr;
    }

    error = sqrt(pow(uref(0,0)-(u(0,0)),2) + pow(uref(1,0)-(u(1,0)),2));

    phi1.zeros();
    u1.zeros();
    u0.zeros();
    phi0.zeros();

    u0 = u;
    phi1 = (phi + alfa*(kinv * (uref - u0)));
    phi0 = phi;
    u1 = (u + beta*(k *(phi1 - phi0)));

    u = u1, phi = phi1;

    v = u(0,0) - desp;
    w = u(1,0) - ang;                    
    desp = u(0,0);
    ang = u(1,0);

    pp1.SetSpeed(v,w);
    cout << "Velocidad tangencial: " << v << " Velocidad angular: " << w <<  endl;
    usleep(1200000); 
    p++;
}
};

double actuador::error;

int main()
{
        actuador act;
        int p;
        act.error=300.0;

        while(act.error >= 0.001)
        {
                act.avanzar();
                
        }
        return 0;
}
