#include <iostream>
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING // Stop warning "Boost.Signals"
#include <libplayerc++/playerc++.h>//cabezeras player

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

////////////////////////////////////////////////////////Robot 3 (CONFIGURACION) /////////////////////////////////////////////////////////////////
PlayerClient reybot3("localhost",6667); // forma de declarar conexion al bot y su name.
RangerProxy rp3(&reybot3,0); //usar ranger
Position2dProxy pp3(&reybot3,0); //usar position2d

////////////////////////////////////////////////////////Robot 4 (CONFIGURACION) /////////////////////////////////////////////////////////////////
PlayerClient reybot4("localhost",6668); // forma de declarar conexion al bot y su name.
RangerProxy rp4(&reybot4,0); //usar ranger
Position2dProxy pp4(&reybot4,0); //usar position2d

////////////////////////////////////////////////////////Robot 5 (CONFIGURACION) /////////////////////////////////////////////////////////////////
PlayerClient reybot5("localhost",6669); // forma de declarar conexion al bot y su name.
RangerProxy rp5(&reybot5,0); //usar ranger
Position2dProxy pp5(&reybot5,0); //usar position2d

////////////////////////////////////////////////////////Robot 6 (CONFIGURACION) /////////////////////////////////////////////////////////////////
PlayerClient reybot6("localhost",6670); // forma de declarar conexion al bot y su name.
RangerProxy rp6(&reybot6,0); //usar ranger
Position2dProxy pp6(&reybot6,0); //usar position2d

////////////////////////////////////////////////////////Robot 7 (CONFIGURACION) /////////////////////////////////////////////////////////////////
PlayerClient reybot7("localhost",6671); // forma de declarar conexion al bot y su name.
RangerProxy rp7(&reybot7,0); //usar ranger
Position2dProxy pp7(&reybot7,0); //usar position2d

////////////////////////////////////////////////////////Robot 8 (CONFIGURACION) /////////////////////////////////////////////////////////////////
PlayerClient reybot8("localhost",6672); // forma de declarar conexion al bot y su name.
RangerProxy rp8(&reybot8,0); //usar ranger
Position2dProxy pp8(&reybot8,0); //usar position2d

////////////////////////////////////////////////////////Robot 9 (CONFIGURACION) /////////////////////////////////////////////////////////////////
PlayerClient reybot9("localhost",6673); // forma de declarar conexion al bot y su name.
RangerProxy rp9(&reybot9,0); //usar ranger
Position2dProxy pp9(&reybot9,0); //usar position2d

////////////////////////////////////////////////////////Robot 10 (CONFIGURACION) /////////////////////////////////////////////////////////////////
PlayerClient reybot10("localhost",6674); // forma de declarar conexion al bot y su name.
RangerProxy rp10(&reybot10,0); //usar ranger
Position2dProxy pp10(&reybot10,0); //usar position2d

