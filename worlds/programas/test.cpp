#include <iostream>
#include <libplayerc++/playerc++.h>//cabezeras player
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"

using namespace std;
using namespace PlayerCc; //LIbreria para player

PlayerClient reybot("localhost"); // forma de declarar conexion al bot y su name.
RangerProxy rp(&reybot,0); //usar ranger
Position2dProxy pp(&reybot,0); //usar position2d

class sensado
{
    public:

        double x = pp.GetXPos();
        double y = pp.GetYPos();
        double a = pp.GetYaw();
        double s, s1, sf,izq,der;
        static double ang;

        double obstaculo()
        {
            s = 0;
            s1 = 0;
            sf = 0;

            s = rp[0]; // LEFT
            s1 = rp[5]; //RIGHT
            izq = rp[1]; //esquina izq
            der = rp[4]; //esquina der

            //for(int i=0;i<=2;i++)
              //  s = rp[i] + s; // RIGHT
            //for(int n=5;n<=7;n++)
             //   s1 = rp[n] + s1; // LEFT
            for(int m=2;m<=3;m++)
                sf = rp[m] + sf; // FRONT

            if(s < 1 and s1 > 1)
                ang = -0.5  ;
            if(s1 < 1 and s > 1)
               ang = 0.5  ;
           if(izq < 2 and der > 2)
               ang = -0.5  ;
           if(der < 2 and izq > 2)
               ang =  0.50  ;
            //if(sf < 3.5 and s > 3.5 and s1 > 3.5)
                //ang = rp[3]<rp[4] ? -0.80 : 0.80;
            if(sf < 2.5)
                ang = 0.90;
            else
                ang = 0.00;

            return ang;
            }

    };

double sensado::ang=0.0;

class actuador
{
    public:
        void avanzar()
        { 
            sensado angulo;

            pp.SetSpeed(0.4,sensado::ang);

        }
};

int main()
{
    while(1)
    {
        reybot.Read(); // leer valores constantemente.
        sensado angulo; // declaracion de un objeto angulo del tipo sensado.
        actuador act; // declaracion de un objeto act del tipo actuador.

        angulo.obstaculo();
        act.avanzar();

        cout.precision(4);
        cout << fixed << " (" << angulo.x << " , " << angulo.y << ")\tyaw: " << angulo.a;
        cout << fixed << "\tSonar left : " << angulo.s << "\tSonar right : " << angulo.s1 << "\tSonar Front : " << angulo.sf << endl;
    }
    return 0;
}