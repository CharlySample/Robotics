#include <iostream>
#include <armadillo>
#include <cmath>
#define pi 3.14159

using namespace std;
using namespace arma;

int main()
{
        double r=0.15,b=1.0,alfa=0.25,beta=0.65,e=0.001,error=-30.0,x=0.0,y=0.0,a=2.0;

        mat e1,e2;
        mat dummy,muerta,cordi;
        int p=1;
        mat u,uref,phi,phi1,u1,k,kinv,phio,uo;

        //cout << "Introduce distancia a: ";
       //cin >> a;
       // cout << "\nIntroduce distancia b: ";
       // cin >> b;

        cout << endl;

        k << r/4 << r/4 << r/4 << r/4 << endr
          << ((r*b)/2*(pow(a,2)+pow(b,2))) << ((r*b)/2*(pow(a,2)+pow(b,2))) << ((-r*b)/2*(pow(a,2)+pow(b,2))) << ((-r*b)/2*(pow(a,2)+pow(b,2))) << endr;

        kinv = pinv(k);

        uref << 23 << endr << -pi/8 << endr;

        u << 0 << endr << 0 << endr;

        phi << 0 << endr << 0 << endr << 0 << endr << 0 << endr;

        dummy << u(0,0) << u(1,0) << endr;
        cordi << x << y << endr;

        while(abs(error) >= e)
        {
                error = sqrt(pow(uref(0,0)-(u(0,0)),2) + pow(uref(1,0)-(u(1,0)),2));

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
                muerta << x << endr << y << endr;

                cout << "desplazamiento: "<< u(0,0) << "\n" << "angulo: " << u(1,0) << "\nIteracion: " << p << "\nerror: " << error << endl;

                cout << endl;
                dummy = join_cols(dummy,trans(u));
                cordi = join_cols(cordi,trans(muerta));

                p++;
        }
        dummy = join_rows(dummy,cordi);
        dummy.save("4wd4.txt",raw_ascii);


        return 0;
}
