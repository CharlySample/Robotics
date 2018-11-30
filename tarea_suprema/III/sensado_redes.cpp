#include <iostream>
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"
#include <libplayerc++/playerc++.h>//cabezeras player

using namespace std;
using namespace PlayerCc; //LIbreria para player

////////////////////////////////////////////////////////Robot 1 (CONFIGURACION) /////////////////////////////////////////////////////////////////
PlayerClient reybot1("localhost",6665); // forma de declarar conexion al bot y su name.
RangerProxy rp1(&reybot1,0); //usar ranger
Position2dProxy pp1(&reybot1,0); //usar position2d

class sensado
{
public:

/////////////////////////////////////////////////// Variables utilizadas para ajustar sensores izq,derecha y frontal para cada robot /////////////////////////////////////////////////////////////
static double sr,sl;

void obstaculo()
{
  //////////////////////////////////////////////////////Lectura de sensores para cada robot ///////////////////////////////////////////////////////////////////////////////
        reybot1.Read();

        sl = 0;
        sr = 0;

/////////////////////////////////////////////////////////////////////// Robot 1 (asignacion de sensores) //////////////////////////////////////////////////////////////////
        for(int i=0; i<=2; i++)
                sl += rp1[i];
        sl = sl/3;
        for(int i=3; i<=5; i++)
                sr += rp1[i];
        sr = sr/3;

        cout << sl << ", " << sr << endl;
}

};

double sensado::sl, sensado::sr;

class planear {

public:

static double ang;


double  esquivar ()
{
        ang = 0.0;

/////////////////////////////////// Robot 1 esquivar ////////////////////////////////////////////////////////////////////////////
    /*    if(sensado::sl < 4.5 and (sensado::sr > 2))
                ang = -0.5;
        else if(sensado::sr < 4.5 and (sensado::sl > 2))
                ang = 0.5;
        else if(sensado::sf < 4.5 and (sensado::sl < sensado::sr))
                ang = -0.5;
        else if(sensado::sf < 4.5 and (sensado::sr < sensado::sl))
                ang = 0.5;
        else if(sensado::sf < 4.5 and sensado::sr > 3 and sensado::sl > 3)
                ang = 0.5;
        else
                ang = 0.00;*/

        return ang;
}
};

double planear::ang;


class actuador
{
public:
void avanzar()
{
        ////////////////////////////////////////////////////////// Robot 1 (Actuacion) ////////////////////////////////////////////////////////////////////
        pp1.SetSpeed(0.3*(planear::ang+.5),planear::ang);

}
};

int main()
{
        sensado angulo;
        planear plan;
        actuador act;

        while(1)
        {
                angulo.obstaculo();
          //      plan.esquivar();
            //    act.avanzar();
        }
        return 0;
}
