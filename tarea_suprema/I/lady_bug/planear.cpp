#include <iostream>
#include <armadillo>
#include <unistd.h>

using namespace arma;
using namespace std;

class planear {

private:
  mat x,vel;

public:

double ang=0.0;


double  esquivar ()
{
//  mat x(1,3);
  //usleep(50021);
  //x.zeros();
  x.load("x.txt",arma_ascii);
        ang = 0.0;

/////////////////////////////////// Robot 1 esquivar ////////////////////////////////////////////////////////////////////////////
        if( x(0,1) < 4.5 and ( x(0,0) > 2))
                ang = -0.5;
        else if(  x(0,0) < 4.5 and ( x(0,1) > 2))
                ang = 0.5;
        else if(  x(0,2) < 4.5 and ( x(0,1) <  x(0,0) ))
                ang = -0.5;
        else if(x(0,2) < 4.5 and ( x(0,0) < x(0,1) ))
                ang = 0.5;
        else if( x(0,2) < 4.5 and  x(0,0) > 3 and x(0,1) > 3)
                ang = 0.5;
        else
                ang = 0.00;

///////////////////////////////// Imprimir velocidad angular planeada /////////////////////////////////////////////////////////////////////
          cout << "Velocidad Angular: "<< ang << endl;

////////////////////////////////////// Guardar velocidad angular //////////////////////////////////////////////////////////////////////////////
          vel << ang << endr;
          vel.save("vel.txt",arma_ascii);
        return ang;
}
};

int main()
{
        planear plan;

        while(1)
        {
          usleep(80021);
                plan.esquivar();
        }
        return 0;
}
