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

  b = randn(3000,2)*0.02;
  b+=2;
  a = join_cols(a,b);

  z = randn(3000,1)*0.4;
  z +=1;
  ang = join_cols(ang,z);


  c = randn(3000,2)*0.05;

  for(int o=0;o<=1;o++)
  {
  for(int i=0;i<=2999;i++)
  {
    if(o==0)
    c(i,o) +=  1.34349;
    if(o==1)
    c(i,o) += 3.64146;
  }
}
a = join_cols(a,c);

z = randn(3000,1)*0.4 ;
z += 15;
ang = join_cols(ang,z);

    d = randn(3000,2)*0.04;

    for(int o=0;o<=1;o++)
    {
    for(int i=0;i<=2999;i++)
    {
      if(o==0)
      d(i,o) +=  3.97083;
      if(o==1)
      d(i,o) += 1.10474;
    }
    }

    a = join_cols(a,d);

    z = randn(3000,1)*0.4;
    z -= 15;
    ang = join_cols(ang,z);

    for(int i=0;i<=8999;i++)
    {
      if(  i<=2999 )
      e << i << a(i,0) << a(i,1) << ang(i,0) << 1 << endr;
      else
      e << i << a(i,0) << a(i,1) <<  ang(i,0)<< 0 << endr;

      tabla = join_cols(tabla,e);
     }

     for(int i=0;i<=8999;i++)
     {
       if(  i>=3000 and i<=5999 )
       e << i << a(i,0) << a(i,1) << ang(i,0) << 1 << endr;
       else
       e << i << a(i,0) << a(i,1) <<  ang(i,0)<< 0 << endr;

       tabla1 = join_cols(tabla1,e);
      }

      for(int i=0;i<=8999;i++)
      {
        if( i>=6000 and i<=8999 )
        e << i << a(i,0) << a(i,1) << ang(i,0) << 1 << endr;
        else
        e << i << a(i,0) << a(i,1) <<  ang(i,0)<< 0 << endr;



        tabla2 = join_cols(tabla2,e);
       }

  cout << "Correcto" << endl;
  tabla.save("capa3.txt",arma_ascii);
  tabla1.save("capa1.txt",arma_ascii);
  tabla2.save("capa2.txt",arma_ascii);

  return 0;
}
