#include <iostream>
#include <libplayerc++/playerc++.h>//cabezeras player
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"

using namespace std;
using namespace PlayerCc; //LIbreria para player

////////////////////////////////////////////////////////Robot 1 (CONFIGURACION) /////////////////////////////////////////////////////////////////
PlayerClient reybot1("localhost",6665); // forma de declarar conexion al bot y su name.
RangerProxy rp1(&reybot1,0); //usar ranger
Position2dProxy pp1(&reybot1,0); //usar position2d

////////////////////////////////////////////////////////Robot 2 (CONFIGURACION) /////////////////////////////////////////////////////////////////
PlayerClient reybot2("localhost",6666); // forma de declarar conexion al bot y su name.
RangerProxy rp2(&reybot2,0); //usar ranger
Position2dProxy pp2(&reybot2,0); //usar position2d


class sensado
{
    public:

        double x;
        double y;
        double a;
        static double sr,sl,sf;
        static double sr2,sl2,sf2;

        void obstaculo()
        {
           //x = pp.GetXPos();
        //   y = pp.GetYPos();
      //     a = pp.GetYaw();

            sl = 0,sl2=0;
            sr = 0, sr2=0;
            sf = 0, sf2=0;

/////////////////////////////////////////////////////////////////////// Robot 1 (asignacion de sensores) //////////////////////////////////////////////////////////////////
            for(int i=120;i<=180;i++)
            sl += rp1[i];
            sl = sl/60;
            for(int i=0;i<=60;i++)
            sr += rp1[i];
            sr = sr/60;
            for(int i = 60 ; i<=120;i++)
            sf += rp1[i];
            sf = sf/60;

            /////////////////////////////////////////////////////////////////////// Robot 2 (asignacion de sensores) //////////////////////////////////////////////////////////////////
                        for(int i=120;i<=180;i++)
                        sl2 += rp2[i];
                        sl2 = sl2/60;
                        for(int i=0;i<=60;i++)
                        sr2 += rp2[i];
                        sr2 = sr2/60;
                        for(int i = 60 ; i<=120;i++)
                        sf2 += rp2[i];
                        sf2 = sf2/60;
            }

    };

double sensado::sl, sensado::sr, sensado::sf;
double sensado::sl2, sensado::sr2, sensado::sf2;

    class planear {

    public:

      static double ang, ang2;


      double  esquivar ()
      {
        ang = 0.0, ang2=0.0;

/////////////////////////////////// Robot 1 esquivar ////////////////////////////////////////////////////////////////////////////
        if(sensado::sl < 4.5 and (sensado::sr > 3))
             ang = -0.5  ;
    else if(sensado::sr < 4.5 and (sensado::sl > 3))
            ang = 0.5  ;
        else if(sensado::sf < 4.5 and (sensado::sl < sensado::sr))
             ang = 0.5;
        else if(sensado::sf < 4.5 and (sensado::sr < sensado::sl))
             ang = -0.5;
        else if(sensado::sf < 4.5 and sensado::sr > 3 and sensado::sl > 3)
             ang = 0.5;
         else
             ang = 0.00;

             /////////////////////////////////// Robot 2 esquivar ////////////////////////////////////////////////////////////////////////////
                     if((sensado::sl2 < 4.5 and sensado::sr2 > 3) )
                          ang2 = -0.5  ;
                 else if((sensado::sr2 < 4.5 and sensado::sl2 > 3) )
                         ang2 = 0.5  ;
                     else if(sensado::sf2 < 4.5 and (sensado::sl2 < sensado::sr2))
                          ang2 = 0.5;
                     else if(sensado::sf2 < 4.5 and (sensado::sr2 <sensado::sl2))
                          ang2 = -0.5;
                     else if(sensado::sf2 < 4.5 and sensado::sr2 > 3 and sensado::sl2 > 3)
                          ang2 = 0.5;
                      else
                          ang2 = 0.00;

             return ang, ang2;
      }
    };

double planear::ang,planear::ang2;


class actuador
{
    public:
        void avanzar()
        {
          ////////////////////////////////////////////////////////// Robot 1 (Actuacion) ////////////////////////////////////////////////////////////////////
            pp1.SetSpeed(0.3,planear::ang);
            ////////////////////////////////////////////////////////// Robot 2 (Actuacion) ////////////////////////////////////////////////////////////////////
              pp2.SetSpeed(0.3,planear::ang2);
        }
};

int main()
{
  sensado angulo;
  planear plan;
  actuador act;

    while(1)
    {
        reybot1.Read(); // leer valores constantemente.
        reybot2.Read();
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
