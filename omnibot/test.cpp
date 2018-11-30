#include <iostream>
#include <fstream>
#include <cmath>
#include <armadillo>
#include "unistd.h"
#define pi 3.14159

using namespace std;
using namespace arma;

int main()
{
   mat phi, K, u;
   float r=5;
   double s1=0.0,s2=0.0,s3=0.0;

while(1)
{
   K << cos((7/3)*pi) << cos(pi) << cos((5/3)*pi) << endr
     << sin((7/3)*pi) << 0 << sin((5/3)*pi) << endr;

   u << 1 << endr << 0 << endr;

   phi = (3/r) * pinv(K) * u;
   phi *=-1;
   
   s1 = 
0.0702341+3.01968*phi(0,0)+5.10016*pow(phi(0,0),2)-6.00479*pow(phi(0,0),3)+3.50626*pow(phi(0,0),4)-1.11228*pow(phi(0,0),5)+0.195824*pow(phi(0,0),6)-0.0179695*pow(phi(0,0),7)+0.000670904*pow(phi(0,0),8);

   s2 = 0.0701971+2.95862*phi(1,0)+5.00309*pow(phi(0,0),2)-5.83549*pow(phi(0,0),3)+3.38012*pow(phi(0,0),4)-1.06371*pow(phi(0,0),5)+0.185782*pow(phi(0,0),6)-0.0169127*pow(phi(0,0),7)+0.000626453*pow(phi(0,0),8);

   s3 = 0.0806085*+2.40593*phi(2,0)+5.6996*pow(phi(2,0),2)-6.4475*pow(phi(2,0),3)+3.62637*pow(phi(2,0),4)-1.10854*pow(phi(2,0),5)+0.188052*pow(phi(2,0),6)-0.0166264*pow(phi(2,0),7)+0.000597989*pow(phi(2,0),8);

   cout << phi << endl;

   cout << s1+1.1 << endl;
   cout << s2 << endl;
   cout << s3 << endl;
   usleep(1000000);
}
return 0;
}