class sensado
{
public:

/////////////////////////////////////////////////// Variables utilizadas para ajustar sensores izq,derecha y frontal para cada robot /////////////////////////////////////////////////////////////
static double sr,sl,sf;
static double sr2,sl2,sf2;
static double sr3,sl3,sf3;
static double sr4,sl4,sf4;
static double sr5,sl5,sf5;
static double sr6,sl6,sf6;
static double sr7,sl7,sf7;
static double sr8,sl8,sf8;
static double sr9,sl9,sf9;
static double sr10,sl10,sf10;

void obstaculo()
{
  //////////////////////////////////////////////////////Lectura de sensores para cada robot ///////////////////////////////////////////////////////////////////////////////
        reybot1.Read();
        reybot2.Read();
        reybot3.Read();
        reybot4.Read();
        reybot5.Read();
        reybot6.Read();
        reybot7.Read();
        reybot8.Read();
        reybot9.Read();
        reybot10.Read();

        sl = 0,sl2=0,sl3=0,sl4=0,sl5=0,sl6=0,sl7=0,sl8=0,sl9=0,sr10=0;
        sr = 0, sr2=0,sr3=0,sr4=0,sr5=0,sr6=0,sr7=0,sr8=0,sr9=0,sr10=0;
        sf = 0, sf2=0,sf3=0,sf4=0,sf5=0,sf6=0,sf7=0,sf8=0,sf9=0,sf10=0;

/////////////////////////////////////////////////////////////////////// Robot 1 (asignacion de sensores) //////////////////////////////////////////////////////////////////
        for(int i=120; i<=180; i++)
                sl += rp1[i];
        sl = sl/60;
        for(int i=0; i<=60; i++)
                sr += rp1[i];
        sr = sr/60;
        for(int i = 60; i<=120; i++)
                sf += rp1[i];
        sf = sf/60;

        /////////////////////////////////////////////////////////////////////// Robot 2 (asignacion de sensores) //////////////////////////////////////////////////////////////////
        for(int i=120; i<=180; i++)
                sl2 += rp2[i];
        sl2 = sl2/60;
        for(int i=0; i<=60; i++)
                sr2 += rp2[i];
        sr2 = sr2/60;
        for(int i = 60; i<=120; i++)
                sf2 += rp2[i];
        sf2 = sf2/60;

        /////////////////////////////////////////////////////////////////////// Robot 3 (asignacion de sensores) //////////////////////////////////////////////////////////////////
        for(int i=120; i<=180; i++)
                sl3 += rp3[i];
        sl3 = sl3/60;
        for(int i=0; i<=60; i++)
                sr3 += rp3[i];
        sr3 = sr3/60;
        for(int i = 60; i<=120; i++)
                sf3 += rp3[i];
        sf3 = sf3/60;

        /////////////////////////////////////////////////////////////////////// Robot 4 (asignacion de sensores) //////////////////////////////////////////////////////////////////
        for(int i=120; i<=180; i++)
                sl4 += rp4[i];
        sl4 = sl4/60;
        for(int i=0; i<=60; i++)
                sr4 += rp4[i];
        sr4 = sr4/60;
        for(int i = 60; i<=120; i++)
                sf4 += rp4[i];
        sf4 = sf4/60;

        /////////////////////////////////////////////////////////////////////// Robot 5 (asignacion de sensores) //////////////////////////////////////////////////////////////////
        for(int i=120; i<=180; i++)
                sl5 += rp5[i];
        sl5 = sl5/60;
        for(int i=0; i<=60; i++)
                sr5 += rp5[i];
        sr5 = sr5/60;
        for(int i = 60; i<=120; i++)
                sf5 += rp5[i];
        sf5 = sf5/60;

        /////////////////////////////////////////////////////////////////////// Robot 6 (asignacion de sensores) //////////////////////////////////////////////////////////////////
        for(int i=120; i<=180; i++)
                sl6 += rp6[i];
        sl6 = sl6/60;
        for(int i=0; i<=60; i++)
                sr6 += rp6[i];
        sr6 = sr6/60;
        for(int i = 60; i<=120; i++)
                sf6 += rp6[i];
        sf6 = sf6/60;

        /////////////////////////////////////////////////////////////////////// Robot 7 (asignacion de sensores) //////////////////////////////////////////////////////////////////
        for(int i=120; i<=180; i++)
                sl7 += rp7[i];
        sl7 = sl7/60;
        for(int i=0; i<=60; i++)
                sr7 += rp7[i];
        sr7 = sr7/60;
        for(int i = 60; i<=120; i++)
                sf7 += rp7[i];
        sf7 = sf7/60;

        /////////////////////////////////////////////////////////////////////// Robot 8 (asignacion de sensores) //////////////////////////////////////////////////////////////////
        for(int i=120; i<=180; i++)
                sl8 += rp8[i];
        sl8 = sl8/60;
        for(int i=0; i<=60; i++)
                sr8 += rp8[i];
        sr8 = sr8/60;
        for(int i = 60; i<=120; i++)
                sf8 += rp8[i];
        sf8 = sf8/60;

        /////////////////////////////////////////////////////////////////////// Robot 9 (asignacion de sensores) //////////////////////////////////////////////////////////////////
        for(int i=120; i<=180; i++)
                sl9 += rp9[i];
        sl9 = sl9/60;
        for(int i=0; i<=60; i++)
                sr9 += rp9[i];
        sr9 = sr9/60;
        for(int i = 60; i<=120; i++)
                sf9 += rp9[i];
        sf9 = sf9/60;

        /////////////////////////////////////////////////////////////////////// Robot 10 (asignacion de sensores) //////////////////////////////////////////////////////////////////
        for(int i=120; i<=180; i++)
                sl10 += rp10[i];
        sl10 = sl10/60;
        for(int i=0; i<=60; i++)
                sr10 += rp10[i];
        sr10 = sr10/60;
        for(int i = 60; i<=120; i++)
                sf10 += rp10[i];
        sf10 = sf10/60;
}

};

