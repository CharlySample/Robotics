#include <iostream>
#include <armadillo>
#include <cmath>
#define pi 3.14159

using namespace std;
using namespace arma;

int main()
{
        double r=0.15,b=0.25,alfa=0.25,beta=0.65,e=0.001,error=-30.0,error2=100.0,x=0.0,y=0.0;
        double desp=0.0,ang=0.0,s=0.0,th=0.0;
        float t=0.1;
        mat e1,e2;
        mat dummy,muerta,cordi;
        int p=1;
        mat u,uref,phi,phi1,u1,k,ktrans,phio,uo;

        k << cos((7/3)*pi) << cos(pi) << cos((5/3)*pi) <<endr
          << sin((7/3)*pi) << 0 << sin((5/3)*pi) << endr;

        ktrans = trans(k);

        uref << 0 << endr << 0 << endr;

        u << 0 << endr << 0 << endr;

        phi << 0 << endr << 0 << endr << 0 << endr;

        dummy << u(0,0) << u(1,0) << endr;
        cordi << desp << ang << endr;

        while(s < 5)
        {
                error = sqrt(pow(uref(0,0)-(u(0,0)),2) + pow(uref(1,0)-(u(1,0)),2));

                phi1.zeros();
                u1.zeros();
                uo.zeros();
                phio.zeros();

                if(error < e)
                {
                s = (0.25)*pow(t,2);
                th = t;
                t+=0.01;
                uref << s << endr << th << endr;
                }

               // uref << s << endr << th << endr;

                uo = u;


                phi1 = phi + ((3/r)*pinv(k) * alfa*(uref - uo));
                phio = phi;

                u1 = u + ((r/3)*k *beta*(phi1 - phio));

                u = u1, phi = phi1;
u.print();
               // desp = sqrt(pow(u(0,0),2)+pow(u(1,0),2));
               // ang = (atan(u(1,0)/u(0,0)));
               // ang += ang * -1;
                x = u(0,0)*cos(u(1,0));
                y = u(0,0)*sin(u(1,0));
                muerta << x << endr << y << endr;

                cout << "desplazamiento: "<< u(0,0) << "\n" << "angulo: " << u(1,0) << "\nIteracion: " << p << "\nerror: " << error << endl;

                cout << endl;

                dummy = join_cols(dummy,trans(u));
               cordi = join_cols(cordi,trans(muerta));

                p++;
             //   t+=0.01;
        }
        dummy = join_rows(dummy,cordi);
        dummy.save("omniejer.txt",raw_ascii);


        return 0;
}
