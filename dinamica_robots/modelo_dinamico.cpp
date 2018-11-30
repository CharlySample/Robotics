#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat k,u,y,z;
    float r=0.1,b=0.05;
    float vr=0,vl=0;

    k <<  1/r << b/4*r << endr
       << 1/r << -b/4*r << endr;

    //   k.print();

    for (int i=1;i<=20;i++)
    {
    vl = 0;
    vr = 0-3.14159/8;

      y << vl << endr << vr << endr;

      u = k * y;
      z = join_rows(z,u);

      //cout << "Iteracion " << i << endl << u << endl;

    }

z = trans(z);

z.print("matriz: " );
z.save("invd.txt", arma_ascii);

  return 0;
}