double sensado::sl, sensado::sr, sensado::sf;
double sensado::sl2, sensado::sr2, sensado::sf2;
double sensado::sl3, sensado::sr3, sensado::sf3;
double sensado::sl4, sensado::sr4, sensado::sf4;
double sensado::sl5, sensado::sr5, sensado::sf5;
double sensado::sl6, sensado::sr6, sensado::sf6;
double sensado::sl7, sensado::sr7, sensado::sf7;
double sensado::sl8, sensado::sr8, sensado::sf8;
double sensado::sl9, sensado::sr9, sensado::sf9;
double sensado::sl10, sensado::sr10, sensado::sf10;

class planear {

public:

static double ang, ang2,ang3,ang4,ang5,ang6,ang7,ang8,ang9,ang10;


double  esquivar ()
{
        ang = 0.0, ang2=0.0,ang3=0.0,ang4=0.0,ang5=0.0,ang6=0.0,ang7=0.0,ang8=0.0,ang9=0.0,ang10=0.0;

/////////////////////////////////// Robot 1 esquivar ////////////////////////////////////////////////////////////////////////////
        if(sensado::sl < 4.5 and (sensado::sr > 2))
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
                ang = 0.00;

        /////////////////////////////////// Robot 2 esquivar ////////////////////////////////////////////////////////////////////////////
        if((sensado::sl2 < 4.5 and sensado::sr2 > 2) )
                ang2 = -0.5;
        else if((sensado::sr2 < 4.5 and sensado::sl2 > 2) )
                ang2 = 0.5;
        else if(sensado::sf2 < 4.5 and (sensado::sl2 < sensado::sr2))
                ang2 = -0.5;
        else if(sensado::sf2 < 4.5 and (sensado::sr2 < sensado::sl2))
                ang2 = 0.5;
        else if(sensado::sf2 < 4.5 and sensado::sr2 > 3 and sensado::sl2 > 3)
                ang2 = 0.5;
        else
                ang2 = 0.00;

        /////////////////////////////////// Robot 3 esquivar ////////////////////////////////////////////////////////////////////////////
        if((sensado::sl3 < 4.5 and sensado::sr3 > 2) )
                ang3 = -0.5;
        else if((sensado::sr3 < 4.5 and sensado::sl3 > 2) )
                ang3 = 0.5;
        else if(sensado::sf3 < 4.5 and (sensado::sl3 < sensado::sr3))
                ang3 = -0.5;
        else if(sensado::sf3 < 4.5 and (sensado::sr3 < sensado::sl3))
                ang3 = 0.5;
        else if(sensado::sf3 < 4.5 and sensado::sr3 > 3 and sensado::sl3 > 3)
                ang3 = 0.5;
        else
                ang3 = 0.00;

        /////////////////////////////////// Robot 4 esquivar ////////////////////////////////////////////////////////////////////////////
        if((sensado::sl4 < 4.5 and sensado::sr4 > 2) )
                ang4 = -0.5;
        else if((sensado::sr4 < 4.5 and sensado::sl4 > 2) )
                ang4 = 0.5;
        else if(sensado::sf4 < 4.5 and (sensado::sl4 < sensado::sr4))
                ang4 = -0.5;
        else if(sensado::sf4 < 4.5 and (sensado::sr4 < sensado::sl4))
                ang4 = 0.5;
        else if(sensado::sf4 < 4.5 and sensado::sr4 > 3 and sensado::sl4 > 3)
                ang4 = 0.5;
        else
                ang4 = 0.00;

        /////////////////////////////////// Robot 5 esquivar ////////////////////////////////////////////////////////////////////////////
        if((sensado::sl5 < 4.5 and sensado::sr5 > 2) )
                ang5 = -0.5;
        else if((sensado::sr5 < 4.5 and sensado::sl5 > 2) )
                ang5 = 0.5;
        else if(sensado::sf5 < 4.5 and (sensado::sl5 < sensado::sr5))
                ang5 = -0.5;
        else if(sensado::sf5 < 4.5 and (sensado::sr5 < sensado::sl5))
                ang5 = 0.5;
        else if(sensado::sf5 < 4.5 and sensado::sr5 > 3 and sensado::sl5 > 3)
                ang5 = 0.5;
        else
                ang5 = 0.00;

        /////////////////////////////////// Robot 6 esquivar ////////////////////////////////////////////////////////////////////////////
        if((sensado::sl6 < 4.5 and sensado::sr6 > 2) )
                ang6 = -0.5;
        else if((sensado::sr6 < 4.5 and sensado::sl6 > 2) )
                ang6 = 0.5;
        else if(sensado::sf6 < 4.5 and (sensado::sl6 < sensado::sr6))
                ang6 = -0.5;
        else if(sensado::sf6 < 4.5 and (sensado::sr6 < sensado::sl6))
                ang6 = 0.5;
        else if(sensado::sf6 < 4.5 and sensado::sr6 > 3 and sensado::sl6 > 3)
                ang6 = 0.5;
        else
                ang6 = 0.00;

        /////////////////////////////////// Robot 7 esquivar ////////////////////////////////////////////////////////////////////////////
        if((sensado::sl7 < 4.5 and sensado::sr7 > 2) )
                ang7 = -0.5;
        else if((sensado::sr7 < 4.5 and sensado::sl7 > 2) )
                ang7 = 0.5;
        else if(sensado::sf7 < 4.5 and (sensado::sl7 < sensado::sr7))
                ang7 = -0.5;
        else if(sensado::sf7 < 4.5 and (sensado::sr7 < sensado::sl7))
                ang7 = 0.5;
        else if(sensado::sf7 < 4.5 and sensado::sr7 > 3 and sensado::sl7 > 3)
                ang7 = 0.5;
        else
                ang7 = 0.00;

        /////////////////////////////////// Robot 8 esquivar ////////////////////////////////////////////////////////////////////////////
        if((sensado::sl8 < 4.5 and sensado::sr8 > 2) )
                ang8 = -0.5;
        else if((sensado::sr8 < 4.5 and sensado::sl8 > 2) )
                ang8 = 0.5;
        else if(sensado::sf8 < 4.5 and (sensado::sl8 < sensado::sr8))
                ang8 = -0.5;
        else if(sensado::sf8 < 4.5 and (sensado::sr8 < sensado::sl8))
                ang8 = 0.5;
        else if(sensado::sf8 < 4.5 and sensado::sr8 > 3 and sensado::sl8 > 3)
                ang8 = 0.5;
        else
                ang8 = 0.00;

        /////////////////////////////////// Robot 9 esquivar ////////////////////////////////////////////////////////////////////////////
        if((sensado::sl9 < 4.5 and sensado::sr9 > 2) )
                ang9 = -0.5;
        else if((sensado::sr9 < 4.5 and sensado::sl9 > 2) )
                ang9 = 0.5;
        else if(sensado::sf9 < 4.5 and (sensado::sl9 < sensado::sr9))
                ang9 = -0.5;
        else if(sensado::sf9 < 4.5 and (sensado::sr9 < sensado::sl9))
                ang9 = 0.5;
        else if(sensado::sf9 < 4.5 and sensado::sr9 > 3 and sensado::sl9 > 3)
                ang9 = 0.5;
        else
                ang9 = 0.00;

        /////////////////////////////////// Robot 10 esquivar ////////////////////////////////////////////////////////////////////////////
        if((sensado::sl10 < 4.5 and sensado::sr10 > 2) )
                ang10 = -0.5;
        else if((sensado::sr10 < 4.5 and sensado::sl10 > 2) )
                ang10 = 0.5;
        else if(sensado::sf10 < 4.5 and (sensado::sl10 < sensado::sr10))
                ang10 = -0.5;
        else if(sensado::sf10 < 4.5 and (sensado::sr10 < sensado::sl10))
                ang10 = 0.5;
        else if(sensado::sf10 < 4.5 and sensado::sr10 > 3 and sensado::sl10 > 3)
                ang10 = 0.5;
        else
                ang10 = 0.00;

        return ang, ang2,ang3,ang4,ang5,ang6,ang7,ang8,ang9,ang10;
}
};

