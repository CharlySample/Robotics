#include <iostream>
#include <cmath>
#include <armadillo>
#define pi 3.14159

using namespace std;
using namespace arma;

int main()
{
        mat phi, K, u,phir, dato, dummy;
        float r=5;
        double s1=0.0,s2=0.0,s3=0.0,t=0.0;

        while(t<=10)
        {
                K << cos((7/3)*pi) << cos(pi) << cos((5/3)*pi) << endr
                  << sin((7/3)*pi) << 0 << sin((5/3)*pi) << endr;

                u << t/2 << endr << 1 << endr;

                phi = (3/r) * pinv(K) * u;
                phi *=-1;
                phir = phi*0.00001;

                s1 = 0.0702341+3.01968*phir(0,0)+5.10016*pow(phir(0,0),2)-6.00479*pow(phir(0,0),3)+3.50626*pow(phir(0,0),4)-1.11228*pow(phir(0,0),5)+0.195824*pow(phir(0,0),6)-0.0179695*pow(phir(0,0),7)+0.000670904*pow(phir(0,0),8)
                s2 = 0.0701971+2.95862*phir(1,0)+5.00309*pow(phir(0,0),2)-5.83549*pow(phir(0,0),3)+3.38012*pow(phir(0,0),4)-1.06371*pow(phir(0,0),5)+0.185782*pow(phir(0,0),6)-0.0169127*pow(phir(0,0),7)+0.000626453*pow(phir(0,0),8);
                s3 = 0.0806085* +2.40593*phir(2,0)+5.6996*pow(phir(2,0),2)-6.4475*pow(phir(2,0),3)+3.62637*pow(phir(2,0),4)-1.10854*pow(phir(2,0),5)+0.188052*pow(phir(2,0),6)-0.0166264*pow(phir(2,0),7)+0.000597989*pow(phir(2,0),8);

                dummy << s1 << s2 << (s3*1000000)+2 << endr;
                dato = join_cols(dato,dummy);
                t+=0.1;
        }

        dato.print();
        dato.save("dato.txt",raw_ascii);
        
        return 0;
}
