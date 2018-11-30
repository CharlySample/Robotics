#include <iostream>
#include <fstream>
#include <string>
#include <armadillo>
#include <unistd.h>

using namespace std;
using namespace arma;

int main() {
  double i=0.0,dato=0.0;
  mat a(1,2);
//  string line;
//  ifstream fp("dato.txt");

  for(;;)
  {
    a.zeros();
a.load("data.txt", arma_ascii);
//i= a(0,0);
usleep(10000);
if(i!=a(0,0))
{
  a.print();
  i= a(0,0);
//  a.zeros();
}
//i= a(0,0);
//    ifstream fp("dato.txt");
//fp.open("data.txt");

  //  if (fp.is_open())
//    {
  //    while ( getline (fp,line) )
    //  {
    //    fp >> cin.getline(line,40);
      //  cout << line << endl;
    //  }
    //  fp.close();
    }

  return 0;
}