double planear::ang,planear::ang2,planear::ang3,planear::ang4,planear::ang5,planear::ang6,planear::ang7,planear::ang8,planear::ang9,planear::ang10;


class actuador
{
public:
void avanzar()
{
        ////////////////////////////////////////////////////////// Robot 1 (Actuacion) ////////////////////////////////////////////////////////////////////
        pp1.SetSpeed(0.3*(planear::ang+.5),planear::ang);
        ////////////////////////////////////////////////////////// Robot 2 (Actuacion) ////////////////////////////////////////////////////////////////////
        pp2.SetSpeed(0.3*(planear::ang2+.5),planear::ang2);
        ////////////////////////////////////////////////////////// Robot 3 (Actuacion) ////////////////////////////////////////////////////////////////////
        pp3.SetSpeed(0.3*(planear::ang3+.5),planear::ang3);
        ////////////////////////////////////////////////////////// Robot 4 (Actuacion) ////////////////////////////////////////////////////////////////////
        pp4.SetSpeed(0.3*(planear::ang4+.5),planear::ang4);
        ////////////////////////////////////////////////////////// Robot 5 (Actuacion) ////////////////////////////////////////////////////////////////////
        pp5.SetSpeed(0.3*(planear::ang5+.5),planear::ang5);
        ////////////////////////////////////////////////////////// Robot 6 (Actuacion) ////////////////////////////////////////////////////////////////////
        pp6.SetSpeed(0.3*(planear::ang6+.5),planear::ang6);
        ////////////////////////////////////////////////////////// Robot 7 (Actuacion) ////////////////////////////////////////////////////////////////////
        pp7.SetSpeed(0.3*(planear::ang7+.5),planear::ang7);
        ////////////////////////////////////////////////////////// Robot 8 (Actuacion) ////////////////////////////////////////////////////////////////////
        pp8.SetSpeed(0.3*(planear::ang8+.5),planear::ang8);
        ////////////////////////////////////////////////////////// Robot 9 (Actuacion) ////////////////////////////////////////////////////////////////////
        pp9.SetSpeed(0.3*(planear::ang9+.5),planear::ang9);
        ////////////////////////////////////////////////////////// Robot 10 (Actuacion) ////////////////////////////////////////////////////////////////////
        pp10.SetSpeed(0.3*(planear::ang10+.5),planear::ang10);

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
                plan.esquivar();
                act.avanzar();
        }
        return 0;
}
