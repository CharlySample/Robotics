#include <iostream>
#include <fstream>
#include <armadillo>
#include <unistd.h>

using namespace std;
using namespace arma;

int main() {
  double i=0.0,dato=0.0;
   mat a(1,2);
    //  ofstream fp("data.txt");
  //ofstream fp("data.txt");

  /*if (fp.is_open())
   {
     fp << i << ", " << dato << endl;
     fp.close();
   }
   else cout << "Unable to open file";*/

  for(;;)
  {
    a.zeros();
i+=0.001;
    dato +=0.0005;
a(0,0) = i;
a(0,1) = dato;
a.save("data.txt",arma_ascii);
usleep(200000);
//fp.open("data.txt");

  //  if (fp.is_open())
    // {
      // fp << i << ", " << dato << endl;
  //    fp.close();
  //   }

  //  i+=0.001;
    //dato +=0.0005;
    //fp << i << ", " << dato << endl;

  }
  return 0;
}
