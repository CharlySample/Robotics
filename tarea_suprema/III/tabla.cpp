#include <iostream>
#include <armadillo>
#include <fstream>

using namespace std;
using namespace arma;

int main()
{
  int k=1,x0=1,y=1,i=0;
  double x1=1.9,x2=1.9;
  mat a,b,c,d,e,tabla,ang,z,tabla1,tabla2;

  b = randn(3000,6)*0.0001;
  b+=2.3;
  //a += N(1,1);
  //a += 2.06697;
  a = join_cols(a,b);

  c = randn(3000,6)*0.0001;

  for(int o=0;o<=5;o++)
  {
  for(int i=0;i<=2999;i++)
  {
    if(o<=2)
    c(i,o) +=  3.75463;
    if(o>2 and o<=5)
    c(i,o) += 0.976588;
  }
}

a = join_cols(a,c);

    d = randn(3000,6)*0.0001;

    for(int o=0;o<=5;o++)
    {
    for(int i=0;i<=2999;i++)
    {
      if(o<=2)
      d(i,o) +=  1.176588;
      if(o>2 and o<=5)
      d(i,o) += 3.35463;
    }
    }

    a = join_cols(a,d);

    for(int i=0;i<=2;i++)
    {
      if(i==0)
      {
      z = randn(3000,1)*2;
      ang = join_cols(ang,z);
    }

    if(i==1)
    {
    z = randn(3000,1)*15;
    z += 50;
    ang = join_cols(ang,z);
  }

  if(i==1)
  {
  z = randn(3000,1)*15;
  z -= 50;
  ang = join_cols(ang,z);
}


}

    //cout << ang << endl;
    //cin.get();

    for(int i=0;i<=8999;i++)
    {
      if(  i<=2999 )
      e << i << a(i,0) << a(i,1) << a(i,2) << a(i,3) << a(i,4) << a(i,5) << ang(i,0) << 1 << endr;
      else
      e << i << a(i,0) << a(i,1) << a(i,2) << a(i,3) << a(i,4) << a(i,5) << ang(i,0) << 0 << endr;

      tabla = join_cols(tabla,e);
     }

     for(int i=0;i<=8999;i++)
     {
       if(  i>=3000 and i<=5999 )
       e << i << a(i,0) << a(i,1) << a(i,2) << a(i,3) << a(i,4) << a(i,5) << ang(i,0) << 1 << endr;
       else
       e << i << a(i,0) << a(i,1) << a(i,2) << a(i,3) << a(i,4) << a(i,5) << ang(i,0) << 0 << endr;

       tabla1 = join_cols(tabla1,e);
      }

      for(int i=0;i<=8999;i++)
      {
        if( i>=6000 and i<=8999 )
        e << i << a(i,0) << a(i,1) << a(i,2) << a(i,3) << a(i,4) << a(i,5) << ang(i,0) << 1 << endr;
        else
        e << i << a(i,0) << a(i,1) << a(i,2) << a(i,3) << a(i,4) << a(i,5) << ang(i,0) << 0 << endr;

        tabla2 = join_cols(tabla2,e);
       }

  cout << "Correcto" << endl;
  tabla.save("capa3.txt",arma_ascii);
  tabla1.save("capa1.txt",arma_ascii);
  tabla2.save("capa2.txt",arma_ascii);

  return 0;
}
