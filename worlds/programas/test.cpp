#include <iostream>
#include <libplayerc++/playerc++.h>//cabezeras player
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"

using namespace std;
using namespace PlayerCc; //LIbreria para player

PlayerClient reybot("localhost",6666); // forma de declarar conexion al bot y su name.
RangerProxy rp(&reybot,0); //usar ranger
Position2dProxy pp(&reybot,0); //usar position2d

class sensado
{
    public:

        double x;
        double y;
        double a;
        static double s,s1,sf;

        void obstaculo()
        {
           x = pp.GetXPos();
           y = pp.GetYPos();
           a = pp.GetYaw();

            s = 0;
            s1 = 0;
            sf = 0;

            for(int i=175;i<=270;i++)
            s += rp[i];
            s = s/95;
            for(int i=0;i<=95;i++)
            s1 += rp[i];
            s1 = s1/95;
            for(int i = 95 ; i<=175;i++)
            sf += rp[i];
            sf = sf/80;
            }

    };

double sensado::s, sensado::s1, sensado::sf;

    class planear {

    public:

      static double ang;

      double  esquivar ()
      {
        ang = 0.0;

/////////////////////////////////// Robot 1////////////////////////////////////////////////////////////////////////////
        if((sensado::s < sensado::s1) and sensado::sf > 4.5)
             ang = -0.5  ;
    else if((sensado::s1 < sensado::s) and sensado::sf > 4.5)
            ang = 0.5  ;
         //if(sf < 4.5 and s)
             //ang = ;
        else if(sensado::sf < 4.5 and (sensado::s < sensado::s1))
             ang = -0.50;
        else if(sensado::sf < 4.5 and (sensado::s1 < sensado::s))
             ang = 0.50;
        else if(sensado::sf < 4.5 and sensado::s > 4.5 and sensado::s1 > 4.5)
             ang = 0.50;
         else
             ang = 0.00;

             return ang;
      }
    };

double planear::ang;


class actuador
{
    public:
        void avanzar()
        {
            pp.SetSpeed(0.3,planear::ang);
        }
};

int main()
{
  sensado angulo;
  planear plan;
  actuador act;

    while(1)
    {
        reybot.Read(); // leer valores constantemente.
        //sensado angulo; // declaracion de un objeto angulo del tipo sensado.
        //actuador act; // declaracion de un objeto act del tipo actuador.

        angulo.obstaculo();
        plan.esquivar();
        act.avanzar();

        //cout.precision(4);
        //cout << fixed << " (" << angulo.x << " , " << angulo.y << ")\tyaw: " << angulo.a;
        //cout << fixed << "\tSonar left : " << angulo.s << "\tSonar right : " << angulo.s1 << "\tSonar Front : " << angulo.sf << endl;
    }
    return 0;
}
