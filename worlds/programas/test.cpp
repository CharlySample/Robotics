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
        double s, s1, sf, ang;

        double obstaculo()
        {
            s = 0;
            s1 = 0;
            sf = 0;

            for(int i=0;i<=2;i++)
                s = rp[i] + s;
            for(int n=5;n<=7;n++)
                s1 = rp[n] + s1;
            for(int m=3;m<=4;m++)
                sf = rp[m] + sf;

            if(s < 3 and s1 > 3)
                ang = s<6 ? -0.80 : -0.20  ;
            else if(s1 < 3 and s > 3)
               ang = s1<6 ? 0.80 : 0.20  ;
            else if(sf < 3 and s > 4 and s1 > 4)
                ang = rp[3]<rp[4] ? -0.80 : 0.80;
            else if(sf < 4 and s < 4 and s1 < 4)
                ang = 0.90;
            else
                ang = 0.00;

            return ang;
            }

    };

class actuador
{
    public:
        void avanzar()
        { 
            sensado angulo;

            pp.SetSpeed(0.2,angulo.obstaculo());

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