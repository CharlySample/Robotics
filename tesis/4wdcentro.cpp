#include <iostream>
#include <armadillo>
#include <cmath>
#define pi 3.14159

using namespace std;
using namespace arma;

int main()
{
        double r=0.15,b=1.0,alfa=0.25,beta=0.65,e=0.001,error=-30.0,x=0.0,y=0.0,a=2.0,vmax=1.5;
        double xz=0.0,yz=0.0, desp = 0.0, ang = 0.0, ekis=0.0;
        mat e1,e2, m,mm;
        mat dummy,muerta,cordi;
        int p=1;
        mat u,uref,phi,phi1,u1,k,kinv,phio,uo;

        cout << endl;

        k << r/4 << r/4 << r/4 << r/4 << endr
          << ((r*b)/2*(pow(a,2)+pow(b,2))) << ((r*b)/2*(pow(a,2)+pow(b,2))) << ((-r*b)/2*(pow(a,2)+pow(b,2))) << ((-r*b)/2*(pow(a,2)+pow(b,2))) << endr
          << (b*r)/(vmax) << (-b*r)/(vmax) << (-b*r)/(vmax) << (b*r)/(vmax) << endr
          << (-a*r)/(vmax) << (a*r)/(vmax) << (-a*r)/(vmax) << (a*r)/(vmax) << endr;

        kinv = inv(k);

        uref << 0 << endr << 0 << endr << 1 << endr << 0.5 << endr;

        u << 0 << endr << 0 << endr << 0 << endr << 0 << endr;

        phi << 0 << endr << 0 << endr << 0 << endr << 0 << endr;

        dummy << u(0,0) << u(1,0) << u(2,0) << u(3,0) << endr;
        mm << 0 << 0 << endr;
        cordi << x << y << endr;

        while((abs(error) >= e ) or desp <= 25)
        {
                error = sqrt(pow(uref(0,0)-(u(0,0)),2) + pow(uref(1,0)-(u(1,0)),2));

                if( (abs(error) < e ) and desp <= 25)
                {
                    ekis +=0.1;
                    ang = atan((sin(ekis))/(ekis));
                    desp = sqrt(pow(ekis,2) + pow(sin(ekis),2));
                    uref(0,0) = desp;
                    uref(1,0) = ang;
                }



                phi1.zeros();
                u1.zeros();
                uo.zeros();
                phio.zeros();

                uo = u;

                phi1 = (phi + alfa*(kinv * (uref - uo)));
                phio = phi;

                u1 = (u + beta*(k *(phi1 - phio)));

                u = u1, phi = phi1;
                x = u(0,0)*cos(u(1,0));
                y = u(0,0)*sin(u(1,0));
                xz = (sqrt(pow(uref(2,0),2) + pow(uref(3,0),2)) * cos(u(1,0))) + u(0,0)*cos(u(1,0));
                yz = (sqrt(pow(uref(2,0),2) + pow(uref(3,0),2)) * sin(u(1,0))) + u(0,0)*sin(u(1,0));
                muerta << x << endr << y << endr;
                m << xz << endr << yz << endr;

                //cout << "desplazamiento: "<< u(0,0) << "\n" << "angulo: " << u(1,0) << "\nIteracion: " << p << "\nerror: " << error << endl;
                cout << phi << endl;
                cout << endl;
                dummy = join_cols(dummy,trans(u));
                cordi = join_cols(cordi,trans(muerta));
                mm = join_cols(mm,trans(m));

                p++;
        }
        dummy = join_rows(dummy,cordi);
        dummy.save("4wdcentro.txt",raw_ascii);
        mm.save("centro.txt",raw_ascii);


        return 0;
}
